#include <alsa/asoundlib.h>

/* Use the newer ALSA API */
#define ALSA_PCM_NEW_HW_PARAMS_API

int main(int argc, char **argv)
{
    long loops;
    int rc;
    int size;
    snd_pcm_t *handle;
    snd_pcm_hw_params_t *params;
    unsigned int val;
    int dir;
    snd_pcm_uframes_t frames;
    char *buffer;
    int audio_file_fd;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s -d <time in us>\n", argv[0]);
        exit(1);
    }

    /* Open PCM device for recording (capture). USE THE CORRECT DEVICE! */
    rc = snd_pcm_open(&handle, "hw:0,0", SND_PCM_STREAM_CAPTURE, 0);
    if (rc < 0) {
        fprintf(stderr, "unable to open pcm device: %s\n", snd_strerror(rc));
        exit(1);
    }

    /* Allocate a hardware parameters object. */
    snd_pcm_hw_params_alloca(&params);

    /* Fill it in with default values. */
    snd_pcm_hw_params_any(handle, params);

    /* Set the desired hardware parameters. */

    /* Interleaved mode */
    snd_pcm_hw_params_set_access(handle, params, SND_PCM_ACCESS_RW_INTERLEAVED);

    /* Signed 32-bit little-endian format */
    snd_pcm_hw_params_set_format(handle, params, SND_PCM_FORMAT_S32_LE);

    /* Two channels (stereo) */
    snd_pcm_hw_params_set_channels(handle, params, 1);

    /* 44100 bits/second sampling rate (CD quality) */
    val = 44100;
    snd_pcm_hw_params_set_rate_near(handle, params, &val, &dir);

    /* Set period size to 32 frames. */
    frames = 32;
    snd_pcm_hw_params_set_period_size_near(handle, params, &frames, &dir);

    /* Write the parameters to the driver */
    rc = snd_pcm_hw_params(handle, params);
    if (rc < 0) {
        fprintf(stderr, "unable to set hw parameters: %s\n", snd_strerror(rc));
        exit(1);
    }

    /* Use a buffer large enough to hold one period */
    snd_pcm_hw_params_get_period_size(params, &frames, &dir);
    size = frames * 8; /* 2 bytes/sample, 2 channels */
    buffer = (char *)malloc(size);

    /* We want to loop for X seconds */
    snd_pcm_hw_params_get_period_time(params, &val, &dir);
    loops = atoi(argv[2]) / val;

    audio_file_fd = open("sample.raw", O_WRONLY | O_APPEND | O_CREAT | O_EXCL);
    if (!audio_file_fd) {
        fprintf(stderr, "unable to create output file\n");
        exit(1);
    }

    while (loops > 0) {
        loops--;
        rc = snd_pcm_readi(handle, buffer, frames);
        if (rc == -EPIPE) {
            /* EPIPE means overrun */
            fprintf(stderr, "overrun occurred\n");
            snd_pcm_prepare(handle);
        } else if (rc < 0) {
            fprintf(stderr, "error from read: %s\n", snd_strerror(rc));
        } else if (rc != (int)frames) {
            fprintf(stderr, "short read, read %d frames\n", rc);
        }
        
        rc = write(audio_file_fd, buffer, size);
        if (rc != size)
            fprintf(stderr, "short write: wrote %d bytes\n", rc);
    }

    snd_pcm_drain(handle);
    snd_pcm_close(handle);
    free(buffer);

    return 0;
}
