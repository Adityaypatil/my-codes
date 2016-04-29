#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<errno.h>

int sendFileData(int sockfd,char *filename)
{
	char serverString[1024];
	bzero(serverString,sizeof(serverString));
	
	FILE *fp;
	int n,ret;
	fp = fopen(filename,"rb");
	if(fp == NULL)
	{
		printf("\n\tFile open error\n");
		perror("\n\tFopen");
		exit(1);
	}
	
	while((ret = fread(serverString,sizeof(serverString),1,fp)))
	{
		again : if((n = write(sockfd,serverString,sizeof(serverString))) < 0)
		{
			if((n < 0) && (errno == EINTR))			
			{
				goto again;
			}
			if(n < 0)
			{
				printf("\n\tWrite Error\n");
				exit(1);
			}
		}
		bzero(serverString,sizeof(serverString));
	}
	fclose(fp);
	return 0;
}

int sendFileName(int sockfd,char *filename)
{
	int n;
	agian1 : if((n = write(sockfd,filename,strlen(filename))) < 0)
	{
		if((n < 0) && (errno == EINTR))
		{
			goto agian1;
		}
		if(n < 0)
		{
			printf("\n\tWrite error\n");
			exit(1); 
		}
	}
	
	return 0;
}

int main(int argc,char *argv[])
{
	if(argc != 3)
	{
		printf("\n\tUsage : ./a.out 127.0.0.1 mp3_file.mp3\n");
		exit(1);
	}
	struct sockaddr_in servaddr;
	bzero(&servaddr,sizeof(servaddr));
	
	int sockfd,connfd;
	
	sockfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(sockfd < 0)
	{
		printf("\n\tSocket Error\n");
		perror("\n\tSocket");
		exit(1);
	}
	
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(9999);
	inet_pton(sockfd,argv[1],&servaddr.sin_addr);
	
	connfd = connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	if(connfd < 0)
	{
		printf("\n\tConnect Error\n");
		perror("\n\tConnect\n");
		exit(1);
	}
	
	sendFileName(sockfd,argv[2]);
	sendFileData(sockfd,argv[2]);
	printf("\n\tExiting\n");
}
