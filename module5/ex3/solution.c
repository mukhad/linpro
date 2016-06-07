#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdbool.h>

int ex = false;
int sig1 = 0;
int sig2 = 0;

void sig_usr1(int signo){
	sig1++;
}
void sig_usr2(int signo){
	sig2++;
}
void sig_ex(int signo){
	printf("%d %d\n",sig1,sig2);
	ex = true;
}
int main(int argc, char *argv[])
{ 

	signal(SIGUSR1,sig_usr1);
	signal(SIGUSR2,sig_usr2);
	signal(SIGTERM,sig_ex);
	while(1){
  	    if(ex) break;	
            sleep(1);
	}
    
    return 0;
}
