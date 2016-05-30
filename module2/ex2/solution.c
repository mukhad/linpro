#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#define dd 0

int (*func)(int);

bool init_library(char* libname, char* funcname){
	
	char li[100] = "./";
	strcat(li,libname);


	if (dd) printf("libname:  %s\nfuncname:  %s\n",li,funcname);


	void *hdl = dlopen(li, RTLD_LAZY);
	if ( NULL == hdl )
		return false;

	func = (int(*)(int))dlsym(hdl,funcname);

	if (NULL == func)
		return false;

	return true;
}

int main(int arg, char *argv[])
{

	int i,data;	
	if (dd) for(i=0;i<arg;i++) printf("%s \n",argv[i]);	

	if(arg==4){
		data = atoi(argv[3]);
		if (dd) printf("data ok %d\n",data);
	}
	else return 1;
	
	
	if (init_library(argv[1],argv[2]) )
	{
		int res = func(data);
		printf("%d\n",res);
	}
	else
		printf("error with library\n\n");

	return 0;
}
