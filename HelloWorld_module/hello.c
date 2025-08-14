#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

// This is is a macro for the sdk of the Linux modules
// Licenses my models, if GPL is not added it limits what you can do in the kernel. If you are licensing to GPL then it is bound to the GPL license.
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Bjorn O");
MODULE_DESCRIPTION("A simple hello world module");
MODULE_VERSION("1.0.0");

static int __init helloworld_init(void)
{ 
    printk(KERN_INFO "Hello World!\n");
    return 0;
} 

static void __exit helloworld_exit(void)
{
    printk(KERN_INFO "Goodbye World!\n");
}

//Tell the kernel which functions are initialization function and exit functions
module_init(helloworld_init);
module_exit(helloworld_exit);
