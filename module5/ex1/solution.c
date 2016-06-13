#include <string.h>
#include <stdio.h>

FILE *fp;

int main(int argc, char *argv[])
{ 
    int status;
    int c,cnt = 0;
    char path[128];
    
    strcat(path,argv[1]);
    strcat(path," ");
    strcat(path,argv[2]);

	printf("%s\n",path);

    fp = popen(path, "r");
    if(fp == NULL) return 0;
    
    do
    {
      c = fgetc(fp);
      if (c == '0') cnt++;
    } while (c != EOF);


    pclose(fp);
    
    printf("%d\n", cnt);

    return 0;
}
