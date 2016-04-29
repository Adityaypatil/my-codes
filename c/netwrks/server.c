#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<time.h>

main(int argc,char *argv[])
{
	int listenfd,bindfd,listenvalue,connfd;
	char t[26];
	time_t ticks;
	struct sockaddr_in s;
	listenfd = socket(AF_INET,SOCK_STREAM,0);
	bzero(&s,sizeof(s));
	
	if(listenfd < 0)
	{
		printf("\n\tSocket Error");
		exit(1);
	}
	
	s.sin_port = htons(8888);
	s.sin_family = AF_INET;
	s.sin_addr.s_addr = htonl(INADDR_ANY);
	
	bindfd = bind(listenfd,(struct sockaddr *)&s,sizeof(s));
	
	if(bindfd < 0)
	{
		printf("\n\tBind Error\n");
		perror("-s");
		exit(1);
	}
	
	listenvalue = listen(listenfd,5);
	if(listenvalue < 0)
	{
		printf("\n\tListen Error");
		exit(1);
	}
	
	for(;;)
	{
		connfd = accept(listenfd,(struct sockaddr *)NULL,NULL);
		if(connfd < 0)
		{
			printf("\n\tAccept Error ");
			exit(1);
		}
		
		ticks = time(NULL);
		snprintf(t,sizeof(t),"%24s\r\n",ctime(&ticks));
		
		write(connfd,t,strlen(t));
		close(connfd);
	}
}
