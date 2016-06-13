#include <fcntl.h>
#include <sys/select.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    int fds[2];
    char buf;
    int i,rc,maxfd; 
    int c, sum = 0;

    fds[0] = open("in1", O_RDONLY|O_NONBLOCK);
    fds[1] = open("in2", O_RDONLY|O_NONBLOCK);
    
    
    fd_set watchset;
    fd_set inset;

    FD_ZERO(&watchset);
    FD_SET(fds[0],&watchset);
    FD_SET(fds[1],&watchset);

    maxfd = fds[0] > fds[1]? fds[1] : fds[1];

    while(FD_ISSET(fds[0],&watchset) || FD_ISSET(fds[1],&watchset)){
	inset  = watchset;
	select(maxfd+1,&inset,NULL,NULL,NULL);

	for(i=0;i<2;i++){
	    if(FD_ISSET(fds[i],&inset)){
		rc = read(fds[i],&buf,sizeof(buf));
		if(!rc){
	 	    close(fds[i]);
		    FD_CLR(fds[i],&watchset);
		}
		else{
		    c = buf - '0';
                    sum += c;
		}
	    }
	}
   }
    
   printf("%d\n", sum);

    return 0;
}
