


#include <alsa/asoundlib.h>
#include <stdlib.h>


int record(int connf)
{
	unsigned int pcm, tmp, dir;
	int rate, channels, seconds;
	snd_pcm_t *pcm_handle;
	snd_pcm_hw_params_t *params;
	snd_pcm_uframes_t frames;
	char *buff,*buf;
	int buff_size, loops;
	int fp; 
	int n1;
	char temp[10000],*ptr;
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

	buff_size = frames * channels * 2 /* 2 -> sample size */;
	buff = (char *) malloc(buff_size*3);

//	size = frames * channels * 2 /* 2 -> sample size */;
	buf = (char *) malloc(8000);
	
	snd_pcm_hw_params_get_period_time(params, &tmp, NULL);
	
	fp=open("1.wav",O_WRONLY);
	frames=2000;
	ptr=temp;
	while(1)
//	for (loops=500000; loops > 0; loops--)
	{
       
		label1 :
			n1=read(connf,buf,8000);
	/*		
			write(fp,buf,n1); 
			if(n1==0)
			{
				printf("SSEORRRR");
				exit(0);
			}
			if((n1 < 0) && (errno == EINTR))
			{
				goto label1;
			}
			if(n1 < 0)
			{
				printf("\n\tRead Error\n");
				perror("\n\tRead");
				//exit(1);
			}
			/*if(loops%7==0)
			{
				memcpy(ptr,buf,n1);
				ptr+=n1;
			}*/
		
//			else{
					//memcpy(temp,buf,n1);
					snd_pcm_prepare(pcm_handle);
					
					snd_pcm_writei(pcm_handle, buf, 8000);
				/*	{
						printf("XRUN.\n");

						snd_pcm_prepare(pcm_handle);
					} 
					else 
					if(pcm < 0) 
					{
						printf("ERROR. Can't write to PCM device. %s\n", snd_strerror(pcm));
					}
					ptr=temp;*/
//		}
	}
		

	snd_pcm_drain(pcm_handle);
	snd_pcm_close(pcm_handle);
	free(buff);

	return 0;
}

