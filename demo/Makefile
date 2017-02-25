CXX = gcc

CFLAGS = -I../sdk/include
LDFLAGS = -L../sdk/lib -lrgb2yuv

all:
	$(CXX) demo.c $(CFLAGS) $(LDFLAGS) -o demo  

.PHONY: clean
clean:
	@rm -f demo 

