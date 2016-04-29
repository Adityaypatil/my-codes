#define ALSA_PCM_NEW_HW_PARAMS_API
#include <alsa/asoundlib.h>

int main()
{
  unsigned int pcm, tmp, dir;
  int buff_size;
	
  long loops;
  int rc;
  int size;
  snd_pcm_t *handle,*pcm_handle;
  snd_pcm_hw_params_t *params;
  unsigned int val;
  
  snd_pcm_uframes_t frames;
  char *buff;
  int rate, channels, seconds;
  snd_pcm_hw_params_t *pcm_params;
	



  snd_pcm_open(&handle, "default", SND_PCM_STREAM_CAPTURE, 0);
  snd_pcm_open(&pcm_handle, "default" ,	SND_PCM_STREAM_PLAYBACK, 0);
  
  snd_pcm_hw_params_alloca(&params);
  snd_pcm_hw_params_alloca(&pcm_params);
  
  snd_pcm_hw_params_any(handle, params);
  snd_pcm_hw_params_any(pcm_handle, pcm_params);
  
  snd_pcm_hw_params_set_access(handle, params,  SND_PCM_ACCESS_RW_INTERLEAVED);
  snd_pcm_hw_params_set_access(pcm_handle, pcm_params,SND_PCM_ACCESS_RW_INTERLEAVED);
  
  snd_pcm_hw_params_set_format(handle, params, SND_PCM_FORMAT_S16_LE);
  snd_pcm_hw_params_set_format(pcm_handle, pcm_params,SND_PCM_FORMAT_S16_LE);
  
  snd_pcm_hw_params_set_channels(handle, params, 2);
  snd_pcm_hw_params_set_channels(pcm_handle, pcm_params, 2);


  val = 30000;
  snd_pcm_hw_params_set_rate_near(handle, params,  &val, &dir);
  snd_pcm_hw_params_set_rate_near(pcm_handle, pcm_params, &val, 0);
  
  frames = 32;
  snd_pcm_hw_params_set_period_size_near(handle,params, &frames, &dir);
  //snd_pcm_hw_params_get_period_size_near(pcm_handle,pcm_params, &frames, 0);

  snd_pcm_hw_params(handle, params);
  snd_pcm_hw_params(pcm_handle, pcm_params);

		snd_pcm_hw_params(pcm_handle, pcm_params);
		
  snd_pcm_hw_params_get_period_size(params,  &frames, &dir);
  snd_pcm_hw_params_get_period_size(pcm_params, &frames, 0);
  
  size = frames * 4; /* 2 bytes/sample, 2 channels */
  buff = (char *) malloc(size);

  snd_pcm_hw_params_get_period_time(params, &val, &dir);
  snd_pcm_hw_params_get_period_time(pcm_params, &val, NULL);
  
  loops = 5000000 / val;

	printf("\nRecording.");
  while (loops > 0) 
	{
		loops--;
		snd_pcm_readi(handle, buff, frames);
	}
		system("sleep 3");
	
	loops = 5000000 / val;

printf("\nplaying.....");
  while (loops > 0) 
	{
		loops--;
		snd_pcm_writei(pcm_handle, buff, frames);
	}
  
 

  snd_pcm_drain(handle);
  snd_pcm_close(handle);
  snd_pcm_drain(pcm_handle);
  snd_pcm_close(pcm_handle);
  free(buff);
  return 0;

}

//===============================================================================================
	
		
	/* Resume information */
/*	printf("PCM name: '%s'\n", snd_pcm_name(pcm_handle));

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

	

	buff_size = frames * channels * 2 ;
	buff = (char *) malloc(buff_size);

	

*/	
