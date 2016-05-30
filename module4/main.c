#include <stdio.h>
#include "solution.h"


int main(){

	int c = 2;
	int *pc;
	pc = &c;
	int r = stringStat("Dima",2,pc);
	printf("res %d,  count %d \n\n",r,*pc);

	return 0;
}
