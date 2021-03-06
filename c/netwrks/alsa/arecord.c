/*
This example reads from the default PCM device
and writes to standard output for 5 seconds of data.
*/

/* Use the newer ALSA API */
#define PCM_DEVICE "default"
#define ALSA_PCM_NEW_HW_PARAMS_API


#include <alsa/asoundlib.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
  int fp;
  unsigned int pcm, tmp, dir;
  int buff_size;
  char fname;	
  long loops;
  int rc;
  int size;
  snd_pcm_t *handle;
  snd_pcm_hw_params_t *params;
  unsigned int val;
  
  snd_pcm_uframes_t frames;
  char *buff;
  int rate, channels, seconds;

  /* Open PCM device for recording (capture). */
  rc = snd_pcm_open(&handle, "default", SND_PCM_STREAM_CAPTURE, 0);// set to default for device

  if (rc < 0) 
  {
    fprintf(stderr,"unable to open pcm device: %s\n",   snd_strerror(rc));
    exit(1);
  }

  /* Allocate a hardware parameters object. */
  snd_pcm_hw_params_alloca(&params);

  /* Fill it in with default values. */
  snd_pcm_hw_params_any(handle, params);

  /* Set the desired hardware parameters. */

  /* Interleaved mode */
  snd_pcm_hw_params_set_access(handle, params,  SND_PCM_ACCESS_RW_INTERLEAVED);

  /* Signed 16-bit little-endian format */
  snd_pcm_hw_params_set_format(handle, params,SND_PCM_FORMAT_U8);

  /* Two channels (stereo) */
  snd_pcm_hw_params_set_channels(handle, params, 1);

  /* 44100 bits/second sampling rate (CD quality) */
  val = 8000;
  
  snd_pcm_hw_params_set_rate_near(handle, params,  &val, &dir);

  /* Set period size to 32 frames. */
  frames = 32;
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
  size = frames * 4; /* 2 bytes/sample, 2 channels */
  buff = (char *) malloc(size);

  /* We want to loop for 5 seconds */

  snd_pcm_hw_params_get_period_time(params, &val, &dir);
  loops = 50000000 / val;
  
  printf("\n\tEnter ip : ");
  scanf("%s",ipaddress);

	fp=open("221.wav",O_WRONLY);
  while (loops > 0) 
  {
		loops--;
		bzero(buff,sizeof(buff));
		rc = snd_pcm_readi(handle, buff, frames);
		write(fp,buff,128);
		if (rc == -EPIPE) 
		{
		  /* EPIPE means overrun(capture) */
		  fprintf(stderr, "overrun occurred\n");
		  snd_pcm_prepare(handle);
		} else if (rc < 0) 
		{
		  fprintf(stderr,"error from read: %s\n",  snd_strerror(rc));
		} else if (rc != (int)frames) 
		{
		  fprintf(stderr, "short read, read %d frames\n", rc);
		}
		
	//	rc = write(1, buff, size);
	//	if (rc != size)
	//	  fprintf(stderr,"short write: wrote %d bytes\n", rc);
	
  }
fname="221.wav";

	func(fname,ipaddr);

  snd_pcm_drain(handle);//this used for recover from this state.
  snd_pcm_close(handle);
  
	free(buff);

	return 0;
}
