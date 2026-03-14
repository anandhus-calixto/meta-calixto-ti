require u-boot-ti.inc

include ${@ 'recipes-bsp/u-boot/ti-extras.inc' if d.getVar('TI_EXTRAS') else ''}

PR = "r0"

BRANCH = "main"

SRCREV_uboot = "2fe50f80a8317f86d7fb4da9340d02cb06a418a7"
