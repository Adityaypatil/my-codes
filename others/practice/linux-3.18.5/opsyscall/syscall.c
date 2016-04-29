#include<linux/kernel.h>
#include<linux/syscall.h>

asmlinkage long sys_opsyscall(const char *test)
{
	printk(KERN_ALERT "CALLED WITH STRING \n",test);
	return 0;
}
