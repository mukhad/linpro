#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

struct sockaddr_in local;

int main(int argc, char *argv[])
{ 
    int p = 12345;
    if(argc>1) p = atoi(argv[1]);
    int s = socket(AF_INET,SOCK_DGRAM,0);

    inet_aton("127.0.0.1",&local.sin_addr);
    local.sin_port = htons(p);
    local.sin_family = AF_INET;

    int res = bind(s, (struct sockaddr*)&local,sizeof local);

    printf("port %d   socket  %d;   bind   %d\n",p , s , res);

    char buf[BUFSIZ];

    while (1) {   
        int len = read(s, buf, BUFSIZ);
        buf[len] = '\0';
        if (strcmp(buf, "OFF\n") == 0)
            break;
        else
            printf("%s\n", buf);
    }
    return 0;
}
