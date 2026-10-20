# CAN Data Flow: User Space to MCP2517FD

## 1. Purpose

This document explains the complete transmit data flow when a Linux user-space application sends a Classical CAN or CAN FD frame through SocketCAN using an MCP2517FD controller connected over SPI.

The complete path is:

```text
User Application
    -> SocketCAN socket
    -> System call
    -> CAN_RAW protocol
    -> Socket buffer (SKB)
    -> CAN networking core
    -> can0 network device
    -> mcp251xfd driver
    -> Linux SPI subsystem
    -> SPI controller
    -> MCP2517FD Message RAM / TX FIFO
    -> MCP2517FD CAN protocol engine
    -> CAN transceiver
    -> Physical CAN bus
```

---

## 2. High-Level Architecture

```text
+------------------------------------------------------------+
| USER SPACE                                                 |
|                                                            |
|  CAN Application                                           |
|      |                                                     |
|      | socket(), bind(), write()/send()                    |
|      v                                                     |
+------------------------------------------------------------+
| USER / KERNEL BOUNDARY                                     |
+------------------------------------------------------------+
| KERNEL SPACE                                               |
|                                                            |
|  System-call and socket layers                             |
|      |                                                     |
|      v                                                     |
|  CAN_RAW protocol                                          |
|      |                                                     |
|      v                                                     |
|  struct sk_buff                                            |
|      |                                                     |
|      v                                                     |
|  CAN networking core                                       |
|      |                                                     |
|      v                                                     |
|  can0: struct net_device                                   |
|      |                                                     |
|      v                                                     |
|  mcp251xfd network driver                                  |
|      |                                                     |
|      v                                                     |
|  Linux SPI subsystem and host SPI controller               |
+------------------------------------------------------------+
| HARDWARE                                                   |
|                                                            |
|  MCP2517FD                                                 |
|      |                                                     |
|      v                                                     |
|  Message RAM / TX FIFO                                     |
|      |                                                     |
|      v                                                     |
|  CAN/CAN FD protocol engine                                |
|      |                                                     |
|      v                                                     |
|  External CAN transceiver                                  |
|      |                                                     |
|      v                                                     |
|  CANH / CANL bus                                           |
+------------------------------------------------------------+
```

---

## 3. User-Space SocketCAN Application

### 3.1 Create a CAN raw socket

```c
int sock = socket(AF_CAN, SOCK_RAW, CAN_RAW);
```

Meaning:

| Parameter | Meaning |
|---|---|
| `AF_CAN` | CAN protocol address family |
| `SOCK_RAW` | Raw network socket type |
| `CAN_RAW` | SocketCAN raw CAN protocol |

`CAN_RAW` is a socket protocol. It is not the hardware driver and it does not directly access the MCP2517FD.

### 3.2 Find the CAN interface index

The application normally resolves the interface name, such as `can0`, into a network-interface index.

```c
struct ifreq ifr = {0};
strncpy(ifr.ifr_name, "can0", IFNAMSIZ - 1);
ioctl(sock, SIOCGIFINDEX, &ifr);
```

### 3.3 Bind the socket to `can0`

```c
struct sockaddr_can addr = {0};
addr.can_family  = AF_CAN;
addr.can_ifindex = ifr.ifr_ifindex;

bind(sock, (struct sockaddr *)&addr, sizeof(addr));
```

Binding associates the socket with the Linux CAN network interface represented by `can0`.

> `can0` is a Linux network interface. It is not the MCP2517FD device itself. The interface connects the generic networking stack to the registered MCP251xFD driver.

### 3.4 Prepare a Classical CAN frame

```c
struct can_frame frame = {0};

frame.can_id  = 0x123;
frame.can_dlc = 8;

frame.data[0] = 0x11;
frame.data[1] = 0x22;
frame.data[2] = 0x33;
frame.data[3] = 0x44;
frame.data[4] = 0x55;
frame.data[5] = 0x66;
frame.data[6] = 0x77;
frame.data[7] = 0x88;
```

Conceptual frame:

```text
CAN ID : 0x123
Length : 8 bytes
Data   : 11 22 33 44 55 66 77 88
```

### 3.5 Send the frame

```c
ssize_t ret = write(sock, &frame, sizeof(frame));
```

or:

```c
ssize_t ret = send(sock, &frame, sizeof(frame), 0);
```

A successful return means that the kernel accepted the frame from this socket. It does not necessarily mean that another CAN node has already acknowledged the frame on the physical bus.

---

## 4. Classical CAN Versus CAN FD

### Classical CAN

```c
struct can_frame frame;
```

- Maximum payload: 8 bytes
- Uses `struct can_frame`
- The write size is normally `sizeof(struct can_frame)`

### CAN FD

```c
struct canfd_frame frame;
```

- Maximum payload: 64 bytes
- Uses `struct canfd_frame`
- Can use Bit Rate Switching, depending on configuration and frame flags
- The write size is normally `sizeof(struct canfd_frame)`

Before sending CAN FD frames through a raw socket, the application normally enables CAN FD frame support:

```c
int enable_canfd = 1;
setsockopt(sock,
           SOL_CAN_RAW,
           CAN_RAW_FD_FRAMES,
           &enable_canfd,
           sizeof(enable_canfd));
```

Example:

```c
struct canfd_frame frame = {0};

frame.can_id = 0x123;
frame.len    = 16;
frame.flags  = CANFD_BRS;
```

Important distinction:

| Application structure | Length member | Payload |
|---|---:|---:|
| `struct can_frame` | `can_dlc` | 0 to 8 bytes |
| `struct canfd_frame` | `len` | 0 to 64 bytes |

---

## 5. User-to-Kernel Transition

When the application calls `write()` or `send()`, the CPU enters kernel mode through the system-call mechanism.

```text
USER MODE
    |
    | write()/send()
    v
KERNEL MODE
```

The kernel receives information such as:

- File descriptor
- Address of the user-space frame buffer
- Requested byte count
- Socket state and protocol information

The kernel must safely access user memory. It does not treat an arbitrary user pointer as trusted kernel memory.

The application-side object is therefore not passed directly to the MCP2517FD hardware. The frame is validated and represented inside the kernel using networking data structures.

---

## 6. File Descriptor and Socket Resolution

The file descriptor is an integer meaningful within the calling process. The kernel uses it to locate the associated socket object.

Conceptually:

```text
File descriptor
    |
    v
Process file-descriptor table
    |
    v
struct file
    |
    v
struct socket
    |
    v
struct sock
    |
    v
CAN_RAW socket state
```

Roles:

| Object | Purpose |
|---|---|
| File descriptor | User-visible handle |
| `struct file` | Kernel open-file object |
| `struct socket` | BSD socket-layer representation |
| `struct sock` | Internal networking socket state |
| CAN raw private state | CAN_RAW filters, options and bindings |

---

## 7. CAN_RAW Processing

Because the socket was created with:

```c
socket(AF_CAN, SOCK_RAW, CAN_RAW);
```

the request is handled by the SocketCAN raw protocol.

Conceptual flow:

```text
write()/send()
    |
    v
Generic socket layer
    |
    v
CAN_RAW send path
    |
    v
CAN frame validation and SKB preparation
```

Typical responsibilities include:

- Identifying whether the supplied object is a Classical CAN or CAN FD frame
- Checking whether the supplied size is valid
- Checking socket and interface state
- Allocating a kernel packet buffer
- Copying frame data from user space
- Associating the packet with the selected network device
- Submitting the packet to the CAN/network transmit path

---

## 8. Socket Buffer: `struct sk_buff`

Linux networking carries packets using `struct sk_buff`, commonly called an SKB.

```text
USER SPACE

struct can_frame
+---------------------------+
| CAN ID                    |
| DLC                       |
| Data bytes                |
+---------------------------+
             |
             | copy into kernel-managed packet storage
             v
KERNEL SPACE

struct sk_buff
+---------------------------+
| Networking metadata       |
| Device reference          |
| Protocol information      |
| CAN frame in data area    |
+---------------------------+
```

The SKB provides the generic packet representation required by the Linux networking subsystem.

The driver later accesses the CAN frame stored in the SKB data region.

Conceptually:

```c
struct canfd_frame *cfd = (struct canfd_frame *)skb->data;
```

The exact helper or cast used can depend on the kernel version and driver implementation.

---

## 9. CAN Core and Network Transmit Path

The CAN networking layer passes the prepared SKB toward the selected network device.

Simplified flow:

```text
CAN_RAW
    |
    v
CAN send path
    |
    v
Network transmit queue
    |
    v
can0
    |
    v
Driver transmit callback
```

The generic networking transmit path performs work such as:

- Associating the SKB with the target `struct net_device`
- Applying applicable queueing behavior
- Checking whether the device and transmit queue can accept traffic
- Calling the driver's network-device transmit operation

A commonly visible networking function in this path is:

```c
dev_queue_xmit(skb);
```

---

## 10. `can0` and `struct net_device`

`can0` is represented inside the kernel by a `struct net_device`.

```text
can0
  |
  +-- Interface name
  +-- Interface index
  +-- CAN bit-timing configuration
  +-- Supported controller modes
  +-- Network statistics
  +-- TX queue state
  +-- Driver operations
  +-- Driver-private data
```

Important relationship:

```text
can0                     Linux network interface
mcp251xfd                Linux hardware driver
MCP2517FD                External CAN/CAN FD controller
SPI                      Host-to-controller transport
CAN transceiver          Controller-to-physical-bus interface
```

The interface must normally be configured and brought up before transmission, for example:

```bash
sudo ip link set can0 down
sudo ip link set can0 type can bitrate 500000 dbitrate 2000000 fd on
sudo ip link set can0 up
```

The selected bit rates must match the CAN network design and the capabilities of all participating nodes.

---

## 11. Driver TX Entry Point

The network core eventually invokes the driver's transmit callback through the network device operations.

Conceptually:

```text
struct net_device_ops
    |
    v
.ndo_start_xmit
    |
    v
MCP251xFD driver's TX function
```

The exact function name can vary with kernel and driver version. It is commonly represented as an MCP251xFD start-transmit function.

The driver receives:

- Pointer to the SKB
- Pointer to the CAN network device

The driver then performs the hardware-specific conversion from Linux CAN frame format to an MCP2517FD transmit object.

---

## 12. Driver-Side Frame Processing

The driver determines information such as:

- Standard or extended CAN identifier
- Classical CAN or CAN FD format
- Payload length or DLC encoding
- Bit Rate Switch request
- Error State Indicator information, where applicable
- RTR information for Classical CAN remote frames
- Payload bytes

Conceptually:

```text
SKB data
    |
    v
Linux can_frame / canfd_frame
    |
    v
MCP2517FD TX object
```

The driver must encode Linux frame fields into the controller-specific transmit-object layout.

---

## 13. MCP2517FD TX Object

A transmit object in MCP2517FD Message RAM conceptually contains:

```text
+--------------------------------------------------+
| Identifier and format information                |
+--------------------------------------------------+
| Control information                              |
| - IDE                                             |
| - RTR/RRS-related format information             |
| - FDF                                             |
| - BRS                                             |
| - ESI                                             |
| - DLC                                             |
+--------------------------------------------------+
| Payload: 0 to 8 bytes for Classical CAN          |
|          0 to 64 bytes for CAN FD                |
+--------------------------------------------------+
| Optional sequence/status-related information     |
+--------------------------------------------------+
```

The controller format is not identical to Linux's `struct can_frame` or `struct canfd_frame`. The driver performs the conversion.

---

## 14. TX FIFO and Message RAM

The MCP2517FD contains internal Message RAM used for transmit and receive objects.

Conceptually:

```text
MCP2517FD Message RAM
+--------------------------------------------------+
| TEF: Transmit Event FIFO, if configured           |
+--------------------------------------------------+
| TX FIFO / transmit queue                          |
|   +--------------------------------------------+   |
|   | TX object header                           |   |
|   | DLC and control bits                       |   |
|   | Data payload                               |   |
|   +--------------------------------------------+   |
+--------------------------------------------------+
| RX FIFO objects                                   |
+--------------------------------------------------+
```

A typical transmit sequence is conceptually:

1. Obtain or identify a free software/hardware TX location.
2. Encode the MCP2517FD TX object.
3. Write the object into Message RAM over SPI.
4. Update the FIFO state as required.
5. Request transmission from the controller.
6. Track the outstanding SKB until completion or failure handling.

---

## 15. Linux SPI Subsystem

The MCP2517FD is commonly connected to the host processor using SPI.

```text
mcp251xfd driver
    |
    v
Linux SPI core
    |
    v
Host SPI-controller driver
    |
    v
SPI controller hardware
    |
    v
MCP2517FD
```

SPI signals:

| Signal | Meaning | Direction relative to host |
|---|---|---|
| `SCLK` | Serial clock | Host to MCP2517FD |
| `MOSI` | Controller data input | Host to MCP2517FD |
| `MISO` | Controller data output | MCP2517FD to host |
| `CS` | Chip select | Host to MCP2517FD |

The Linux device driver prepares SPI transfers containing the MCP2517FD command, address and data required for register or Message RAM access.

Depending on the implementation and operation, the driver may use synchronous or asynchronous SPI APIs and may combine multiple transfers into a message.

---

## 16. Host SPI Controller

The Linux SPI-controller driver programs the SoC's SPI hardware.

The host SPI controller then:

- Asserts chip select
- Produces the SPI clock
- Shifts command, address and transmit-object bytes on MOSI
- Samples response bytes on MISO when required
- Deasserts chip select at the end of the transfer
- Reports transfer completion to the SPI subsystem

This SPI transfer only moves the transmit object from the host to the MCP2517FD. It is not the CAN-bus transmission itself.

---

## 17. Transmission Request Inside MCP2517FD

After the TX object has been loaded, the controller is instructed to make it available for transmission.

Conceptually:

```text
TX object written to Message RAM
    |
    v
FIFO state updated
    |
    v
Transmission requested
    |
    v
MCP2517FD CAN engine schedules the frame
```

The controller may wait if:

- Another node is currently transmitting
- Inter-frame timing is active
- A higher-priority local transmit object is selected
- The controller is not in a state that permits transmission

---

## 18. MCP2517FD Hardware CAN Processing

After transmission is requested, the MCP2517FD hardware performs CAN protocol operations.

### 18.1 Arbitration

CAN uses non-destructive bitwise arbitration.

- Dominant bits overwrite recessive bits on the bus
- A transmitting node monitors the bus while sending
- A node that sends recessive but reads dominant loses arbitration
- The losing node stops transmitting and retries later

For normal data frames, a numerically lower identifier normally has higher arbitration priority when the relevant frame-format bits are equal.

### 18.2 Bit timing

The controller uses the configured nominal bit timing.

For CAN FD with Bit Rate Switching enabled:

- Arbitration phase uses the nominal bit rate
- Data phase may use the configured higher data bit rate

### 18.3 Bit stuffing

The controller inserts and checks stuff bits according to the applicable CAN protocol rules.

### 18.4 CRC

The controller generates the transmitted CRC. The user-space application does not append the physical CAN CRC manually.

### 18.5 ACK handling

The transmitter sends a recessive level in the ACK slot. A receiving node that correctly receives the frame can drive the bus dominant during that slot.

- Dominant observed in ACK slot: acknowledgment detected
- Recessive observed: ACK error

An ACK confirms that at least one other active node received the frame sufficiently to acknowledge it. It is not an application-level confirmation that the payload was processed.

### 18.6 Error handling

The controller participates in CAN error handling, including:

- Bit errors
- Stuff errors
- CRC errors
- Form errors
- ACK errors
- Transmit and receive error counters
- Error-active, error-passive and bus-off state transitions

---

## 19. CAN Transceiver

The MCP2517FD is a CAN protocol controller, not the complete physical-layer interface.

```text
MCP2517FD TX/RX logic signals
    |
    v
CAN transceiver
    |
    v
CANH and CANL differential signals
    |
    v
Physical CAN bus
```

The external transceiver:

- Converts controller logic-level transmit data into differential CANH/CANL signaling
- Converts bus differential signaling back into controller logic-level receive data
- Provides physical-layer electrical behavior
- May provide standby, wake-up or fault features, depending on the transceiver

---

## 20. TX Completion Path

After a frame is successfully transmitted, the controller records transmit completion information. Depending on configuration, this may involve the Transmit Event FIFO and interrupt flags.

Conceptual completion path:

```text
Frame transmitted or terminal condition detected
    |
    v
MCP2517FD updates status / event information
    |
    v
MCP2517FD asserts INT pin when enabled
    |
    v
Host GPIO/IRQ controller
    |
    v
Linux interrupt handling
    |
    v
mcp251xfd IRQ processing
    |
    v
Read status/event information through SPI
    |
    v
Complete or release the tracked echo SKB
    |
    v
Update network statistics and wake TX queue if required
```

### Why the driver keeps an echo SKB

The driver/networking layer may keep track of an outstanding transmitted SKB until hardware completion is known. This supports correct local echo behavior, accounting and cleanup.

The packet cannot simply be forgotten immediately after starting the SPI transfer because:

- The SPI write only loads the hardware transmit object
- Bus arbitration can occur later
- Transmission can succeed, be retried or encounter an error condition
- Driver bookkeeping must be completed safely

---

## 21. Meaning of `write()` Success

This distinction is important:

```text
write() returns successfully
```

usually means:

```text
The kernel accepted the frame into the networking/driver path.
```

It does not by itself prove:

- The frame has already appeared on CANH/CANL
- Another node acknowledged it
- A receiving application processed it
- A higher-level protocol response was received

Physical-bus confirmation requires controller/driver completion information or external bus observation. Application-level confirmation requires a protocol-level response designed by the application.

---

## 22. Queueing and Backpressure

Several queueing points can exist:

```text
Application socket
    |
    v
Linux networking TX queue
    |
    v
Driver software TX bookkeeping
    |
    v
MCP2517FD TX FIFO / queue
    |
    v
CAN bus arbitration
```

If the driver or hardware has no free TX space, the network queue can be stopped. After completion frees space, the driver can wake the queue.

Conceptual APIs include:

```c
netif_stop_queue(ndev);
netif_wake_queue(ndev);
```

The exact mechanism depends on driver and kernel version.

---

## 23. Error Scenarios

| Condition | Possible result |
|---|---|
| `can0` does not exist | Bind or interface lookup fails |
| `can0` is down | Transmission fails or is rejected |
| Incorrect frame size | Socket send path rejects the frame |
| CAN FD disabled on socket | CAN FD frame is rejected |
| CAN FD disabled on interface | CAN FD transmission cannot operate correctly |
| Incorrect nominal bit rate | Communication errors or no reception |
| Incorrect data bit rate | CAN FD data-phase errors |
| No other active node | ACK errors may occur |
| Missing or incorrect termination | Signal integrity and communication errors |
| SPI communication failure | Controller access and TX processing fail |
| MCP2517FD bus-off | Normal transmission stops until recovery policy acts |
| TX FIFO unavailable | Queue stops, frame is delayed or send path reports failure |

---

## 24. Important Return-Value Checks

### Socket creation

```c
if (sock < 0) {
    perror("socket");
}
```

### Binding

```c
if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("bind");
}
```

### Classical CAN send

```c
ssize_t nbytes = write(sock, &frame, sizeof(frame));

if (nbytes < 0) {
    perror("write");
} else if (nbytes != sizeof(frame)) {
    fprintf(stderr, "Incomplete CAN frame write\n");
}
```

SocketCAN frames are packet-oriented. Treat an unexpected returned size as an error condition rather than attempting to send the remaining bytes as though the socket were a byte stream.

---

## 25. Complete Classical CAN Example

```c
#include <errno.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <net/if.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <unistd.h>

int main(void)
{
    int sock;
    struct ifreq ifr;
    struct sockaddr_can addr;
    struct can_frame frame;
    ssize_t nbytes;

    /* Create a raw SocketCAN socket. */
    sock = socket(AF_CAN, SOCK_RAW, CAN_RAW);
    if (sock < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    /* Resolve can0 to its kernel interface index. */
    memset(&ifr, 0, sizeof(ifr));
    strncpy(ifr.ifr_name, "can0", IFNAMSIZ - 1);

    if (ioctl(sock, SIOCGIFINDEX, &ifr) < 0) {
        perror("SIOCGIFINDEX");
        close(sock);
        return EXIT_FAILURE;
    }

    /* Bind the socket to can0. */
    memset(&addr, 0, sizeof(addr));
    addr.can_family  = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        close(sock);
        return EXIT_FAILURE;
    }

    /* Prepare an 11-bit Classical CAN data frame. */
    memset(&frame, 0, sizeof(frame));
    frame.can_id  = 0x123;
    frame.can_dlc = 8;

    frame.data[0] = 0x11;
    frame.data[1] = 0x22;
    frame.data[2] = 0x33;
    frame.data[3] = 0x44;
    frame.data[4] = 0x55;
    frame.data[5] = 0x66;
    frame.data[6] = 0x77;
    frame.data[7] = 0x88;

    /* Submit one complete CAN frame to SocketCAN. */
    nbytes = write(sock, &frame, sizeof(frame));
    if (nbytes < 0) {
        perror("write");
        close(sock);
        return EXIT_FAILURE;
    }

    if (nbytes != (ssize_t)sizeof(frame)) {
        fprintf(stderr, "Unexpected CAN write length: %zd\n", nbytes);
        close(sock);
        return EXIT_FAILURE;
    }

    printf("CAN frame accepted by the kernel TX path\n");

    close(sock);
    return EXIT_SUCCESS;
}
```

Compile:

```bash
gcc -Wall -Wextra -O2 can_tx.c -o can_tx
```

---

## 26. Complete CAN FD Example

```c
#include <linux/can.h>
#include <linux/can/raw.h>
#include <net/if.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <unistd.h>

int main(void)
{
    int sock;
    int enable_canfd = 1;
    struct ifreq ifr;
    struct sockaddr_can addr;
    struct canfd_frame frame;
    ssize_t nbytes;

    sock = socket(AF_CAN, SOCK_RAW, CAN_RAW);
    if (sock < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    /* Permit struct canfd_frame on this CAN_RAW socket. */
    if (setsockopt(sock,
                   SOL_CAN_RAW,
                   CAN_RAW_FD_FRAMES,
                   &enable_canfd,
                   sizeof(enable_canfd)) < 0) {
        perror("setsockopt(CAN_RAW_FD_FRAMES)");
        close(sock);
        return EXIT_FAILURE;
    }

    memset(&ifr, 0, sizeof(ifr));
    strncpy(ifr.ifr_name, "can0", IFNAMSIZ - 1);

    if (ioctl(sock, SIOCGIFINDEX, &ifr) < 0) {
        perror("SIOCGIFINDEX");
        close(sock);
        return EXIT_FAILURE;
    }

    memset(&addr, 0, sizeof(addr));
    addr.can_family  = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        close(sock);
        return EXIT_FAILURE;
    }

    memset(&frame, 0, sizeof(frame));
    frame.can_id = 0x123;
    frame.len    = 16;
    frame.flags  = CANFD_BRS;

    for (unsigned int i = 0; i < frame.len; ++i) {
        frame.data[i] = (unsigned char)i;
    }

    nbytes = write(sock, &frame, sizeof(frame));
    if (nbytes < 0) {
        perror("write");
        close(sock);
        return EXIT_FAILURE;
    }

    if (nbytes != (ssize_t)sizeof(frame)) {
        fprintf(stderr, "Unexpected CAN FD write length: %zd\n", nbytes);
        close(sock);
        return EXIT_FAILURE;
    }

    printf("CAN FD frame accepted by the kernel TX path\n");

    close(sock);
    return EXIT_SUCCESS;
}
```

---

## 27. Practical Test Commands

### Configure Classical CAN

```bash
sudo ip link set can0 down
sudo ip link set can0 type can bitrate 500000
sudo ip link set can0 up
```

### Configure CAN FD

```bash
sudo ip link set can0 down
sudo ip link set can0 type can bitrate 500000 dbitrate 2000000 fd on
sudo ip link set can0 up
```

### Check interface details

```bash
ip -details -statistics link show can0
```

### Send a Classical CAN frame

```bash
cansend can0 123#1122334455667788
```

### Monitor frames

```bash
candump can0
```

### Monitor with timestamps

```bash
candump -t a can0
```

### Generate continuous traffic carefully

```bash
cangen can0
```

Use traffic generation only on an isolated test bus where the generated identifiers and payloads are safe for all connected nodes.

---

## 28. Debugging the TX Path

### Layer 1: User application

Check:

- Return value of `socket()`
- Return value of `ioctl(SIOCGIFINDEX)`
- Return value of `bind()`
- Return value and `errno` from `write()` or `send()`
- Correct frame type and byte count

Useful tool:

```bash
strace -e trace=socket,ioctl,bind,write,sendto ./can_tx
```

### Layer 2: SocketCAN interface

```bash
ip -details -statistics link show can0
```

Check:

- Interface is `UP`
- Bit rate is correct
- CAN FD mode is correct
- TX packet and error counters
- Controller state such as error-active, error-passive or bus-off

### Layer 3: Driver and kernel log

```bash
dmesg | grep -i -E 'can|mcp25|spi'
```

Check for:

- Probe failure
- Clock or regulator issues
- SPI communication errors
- Interrupt errors
- Bus-off or controller errors

### Layer 4: SPI

Use, where appropriate:

- Kernel tracing
- SPI-controller debug information
- Logic analyzer on `SCLK`, `MOSI`, `MISO` and `CS`

Verify:

- Chip select reaches the intended controller
- Clock polarity and phase are correct
- SPI frequency is valid
- Commands and data are transferred

### Layer 5: Interrupt

```bash
cat /proc/interrupts
```

Check whether the interrupt count for the MCP251xFD device changes during communication.

### Layer 6: Physical CAN bus

Verify:

- CAN transceiver is powered and enabled
- CANH and CANL are connected correctly
- Bus has correct termination
- At least one other active CAN node is available for ACK
- All nodes use matching nominal bit timing
- CAN FD nodes use compatible data-phase timing

Useful equipment:

- CAN analyzer
- Oscilloscope
- Differential probe
- Logic analyzer with CAN decoding

---

## 29. Useful Linux Tracing Points

Depending on kernel configuration and available symbols, inspect events and functions related to:

```text
System calls
Socket send path
CAN raw send path
CAN packet submission
Network-device TX queue
MCP251xFD TX handling
SPI message submission/completion
IRQ handling
Network queue stop/wake
```

Examples of investigation tools:

| Tool | Best use |
|---|---|
| `strace` | Confirm user-space system calls and errors |
| `ip -s -d link` | Inspect CAN state, configuration and counters |
| `candump` | Observe SocketCAN receive-visible traffic |
| `ftrace` | Trace selected kernel functions and timing |
| `perf` | Profile CPU activity and kernel call paths |
| `bpftrace`/eBPF | Dynamic tracing where supported |
| Logic analyzer | Verify SPI and interrupt electrical activity |
| CAN analyzer | Verify actual frames on the physical bus |

Function names and tracepoint availability depend on the exact Linux kernel and driver version.

---

## 30. Common Misunderstandings

### Misunderstanding 1: `CAN_RAW` is the hardware driver

Incorrect.

```text
CAN_RAW = SocketCAN socket protocol
mcp251xfd = hardware-specific driver
```

### Misunderstanding 2: `can0` is the physical controller

Not exactly.

```text
can0 = kernel network-interface representation
MCP2517FD = external hardware controller
```

### Misunderstanding 3: SPI transmits the CAN frame on CANH/CANL

Incorrect.

```text
SPI transfers a controller-specific TX object from host to MCP2517FD.
MCP2517FD then generates the actual CAN/CAN FD bit stream.
```

### Misunderstanding 4: The application calculates CRC and bit stuffing

Incorrect for normal SocketCAN use.

```text
Application supplies ID, length, flags and payload.
MCP2517FD hardware performs protocol-level CRC and bit stuffing.
```

### Misunderstanding 5: Successful `write()` proves ACK reception

Incorrect.

```text
Successful write() means the kernel accepted the packet.
Physical completion and ACK occur later in the controller/bus path.
```

### Misunderstanding 6: The user-space structure is written unchanged into Message RAM

Incorrect.

```text
User can_frame/canfd_frame
    -> kernel SKB representation
    -> driver-specific conversion
    -> MCP2517FD TX object
```

---

## 31. End-to-End Sequence Diagram

```text
Application      CAN_RAW       CAN/Net Core      mcp251xfd       SPI       MCP2517FD       Bus
    |                |               |                |             |            |             |
    | write(frame)   |               |                |             |            |             |
    |--------------->|               |                |             |            |             |
    |                | validate      |                |             |            |             |
    |                | allocate SKB  |                |             |            |             |
    |                | copy frame    |                |             |            |             |
    |                |-------------->|                |             |            |             |
    |                |               | queue/xmit     |             |            |             |
    |                |               |--------------->|             |            |             |
    |                |               |                | encode TX   |            |             |
    |                |               |                | object      |            |             |
    |                |               |                |------------>|            |             |
    |                |               |                |             | SPI write  |             |
    |                |               |                |             |----------->|             |
    |                |               |                |             |            | TX request  |
    |                |               |                |             |            |------------>|
    |                |               |                |             |            | arbitration |
    |                |               |                |             |            | CRC/ACK     |
    |                |               |                |             |            |<------------|
    |                |               |                |<------------ interrupt/status          |
    |                |               |                | release/complete SKB                    |
    |                |               |<---------------|                                       |
```

The diagram is conceptual. Some operations can be deferred, queued or executed in different kernel contexts depending on the driver and kernel version.

---

## 32. Compact Layer Table

| Layer | Main object | Main responsibility |
|---|---|---|
| User application | `struct can_frame` / `struct canfd_frame` | Prepare and send frame |
| System-call layer | File descriptor and user buffer | Enter kernel and validate access |
| CAN_RAW | Raw CAN socket state | Validate frame and create packet representation |
| Networking buffer | `struct sk_buff` | Carry frame and kernel metadata |
| CAN/networking core | TX routing and queueing | Send SKB to selected CAN device |
| CAN interface | `struct net_device` for `can0` | Represent CAN controller as a network device |
| MCP251xFD driver | Driver-private TX state | Convert SKB frame to controller TX object |
| SPI subsystem | SPI message/transfers | Transfer object to MCP2517FD |
| MCP2517FD Message RAM | TX FIFO/queue object | Store frame awaiting transmission |
| MCP2517FD CAN engine | Protocol state machine | Arbitration, timing, stuffing, CRC and ACK |
| CAN transceiver | Physical-layer device | Convert logic data to CANH/CANL signaling |
| CAN bus | Differential medium | Carry CAN frame among nodes |

---

## 33. Key Terms

### `AF_CAN`
Linux CAN address family.

### `SOCK_RAW`
Raw socket type used with the CAN_RAW protocol.

### `CAN_RAW`
SocketCAN raw protocol for direct CAN frame send and receive operations.

### `struct can_frame`
User/kernel CAN frame layout used for Classical CAN.

### `struct canfd_frame`
CAN FD frame layout supporting a payload of up to 64 bytes.

### SKB
Short name for `struct sk_buff`, the Linux kernel networking packet buffer.

### CAN core
Common Linux CAN networking support shared by CAN network drivers and CAN protocols.

### `can0`
Linux network interface associated with a CAN controller driver instance.

### `struct net_device`
Kernel object representing a network interface.

### `mcp251xfd`
Linux driver family for supported MCP25xxFD SPI CAN/CAN FD controllers, including MCP2517FD.

### SPI
Host communication bus used to access MCP2517FD registers and Message RAM.

### Message RAM
MCP2517FD internal memory used for transmit, receive and event objects.

### TX FIFO / TX queue
Hardware storage and scheduling mechanism for pending transmit objects.

### TEF
Transmit Event FIFO, used by the controller to record configured transmit events.

### CAN transceiver
Physical-layer component between the CAN controller logic signals and CANH/CANL.

### ACK
Bus-level acknowledgment driven by a receiving node after correct frame reception.

### Bus-off
CAN controller state entered after excessive transmit errors; normal transmission is disabled until recovery according to the configured policy.

---

## 34. Interview Answer

> A Linux application sends a CAN frame by writing a `struct can_frame` or `struct canfd_frame` to a SocketCAN raw socket bound to `can0`. The system call enters the kernel, where the CAN_RAW layer validates the frame and places it in an SKB. The CAN and generic networking transmit path routes the SKB to the `can0` network device. The MCP251xFD driver's transmit callback converts the Linux CAN frame into an MCP2517FD TX object and writes it through the Linux SPI subsystem into the controller's Message RAM. The driver then requests transmission. The MCP2517FD performs arbitration, bit timing, bit stuffing, CRC generation, ACK monitoring and CAN error handling. The external CAN transceiver converts the controller's logic signal into differential CANH/CANL bus signaling. After transmission or an error event, the controller reports status, typically through its interrupt path, and the driver completes its SKB bookkeeping and updates network state.

---

## 35. One-Line Summary

```text
Application -> write()/send() -> CAN_RAW -> SKB -> CAN networking core -> can0 -> mcp251xfd driver -> SPI -> MCP2517FD TX FIFO -> CAN engine -> CAN transceiver -> CAN bus
```

---

## 36. Final Memory Points

```text
CAN_RAW     = SocketCAN raw socket protocol
SKB         = Kernel packet container
can0        = Linux CAN network interface
mcp251xfd   = MCP2517FD hardware driver
SPI         = Host-to-controller communication
Message RAM = Controller-side TX/RX/event object storage
MCP2517FD   = CAN/CAN FD protocol controller
Transceiver = Physical CANH/CANL interface
```
