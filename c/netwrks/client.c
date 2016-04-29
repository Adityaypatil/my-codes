#include<netinet/in.h>
#include<sys/socket.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

main(int argc,char *argv[])
{
	int sockfd,connfd,n;
	char c[26];
	struct sockaddr_in s;
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	
	if(argc != 2)
	{
		printf("\n\tinsufficient number of arguments\n");
		exit(1);
	}
	
	if(sockfd < 0)
	{
		printf("\n\tSocket Error\n");
		exit(1);
	}
	
	bzero(&s,sizeof(s));
	s.sin_family = AF_INET;
	s.sin_port = htons(8888);
	s.sin_addr.s_addr = inet_addr(argv[1]);
	
	connfd = connect(sockfd,(struct sockaddr *)&s,sizeof(s));
	if(connfd < 0 )
	{
		printf("\n\tConnection Error\n");
		exit(1);
	}
	
	while(( n = read(sockfd,c,sizeof(c)) > 0))
	{
		c[n] = '\0';
		printf("\n\t%s",c);
	}
	printf("\n");
	
	exit(0);	
}
