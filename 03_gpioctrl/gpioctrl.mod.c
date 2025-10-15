#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x991fb4bf, "gpiod_set_value" },
	{ 0x92997ed8, "_printk" },
	{ 0x1bbb3529, "gpio_to_desc" },
	{ 0xbb9a6196, "gpiod_direction_output" },
	{ 0x2cc6ea32, "gpiod_direction_input" },
	{ 0x30708b69, "gpiod_get_value" },
	{ 0x474e54d2, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "A3EE9C734E63EA2D2D7DEEE");
