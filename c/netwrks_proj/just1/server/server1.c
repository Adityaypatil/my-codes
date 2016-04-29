#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<errno.h>

int main(int argc,char *argv[])
{
	system("clear");
	printf("\n\t\t\t\t\tServer\t\t\t\t\n");

	int connfd,sockfd,n,n1,clen,pid;
	FILE *fp;

	struct sockaddr_in servaddr,cliaddr;

	char serverString[1024],filename[50];

	bzero(&servaddr,sizeof(servaddr));
	bzero(&cliaddr,sizeof(cliaddr));
	
	sockfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);//socket 

	if(sockfd < 0)
	{
		printf("\n\tSocket Error\n");
		perror("\n\tSocket");
		exit(1);
	}
	
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(9999);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	if((bind(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr))) < 0)//bind func
	{
		printf("\n\tBind Error\n");
		perror("\n\tBind");
		exit(1);
	}
	
	if((listen(sockfd,3)) < 0)//listen
	{
		printf("\n\tListen Error\n");
		perror("\n\tListen");
		exit(1);
	}
	
	while(1)
	{
		clen = sizeof(cliaddr);
		connfd = accept(sockfd,(struct sockaddr *)&cliaddr,&clen);
		if(connfd < 0)
		{
			printf("\n\tAccept Error\n");
			perror("\n\tAccept");
			exit(1);
		}
		
		if((pid = fork()) == 0)
		{
			//close(sockfd);
			again : if((n = read(connfd,serverString,sizeof(serverString)) )> 0)
			serverString[n] = '\0';
			if((n < 0) && (errno == EINTR))
			{
				goto again;
			}
			if(n < 0)
			{
				printf("\n\tRead Error\n");
				perror("read");
				exit(1);
			}
			
			printf("\n\tServerString : %s\n",serverString);
			strcpy(filename,serverString);
			fp = fopen(filename,"wb+");
			if(fp == NULL)
			{
				printf("\n\tCouldn't create file\n");
				exit(1);
			}
			while((n1 = read(connfd,serverString,sizeof(serverString))) > 0)
			{
				//serverString[n1] = '\0';
				if((fwrite(serverString,sizeof(serverString),1,fp)) == 0)
				{
					printf("\n\tFile write error\n");
					perror("\n\tFwrite");
					exit(1);
				}
			}
			if(n1 < 0)
			{
				printf("\n\tRead Error\n");
				perror("\n\tRead");
				exit(1);
			}
			printf("\n\tRead finished\n");
			fclose(fp);
		}
		close(connfd);
	}
}
