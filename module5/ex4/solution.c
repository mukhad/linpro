#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdbool.h>

bool ex = false;

void sig_ex(int signo){
	ex = true;
}

int main(int argc, char *argv[])
{ 

    pid_t pid,sid;
    pid = fork();
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
   
	signal(SIGURG,sig_ex);
	while(1){
  	    if(ex) break;	
            sleep(1);
	}
    
    return 0;
}
