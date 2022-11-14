# oxygen-patch

Add patch kernel to support port rom Oxygen Os

# Supported kernel
Xiaomi - SDM845
Xiaomi - SM8150
Xiaomi - SM8250

# Required
Kernel SM8150 - SM8250 req implement double tap node
Kernel SDM845 req implement DT2W

# Working module
This module help your kernel to symlink
/proc/touchpanel/double_tap_enable   (OxygenOs 12)
/proc/touchpanel/gesture_enable   (OxygenOs 11)

to use double tap to weakup from port rom Oxygen OS
