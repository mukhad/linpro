#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdbool.h>

bool is_parent(char* pproc, char* proc){

    char key[] = "PPid:";
    FILE *fp;
    char buff[255];

    strcpy(buff,proc);
    bool res = false;

   //printf("\n%s ->  %s\n",pproc,buff);
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
        //printf("%s\n", buff);

        fclose(fp);
        cmp = strcmp("0",buff);

        if(strcmp(pproc,buff)==0){
              res = true;
              //printf("=====ok=====\n");
	}

   }while(cmp!=0);

   return res;
}

int main(int argc, char *argv[])
{   
   char pproc[255];
   strcpy(pproc,argv[1]);

   DIR *pDIR;
   struct dirent *entry;
   int cnt=0;

   if( pDIR=opendir("/proc") ){
        while(entry = readdir(pDIR)){
                if( strcmp(entry->d_name, ".") != 0 &&
                    strcmp(entry->d_name, "..") != 0 &&
                    isdigit(entry->d_name[0]) ){
                        if(is_parent(pproc,entry->d_name)) cnt++;
                }
        }
        closedir(pDIR);
   }
   printf("%d\n",cnt+1);

   return 0;
}
