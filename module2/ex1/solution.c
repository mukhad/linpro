#include <stdio.h>
#include <string.h>

int stringStat(const char *string, int multiplier, int *count)
{
	int len = strlen(string);
	len *= multiplier;
	(*count)++;
	
	//int a = *count;
	//printf("count  %d\n",a );

	return len;

}
