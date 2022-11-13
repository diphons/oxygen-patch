// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/*
 * OxygenOS DT2W interfaces
 *
 * Copyright (C) 2022, Rudi Setiyawan <diphons@gmail.com>
 */

#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/seq_file.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("diphons");
MODULE_DESCRIPTION("oxygen os touch gesture");
MODULE_VERSION("0.0.5");

#define double_tap "touchpanel/double_tap_enable"
#define genable "touchpanel/gesture_enable"
#define tp_dt "touchpanel/double_tap"
#define tp_g "touchpanel/gesture_enable"
#define tpg "tp_gesture"

static int __init d8g_touch_oos_init(void) {
    static struct proc_dir_entry *tp_oos;
	int ret = 0;

	printk(KERN_INFO "oxygen os touch gesture initial");

#ifdef CONFIG_BOARD_XIAOMI_SM8250
	tp_oos = proc_symlink(double_tap, NULL, tp_dt);
	if (!tp_oos)
		ret = -ENOMEM;
	tp_oos = proc_symlink(genable, NULL, tp_dt);
	if (!tp_oos)
		ret = -ENOMEM;
#else
	tp_oos = proc_symlink(double_tap, NULL, tp_g);
	if (!tp_oos)
		ret = -ENOMEM;
#endif
	tp_oos = proc_symlink(tpg, NULL, tp_g);
	if (!tp_oos) {
		ret = -ENOMEM;
		printk(KERN_INFO "oxygen os touch gesture initial failed");
	} else
		printk(KERN_INFO "oxygen os touch gesture initialized");

	return ret;
}

static void __exit d8g_touch_oos_exit(void) {
	printk(KERN_INFO "oxygen os touch gesture exit");
}

module_init(d8g_touch_oos_init);
module_exit(d8g_touch_oos_exit);
