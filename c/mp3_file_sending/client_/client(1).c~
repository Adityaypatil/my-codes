#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<errno.h>

int openFile(char *filename)
{
	FILE *fp;
	fp = fopen(filename,"rb");
	if(fp == NULL)
	{
		return 0;
	}
	fclose(fp);
	return 1;
}

int sendFile(int sockfd,char *filename)
{
	FILE *fp,*fp2;
	fp = fopen(filename,"rb");
	fp2 = fopen("sss.txt","wb+");
	int n,n1,n2 = 0;
	char serverString[1024];
	bzero(serverString,sizeof(serverString));
	if(fp == NULL)
	{
		printf("\n\tError in opening file for reading\n");
		return 0;		
	}
	agian1 : if((n = write(sockfd,filename,strlen(filename))) > 0)
	{
		
	}
	if((n < 0) && (errno == EINTR))
	{
		goto agian1;
	}
	if(n < 0)
	{
		printf("\n\tWrite error\n");
		return 0; 
	}
	
	
	printf("\n\t%s\n",serverString);//??????????????????????
	
	while((n2 = fread(serverString,sizeof(serverString),1,fp)) != 0)
	{
		//printf("\n\t%s\n",serverString);
		fp2 = fopen("sss.txt","rb+");
		if(fp2 == NULL)
		{
			printf("\n\tOpen error\n");
		}
		if((n1 = fwrite(serverString,strlen(serverString),1,fp2)) == 0)
		{
			printf("\n\tWrite error\n");
		}
		fclose(fp2);
		
		again : if(n = write(sockfd,serverString,n2) < 0)
		{
			if((n < 0) && (errno == EINTR))			
			{
				goto again;
			}
			if(n < 0)
			{
				printf("\n\tWrite Error\n");
				return 0;
			}
		}
		
	}
	
	printf("N : %d\n",n2);
	fclose(fp);
	
	return 1;
}

int main(int argc,char **argv)
{
	if(argc != 3)
	{
		printf("\n\tError please enter ip address and filename\n");
		exit(1);
	}
	printf("\n\tfilename : %s\n",argv[2]);
	int sockfd,connfd;
	
	struct sockaddr_in servaddr;
	bzero(&servaddr,sizeof(servaddr));
	
	sockfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	
	if(sockfd < 0)
	{
		printf("\n\tSocket Error\n");
		exit(1);
	}
	
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(8889);
	inet_pton(sockfd,argv[1],&servaddr.sin_addr);
	
	/*if(openFile(argv[2]) == 0)
	{
		printf("\n\tError in opening file \n");
		exit(1);
	}*/
	
	connfd = connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	if(connfd < 0)
	{
		printf("\n\tConnection Error\n");
		perror("connect");
		exit(1);
	}
	
	if(sendFile(sockfd,argv[2]) == 0)
	{
		printf("\n\tError in sending file \n");
		exit(1);
	}
}
