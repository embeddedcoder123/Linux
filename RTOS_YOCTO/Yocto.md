# Yocto Configuration for I2C, SPI, GCC, and CMake on TI Sitara (AM335x)

This guide explains step-by-step how to configure Yocto for I2C, SPI, GCC, and CMake on a TI Sitara AM335x platform (e.g., BeagleBone Black).

---

## Prerequisites

- Linux PC for Yocto build
- Target board: TI Sitara AM335x (e.g., BeagleBone Black)
- Basic knowledge of Yocto build system

---

## 1. Setup Yocto Environment and Layers

### 1.1 Clone poky and meta-ti layers

```bash
mkdir ~/yocto
cd ~/yocto

git clone -b dunfell git://git.yoctoproject.org/poky.git
git clone -b dunfell https://github.com/RobertCNelson/meta-ti.git
```

### 1.2 Initialize build directory

```bash
cd poky
source oe-init-build-env build
```

- his command sources the environment setup script (oe-init-build-env) and creates/enters a build directory (named build here).
- After sourcing, your shell environment is set up for BitBake and Yocto development.
- It also sets BUILDDIR, adjusts PATH, and puts you in the build directory.

### 1.3 Add meta-ti to bblayers.conf

Edit build/conf/bblayers.conf:

```conf
BBLAYERS ?= " \
  /home/youruser/yocto/poky/meta \
  /home/youruser/yocto/poky/meta-poky \
  /home/youruser/yocto/poky/meta-yocto-bsp \
  /home/youruser/yocto/meta-ti \
"
```

🔑 What's Happening Here?

- BBLAYERS lists the directories where Yocto will look for layer metadata (e.g., recipes, classes).

- You add /home/youruser/yocto/meta-ti so Yocto includes all the TI-specific recipes and configs in your build.

Make sure that:

- The meta-ti directory actually exists at that location.

- You've cloned it from the correct repository (usually from https://git.yoctoproject.org/meta-ti/
) and checked out a compatible version for your Yocto release (e.g., kirkstone, mickledore, etc.).

### 1.4 Set MACHINE in local.conf

Edit build/conf/local.conf:
```conf
MACHINE = "am335x-boneblack"
```

MACHINE is a core Yocto variable that specifies the target hardware platform (board or SoC).
It defines:

- Kernel configuration
- Bootloader settings
- Device tree
- Root filesystem layout
- Additional hardware-specific packages
  
local.conf (with kernel, bootloader, device tree, GPU/PRU, and image settings explained)

```bash
# -----------------------------------------------------------------------------
# MACHINE SELECTION
# -----------------------------------------------------------------------------
MACHINE = "am335x-boneblack"
# This selects the target hardware platform.
# Yocto loads machine config from:
#   meta-ti/conf/machine/am335x-boneblack.conf
#
# This file sets:
# - Kernel recipe (e.g., linux-ti-staging)
# - U-Boot bootloader recipe (e.g., u-boot-ti-staging)
# - Device tree files (e.g., am335x-boneblack.dtb)
# - Optional features (GPU, PRU support)

# -----------------------------------------------------------------------------
# KERNEL SETTINGS (influenced by MACHINE)
# -----------------------------------------------------------------------------
# You typically don't override kernel recipe here, but you can:

# PREFERRED_PROVIDER_virtual/kernel = "linux-ti-staging"
# PREFERRED_VERSION_linux-ti-staging = "5.10%"
# These control which kernel provider/version to use.

# If MACHINE sets it already, you usually don't need to repeat this here.

# -----------------------------------------------------------------------------
# BOOTLOADER SETTINGS (influenced by MACHINE)
# -----------------------------------------------------------------------------
# Like kernel, bootloader is selected via MACHINE, but can be customized:
# PREFERRED_PROVIDER_u-boot = "u-boot-ti-staging"
# PREFERRED_VERSION_u-boot-ti-staging = "2021.01%"
# This ensures correct bootloader for TI boards.

# -----------------------------------------------------------------------------
# DEVICE TREE SELECTION (in kernel recipe or machine file)
# -----------------------------------------------------------------------------
# Device tree is chosen automatically based on MACHINE.
# For am335x-boneblack, you get:
#   arch/arm/boot/dts/am335x-boneblack.dtb
# You usually don’t need to set this manually unless customizing.

# -----------------------------------------------------------------------------
# GPU / PRU / FEATURE FLAGS (Optional)
# -----------------------------------------------------------------------------
# The MACHINE file may include support for optional hardware like:
# - SGX GPU
# - PRU (Programmable Real-time Unit)
#
# You can enable additional support through image/package customization:

# Enable PRU support (if using PRU on AM335x):
IMAGE_INSTALL_append = " pru-software-support ti-cgt-pru"

# Enable SGX GPU userspace libraries (if using PowerVR GPU):
# IMAGE_INSTALL_append = " ti-sgx-ddk-km ti-sgx-ddk-um"

# These packages are usually provided by meta-ti and depend on SoC support.

# -----------------------------------------------------------------------------
# IMAGE FEATURES (adds tools and services to your rootfs)
# -----------------------------------------------------------------------------
EXTRA_IMAGE_FEATURES ?= "debug-tweaks ssh-server-dropbear"
# debug-tweaks: Enables root SSH and disables root password (for dev)
# ssh-server-dropbear: Lightweight SSH server for remote login

# -----------------------------------------------------------------------------
# ADDITIONAL IMAGE CONTENT
# -----------------------------------------------------------------------------
IMAGE_INSTALL_append = " nano htop kernel-modules"
# Adds nano editor, htop system monitor, and all kernel modules to the image

# -----------------------------------------------------------------------------
# IMAGE FORMAT (output file types)
# -----------------------------------------------------------------------------
IMAGE_FSTYPES = "ext4 tar.gz"
# ext4: Raw ext4 partition image
# tar.gz: Compressed root filesystem archive

# -----------------------------------------------------------------------------
# PACKAGE MANAGEMENT FORMAT
# -----------------------------------------------------------------------------
PACKAGE_CLASSES ?= "package_ipk"
# Use IPK packages (others include rpm, deb)

# -----------------------------------------------------------------------------
# CACHE DIRECTORIES
# -----------------------------------------------------------------------------
DL_DIR ?= "${TOPDIR}/downloads"
SSTATE_DIR ?= "${TOPDIR}/sstate-cache"
TMPDIR ?= "${TOPDIR}/tmp"

# -----------------------------------------------------------------------------
# PARALLEL BUILD SETTINGS
# -----------------------------------------------------------------------------
BB_NUMBER_THREADS ?= "4"
PARALLEL_MAKE ?= "-j4"
# Adjust depending on number of CPU cores

# -----------------------------------------------------------------------------
# BUILD OUTPUT HISTORY (Optional, useful for debugging)
# -----------------------------------------------------------------------------
# INHERIT += "buildhistory"
# BUILDHISTORY_COMMIT = "1"

# -----------------------------------------------------------------------------
# LOCALIZATION / TIMEZONE (Optional)
# -----------------------------------------------------------------------------
# IMAGE_LINGUAS = "en-us"
# TIMEZONE = "UTC"

# -----------------------------------------------------------------------------
# CUSTOM IMAGE (Optional: set default image to build)
# -----------------------------------------------------------------------------
# You can define a custom image with specific packages and settings
# IMAGE_NAME = "my-custom-image"
# Or use predefined:
# bitbake core-image-minimal
# bitbake tisdk-base-image (from meta-ti)
```

## 2. Enable I2C and SPI Kernel Drivers

### 2.1 Create kernel config fragment

Create the file `meta-my-layer/recipes-kernel/linux/linux-ti-i2c-spi.cfg` with the following content:

```conf
CONFIG_I2C=y
CONFIG_I2C_CHARDEV=y       # Enables /dev/i2c-* device files
CONFIG_SPI=y
CONFIG_SPI_TI_SCI=y        # TI Sitara SPI controller driver
CONFIG_SPI_SPIDEV=y        # spidev user-space driver
CONFIG_SPI_DEVICES=y
```

### 2.2 Add your layer to bblayers.conf

Add your custom layer meta-my-layer to bblayers.conf:

```conf
BBLAYERS += " /home/youruser/yocto/meta-my-layer "
```

### 2.3 Append kernel fragment in local.conf

Add this line to local.conf:

```conf
KERNEL_CONFIG_FRAGMENTS += "linux-ti-i2c-spi.cfg"
```

## 3. Modify Device Tree for I2C and SPI

### 3.1 Locate device tree source

Path example:

```swift
meta-ti/recipes-kernel/linux/linux-ti-staging/arch/arm/boot/dts/am335x-boneblack.dts
```
### 3.2 Edit device tree source

Enable I2C1:

```dts
&i2c1 {
    status = "okay";
    clock-frequency = <100000>;
};
```

Enable SPI0 with spidev node:

```dts
&spi0 {
    status = "okay";

    spidev@0 {
        compatible = "spidev";
        reg = <0>;
        spi-max-frequency = <24000000>;
    };
};
```

### 3.3 (Optional) Pin multiplexing

```dts
&i2c1_pins {
    pinctrl-single,pins = <
        0x98 0x37  /* i2c1_sda */
        0x9c 0x37  /* i2c1_scl */
    >;
};

&spi0_pins {
    pinctrl-single,pins = <
        0x150 0x30  /* spi0_sclk */
        0x154 0x30  /* spi0_d0 (MISO) */
        0x158 0x30  /* spi0_d1 (MOSI) */
        0x15c 0x30  /* spi0_cs0 */
    >;
};
```

Ensure pinctrl groups are linked to the device nodes.

## 4. Add GCC and CMake to the Image

Edit local.conf to install GCC and CMake:

```conf
IMAGE_INSTALL_append = " gcc cmake"
```

(Optional: add other tools)

```conf
IMAGE_INSTALL_append = " gcc cmake make gdb"
```

## 5. Build the Image

Run the build command:

```conf

bitbake core-image-full-cmdline
```

## 6. Flash and Test

### 6.1 Flash the built image on your board

Use your board’s instructions to flash the image to SD card or eMMC.

### 6.2 Verify I2C and SPI devices

```bash
ls /dev/i2c-*
ls /dev/spidev*
```

### 6.3 Verify GCC and CMake

```bash
ls /dev/i2c-*
ls /dev/spidev*
```

## Bonus: Simple I2C Test Program in C

```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>

int main() {
    const char *filename = "/dev/i2c-1";
    int file, addr = 0x50; // Example device address

    if ((file = open(filename, O_RDWR)) < 0) {
        perror("Open I2C device failed");
        return 1;
    }

    if (ioctl(file, I2C_SLAVE, addr) < 0) {
        perror("Failed to acquire bus access or talk to slave");
        close(file);
        return 1;
    }

    char reg = 0x00;
    if (write(file, &reg, 1) != 1) {
        perror("Failed to write register");
        close(file);
        return 1;
    }

    char data;
    if (read(file, &data, 1) != 1) {
        perror("Failed to read data");
        close(file);
        return 1;
    }

    printf("Data read from device: 0x%02x\n", data);

    close(file);
    return 0;
}
```

Compile on the target:

```bash
gcc -o i2c_test i2c_test.c
./i2c_test
```

## Summary Table

| Step | File / Command                                                          | Purpose                                             |
| ---- | ----------------------------------------------------------------------- | --------------------------------------------------- |
| 1    | `conf/bblayers.conf`, `conf/local.conf`                                 | Setup layers and MACHINE                            |
| 2    | `meta-my-layer/recipes-kernel/linux/linux-ti-i2c-spi.cfg`, `local.conf` | Enable kernel drivers for I2C and SPI               |
| 3    | `am335x-boneblack.dts` (or overlay)                                     | Enable device tree nodes for I2C and SPI            |
| 4    | `local.conf`                                                            | Add GCC and CMake to image                          |
| 5    | `bitbake core-image-full-cmdline`                                       | Build the image                                     |
| 6    | On target shell                                                         | Verify `/dev/i2c-*`, `/dev/spidev*`, `gcc`, `cmake` |
