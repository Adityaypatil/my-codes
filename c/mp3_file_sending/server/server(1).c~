#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<errno.h>

int createFile(char *p)
{
	FILE *fp;
	fp = fopen("read_text.c","wb+");
	if(fp == NULL)
	{
		return 0;
	}
	fclose(fp);
	return 1;
}

void checkFileName(char *p)
{
	int i,j,flag = 0;
	for(i = 0;p[i] != '0' && j > 0;i++)
	{
		
		if(p[i] == '.')
		{
			j = 3;
			flag = 1;
		}
		if(flag == 1)
		{
			j--;
		}
	}
	p[++i] = '\0';
}

int main(int argc,char *argv[])
{
	system("clear");
	printf("\n\t\t\t\t\t\tSERVER\n");
	
	int connfd,sockfd,clen,n,n1,pid,writefd;
	char serverString[50],clientString[50],filename[20];
	
	struct sockaddr_in servaddr,cliaddr;
	bzero(&servaddr,sizeof(servaddr));
	bzero(&cliaddr,sizeof(cliaddr));
	
	sockfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	
	if(sockfd < 0)
	{
		printf("\n\tSocket Error\n");
		perror("socket");
		exit(1);
	}
	
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(8889);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	if(bind(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr)) < 0)
	{
		printf("\n\tSocket Error\n");
		perror("bind");
		exit(1);
	}
	
	if(listen(sockfd,3) < 0)
	{
		printf("\n\tListen Error\n");
		perror("listen");
		exit(1);
	}
	
	while(1)
	{
		clen = sizeof(cliaddr);
		connfd = accept(sockfd,(struct sockaddr *)&cliaddr,&clen);
		if(connfd < 0)
		{
			printf("\n\tAccept Error\n");
			perror("Accept");
			exit(1);
		}
		
		if((pid = fork()) == 0)
		{
		
			close(sockfd);
			
			again : if((n = read(connfd,serverString,sizeof(serverString)) )> 0)
			//serverString[n] = '\0';
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
			checkFileName(filename);
		
			printf("\n\tFilename : %s\n",filename);
			bzero(serverString,sizeof(serverString));
//			printf("\n\tFilename : %s\n",filename);
	
			if(createFile(serverString) != 1)
			{
				printf("\n\tCould not create file\n");
				exit(1);
			}
			else
			{
				while(read(sockfd,serverString,sizeof(serverString)) != 0)
				{
					FILE *fp;
					fp = fopen("read_text.c","rb+");
					if(fp == NULL)
					{
						printf("\n\tError in writting the file\n");
						exit(1);
					}
					
					if((writefd = fwrite(serverString,sizeof(serverString),1,fp)) == 0)
					{
						printf("\n\tWritting error into file\n");
						//error code
						exit(1);
					}
					fclose(fp);
				}
			}
		}
		close(connfd);
	}
}
