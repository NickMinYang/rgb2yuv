#include <stdio.h>
#include "rgb2yuv.h"

#define RGB2YUV(r,g,b,y,u,v)\
	y = (77*r + 150*g + 29*b)>>8;\
	u =((128*b - 43*r -85*g)>>8) +128;\
	v =((128*r - 107*g -21*b)>>8) +128;\
	y = y < 0 ? 0 : y;\
	u = u < 0 ? 0 : u;\
	v = v < 0 ? 0 : v;\
	y = y > 255 ? 255 : y;\
	u = u > 255 ? 255 : u;\
	v = v > 255 ? 255 : v

int rgb888_to_yuv422i(unsigned char *prgb888, unsigned char *pyuv422i, int w, int h)
{
    int i,j;
    unsigned char r,g,b;
    int y,u,v;
    
    if (((w & 0x1) != 0) || ((h & 0x1) != 0))
    {
        printf("width and height must be multiple of 2.\n");
        return -1;
    }

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            r = *prgb888++;
            g = *prgb888++;
            b = *prgb888++;
            RGB2YUV(b,g,r,y,u,v);
            if (j & 0x1)
            {
                *pyuv422i++ = v;
                *pyuv422i++ = y;
            }
            else
            {
                *pyuv422i++ = u;
                *pyuv422i++ = y;
            }
        }
    }

    return 0;
}

int rgb888_to_yuv422p(unsigned char *prgb888, unsigned char *pyuv422p, int w, int h)
{
    int i,j;
    unsigned char r,g,b;
    int y,u,v;
    unsigned char *py,*pu,*pv;
    
    if (((w & 0x1) != 0) || ((h & 0x1) != 0))
    {
        printf("width and height must be multiple of 2.\n");
        return -1;
    }

    py = pyuv422p;
    pu = py + w * h;
    pv = pu + w * h / 2;

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            r = *prgb888++;
            g = *prgb888++;
            b = *prgb888++;
            RGB2YUV(b,g,r,y,u,v);
            *py++ = y;
            if (j & 0x1)
            {
                *pu++ = u;
                *pv++ = v;
            }
        }
    }

    return 0;
}
