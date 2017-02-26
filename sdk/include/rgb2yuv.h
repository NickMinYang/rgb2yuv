#ifndef __RGB2YUV_H__
#define __RGB2YUV_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

int rgb888_to_yuv422i(unsigned char *prgb888, unsigned char *pyuv422i, int w, int h);
int rgb888_to_yuv422p(unsigned char *prgb888, unsigned char *pyuv422p, int w, int h);
int rgb888_to_yuv420i(unsigned char *prgb888, unsigned char *pyuv420i, int w, int h);
int rgb888_to_yuv420p(unsigned char *prgb888, unsigned char *pyuv420p, int w, int h);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif /* __RGB2YUV_H__ */
