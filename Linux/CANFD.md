# CAN frame

| Field | Sub-field | CAN 2.0A | CAN 2.0B | CAN FD | If Selected / Value | Importance |
|---------|-----------|---------|---------|---------|---------------------|-----------|
| **SOF** | Start of Frame | 1 bit | 1 bit | 1 bit | Dominant (0) | Marks start of frame and synchronizes all nodes. |
| **Arbitration Field** | Identifier | 11 bits | 29 bits | 11/29 bits | Lower ID = Higher Priority | Defines message type and arbitration priority. |
| | SRR (Substitute Remote Request) | — | 1 bit | — |  0 = Standard (11-bit)<br>1 = Extended (29-bit) | Used during extended frame arbitration. |
| | RTR | 1 bit | 1 bit | — | 0 = Data Frame<br>1 = Remote Frame | Indicates data transmission or data request. |
| | RRS | — | — | 1 bit | Always Dominant (0) | Replaces RTR in CAN FD. |
| | IDE | 1 bit | 1 bit | 1 bit | 0 = Standard (11-bit)<br>1 = Extended (29-bit) | Selects frame format. |
| **Control Field** | r0/r1 | 1 bit | 2 bits | Reserved | Always 0 | Reserved for future use. |
| | FDF | — | — | 1 bit | 0 = Classical CAN<br>1 = CAN FD | Indicates CAN FD frame. |
| | BRS (Bit Rate Switch)| — | — | 1 bit | 0 = Same Bit Rate<br>1 = Faster Data Phase | Enables higher data-phase speed. |
| | ESI (Error satate indicator)| — | — | 1 bit | 0 = Error Active<br>1 = Error Passive | Indicates transmitter error state. |
| | DLC | 4 bits | 4 bits | 4 bits | 0-15 | Defines payload size. |
| **Data Field** | Data | 0-8 Bytes | 0-8 Bytes | 0-64 Bytes | Application Data | Carries actual payload. |
| **CRC Field** | CRC Sequence | 15 bits | 15 bits | 17/21 bits | Computed by Controller | Error detection. |
| | CRC Delimiter | 1 bit | 1 bit | 1 bit | Recessive (1) | Separates CRC and ACK fields. |
| **ACK Field** | ACK Slot | 1 bit | 1 bit | 1 bit | 0 = ACK Received<br>1 = No ACK | Receiver acknowledgment. |
| | ACK Delimiter | 1 bit | 1 bit | 1 bit | Recessive (1) | End of ACK field. |
| **EOF** | End of Frame | 7 bits | 7 bits | 7 bits | 1111111 (Recessive) | Indicates end of frame. |
-----------------------------------
| Bit | 0 Means | 1 Means |
|------|----------|----------|
| **RTR** (Remote Transmission Request) | Data Frame | Remote Frame |
| **IDE** (Identifier Extension) | Standard ID (11-bit) | Extended ID (29-bit) |
| **FDF** (FD Format) | Classical CAN | CAN FD |
| **BRS** (Bit Rate Switch) | Normal Speed | Higher Data-Phase Speed |
| **ESI** (Error State Indicator) | Error Active | Error Passive |
| **ACK Slot** | ACK Received | No ACK Received |

# FULL HARDWARE + DRIVER DEEP FLOW (VERY TECHNICAL)

```
╔══════════════════════════════════════════════════════════════════════════╗
║                               USER SPACE                                 ║
╠══════════════════════════════════════════════════════════════════════════╣
║ socket()                                                                 ║
║ write(struct can_frame)                                                  ║
╚═══════════════════════════════╦══════════════════════════════════════════╝
                                ║
                                ▼
╔══════════════════════════════════════════════════════════════════════════╗
║                              SOCKETCAN                                   ║
╠══════════════════════════════════════════════════════════════════════════╣
║ can_send()                                                               ║
║ sk_buff allocation                                                       ║
║ CAN frame fields:                                                        ║
║   • can_id                                                               ║
║   • can_dlc                                                              ║
║   • data[0..7]                                                           ║
╚═══════════════════════════════╦══════════════════════════════════════════╝
                                ║
                                ▼
╔══════════════════════════════════════════════════════════════════════════╗
║                          CAN CORE (KERNEL)                               ║
╠══════════════════════════════════════════════════════════════════════════╣
║ • Validate CAN frame                                                     ║
║ • Select netdevice (can0)                                                ║
║ • Queue TX request                                                       ║
╚═══════════════════════════════╦══════════════════════════════════════════╝
                                ║
                                ▼
╔══════════════════════════════════════════════════════════════════════════╗
║                MCP25xxFD DRIVER (TX PATH ENTRY)                          ║
╠══════════════════════════════════════════════════════════════════════════╣
║ mcp25xxfd_start_xmit()                                                   ║
║                                                                          ║
║ STEP 1: skb → CAN frame decode                                           ║
║ STEP 2: Select TX FIFO (Message RAM slot)                                ║
║ STEP 3: Build TX object                                                  ║
║   ├─ CAN ID register                                                     ║
║   ├─ DLC register                                                        ║
║   └─ DATA buffer                                                         ║
║ STEP 4: SPI burst write to MCP2517FD                                     ║
╚═══════════════════════════════╦══════════════════════════════════════════╝
                                ║
                                ▼
╔══════════════════════════════════════════════════════════════════════════╗
║                 MCP2517FD INTERNAL MEMORY MAP                            ║
╠══════════════════════════════════════════════════════════════════════════╣
║ MESSAGE RAM                                                              ║
║   ├─ TX FIFO                                                             ║
║   │   ├─ Header (ID + control bits)                                      ║
║   │   ├─ DLC                                                             ║
║   │   ├─ DATA[0..64 bytes]                                               ║
║   │   └─ TX status flags                                                 ║
║   │                                                                      ║
║   ├─ RX FIFO                                                             ║
║   ├─ FILTER RAM                                                          ║
║   └─ FIFO CONTROL (head / tail pointers)                                 ║
╚═══════════════════════════════╦══════════════════════════════════════════╝
                                ║
                                ▼
╔══════════════════════════════════════════════════════════════════════════╗
║                        TX CONTROL LOGIC (HARDWARE)                       ║
╠══════════════════════════════════════════════════════════════════════════╣
║ • TXREQ bit set                                                          ║
║                                                                          ║
║ Hardware functions:                                                      ║
║   • CAN arbitration (ID priority)                                        ║
║   • Bit timing engine                                                    ║
║   • CRC generation                                                       ║
║   • Bit stuffing                                                         ║
╚═══════════════════════════════╦══════════════════════════════════════════╝
                                ║
                                ▼
╔══════════════════════════════════════════════════════════════════════════╗
║                               CAN BUS                                    ║
╚══════════════════════════════════════════════════════════════════════════╝
```
- `socket(AF_CAN, SOCK_RAW, CAN_RAW)` creates a SocketCAN raw CAN socket.

- You bind it to an interface such as `can0`.

- `write()/send()` puts the CAN frame into the Linux networking stack.

- The `SocketCAN` CAN core routes the frame to the network device representing `can0`.

- The `MCP251xFD` Linux driver receives the frame through the network-device transmit path.

- The driver converts the CAN frame into the appropriate `MCP2517FD/MCP2518FD` controller registers/RAM format.

- The driver communicates with the `MCP2517FD/MCP2518FD` over `SPI`.

- The `MCP2517FD/MCP2518FD` transmits the CAN/CAN-FD frame onto the physical CAN bus.


# RX PATH DIAGRAM (REVERSE FLOW)

```
╔══════════════════════════════════════════════════════╗
║                      CAN BUS                         ║
╚══════════════════════════════════════════════════════╝
                           │
                           ▼
╔══════════════════════════════════════════════════════╗
║              MCP2517FD HARDWARE                      ║
║------------------------------------------------------║
║  • Receives CAN frame                                ║
║  • Stores in RX FIFO (Message RAM)                   ║
║  • Sets interrupt (INT pin)                          ║
╚══════════════════════════════════════════════════════╝
                           │
                           ▼
╔══════════════════════════════════════════════════════╗
║            DRIVER INTERRUPT HANDLER                  ║
║------------------------------------------------------║
║  • Read RX FIFO via SPI                              ║
║  • Decode CAN frame                                  ║
║  • Clear interrupt flags                             ║
╚══════════════════════════════════════════════════════╝
                           │
                           ▼
╔══════════════════════════════════════════════════════╗
║                   SOCKETCAN                          ║
║------------------------------------------------------║
║  • Converts to sk_buff                               ║
║  • Pushes packet to kernel network stack             ║
╚══════════════════════════════════════════════════════╝
                           │
                           ▼
╔══════════════════════════════════════════════════════╗
║                USER SPACE APPLICATION                ║
║------------------------------------------------------║
║  • recv() / read()                                   ║
║  • Gets CAN frame data                               ║
╚══════════════════════════════════════════════════════╝
```

# 1. DRIVER DESIGN ARCHITECTURE (FULL FLOW)
```

                     ┌────────────────────────────┐
                     │      USER SPACE APP        │
                     │----------------------------│
                     │ socket(), write(), read()  │
                     └──────────────┬─────────────┘
                                    │
                                    ▼
                     ┌────────────────────────────┐
                     │        SOCKETCAN           │
                     │----------------------------│
                     │ can_frame ↔ sk_buff        │
                     └──────────────┬─────────────┘
                                    │
                                    ▼
                     ┌────────────────────────────┐
                     │       CAN NETWORK CORE     │
                     │----------------------------│
                     │ TX/RX queues               │
                     │ device selection (can0)    │
                     └──────────────┬─────────────┘
                                    │
        ┌───────────────────────────┼───────────────────────────┐
        │                           │                           │
        ▼                           ▼                           ▼

┌────────────────────┐   ┌────────────────────┐   ┌────────────────────┐
│   TX PATH          │   │   RX PATH          │   │  CONTROL PATH      │
│--------------------│   │--------------------│   │--------------------│
│ start_xmit()       │   │ IRQ handler        │   │ open()/close()     │
│ FIFO mgmt         │   │ FIFO read          │   │ config/setup       │
│ SPI write         │   │ sk_buff creation   │   │ bitrate setup      │
└─────────┬──────────┘   └─────────┬──────────┘   └─────────┬──────────┘
          │                        │                        │
          └──────────────┬─────────┴─────────┬──────────────┘
                         ▼                   ▼
              ┌────────────────────────────────────┐
              │        SPI DRIVER LAYER            │
              │------------------------------------│
              │ spi_sync(), spi_read/write         │
              │ burst FIFO access                  │
              └──────────────────┬─────────────────┘
                                 ▼
              ┌────────────────────────────────────┐
              │   MCP2517FD HARDWARE CONTROLLER   │
              │------------------------------------│
              │ Message RAM (TX/RX FIFOs)         │
              │ CAN FD engine                     │
              │ Interrupt controller              │
              │ Error counters (TEC/REC)          │
              └──────────────────┬─────────────────┘
                                 ▼
              ┌────────────────────────────────────┐
              │             CAN BUS               │
              └────────────────────────────────────┘
```

# 2. INTERNAL DRIVER DESIGN FLOW (CODE STRUCTURE)

## A. PROBE / INIT FLOW (Driver Start)
```
mcp25xxfd_probe()
   │
   ├─ SPI device init
   ├─ reset MCP2517FD
   ├─ read device ID
   ├─ configure clock (PLL)
   ├─ setup CAN bit timing
   ├─ setup Message RAM
   │     ├─ TX FIFOs
   │     ├─ RX FIFOs
   │     └─ filters
   ├─ enable interrupts
   └─ set NORMAL mode
```

# B. TRANSMIT DESIGN FLOW

```
mcp25xxfd_start_xmit()
   │
   ├─ get skb (from SocketCAN)
   ├─ convert to CAN FD format
   ├─ select TX FIFO
   ├─ build TX message object
   │     ├─ ID register
   │     ├─ DLC register
   │     ├─ DATA buffer
   │
   ├─ SPI write → Message RAM
   ├─ set TXREQ bit
   └─ return NETDEV_TX_OK

```  
## C. RECEIVE DESIGN FLOW (INTERRUPT DRIVEN)
```
mcp25xxfd_irq_handler()
   │
   ├─ read interrupt flags (SPI)
   ├─ check RXIF bit
   │
   ├─ read RX FIFO via SPI
   │     ├─ CAN ID
   │     ├─ DLC
   │     ├─ DATA
   │
   ├─ convert → sk_buff
   ├─ push to SocketCAN
   └─ clear interrupt flags
 ```

## D. ERROR HANDLING DESIGN FLOW
 
 ```
 interrupt handler
   │
   ├─ check error flags
   │     ├─ Bit error
   │     ├─ CRC error
   │     ├─ ACK error
   │
   ├─ read TEC/REC counters
   │
   ├─ state decision:
   │     ├─ Error Active
   │     ├─ Error Passive
   │     └─ Bus-Off
   │
   ├─ report to SocketCAN
   └─ if Bus-Off → stop TX
  ```

  ## E. BUS-OFF RECOVERY DESIGN
  ```
  Bus-Off detected
   │
   ├─ stop transmission
   ├─ notify kernel
   │
   ├─ restart-ms timer (if enabled)
   │
   ▼
reinit sequence
   ├─ reset MCP2517FD
   ├─ reconfigure FIFO
   ├─ re-enable interrupts
   └─ set NORMAL mode
  ```
# 3. INTERNAL BLOCK DESIGN (HARDWARE MAPPING)

```
MCP2517FD INTERNAL DESIGN
│
├── TX Engine
│     ├─ TX FIFO 0..n
│     ├─ TX priority logic
│     └─ TXREQ control
│
├── RX Engine
│     ├─ RX FIFO 0..n
│     ├─ filter logic
│     └─ acceptance masks
│
├── Message RAM
│     ├─ TX buffers
│     ├─ RX buffers
│     └─ TEF (event FIFO)
│
├── CAN FD Bit Engine
│     ├─ arbitration
│     ├─ CRC generation
│     └─ bit timing
│
└── Interrupt Unit
      ├─ RX interrupt
      ├─ TX interrupt
      ├─ error interrupt
``` 


```c
/*
 * Driver probe function
 *
 * Called when Linux detects your CAN hardware
 * (SPI/I2C/PCI/Platform device).
 */
static int my_can_probe(struct device *dev)
{
	struct net_device *netdev;
	struct my_can_priv *priv;

	/*
	 * alloc_candev()
	 *
	 * Linux allocates memory:
	 *
	 * +----------------------+
	 * | struct net_device    |
	 * +----------------------+
	 * | my_can_priv          |
	 * +----------------------+
	 *
	 * net_device:
	 *   Generic Linux network object.
	 *
	 * my_can_priv:
	 *   Driver private memory.
	 */
	netdev = alloc_candev(sizeof(struct my_can_priv), 1);
	if (!netdev)
		return -ENOMEM;

	/*
	 * Retrieve driver's private area.
	 *
	 * netdev
	 *   ↓
	 * private memory
	 */
	priv = netdev_priv(netdev);

	/*
	 * Attach network operations.
	 *
	 * Linux stores these callbacks.
	 *
	 * Later:
	 *
	 * ip link set can0 up
	 *      ↓
	 * ndo_open()
	 *
	 * ip link set can0 down
	 *      ↓
	 * ndo_stop()
	 *
	 * cansend can0 ...
	 *      ↓
	 * ndo_start_xmit()
	 */
	netdev->netdev_ops = &my_can_netdev_ops;

	/*
	 * Register CAN device.
	 *
	 * IMPORTANT STEP.
	 *
	 * Linux now:
	 *
	 * 1. Adds device to networking subsystem
	 * 2. Assigns interface name (can0)
	 * 3. Assigns ifindex
	 * 4. Creates sysfs entries
	 * 5. Makes device visible to SocketCAN
	 * 6. Allows Netlink to manage it
	 */
	if (register_candev(netdev)) {
		free_candev(netdev);
		return -EINVAL;
	}

	pr_info("CAN device registered as %s\n",
		netdev->name);

	return 0;
}
```
# Linux SocketCAN driver development with Netlink-based network interface control and kernel callback architecture (ndo_open, ndo_start_xmit)

```c
/*
 * SIMPLE SOCKETCAN DRIVER (LEARNING VERSION)
 *
 * This does NOT talk to real hardware.
 * It shows how Linux creates:
 *   - net_device (can0)
 *   - net_device_ops
 *   - ifindex
 *   - SocketCAN integration
 *   - Netlink control path
 */

#include <linux/module.h>
#include <linux/netdevice.h>
#include <linux/can/dev.h>
#include <linux/skbuff.h>

/* ---------------------------------------------------------
 * DRIVER PRIVATE DATA
 * ---------------------------------------------------------
 * This is embedded inside struct net_device memory.
 *
 * Created by:
 *   alloc_candev(sizeof(struct my_can_priv))
 *
 * Purpose:
 *   Store hardware state (SPI registers, buffers, etc.)
 */
struct my_can_priv {
    int fake_state;
};

/* ---------------------------------------------------------
 * ndo_open()
 * ---------------------------------------------------------
 * Called when:
 *
 *   ip link set can0 up
 *
 * Flow:
 *   Netlink → rtnetlink → dev_open() → ndo_open()
 *
 * Why important:
 *   - powers on hardware
 *   - enables interrupts
 *   - starts CAN controller
 */
static int my_can_open(struct net_device *netdev)
{
    struct my_can_priv *priv = netdev_priv(netdev);

    pr_info("CAN OPEN called (interface UP)\n");

    /* Example hardware init */
    priv->fake_state = 1;

    netif_start_queue(netdev);

    return 0;
}

/* ---------------------------------------------------------
 * ndo_stop()
 * ---------------------------------------------------------
 * Called when:
 *
 *   ip link set can0 down
 *
 * Flow:
 *   Netlink → dev_close() → ndo_stop()
 *
 * Why important:
 *   - stops hardware
 *   - disables interrupts
 */
static int my_can_stop(struct net_device *netdev)
{
    struct my_can_priv *priv = netdev_priv(netdev);

    pr_info("CAN STOP called (interface DOWN)\n");

    priv->fake_state = 0;

    netif_stop_queue(netdev);

    return 0;
}

/* ---------------------------------------------------------
 * ndo_start_xmit()
 * ---------------------------------------------------------
 * Called when:
 *
 *   cansend can0 123#1122
 *
 * Flow:
 *   userspace → PF_CAN socket → SocketCAN → skb → driver
 *
 * NOT Netlink!
 *
 * Why important:
 *   - sends CAN frame to hardware
 */
static netdev_tx_t my_can_start_xmit(struct sk_buff *skb,
                                     struct net_device *netdev)
{
    struct can_frame *cf = (struct can_frame *)skb->data;

    pr_info("TX frame: can_id=0x%X dlc=%d\n",
            cf->can_id, cf->can_dlc);

    /* In real driver:
     * - write SPI registers
     * - push FIFO
     * - trigger TX
     */

    dev_kfree_skb(skb);

    return NETDEV_TX_OK;
}

/* ---------------------------------------------------------
 * net_device_ops TABLE
 * ---------------------------------------------------------
 *
 * This is NOT created by kernel.
 * Driver defines it.
 *
 * Kernel uses it like:
 *
 *   netdev->netdev_ops->ndo_open()
 */
static const struct net_device_ops my_can_netdev_ops = {

    /* Called by Netlink (ip link set can0 up) */
    .ndo_open       = my_can_open,

    /* Called by Netlink (ip link set can0 down) */
    .ndo_stop       = my_can_stop,

    /* Called by SocketCAN (cansend) */
    .ndo_start_xmit = my_can_start_xmit,

    /* MTU change via Netlink */
    .ndo_change_mtu = can_change_mtu,
};

/* ---------------------------------------------------------
 * PROBE FUNCTION (driver load)
 * ---------------------------------------------------------
 *
 * Called when hardware is detected (SPI/PCI/platform)
 *
 * This is where Linux creates can0.
 */
static int my_can_probe(void)
{
    struct net_device *netdev;
    struct my_can_priv *priv;

    /*
     * alloc_candev():
     *
     * Creates:
     *   - struct net_device (can0)
     *   - private memory (my_can_priv)
     *
     * Stored in kernel memory (slab allocator)
     */
    netdev = alloc_candev(sizeof(struct my_can_priv), 1);
    if (!netdev)
        return -ENOMEM;

    /*
     * Get driver private memory
     */
    SET_NETDEV_DEV(netdev, &spi->dev);  // set up the network this is important 
    priv = netdev_priv(netdev);

    /* Attach operations (IMPORTANT) */
    netdev->netdev_ops = &my_can_netdev_ops;

    /*
     * register_candev():
     *
     * THIS IS THE BIG STEP
     *
     * Linux creates:
     *
     * 1. ifindex (unique ID)
     * 2. name (can0)
     * 3. sysfs entry (/sys/class/net/can0)
     * 4. Netlink registration (ip link works)
     * 5. SocketCAN registration (cansend works)
     */
    if (register_candev(netdev)) {
        free_candev(netdev);
        return -EINVAL;
    }

    pr_info("CAN device created as %s\n", netdev->name);

    return 0;
}

/* ---------------------------------------------------------
 * MODULE INIT / EXIT
 * ---------------------------------------------------------
 */
static int __init my_init(void)
{
    return my_can_probe();
}

static void __exit my_exit(void)
{
    pr_info("CAN driver removed\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
```





| Object                              | Created by                               | Kernel subsystem / source file | What it means                                    | Why important / purpose                                             |
| ----------------------------------- | ---------------------------------------- | ------------------------------ | ------------------------------------------------ | ------------------------------------------------------------------- |
| `struct net_device`                 | `alloc_candev()` → `alloc_netdev()`      | `net/core/dev.c`               | Core network interface object (`can0`, `eth0`)   | This is the **main identity of the network interface** in Linux     |
| `my_can_priv` (driver private data) | `alloc_candev(size)`                     | `drivers/net/can/dev.c`        | Driver-specific memory inside net_device         | Stores **hardware details (SPI, registers, state)** for your driver |
| `net_device_ops`                    | Driver code                              | Your CAN driver                | Function pointers (`ndo_open`, `ndo_start_xmit`) | Tells Linux **what functions to call in your driver**               |
| `ifindex`                           | `register_netdevice()`                   | `net/core/dev.c`               | Unique numeric ID for interface                  | Lets kernel/userspace **uniquely identify can0**                    |
| `can0 name`                         | `register_candev()` → `dev_alloc_name()` | `net/core/dev.c`               | Human-readable interface name                    | So users can use `can0` instead of numeric ID                       |
| Netlink registration                | `register_netdevice()` + rtnetlink       | `net/core/rtnetlink.c`         | Control channel for network config               | Enables `ip link set can0 up/down`, bitrate changes                 |
| SocketCAN registration              | `register_candev()`                      | `net/can/dev.c`                | CAN socket interface layer                       | Enables **cansend / candump / PF_CAN sockets** for CAN data         |



# 

```
1. Application sends CAN frame
        ↓
2. skb created in kernel
        ↓
3. start_xmit() called
        ↓
4. lock SPI + pick FIFO
        ↓
5. encode CAN frame into SRAM format
        ↓
6. async SPI write (fill FIFO)
        ↓
7. async SPI write (trigger TX)
        ↓
8. skb stored in echo buffer
        ↓
9. SPI completes in background
        ↓
10. interrupt confirms TX done
        ↓
11. echo skb released → user notified
```


```c
int mcp25xxfd_can_setup(struct mcp25xxfd_priv *priv)
{
	struct spi_device *spi = priv->spi;
	struct mcp25xxfd_can_priv *cpriv;
	struct net_device *net;
	struct regulator *transceiver;
	int ret;

	/*
	 * STEP 1: Get the CAN transceiver power regulator.
	 *
	 * Device Tree may define something like:
	 *
	 *     xceiver-supply = <&...>;
	 *
	 * If the regulator provider has not probed yet,
	 * devm_regulator_get_optional() can return -EPROBE_DEFER.
	 *
	 * DEBUG:
	 *   - Check whether the regulator exists in Device Tree.
	 *   - Check the return value using IS_ERR()/PTR_ERR().
	 *   - If probe is repeatedly deferred, investigate the regulator
	 *     provider/Device Tree dependency.
	 */
	transceiver = devm_regulator_get_optional(&spi->dev,
						  "xceiver");

	if (PTR_ERR(transceiver) == -EPROBE_DEFER)
		return -EPROBE_DEFER;

	/*
	 * STEP 2: Allocate a CAN network device.
	 *
	 * alloc_candev() allocates:
	 *   - struct net_device
	 *   - private driver data (struct mcp25xxfd_can_priv)
	 *
	 * TX_ECHO_SKB_MAX specifies the number of TX echo buffers.
	 *
	 * DEBUG:
	 *   - If this returns NULL, memory allocation failed.
	 *   - Return -ENOMEM.
	 */
	net = alloc_candev(sizeof(*cpriv), TX_ECHO_SKB_MAX);
	if (!net)
		return -ENOMEM;

	/*
	 * STEP 3: Get the driver's private data associated with
	 * the network device.
	 *
	 * netdev_priv(net) points to the memory allocated by
	 * alloc_candev(sizeof(*cpriv), ...).
	 *
	 * Create the relationship:
	 *
	 *      net_device
	 *          |
	 *          v
	 *   mcp25xxfd_can_priv
	 *          |
	 *          v
	 *   mcp25xxfd_priv
	 *
	 * This allows the CAN network layer to reach the
	 * SPI/controller-specific driver data.
	 */
	cpriv = netdev_priv(net);

	cpriv->priv = priv;
	priv->cpriv = cpriv;

	/*
	 * STEP 4: Associate the network device with the SPI device.
	 *
	 * SET_NETDEV_DEV() establishes the parent device relationship.
	 *
	 * This is useful for:
	 *   - sysfs hierarchy
	 *   - device ownership/lifetime
	 *   - power management
	 *   - debugging with /sys/class/net/...
	 */
	SET_NETDEV_DEV(net, &spi->dev);

	/*
	 * STEP 5: Tell the networking core which callbacks this
	 * driver implements.
	 *
	 * When userspace performs operations such as:
	 *
	 *     ip link set can0 up
	 *     ip link set can0 down
	 *     ip link ...
	 *
	 * the CAN/network framework eventually uses these callbacks.
	 *
	 * DEBUG:
	 *   If "ip link set can0 up" fails, inspect the functions
	 *   referenced by mcp25xxfd_netdev_ops.
	 */
	net->netdev_ops = &mcp25xxfd_netdev_ops;

	/*
	 * Enable CAN echo support.
	 *
	 * This allows transmitted CAN frames to be echoed back
	 * through the networking stack.
	 */
	net->flags |= IFF_ECHO;

	/*
	 * STEP 6: Save the transceiver regulator in driver-private data.
	 *
	 * Later, typically during open/close or power-management paths,
	 * the driver can enable/disable the transceiver supply.
	 *
	 * DEBUG:
	 *   If CAN interface is registered but hardware doesn't
	 *   transmit/receive, check whether this regulator is actually
	 *   enabled when the interface is brought UP.
	 */
	cpriv->transceiver = transceiver;

	/*
	 * STEP 7: Configure CAN controller capabilities.
	 *
	 * clock.freq:
	 *   Controller oscillator/clock frequency.
	 *
	 * DEBUG:
	 *   Verify priv->clock_freq against the actual MCP25xxFD
	 *   oscillator frequency.
	 *
	 * A wrong clock frequency can result in incorrect CAN bit timing
	 * and communication failures.
	 */
	cpriv->can.clock.freq = priv->clock_freq;

	/*
	 * Nominal/arbitration phase bit-timing constraints.
	 *
	 * These constants tell the CAN framework which bit timing
	 * values are valid for this controller.
	 */
	cpriv->can.bittiming_const =
		&mcp25xxfd_can_nominal_bittiming_const;

	/*
	 * CAN-FD data phase bit-timing constraints.
	 */
	cpriv->can.data_bittiming_const =
		&mcp25xxfd_can_data_bittiming_const;

	/*
	 * Normally CAN drivers can provide bit-timing setup callbacks.
	 *
	 * This driver deliberately does NOT configure bit timing here.
	 *
	 * Reason:
	 * The CAN framework may call bit-timing-related operations
	 * before the interface is opened.
	 *
	 * At that point the MCP25xxFD controller is still in sleep
	 * mode, so accessing/configuring the hardware may not work.
	 *
	 * Therefore hardware configuration is postponed until the
	 * interface is opened.
	 *
	 * INTERVIEW POINT:
	 *   "Why not configure the hardware here?"
	 *
	 * Answer:
	 *   Because the controller is not yet in the appropriate
	 *   operating state; hardware configuration is intentionally
	 *   performed during the open path.
	 */

	/*
	 * STEP 8: Mode-change callback.
	 *
	 * Handles requests such as:
	 *   - CAN loopback
	 *   - CAN listen-only
	 *   - CAN reset
	 *
	 * DEBUG:
	 *   If "ip link set can0 type can loopback on" behaves
	 *   unexpectedly, inspect mcp25xxfd_can_do_set_mode().
	 */
	cpriv->can.do_set_mode =
		mcp25xxfd_can_do_set_mode;

	/*
	 * STEP 9: CAN error counter callback.
	 *
	 * Used to retrieve controller error counters:
	 *   - RX error counter
	 *   - TX error counter
	 *
	 * Useful when debugging:
	 *   - bus-off
	 *   - ACK errors
	 *   - bit errors
	 *   - CAN wiring/termination problems
	 */
	cpriv->can.do_get_berr_counter =
		mcp25xxfd_can_get_berr_counter;

	/*
	 * STEP 10: Advertise supported CAN controller modes.
	 *
	 * CAN_CTRLMODE_FD:
	 *   CAN-FD is supported.
	 *
	 * CAN_CTRLMODE_FD_NON_ISO:
	 *   Non-ISO CAN-FD mode is supported.
	 *
	 * CAN_CTRLMODE_LOOPBACK:
	 *   Internal loopback testing is supported.
	 *
	 * CAN_CTRLMODE_LISTENONLY:
	 *   Listen-only/silent mode is supported.
	 *
	 * CAN_CTRLMODE_BERR_REPORTING:
	 *   CAN bus error reporting is supported.
	 *
	 * CAN_CTRLMODE_ONE_SHOT:
	 *   One-shot transmission is supported.
	 *
	 * INTERVIEW POINT:
	 *   ctrlmode_supported does not enable all these modes.
	 *   It tells the CAN framework which modes the hardware
	 *   and driver are capable of supporting.
	 */
	cpriv->can.ctrlmode_supported =
		CAN_CTRLMODE_FD |
		CAN_CTRLMODE_FD_NON_ISO |
		CAN_CTRLMODE_LOOPBACK |
		CAN_CTRLMODE_LISTENONLY |
		CAN_CTRLMODE_BERR_REPORTING |
		CAN_CTRLMODE_ONE_SHOT;

	/*
	 * STEP 11: Register the CAN network device.
	 *
	 * This is the important point where the network interface
	 * becomes visible to the kernel/userspace.
	 *
	 * After successful registration, you should normally see
	 * something like:
	 *
	 *     can0
	 *
	 * and:
	 *
	 *     ip link show
	 *
	 * should show the CAN interface.
	 *
	 * DEBUG:
	 *   If register_candev() fails:
	 *
	 *     1. Print/log ret.
	 *     2. Check whether the net_device was initialized correctly.
	 *     3. Check CAN timing configuration.
	 *     4. Check duplicate interface/device registration.
	 *     5. Check kernel logs using dmesg.
	 */
	ret = register_candev(net);

	if (ret) {
		dev_err(&spi->dev,
			"Failed to register can device: %d\n", ret);
		goto out;
	}

	/*
	 * Registration succeeded.
	 *
	 * net->name will typically be something like "can0".
	 *
	 * At this point:
	 *
	 *     SPI device
	 *          |
	 *          v
	 *     CAN driver
	 *          |
	 *          v
	 *     net_device (can0)
	 *
	 * is successfully connected.
	 */
	dev_info(&spi->dev, "Mapped to %s!\n", net->name);

	/*
	 * STEP 12: Create debugfs entries.
	 *
	 * This is driver-specific debugging information.
	 *
	 * DEBUG:
	 *   If debugfs is mounted, inspect:
	 *
	 *     /sys/kernel/debug/
	 *
	 * for MCP25xxFD-related entries.
	 *
	 * These can be useful for inspecting driver/controller state.
	 */
	mcp25xxfd_can_debugfs_setup(cpriv);

	/*
	 * Everything succeeded.
	 */
	return 0;

out:
	/*
	 * ERROR CLEANUP PATH.
	 *
	 * register_candev() failed, so the network device must be
	 * released.
	 *
	 * Since alloc_candev() allocated the net_device, use the
	 * corresponding free_candev().
	 */
	free_candev(net);

	/*
	 * Prevent priv->cpriv from pointing to freed memory.
	 *
	 * This is important to avoid a dangling pointer/use-after-free.
	 */
	priv->cpriv = NULL;

	return ret;
}

```

## Can error handling

```
            CAN Controller
                   |
                   | Error
                   ↓
                 IRQ
                   |
                   ↓
          mcp25xxfd_can_int()
                   |
                   ↓
      Read INT/TREC registers
                   |
                   ↓
   mcp25xxfd_can_int_handle_status()
                   |
                   ↓
   mcp25xxfd_can_int_error_counters()
                   |
      +------------+-------------+
      |            |             |
      ↓            ↓             ↓
  WARNING       PASSIVE       BUS OFF
      |            |             |
      +------------+-------------+
                   |
                   ↓
   mcp25xxfd_can_int_error_handling()
                   |
                   ↓
         Update CAN state
                   |
                   ↓
         Generate error SKB
                   |
                   ↓
            Linux CAN stack

```

- In the `MCP25xxFD` driver, CAN errors are detected through the controller's interrupt and status registers. 
- The interrupt handler reads the status over `SPI` and passes it to the status-processing function. 
- The `mcp25xxfd_can_int_error_counters()` function checks the `TREC` register. 
- Depending on the status bits, it identifies error warning, error passive, or bus-off. 
- For bus-off, it checks `MCP25XXFD_CAN_TREC_TXBO`, sets `CAN_STATE_BUS_OFF`, and adds `CAN_ERR_BUSOFF` to the error frame. 
- Then `mcp25xxfd_can_int_error_handling`() updates the actual CAN state, sends the error SKB to the Linux networking stack, updates bus-off statistics, and calls can_bus_off() when restart isn't configured.
-  The actual automatic restart and TX timeout paths are handled separately in the driver/framework.
  

### Error firs t serve system error

1. Bus Bandwidth Error — RX
- A message comes into the RX buffer.

- The buffer is already full with the previous message.

- The new message has no space to enter.

So, the new message is ignored/discarded.

👉 Simple: “RX buffer is full → new message is lost.”

2. TX MAB Underflow — TX
- The system wants to send a message.

- But the TX buffer does not have valid/complete data (e.g., ECC error).

- So, the message cannot be transmitted safely.

- The system goes to Restricted or Listen Only mode.

👉 Simple: “TX data is invalid/missing → transmission is stopped/restricted.”
