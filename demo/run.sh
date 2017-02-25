cd ../sdk
make clean;make
cd -
make clean;make

#./demo 0 900 500 colorbar_900x500.bin colorbar_yuv422i.yuv
#./demo 1 900 500 colorbar_900x500.bin colorbar_yuv422p.yuv

./demo 0 1280 720 rgb888.bin yuv422i.yuv
./demo 1 1280 720 rgb888.bin yuv422p.yuv
