#include<stdio.h>
#include<stdlib.h>// for exit
#include<string.h>
#include<unistd.h> //for close(),read()
#include<sys/types.h>//
#include<sys/socket.h> //for socket api's
#include<netinet/in.h>//for struct sockaddr_in
#include<arpa/inet.h>// for inet_pton

#define MAX 30

int ssfd;   //listenfd
int res; //connfd
int serverlen;
int free_port[100];
struct sockaddr_in serveraddr;

void main()
{
    int i=0,j=0,res;
    int startPortRange=0;  
    int stopPortRange=65536; 
    for(i=startPortRange; i<stopPortRange; i++)  
    {  
        ssfd=socket(AF_INET,SOCK_STREAM,0);
        if(ssfd==-1)
        {
            printf("\nSocket Creation Failed....");
        }

        serveraddr.sin_family=AF_INET;
        serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1"); // inet_addr converts an IPV4 from dotted decimal string
        //to e.g(127.0.0.1) to its 32-bit network byte ordered binary value.    

        serveraddr.sin_port=i;

        serverlen=sizeof(serveraddr);

        res = bind(ssfd,(struct sockaddr*)&serveraddr,serverlen);

        if(res==-1)
        {
            printf("\nPort in Use : %d",i);
        }
        else
        {		         	  
            printf("\nPort not in use: %d",i); 
        }
        
       close(ssfd);
    }	   	
}
