#include<malloc.h>

struct employee1
{
	char emp_name[20];
	int emp_id;
};

int main()
{
	struct employee1 emp;
	printf("\n\t\t\t------ Enter employee Details ------\n");
	printf("Enter Emplyee Name:");
	scanf("%s",emp.emp_name);
	printf("\nEnter Employee ID:");
	scanf("%d",&emp.emp_id);
	
	printf("Entries of Employee");
	printf("\nName:%s",emp.emp_name);
	printf("\nID:%d\n",emp.emp_id);
	return 0;
}
