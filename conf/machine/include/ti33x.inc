require conf/machine/include/ti-soc.inc
SOC_FAMILY:append = ":ti33x"

DEFAULTTUNE ?= "armv7athf-neon"
require conf/machine/include/arm/armv7a/tune-cortexa8.inc

require conf/machine/include/ti-bsp.inc

# Graphics providers and variables
require conf/machine/include/mesa-pvr.inc
PREFERRED_PROVIDER_virtual/gpudriver ?= "${BSP_SGX_DRIVER_PROVIDER}"

KERNEL_IMAGETYPE = "zImage"

#KERNEL_DEVICETREE_PREFIX = " \
#    am335x \
#    ti/omap/am335x \
#"

#KERNEL_DEVICETREE = " \
#    ti/omap/am335x-calixto-nxt512.dtb \
#"

UBOOT_ARCH = "arm"
#UBOOT_MACHINE = "am335x_evm_config"

UBOOT_ENTRYPOINT = "0x80008000"
UBOOT_LOADADDRESS = "0x80008000"


SPL_BINARY = "MLO"
UBOOT_SUFFIX = "img"

# Use the expected value of the ubifs filesystem's volume name in the kernel
# and u-boot.
UBI_VOLNAME = "rootfs"

EXTRA_IMAGEDEPENDS += "virtual/bootloader"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "kernel-image-zimage"

MACHINE_ESSENTIAL_EXTRA_RRECOMMENDS += "amx3-cm3 prueth-fw pruhsr-fw pruprp-fw"

# List common SoC features, may need to add touchscreen for specific machines
MACHINE_FEATURES = "apm usbgadget usbhost vfat ext2 alsa"

IMAGE_FSTYPES += "tar.xz wic.xz wic.bmap"
WKS_FILE ?= "sdimage-2part.wks"
IMAGE_BOOT_FILES ?= "${SPL_BINARY} u-boot.${UBOOT_SUFFIX}"
do_image_wic[depends] += "virtual/bootloader:do_deploy"

