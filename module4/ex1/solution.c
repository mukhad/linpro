#include <stdio.h>
#include <string.h>

int main() {
   char key[] = "PPid:";
   FILE *fp;
   char buff[255];

   fp = fopen("/proc/self/status", "r");
   int i=0;
   do{
   
      fscanf(fp, "%s", buff);
      i = strcmp(key,buff);	
      //printf("$%s$   %d\n", buff,i);
   }while(i!=0);

      fscanf(fp, "%s", buff);
      printf("%s\n", buff);
   fclose(fp);
   

   return 0;
}
