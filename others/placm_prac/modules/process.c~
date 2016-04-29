#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>

int init_module(void)
{
  struct task_struct *task = &init_task;

  do {
	printk( KERN_INFO "Name : %s , pid =[%d] \n",
		task->comm, task->pid);
	
	} while ( (task = next_task(task)) != &init_task );
	return 0;
}

void cleanup_module( void )
{
  return;
}
