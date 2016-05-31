#include <stdio.h>
#include <string.h>
#include <dirent.h>

int main() {
   char key[] = "PPid:";
   FILE *fp;
   char buff[255];

   DIR *pDIR;
   struct dirent *entry;
   int cnt=0;

   if( pDIR=opendir("/proc") ){
        while(entry = readdir(pDIR)){
                if( strcmp(entry->d_name, ".") != 0 && 
                    strcmp(entry->d_name, "..") != 0 &&
                    isdigit(entry->d_name[0]) ){
   			char fname[255]={0};	
			strcat(fname,"/proc/");
			strcat(fname,entry->d_name);     
			strcat(fname,"/status");
			
   		fp = fopen(fname, "r");
		int i = 1;
		if(fp == NULL) i = 0;
   
     		fscanf(fp, "%s", buff);
     		fscanf(fp, "%s", buff);

                int c = strcmp("genenv",buff);	
		if(c==0) cnt++;
 		 
		printf("%s   %d   %s   %s\n ",entry->d_name,i,fname,buff);


		fclose(fp);
        	}     
	}
        closedir(pDIR);
   }
   printf("%d\n",cnt);

   return 0;
}
