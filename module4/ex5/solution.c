#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{ 

    pid_t pid,sid;

    pid = fork();

    //printf("-> %d     %d    %d\n",pid,getpid(),getppid());	
    
    if (pid>0){
    	//printf("exit parent %d  %d\n",pid,getpid());
	return 0;
    }

    chdir("/");
    sid = setsid();
    //printf("setsid()  %d\n",sid);

    umask(0);

    printf("%d\n",getpid());

    close (0);
    close (1);
    close (2);
   
    sleep(5);
    
    return 0;
}
