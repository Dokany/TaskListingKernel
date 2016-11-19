/*CSCE3401 Project 2: 900131538*/

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>

/*Function to be called when the module is loaded to iterate over tasks linearly*/
int linear_tasks_init (void)
{
	struct task_struct *task;

	printk(KERN_INFO "Loading Linear Tasks List Module...\n%-16s\tSTATE\tPID\n", "NAME");

	for_each_process(task)
	{
		printk(KERN_INFO "%-16s\t%ld\t%d\n", task->comm, task->state, task->pid);

		/* Names of required fields found in the declaration of the task_struct in the linux/schedule [@ Line 1117] (thru the link: lxr.linux.no/linux+v2.6.30.5/include/linux/sched.h)
			where:
			- comm [@ Line 1252]: char array containing the executable name of the task without its path of maximum length "MAX_COMM_LEN" which is defined as 16 characters [@ Line 233]
			- state [@ Line 1118]: volatile long variable that reads -1 if the task is unrunnable, 0 if it is runnable and greater than 0 if stopped
			- pid [@ Line 1184]: pid_t variable indicating the process id pf the task
		*/
	}		

	return 0;
}

/*Function to be called when the module is removed*/
void linear_tasks_exit(void)
{
	printk(KERN_INFO "Removing Linear Tasks List Module...\n");
}

/*Macros for registering module entry and exit points*/
module_init(linear_tasks_init);
module_exit(linear_tasks_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Linear Tasks List Module");
MODULE_AUTHOR("Yasmin ElDokany");
