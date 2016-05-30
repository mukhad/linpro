#include <stdio.h>
#include <string.h>
#include <dirent.h>

int main() {
   char key[] = "PPid:";
   FILE *fp;
   char buff[255];

DIR *pDIR;
        struct dirent *entry;
        if( pDIR=opendir("/proc") ){
            while(entry = readdir(pDIR)){
                if( strcmp(entry->d_name, ".") != 0 && 
                    strcmp(entry->d_name, "..") != 0 &&
                    isdigit(entry->d_name[0]) )
                        printf("%s    %d\n", entry->d_name,entry->d_type );
            }
            closedir(pDIR);
        }

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
