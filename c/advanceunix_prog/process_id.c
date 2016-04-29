#include <stdio.h>
int main(void)
{
int i;
//scanf("%d");
//printf("hello world from process ID %d\n", getpid());
//exit(0);
fork();
scanf("%d",&i);
fork();
scanf("%d",&i);
fork();
//scanf("%d",&i);
//fork();
}
