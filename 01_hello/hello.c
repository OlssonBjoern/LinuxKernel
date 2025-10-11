#include <linux/module.h>
#include <linux/init.h>

// Callback functions for when the module is loaded in or out of the kernel
int my_init(void) {
  //Printk writes to the kernel log
   printk("hello - Hello, Kernel!\n");
   return 0;
}

//Removing module from kernel
void my_exit(void) {
  
  printk("hello- Goodbye, Kernel!\n");

}

// Have to tell the module when the module is loaded or removed from kernel

module_init(my_init);
module_exit(my_exit);

//Have to specify the license of this module to make it executable
MODULE_LICENSE("GPL");
