/*CSCE3401 Project 2: 900131538*/

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>

/*Function that iterates over tasks with a Depth-First Search tree*/
void dfs_task_list(struct task_struct *task)
{
	struct task_struct *ntask;		/*Pointer to next task*/
	struct list_head *list;

	list_for_each(list, &task->children)
	{ 
		ntask = list_entry(list, struct task_struct, sibling);

		if (ntask != NULL)			/*Checking if a sibling was found*/
		{
			printk(KERN_INFO "%-16s\t%ld\t%d\n", ntask->comm, ntask->state, ntask->pid); 
			dfs_task_list(ntask);
		}
	}
}

/*Function to be called when the module is loaded*/
int dfs_tasks_init (void)
{
	printk(KERN_INFO "Loading DFS Tasks List Module...\n%-16s\tSTATE\tPID\n", "NAME");

	dfs_task_list(&init_task);		/*Initial task for the DFS tree from the Linux/init.h library*/

	return 0;
}

/*Function to be called when the module is removed*/
void dfs_tasks_exit(void)
{
	printk(KERN_INFO "Removing DFS Tasks List Module...\n");
}

/*Macros for registering module entry and exit points*/
module_init(dfs_tasks_init);
module_exit(dfs_tasks_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("DFS Tasks List Module");
MODULE_AUTHOR("Yasmin ElDokany");
