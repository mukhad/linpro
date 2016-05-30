all: exe lib

exe: solution.h main.c lib
	gcc main.c -fPIC -L. -lsolution -o exesol

lib: solution.h solution.c
	gcc -shared solution.c -fPIC -o libsolution.so

clean:
	-rm exesol
