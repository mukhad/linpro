#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <dlfcn.h>


void (*msg_hello)(const char *);

bool init_library(){
	
	void *hdl = dlopen("./libHello.so", RTLD_LAZY);
	if ( NULL == hdl )
		return false;

	msg_hello = (void(*)(const char*))dlsym(hdl,"msg_hello");

	if (NULL == msg_hello)
		return false;

	return true;
}

int main(){
	if ( init_library())
		msg_hello(" Dima in RunTime");
	else
		printf("error with library");
	return 0;
}
