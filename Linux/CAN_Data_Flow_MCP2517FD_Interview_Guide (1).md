# MCP2517FD and SocketCAN Interview Guide

## 1. 30-Second Answer

> A Linux application creates a SocketCAN raw socket, binds it to `can0`, prepares a `struct can_frame` or `struct canfd_frame`, and calls `write()` or `send()`. The CAN raw layer validates the frame and stores it in an SKB. The networking stack routes the SKB to the `can0` network device and invokes the MCP251xFD driver's transmit callback. The driver converts the Linux CAN frame into an MCP2517FD TX object and writes it through SPI into Message RAM. The MCP2517FD performs arbitration, bit timing, bit stuffing, CRC generation, ACK monitoring, retransmission, and error handling. The CAN transceiver then drives CANH and CANL.

## 2. Complete Interview Flow

```text
Application
 -> socket(AF_CAN, SOCK_RAW, CAN_RAW)
 -> bind(can0)
 -> write()/send()
 -> system-call boundary
 -> CAN_RAW send path
 -> frame validation
 -> SKB allocation and copy
 -> CAN/network transmit path
 -> can0 (struct net_device)
 -> ndo_start_xmit
 -> mcp251xfd driver
 -> create controller-specific TX object
 -> Linux SPI subsystem
 -> MCP2517FD Message RAM / TX FIFO
 -> request transmission
 -> arbitration, CRC, stuffing and ACK
 -> CAN transceiver
 -> CANH/CANL
```

## 3. Important Distinctions

| Term | Correct meaning |
|---|---|
| `CAN_RAW` | SocketCAN raw protocol, not the hardware driver |
| `can0` | Linux CAN network interface |
| `struct net_device` | Kernel representation of `can0` |
| SKB | Kernel networking packet container |
| `mcp251xfd` | Linux driver for supported MCP25xxFD controllers |
| SPI | Host-to-controller communication |
| MCP2517FD | CAN/CAN FD protocol controller |
| Message RAM | Controller memory containing TX/RX/event objects |
| CAN transceiver | Electrical interface to CANH/CANL |

## 4. Common Questions and Answers

### Q1. Why is an SKB used for CAN?

SocketCAN is integrated with the Linux networking subsystem. The SKB provides packet ownership, metadata, queueing, network-device association, lifetime management, statistics, and local echo support.

### Q2. Is the user-space `struct can_frame` passed directly to hardware?

No. The frame is safely copied into kernel-managed packet storage. The driver reads it from the SKB and converts it into the MCP2517FD-specific TX-object layout.

```text
User can_frame -> SKB -> MCP2517FD TX object
```

### Q3. What does `can0` do?

`can0` is the network-interface abstraction connecting SocketCAN and the generic networking stack to the hardware driver. It contains interface state, CAN configuration, queue state, statistics, and driver operations.

### Q4. What happens in the driver transmit callback?

Conceptually, the driver:

1. Reads the CAN frame from the SKB.
2. Determines Classical CAN or CAN FD format.
3. Decodes standard/extended ID and frame flags.
4. Reserves a TX resource.
5. Builds an MCP2517FD TX object.
6. Transfers the object through SPI.
7. Requests hardware transmission.
8. Tracks the outstanding SKB until completion.
9. Controls the network queue according to resource availability.

Exact function names and internal ordering can vary by kernel version.

### Q5. Does successful `write()` mean the frame was acknowledged?

No. It normally means the kernel accepted the complete frame into the transmit path. Arbitration, physical transmission, ACK monitoring, retries, and completion occur later.

### Q6. Who generates the CRC and performs bit stuffing?

The MCP2517FD hardware protocol engine. The application provides the identifier, length, flags, and payload. The driver only converts these into the controller-specific object.

### Q7. What travels through SPI?

SPI transfers controller commands, addresses, register values, TX-object headers, flags, DLC information, and payload bytes. The actual CANH/CANL waveform does not travel through SPI.

### Q8. Why are both MCP2517FD and a transceiver required?

The MCP2517FD implements the CAN protocol engine. The transceiver converts controller logic levels to differential CANH/CANL electrical signaling.

```text
CPU -> SPI -> MCP2517FD -> TX/RX logic -> Transceiver -> CANH/CANL
```

### Q9. What happens if arbitration is lost?

Arbitration loss is normal CAN behavior, not a transmission error. The lower-priority transmitter stops without corrupting the winning frame and retries later.

### Q10. What happens when no node provides ACK?

The transmitter detects an ACK error. Repeated errors increase the transmit error counter and can move the controller from error-active to error-passive and eventually bus-off.

### Q11. What is TX completion?

```text
Transmission/status event
 -> MCP2517FD interrupt
 -> Linux IRQ processing
 -> driver reads status through SPI
 -> TX bookkeeping and echo-SKB completion
 -> statistics update
 -> network queue wake, if required
```

### Q12. Why can the network queue stop?

The number of driver tracking slots and hardware TX objects is finite. When no resource is available, the driver applies backpressure by stopping the queue. It wakes the queue after completion releases resources.

### Q13. Difference between Classical CAN and CAN FD structures?

| Feature | `struct can_frame` | `struct canfd_frame` |
|---|---|---|
| Maximum payload | 8 bytes | 64 bytes |
| Length field | `can_dlc` | `len` |
| BRS | Not supported | Supported |
| Raw socket setup | Normal CAN_RAW | Enable `CAN_RAW_FD_FRAMES` |

### Q14. How is CAN FD DLC encoded?

| DLC | Payload bytes |
|---:|---:|
| 0 to 8 | 0 to 8 |
| 9 | 12 |
| 10 | 16 |
| 11 | 20 |
| 12 | 24 |
| 13 | 32 |
| 14 | 48 |
| 15 | 64 |

Above eight bytes, the DLC value is not numerically equal to payload length.

### Q15. What are BRS and ESI?

- **BRS:** Bit Rate Switch. The CAN FD data phase can use the configured higher data bit rate.
- **ESI:** Error State Indicator. It reports whether the transmitting node is error-active or error-passive.

### Q16. Is the CAN ID a destination address?

Normally, no. CAN is message-oriented and broadcast. The identifier represents message meaning and arbitration priority. A higher-level protocol may add source/destination semantics.

### Q17. Why does a lower CAN ID generally have higher priority?

CAN uses dominant `0` and recessive `1` bits. A node that sends recessive but reads dominant loses arbitration. Therefore, among comparable frames, the identifier containing an earlier dominant bit wins.

### Q18. What is TEF?

TEF means Transmit Event FIFO. It records configured transmit-event information. It is different from the TX FIFO:

```text
TX FIFO -> objects waiting for transmission
TEF     -> records of configured transmit events
```

## 5. Scenario-Based Questions

### Scenario: `write()` succeeds but no frame is visible

Check in order:

1. Correct frame structure and complete write size.
2. `can0` exists and is up.
3. Correct nominal and CAN FD data bit rates.
4. Interface state and TX/error counters.
5. Kernel log for driver or SPI errors.
6. SPI clock, MOSI, MISO, and chip select.
7. MCP2517FD interrupt wiring and interrupt count.
8. Transceiver power and standby state.
9. CANH/CANL wiring and termination.
10. Presence of another active node to generate ACK.

```bash
ip -details -statistics link show can0
dmesg | grep -i -E 'can|mcp25|spi'
cat /proc/interrupts
```

### Scenario: Classical CAN works but CAN FD fails

Check:

- `CAN_RAW_FD_FRAMES` enabled on the socket
- `struct canfd_frame` and correct write size
- Interface configured with `fd on`
- Correct nominal bit rate
- Correct data bit rate
- Peer-node CAN FD support
- Compatible BRS configuration
- Valid payload length
- Transceiver suitable for the selected data rate

### Scenario: TX error counter continuously increases

Investigate:

- Missing ACK-producing node
- Bit-rate mismatch
- Incorrect CAN FD data rate
- Incorrect timing/sample point
- CANH/CANL wiring
- Missing common ground
- Incorrect termination
- Transceiver standby state
- Noise or signal-integrity problems
- Controller clock/configuration

### Scenario: Interrupt count does not change

Check:

- Device-tree interrupt GPIO
- Interrupt trigger type
- Physical INT connection
- GPIO/IRQ mapping
- Controller interrupt enable configuration
- Driver probe status
- Whether the expected controller event occurred

### Scenario: Frame latency is unexpectedly high

Possible delay points:

```text
Process scheduling
 -> kernel TX queue
 -> driver resource availability
 -> SPI scheduling
 -> MCP2517FD TX queue
 -> bus arbitration
 -> retransmission after errors
```

A timestamp before `write()` is not the same as the physical start-of-frame time.

## 6. Common Interview Traps

| Incorrect statement | Correct explanation |
|---|---|
| `can0` is a device file | SocketCAN exposes a network interface, normally accessed through CAN sockets |
| SPI sends the frame on CANH/CANL | SPI loads the controller; MCP2517FD and the transceiver generate bus signaling |
| `write()` waits for ACK | `write()` normally reports kernel acceptance, not physical ACK |
| CAN ID is always a receiver address | CAN is broadcast and message-oriented |
| Arbitration loss is an error | It is normal CAN bus-priority behavior |
| CAN FD always runs faster | A faster data phase requires BRS and matching configuration |
| CAN FD DLC always equals byte length | DLC uses encoded lengths above 8 bytes |
| Driver calculates wire CRC | MCP2517FD hardware generates the protocol CRC |
| `candump` always proves electrical transmission | Local echo may show transmitted frames; use controller status or an independent analyzer for physical verification |

## 7. Whiteboard Answer

Draw four blocks:

```text
USER SPACE
Application -> can_frame/canfd_frame -> write()

LINUX KERNEL
CAN_RAW -> SKB -> CAN networking -> can0 -> ndo_start_xmit

HOST-CONTROLLER LINK
mcp251xfd -> Linux SPI subsystem -> host SPI controller

HARDWARE
MCP2517FD Message RAM -> TX FIFO -> CAN engine -> transceiver -> CANH/CANL
```

Then add the reverse completion path:

```text
MCP2517FD status/TEF -> INT -> IRQ handler -> SPI status read
 -> echo-SKB completion -> statistics/queue update
```

## 8. Rapid-Fire Revision

| Question | Answer |
|---|---|
| Maximum Classical CAN payload? | 8 bytes |
| Maximum CAN FD payload? | 64 bytes |
| SocketCAN address family? | `AF_CAN` |
| Raw CAN protocol? | `CAN_RAW` |
| Kernel packet container? | `struct sk_buff` |
| Linux interface representation? | `struct net_device` |
| Host-to-controller interface? | SPI |
| Controller packet memory? | Message RAM |
| Physical interface device? | CAN transceiver |
| BRS full form? | Bit Rate Switch |
| ESI full form? | Error State Indicator |
| TEF full form? | Transmit Event FIFO |
| Who generates CRC? | MCP2517FD hardware |
| Is arbitration loss an error? | No |
| Does write success prove ACK? | No |
| Is SPI clock the CAN bit rate? | No |
| Does CAN FD require BRS? | No |

## 9. Strong Final Answer

> SocketCAN separates the application, generic CAN networking, hardware driver, controller transport, protocol engine, and physical transceiver. The application submits a Linux CAN frame. The kernel carries it in an SKB and routes it through `can0`. The MCP251xFD driver converts it into a controller-specific TX object and transfers it over SPI. The MCP2517FD performs arbitration, bit timing, stuffing, CRC, ACK monitoring, retransmission, and error-state management. The transceiver drives CANH and CANL. Transmission completion is asynchronous and returns through controller status and the interrupt-driven driver path.
