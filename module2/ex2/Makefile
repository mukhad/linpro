all: exe lib

exe: hello.h solution.c lib
	gcc solution.c -fPIC -ldl -o solution

lib: hello.h hello.c
	gcc -shared hello.c -fPIC -o libShared.so
