# rgb2yuv

实现：
a)RGB888到YUV422 interleaved的转换
b)RGB888到YUV422 planar的转换

目录介绍：
a)sdk目录下包括所有的源文件，头文件，Makefile及生成的librgb2yuv.so文件。
提供给客户时，只需要头文件及库文件。
b)demo目录下介绍以上几种方法的使用，以及相应的性能统计。


性能统计：
系统:Ubuntu 14.04.5 LTS
输入RGB888文件尺寸:1280x720

initial version:
rgb888 to yuv422i
Start time: 664411 us
End time: 686476 us
process time: 22065 us

rgb888 to yuv422p
Start time: 691442 us
End time: 714842 us
process time: 23400 us

-O3:
rgb888 to yuv422i
Start time: 270003 us
End time: 279197 us
process time: 9194 us

rgb888 to yuv422p
Start time: 284651 us
End time: 291307 us
process time: 6656 us

注:由于系统工作状态不同，实际统计时间会有差异
