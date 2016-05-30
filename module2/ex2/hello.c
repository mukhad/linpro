#include "hello.h"
#include <stdio.h>

int msg_hello(int data){
	
	printf("hello from func %d\n",data);

	return 5*data;

}
