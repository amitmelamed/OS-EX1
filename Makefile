.PHONY: all clean
all: cmp copy encode decode


cmp: cmp.o
	gcc -Wall -g -o cmp cmp.o

cmp.o: cmp.c
	gcc -Wall -g -c cmp.c

copy: copy.o
	gcc -Wall -g -o copy copy.o

copy.o: copy.c
	gcc -Wall -g -c copy.c

encode: lib encode.c
	gcc encode.c -ldl -o encode
	export LD_LIBRARY_PATH=.
decode: lib decode.c
	gcc decode.c -ldl -o decode
	export LD_LIBRARY_PATH=.
lib: codec1.c codec2.c codec.h
	gcc -Wall -o libcodec1.so -shared -fPIC codec1.c
	gcc -Wall -o libcodec2.so -shared -fPIC codec2.c


clean:
	rm -f *.o *.a *.so cmp copy encode decode

