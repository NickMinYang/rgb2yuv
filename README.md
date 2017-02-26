# rgb2yuv

实现：
a)RGB888到YUV422 interleaved的转换
b)RGB888到YUV422 planar的转换
c)RGB888到YUV420 interleaved的转换
d)RGB888到YUV420 planar的转换

目录介绍：
a)sdk目录下包括所有的源文件，头文件，Makefile及生成的librgb2yuv.so文件。
提供给客户时，只需要头文件及库文件。
b)demo目录下介绍以上几种方法的使用，以及相应的性能统计。


性能统计：
系统:Ubuntu 14.04.5 LTS
输入RGB888文件尺寸:1280x720

initial version:
rgb888 to yuv422i
Start time: 267167 us
End time: 292947 us
process time: 25780 us

rgb888 to yuv422p
Start time: 298473 us
End time: 319223 us
process time: 20750 us

rgb888 to yuv420i
Start time: 324952 us
End time: 356223 us
process time: 31271 us

rgb888 to yuv420p
Start time: 361015 us
End time: 378735 us
process time: 17720 us

-O3:
rgb888 to yuv422i
Start time: 817201 us
End time: 825185 us
process time: 7984 us

rgb888 to yuv422p
Start time: 829960 us
End time: 835525 us
process time: 5565 us

rgb888 to yuv420i
Start time: 839564 us
End time: 843482 us
process time: 3918 us

rgb888 to yuv420p
Start time: 847532 us
End time: 853183 us
process time: 5651 us

注:由于系统工作状态不同，实际统计时间会有差异
