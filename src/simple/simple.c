/*CSCE3401 Project 2: 900131538*/

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>


/*Function to be called when the module is loaded*/

int simple_init(void)
{
	printk(KERN_INFO "Loading Module...\n");

	return 0;
}

/*Function to be called when the module is removed*/
void simple_exit(void)
{
	printk(KERN_INFO "Removing Module...\n");
}

/*Macros for registering module entry and exit points*/
module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("Yasmin ElDokany");
