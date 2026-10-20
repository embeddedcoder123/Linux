```
+-------------------+
|   REST Client     |
| (curl / web UI)   |
+---------+---------+
          |
          | HTTP (REST)
          v
+-------------------+
|   lan-manager     |
|  (REST + Thrift)  |
+----+----+----+----+
     |    |    |
     |    |    |
 Thrift TCP calls
     |    |    |
     v    v    v
+---------+  +-------------+  +------------------+
| power-  |  | peripheral |  | system-monitor   |
| manager |  | service    |  | service          |
+---------+  +-------------+  +------------------+

```

- **lan-manager** → REST architecture + Thrift client

- **power-manager** → CAN communication with external node, power calculation

- **peripheral** → Initialize I2C, GPIO, CAN IC

- **system-monitor** → Health + supervision

## 1. Final System Overview (Understand Before Coding)

```
Yocto Linux (systemd)
│
├── peripheral.service
│    ├── Init GPIO
│    ├── Init I2C
│    └── Init CAN controller (SPI/I2C)
│
├── power-manager.service
│    ├── Uses CAN (socketCAN)
│    ├── Talks to external power node
│    ├── Calculates voltage, current, power
│    └── Thrift TCP server
│
├── system-monitor.service
│    ├── CPU, RAM, temp
│    ├── Service watchdog
│    └── Thrift TCP server
│
└── lan-manager.service
     ├── REST server (HTTP)
     ├── Thrift client
     └── External control interface
```

## 2. Host PC Setup (MANDATORY)
Yocto must be built on a Linux host (Ubuntu 20.04 / 22.04).
```bash
sudo apt update
sudo apt install -y \
  git gawk wget diffstat unzip texinfo gcc \
  build-essential chrpath socat cpio \
  python3 python3-pip python3-pexpect \
  xz-utils debianutils iputils-ping \
  libssl-dev libncurses5-dev
```

## 3. Yocto Source Setup (FROM SCRATCH)

### 3.1 Create workspace

```bash
mkdir yocto-rpi
cd yocto-rpi
```
### 3.2 Clone layers
```bash
git clone -b kirkstone git://git.yoctoproject.org/poky
git clone -b kirkstone https://github.com/agherzan/meta-raspberrypi
git clone -b kirkstone https://github.com/openembedded/meta-openembedded
```
> `kirkstone` = LTS (best for products)
### 3.3 Initialized build
```bash
source poky/oe-init-build-env build
```
### 3.4 Configured layes
Edit `build/conf/bblayers.conf`:

```bash
BBLAYERS += " \
  ${TOPDIR}/../meta-raspberrypi \
  ${TOPDIR}/../meta-openembedded/meta-oe \
  ${TOPDIR}/../meta-openembedded/meta-networking \
  ${TOPDIR}/../meta-openembedded/meta-python \
"
```

### 3.5 Configure machine + systemd
Edit `build/conf/local.conf:`

```conft
MACHINE = "raspberrypi4"

DISTRO_FEATURES:append = " systemd"
VIRTUAL-RUNTIME_init_manager = "systemd"

ENABLE_UART = "1"

IMAGE_INSTALL:append = " \
  can-utils \
  iproute2 \
  thrift \
  libthrift \
  boost \
  libmicrohttpd \
"
```

## 4. Kernel & Device Tree (CRITICAL FOR CAN/I2C/GPIO)

### 4.1 Enable I2C & SPI

In `local.conf:`

```conf
ENABLE_I2C = "1"
ENABLE_SPI = "1"
```

### 4.2 Enable CAN kernel support

Create a `.bbappend` for kernel or use config fragment:
```c
CONFIG_CAN=y
CONFIG_CAN_RAW=y
CONFIG_CAN_DEV=y
CONFIG_CAN_MCP251X=y

```

This is mandatory if your **CAN IC is MCP2515**.

### 4.3 Device Tree Overlay (CAN IC)

Example overlay:

```dts
dtoverlay=mcp2515-can0,oscillator=16000000,interrupt=25
```

this `.dts` file need to compile and generate `.dtbo` file
```bash
dtc -@ -I dts -O dtb -o overlays/mcp2515-can0.dtbo overlays/mcp2515-can0.dts
```
- `-@` → enable `__overrides__` support

- `-I dts` → input format is Device Tree Source

- `-O dtb` → output binary format (Device Tree Blob)

- `-o` ... → output file

----
Add to `/boot/config.txt` via Yocto:
```conf
RPI_KERNEL_DEVICETREE_OVERLAYS += " overlays/mcp2515-can0.dtbo"
```

## 5. Create Your Application Layer
```bash
bitbake-layers create-layer meta-myproduct
bitbake-layers add-layer meta-myproduct
```

Structure:

```markdown
meta-myproduct/
└── recipes-services/
    ├── peripheral/
    ├── power-manager/
    ├── system-monitor/
    └── lan-manager/

```

## 6. Thrift Interface Design (COMMON)
create

```bash
meta-myproduct/recipes-services/thrift/
└── files/
    ├── power.thrift
    ├── peripheral.thrift
    └── system.thrift
```

power.thrift
```thrift
namespace cpp power

service PowerManager {
  double getVoltage()
  double getCurrent()
  double getPower()
}
```
## 7. Full Folder & File Structure
```
meta-myproduct/                   <-- Custom Yocto layer
└── recipes-services/             <-- All your service recipes
    ├── peripheral/              <-- Peripheral service
    │   ├── peripheral.bb        <-- Yocto recipe for this service
    │   ├── main.cpp             <-- C++ code to init GPIO/I2C/CAN IC
    │   └── peripheral.service   <-- systemd unit to start service at boot
    │
    ├── power-manager/           <-- Power Manager service
    │   ├── power-manager.bb     <-- Yocto recipe
    │   ├── main.cpp             <-- C++ code: CAN read, power calc, Thrift server
    │   ├── power.thrift         <-- Thrift IDL for this service
    │   └── power.service        <-- systemd unit
    │
    ├── system-monitor/          <-- System Monitor service
    │   ├── system-monitor.bb    <-- Yocto recipe
    │   ├── main.cpp             <-- C++ code: CPU, RAM, temp, watchdog
    │   ├── system.thrift        <-- Thrift IDL
    │   └── system-monitor.service <-- systemd unit
    │
    └── lan-manager/             <-- LAN Manager service
        ├── lan-manager.bb       <-- Yocto recipe
        ├── main.cpp             <-- REST server + Thrift client
        ├── lan.thrift           <-- Optional Thrift client IDL
        └── lan-manager.service  <-- systemd unit

```
### 7.1 Why Each File Exists

| File                                                  | Purpose                                                                                               |
| ----------------------------------------------------- | ----------------------------------------------------------------------------------------------------- |
| `*.bb`                                                | Yocto recipe: tells BitBake **how to build, compile, and install** the service into the image         |
| `main.cpp`                                            | Core **C++ source code** of the service (hardware init, CAN logic, REST server, Thrift server/client) |
| `*.service`                                           | **systemd unit file**: defines **how to start the service at boot**, dependencies, restart behavior   |
| `*.thrift`                                            | Thrift **interface definition** (IDL) for inter-service communication                                 |
| Layer folders (`meta-myproduct/recipes-services/...`) | **Yocto convention**: each service recipe must live in its own folder for BitBake to find sources     |

## 8. Peripheral Service (FIRST SERVICE TO START)

Responsibility

- ✔ Initialize GPIO
- ✔ Initialize I2C
- ✔ Initialize CAN IC
- ✔ No REST
- ✔ No CAN data processing

### 7.1 peripheral main.cpp
```cpp
#include <fcntl.h>
#include <unistd.h>
#include <iostream>

int main() {
  system("modprobe i2c-dev");
  system("modprobe can");
  system("modprobe can_raw");
  system("ip link set can0 up type can bitrate 500000");

  std::cout << "Peripheral initialized\n";
  while (1) sleep(60);
}
```
### 8.2 systemd service
```ini
[Unit]
Description=Peripheral Init Service
Before=power-manager.service

[Service]
ExecStart=/usr/bin/peripheral
Restart=always

[Install]
WantedBy=multi-user.target
```

### 8.3 peripheral.bb
```bitbake
SUMMARY = "Peripheral Initialization Service"        # Short description of the recipe, shown in BitBake outputs
LICENSE = "MIT"                                      # License of the software; required by Yocto

SRC_URI = "file://main.cpp file://peripheral.service" # Source files for the recipe:
                                                     # - main.cpp: C++ code to init GPIO/I2C/CAN
                                                     # - peripheral.service: systemd unit file

S = "${WORKDIR}"                                     # Source directory for compilation; ${WORKDIR} is BitBake’s temporary build folder

inherit systemd                                      # Enable systemd support:
                                                     # - allows installing systemd service unit
                                                     # - enables service at boot
                                                     # - provides ${systemd_system_unitdir} variable

SYSTEMD_SERVICE:${PN} = "peripheral.service"        # Specify which systemd service belongs to this package
                                                     # ${PN} = recipe/package name ('peripheral')

do_compile() {                                       # Compilation task
  ${CXX} main.cpp -o peripheral                     # Use Yocto-provided C++ compiler to build 'main.cpp' into executable 'peripheral'
}

do_install() {                                      # Installation task
  install -d ${D}/usr/bin                            # Create /usr/bin in image staging area (${D} = root of target image)
  install -m 0755 peripheral ${D}/usr/bin           # Copy compiled binary to /usr/bin with executable permissions (rwx for owner, rx for others)
  install -d ${D}${systemd_system_unitdir}          # Create systemd directory in image (${systemd_system_unitdir} usually /lib/systemd/system)
  install -m 0644 peripheral.service ${D}${systemd_system_unitdir} # Copy systemd service with readable permissions
}

```


## 9 Copy Binary to Pi via SCP

Best for quick testing


Steps
### 1️⃣ Build only the recipe
```bash
bitbake peripheral
```

### 2️⃣ Find the binary

```bash
tmp/work/raspberrypi4-poky-linux/peripheral/*/image/usr/bin/peripheral
```

### 3️⃣ Copy to Raspberry Pi

```
scp peripheral root@<pi-ip>:/usr/bin/
```

### 4️⃣ Run on Pi

```bash
ssh root@<pi-ip>
chmod +x /usr/bin/peripheral
./peripheral
```




----

```bash
###############################################################################
# YOCTO PROJECT CONFIGURATION – FROM SCRATCH TO EXECUTION
# Target: Raspberry Pi
# Language: C++
# Init system: systemd
# Project type: Embedded services (Peripheral, Power, LAN, Monitor)
###############################################################################

###############################################################################
# 1. TARGET MACHINE SELECTION
###############################################################################

# MACHINE tells Yocto which board we are building for.
# This selects:
#   - CPU architecture (ARM)
#   - Kernel configuration
#   - Bootloader
#   - Device tree
MACHINE = "raspberrypi4"

###############################################################################
# 2. BUILD OUTPUT DIRECTORY
###############################################################################

# TMPDIR is where Yocto puts all temporary build output.
# This includes compiled binaries, rootfs staging, packages, images.
# You normally do NOT change this.
TMPDIR = "${TOPDIR}/tmp"

###############################################################################
# 3. PACKAGE MANAGEMENT SYSTEM
###############################################################################

# Select package format for runtime installation and updates.
# ipk is lightweight and commonly used in embedded systems.
PACKAGE_CLASSES = "package_ipk"

###############################################################################
# 4. INIT SYSTEM SELECTION
###############################################################################

# Enable systemd as the init system.
# systemd is required for managing services (.service files).
DISTRO_FEATURES:append = " systemd"

# Tell Yocto to use systemd instead of sysvinit.
VIRTUAL-RUNTIME_init_manager = "systemd"

###############################################################################
# 5. IMAGE FEATURES
###############################################################################

# Enable SSH so we can log into the Raspberry Pi after boot.
IMAGE_FEATURES += "ssh-server-dropbear"

# Enable package management on target (opkg install/remove).
IMAGE_FEATURES += "package-management"

###############################################################################
# 6. HARDWARE INTERFACES (EMBEDDED SYSTEM REQUIREMENTS)
###############################################################################

# Enable UART for serial debugging.
ENABLE_UART = "1"

# Enable I2C support in kernel and userspace.
ENABLE_I2C = "1"

# Enable SPI support (used for CAN IC like MCP2515).
ENABLE_SPI = "1"

###############################################################################
# 7. KERNEL FEATURES (CAN SUPPORT)
###############################################################################

# Enable CAN bus support in Linux kernel.
# Required for power-manager communication with external CAN node.
KERNEL_FEATURES:append = " can"

###############################################################################
# 8. SYSTEM LIBRARIES TO INCLUDE IN IMAGE
###############################################################################

# These packages are installed into the root filesystem.
# They are available at runtime on Raspberry Pi.

IMAGE_INSTALL:append = " \
  can-utils \            # Tools like candump, cansend
  iproute2 \             # Required to bring up CAN interface
  thrift \               # Apache Thrift runtime
  libthrift \            # Thrift C++ library
  boost \                # C++ helper libraries
  libmicrohttpd \        # REST server for lan-manager
"

###############################################################################
# 9. YOUR APPLICATIONS (SERVICES)
###############################################################################

# These are YOUR Yocto recipes (.bb files).
# Yocto will:
#   - Compile them
#   - Install binaries
#   - Install systemd services
#   - Enable them at boot

IMAGE_INSTALL:append = " \
  peripheral \           # Initializes GPIO, I2C, CAN IC
  power-manager \        # Reads CAN, calculates power
  system-monitor \       # Monitors CPU, RAM, services
  lan-manager \          # REST API + Thrift client
"

###############################################################################
# 10. SYSTEMD BOOT FLOW (RUNTIME LOGIC)
###############################################################################

# Boot sequence (conceptual):
#
#   Bootloader
#     ↓
#   Linux Kernel
#     ↓
#   systemd
#     ↓
#   peripheral.service        (hardware init)
#     ↓
#   power-manager.service     (CAN + power calc)
#     ↓
#   system-monitor.service    (health monitoring)
#     ↓
#   lan-manager.service       (REST API access)
#

###############################################################################
# 11. HOW YOCTO BUILDS EVERYTHING (INTERNAL FLOW)
###############################################################################

# 1. BitBake reads this configuration
# 2. BitBake parses all layers:
#      - poky
#      - meta-raspberrypi
#      - meta-openembedded
#      - meta-yourproject
# 3. BitBake processes each recipe (.bb):
#      - SRC_URI → fetch source files
#      - DEPENDS → build dependencies
#      - do_compile → cross-compile C++ code
#      - do_install → install into rootfs staging
# 4. Root filesystem is assembled
# 5. Bootable image (.wic) is created

###############################################################################
# 12. FINAL OUTPUT
###############################################################################

# Yocto generates:
#   - Kernel image
#   - Root filesystem
#   - Bootloader files
#   - Bootable SD card image (.wic)
#
# This image is flashed to Raspberry Pi SD card.
###############################################################################
```