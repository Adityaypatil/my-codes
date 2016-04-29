#define PCM_DEVICE "default"
#define ALSA_PCM_NEW_HW_PARAMS_API

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<errno.h>

#include <alsa/asoundlib.h>

snd_pcm_t *handle;

int fun(char *ipaddress,char *buff,int size,int fp,snd_pcm_t *handle,snd_pcm_uframes_t frames) 
{
	struct sockaddr_in servaddr;
	bzero(&servaddr,sizeof(servaddr));
	
	int sockfd,connfd,loops,rc;
	sockfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);// socket fd
//	strcpy(ipaddress,"192.168.1.90");
	strcpy(ipaddress,"127.0.0.1");
	if(sockfd < 0)
	{
		perror("\n\tSocket");
		printf("\n\tSocket Error\n");
		exit(1);
	}
	buff=(char *) malloc(4000);
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(9999);
	inet_pton(servaddr.sin_family,ipaddress,&servaddr.sin_addr);// convert(ip addrss) string to int
	
	connfd = connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));//connect
	//frames=1280;
	if(connfd < 0)
	{
		fflush(stdout);
		printf("\n\tConnect Error\n");
		perror("\n\tConnect\n");
		exit(1);
	}
	frames=1000;

	
	while(1)
	  {
	  	
		//bzero(buff,sizeof(buff));
		///fflush(stdout);
		//snd_pcm_prepare(pcm_handle);
					 
		rc = snd_pcm_readi(handle, buff, 4000);
	//	write(fp,buff,4000);
		//printf("\n%d",loops);
	//	write(1,buff,1);
		write(sockfd,buff,4000);
		//loops--;	
 	}
  
	
	//sendFileData(sockfd,buffer,size);
}	


int main()
{
	int fp,ff;
  unsigned int pcm, tmp, dir;
  int buff_size;
	char filename[20] = "123.wav";
  long loops;
  int rc;
  int size;
  snd_pcm_t *handle;
  snd_pcm_hw_params_t *params;
  unsigned int val;
  
  snd_pcm_uframes_t frames;
  char *buff,*ipaddress;
  int rate, channels, seconds;
  rc = snd_pcm_open(&handle, "default", SND_PCM_STREAM_CAPTURE, 0);

  if (rc < 0) 
  {
    fprintf(stderr,"unable to open pcm device: %s\n",   snd_strerror(rc));
    exit(1);
  }
  snd_pcm_hw_params_alloca(&params);

  snd_pcm_hw_params_any(handle, params);

  /* Set the desired hardware parameters. */

  /* Interleaved mode */
  snd_pcm_hw_params_set_access(handle, params,  SND_PCM_ACCESS_RW_INTERLEAVED);

  /* Signed 16-bit little-endian format */
  snd_pcm_hw_params_set_format(handle, params,SND_PCM_FORMAT_U8	);

  /* Two channels (stereo) */
  snd_pcm_hw_params_set_channels(handle, params, 1);

  /* 44100 bits/second samplng rate (CD quality) */
  val = 8000;
  
  snd_pcm_hw_params_set_rate_near(handle, params,  &val, &dir);

  /* Set period size to 32 frames. */
  frames = 2000;
  snd_pcm_hw_params_set_period_size_near(handle,params, &frames, &dir);

  /* Write the parameters to the driver */
  rc = snd_pcm_hw_params(handle, params);
  if (rc < 0) 
  {
    fprintf(stderr,"unable to set hw parameters: %s\n", snd_strerror(rc));
    exit(1);
  }

  /* Use a buff large enough to hold one period */

  snd_pcm_hw_params_get_period_size(params,  &frames, &dir);

  /* We want to loop for 5 seconds */

  //snd_pcm_hw_params_get_period_time(params, &val, &dir);


  system("rm 123.wav;touch 123.wav");
  fp=open("123.wav",O_WRONLY);
  ipaddress = malloc(1024);

  fun(ipaddress,buff,8000,fp,handle,frames);
  
  close(fp);
  
 
  snd_pcm_drain(handle);
  snd_pcm_close(handle);
  

	return 0;
}
	
