#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>

int main()
{
int serverfd;
serverfd=socket(AF_INET,SOCK_STREAM,0);

struct sock_addr;


if(serverfd < 0)
	{
	printf("Error in creating server socket\n");

	}

