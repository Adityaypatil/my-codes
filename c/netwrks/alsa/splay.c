#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
#include<alsa/asoundlib.h>
#define ALSA_PCM_NEW_HW_PARAMS_API

int main()
{	
	unsigned int pcm, tmp, dir;
	int rate, channels, seconds;
	snd_pcm_t *pcm_handle;
	snd_pcm_hw_params_t *params;
	snd_pcm_uframes_t frames;
	char *buff;
	int buff_size, loops;
	int fp; 
	struct sockaddr_in serv_addr;
	int sock,connf,num,tpa=1;
	
	/*if (argc < 4)
	{
		printf("Usage: %s <sample_rate> <channels> <seconds>\n",
				argv[0]);
		return -1;
	}*/

	rate = 8000;//atoi(argv[1]);
	channels = 1;//atoi(argv[2]);
	seconds = 10;//atoi(argv[3]);

	/* Open the PCM device in playback mode */
	if (pcm = snd_pcm_open(&pcm_handle, "default" ,	SND_PCM_STREAM_PLAYBACK, 0) < 0)
		printf("ERROR: Can't open \"%s\" PCM device. %s\n",	"default", snd_strerror(pcm));

	/* Allocate parameters object and fill it with default values*/
	snd_pcm_hw_params_alloca(&params);

	snd_pcm_hw_params_any(pcm_handle, params);

	/* Set parameters */
	if (pcm = snd_pcm_hw_params_set_access(pcm_handle, params,SND_PCM_ACCESS_RW_INTERLEAVED) < 0)
		printf("ERROR: Can't set interleaved mode. %s\n", snd_strerror(pcm));

	if (pcm = snd_pcm_hw_params_set_format(pcm_handle, params,SND_PCM_FORMAT_U8) < 0)
		printf("ERROR: Can't set format. %s\n", snd_strerror(pcm));

	if (pcm = snd_pcm_hw_params_set_channels(pcm_handle, params, channels) < 0)
		printf("ERROR: Can't set channels number. %s\n", snd_strerror(pcm));

	if (pcm = snd_pcm_hw_params_set_rate_near(pcm_handle, params, &rate, 0) < 0)
		printf("ERROR: Can't set rate. %s\n", snd_strerror(pcm));

	/* Write parameters */
	if (pcm = snd_pcm_hw_params(pcm_handle, params) < 0)
		printf("ERROR: Can't set harware parameters. %s\n", snd_strerror(pcm));

	/* Resume information */
	printf("PCM name: '%s'\n", snd_pcm_name(pcm_handle));

	printf("PCM state: %s\n", snd_pcm_state_name(snd_pcm_state(pcm_handle)));

	snd_pcm_hw_params_get_channels(params, &tmp);
	printf("channels: %i ", tmp);

	if (tmp == 1)
		printf("(mono)\n");
	else if (tmp == 2)
		printf("(stereo)\n");

	snd_pcm_hw_params_get_rate(params, &tmp, 0);
	printf("rate: %d bps\n", tmp);

	printf("seconds: %d\n", seconds);	

	/* Allocate buffer to hold single period */
	snd_pcm_hw_params_get_period_size(params, &frames, 0);
	//frames=64;
	buff_size = 128;//frames * channels /* 2  2 -> sample size */;
	frames=128;
	buff = (char *) malloc(buff_size);
	printf("\nframes: %d \t buffsize: %d\n",frames,buff_size);
	snd_pcm_hw_params_get_period_time(params, &tmp, NULL);
	printf("\ntmp = %d\n",tmp);
	fp=open("222.wav",O_WRONLY);
	
	sock=socket(AF_INET,SOCK_STREAM,0);

	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(5000);
	serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);

	bind(sock,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
	listen(sock,4);
	
	connf=accept(sock,(struct sockaddr*)NULL,NULL);
	tmp=125000;
	for (loops = (seconds * 1000000) / tmp; 1 ; loops--)
	{
		/*read(connf, buff, 128);
		snd_pcm_writei(pcm_handle, buff, frames);
		write(fp,buff,128);
		*/
		if (pcm = read(connf, buff, 128) == 0)
		
		{
			printf("Early end of file.\n");
			return 0;
		}
		else
		write(fp,buff,128);

		if (pcm = snd_pcm_writei(pcm_handle, buff, frames) == -EPIPE)
		{
			//printf("XRUN.\n");
			snd_pcm_prepare(pcm_handle);
		} else if (pcm < 0) {
			printf("ERROR. Can't write to PCM device. %s\n", snd_strerror(pcm));
		}
	}

	snd_pcm_drain(pcm_handle);
	snd_pcm_close(pcm_handle);
	free(buff);

	return 0;
}
