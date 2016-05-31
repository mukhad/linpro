#include <stdio.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char **argv) {
   
   char key[] = "PPid:";
   FILE *fp;
   char buff[255];
   strcpy(buff,argv[1]);

   printf("%s\n",buff);
   int cmp = 1;

   do{
	char fname[255]="/proc/";
   	strcat(fname,buff);
   	strcat(fname,"/status");
	
	fp = fopen(fname, "r");
	int i=0;
   	do{
		fscanf(fp, "%s", buff);
      		i = strcmp(key,buff);
      		//printf("$%s$   %d\n", buff,i);
   	}while(i!=0);

      	fscanf(fp, "%s", buff);
     	printf("%s\n", buff);
   	
	fclose(fp);
	cmp = strcmp("1",buff);	
		
   }while(cmp!=0);

   return 0;
}
