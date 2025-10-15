#include <linux/module.h>
#include <linux/init.h>


static struct gpio_desc *led, *button;

#define IO_LED 21
#define IO_BUTTON 20

#define IO_OFFSET 

// Callback functions for when the module is loaded in or out of the kernel
// Static maked functions available locally
static int __init my_init(void) {

	int status;

	led = gpio_to_desc(IO_LED + IO_OFFSET);
	if(!led) {
	
		printk("gpioctrl - Error getting pin 21\n");
		return -ENODEV;

	}

	button = gpio_to_desc(IO_BUTTON + IO_OFFSET);
	if(!button) {
		printk("gpioctrl - Error getting pin 20\n");
		return -ENODEV;
	
	}

	status = gpio_direction_output(led, 0);
	if(status) {
		printk("gpioctrl - Error setting pin 20 to output\n");
		return status;
	}

	status = gpio_direction_input(button);
	if(status) {
		printk("gpioctrl - Error setting pin 21 to input\n");
		return status;

	}

	gpio_set_value(led, 1);

	printk("gpioctrl - Button is %spressed\n", gpiod_get_value(button) ? "" : "not ");


	return 0;
}

//Removing module from kernel
static void __exit my_exit(void) {
  
	gpio_set_value(led, 0);
	printk("gpioctrl - Turning light off, Good bye!\n");
}

// Have to tell the module when the module is loaded or removed from kernel

module_init(my_init);
module_exit(my_exit);

//Have to specify the license of this module to make it executable
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Björn Olsson");
MODULE_DESCRIPTION("Trying out basic GPIO input, output");
