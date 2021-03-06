SOC_FAMILY = "AMLS905"

require conf/distro/multilib.inc

# Amlogic defaults
require conf/machine/include/wetek-amlogic.inc
require conf/machine/include/arm/arch-armv8a.inc
require conf/machine/include/soc-family.inc

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
    wetek-dvb-modules-wetekplay2 \
    wetek-dhd-wetekplay2 \
    wetek-mali-wetekplay2 \
    wetek-gst-amlavsink \
    wetek-gst-app \
    wetek-gst-amlavout \
    gst-fluendo-mpegdemux \
    "

MACHINE_ESSENTIAL_EXTRA_RRECOMMENDS += "\
    kernel-module-cdfs \
    kernel-module-sysfillrect \
    kernel-module-syscopyarea \
    kernel-module-mceusb \
    kernel-module-rc-core \
    kernel-module-CH341 \
    kernel-module-cfg80211 \
    kernel-module-rfcomm \
    kernel-module-hidp \
    kernel-module-bluetooth \
    kernel-module-6lowpan-iphc \
    kernel-module-libcrc32c \
    kernel-module-xfs \
    wetek-amlsetfb \
    amremote \
    "

KERNEL_MODULE_AUTOLOAD += "\
    e2-procfs \
    sysfillrect \
    syscopyarea \
    mceusb \
    rc-core \
    mali \
    dhd \
    CH341 \
    rfcomm \
    hidp \
    cfg80211 \
    bluetooth \
    6lowpan-iphc \
    libcrc32c \
    xfs \
"

module_conf_dhd = "options dhd firmware_path=/lib/firmware/brcm/ nvram_path=/lib/firmware/brcm/"

KERNEL_MODULE_PROBECONF += "\
    dhd \
"

PREFERRED_PROVIDER_virtual/kernel = "linux-wetek2"
PREFERRED_VERSION_linux-wetek2 = "3.14.29"

KERNEL_IMAGETYPE = "Image"

MACHINE_FEATURES += "multilib"
