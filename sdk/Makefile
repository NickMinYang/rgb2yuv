CXX = gcc

CFLAGS = -I./include/ 
CFLAGS += -fPIC -shared -O3

all:
	$(CXX) ./src/rgb2yuv.c $(CFLAGS) -o ./lib/librgb2yuv.so 

.PHONY: clean
clean:
	@rm -f *.o 

