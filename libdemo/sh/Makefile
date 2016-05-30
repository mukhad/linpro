all: exe lib

exe: hello.h main.c lib
	gcc main.c -fPIC -L. -lHello -o helloM

lib: hello.h hello.c
	gcc -shared -fPIC hello.c -o libHello.so

clean:
	-rm helloM
