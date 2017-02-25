#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "rgb2yuv.h"

int main(int argc, char *argv[])
{
    int w = 1280;
    int h = 720;
    int mode; 
    unsigned char *prgb888 = NULL;
    unsigned char *pyuv = NULL;
    FILE *pfile_rgb = NULL;
    FILE *pfile_yuv = NULL;

    struct timeval starttime;
    struct timeval endtime;

    if (argc < 4)
    {
        printf("demo mode infile outfile\n");
        printf("mode: 0-rgb888 to yuv422i, 1-rgb888 to yuv422p, 3-rgb888 to yuv420p\n");
        printf("\n");
        return 0;
    }

    mode = atoi(argv[1]); 
    if ((mode != 0) & (mode != 1) & (mode !=3))
    {
        printf("wrong mode:%d\n",mode);
        return 0 ;
    }

    w = atoi(argv[2]); 
    h = atoi(argv[3]); 
    prgb888 = malloc(3*w*h);
    if (prgb888 == NULL)
    {
        goto out;
    }
    pyuv = malloc(3*w*h);
    if (pyuv == NULL)
    {
        goto out;
    }
    pfile_rgb = fopen(argv[4], "rb");
    if (pfile_rgb == NULL)
    {
        goto out;
    }
    pfile_yuv = fopen(argv[5],"wb");
    if (pfile_yuv == NULL)
    {
        goto out;
    }

    fread(prgb888, 1, 3*w*h, pfile_rgb);
    
    switch (mode)
    {
        case 0:
            printf("rgb888 to yuv422i\n");
            gettimeofday(&starttime, NULL);
            rgb888_to_yuv422i(prgb888, pyuv, w, h);
            gettimeofday(&endtime, NULL);
            fwrite(pyuv, 1, 2*w*h, pfile_yuv);
            break;
        case 1:
            printf("rgb888 to yuv422p\n");
            gettimeofday(&starttime, NULL);
            rgb888_to_yuv422p(prgb888, pyuv, w, h);
            gettimeofday(&endtime, NULL);
            fwrite(pyuv, 1, 2*w*h, pfile_yuv);
            break;
        case 3:
            printf("rgb888 to yuv420p\n");
            gettimeofday(&starttime, NULL);
            rgb888_to_yuv420p(prgb888, pyuv, w, h);
            gettimeofday(&endtime, NULL);
            fwrite(pyuv, 1, w*h*3/2, pfile_yuv);
            break;
    }

    printf("Start time: %ld us\n", starttime.tv_usec);
    printf("End time: %ld us\n", endtime.tv_usec);
    if (endtime.tv_usec > starttime.tv_usec)
    {
        printf("process time: %ld us\n", endtime.tv_usec - starttime.tv_usec);
    }
    
out:
    if (pfile_yuv)
    {
        fclose(pfile_yuv);
        pfile_yuv = NULL;
    }

    if (pfile_rgb)
    {
        fclose(pfile_rgb);
        pfile_rgb = NULL;
    }
    
    if (pyuv)
    {
        free(pyuv);
        pyuv = NULL;
    }

    if (prgb888)
    {
        free(prgb888);
        prgb888 = NULL;
    }
    return 0;
}
