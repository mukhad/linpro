#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

// Simple TCP server and client

struct sockaddr_in local;

void bubble(char *items, int count)
{
  register int a, b;
  register char t;

  for(a=1; a < count; ++a)
    for(b=count-1; b >= a; --b) {
      if(items[b-1] > items[b]) {
        /* exchange elements */
        t = items[b-1];
        items[b-1] = items[b];
        items[b] = t;
      }
    }
}

int server(int port){
    
    int s = socket(AF_INET,SOCK_STREAM,0);

    inet_aton("127.0.0.1",&local.sin_addr);
    local.sin_port = htons(port);
    local.sin_family = AF_INET;

    int res = bind(s, (struct sockaddr*)&local,sizeof local);
    listen(s,5);

    int cs = accept(s,NULL,NULL);

    //printf("server%d   socket%d  conn%d\n",port,s,res);

    char buf[BUFSIZ];

    while (1) {   
        int len = read(cs, buf, BUFSIZ);
        //buf[len] = '\0';
        if (strcmp(buf, "OFF") == 0)
            break;
        else{
            bubble(buf,strlen(buf));
            //printf("%s\n", buf);
	    write(cs,buf,strlen(buf)+1);
	}
    }
    close(cs);
   

   return 0;
}

int client(int port){
     
    int s = socket(AF_INET,SOCK_STREAM,0);

    inet_aton("127.0.0.1",&local.sin_addr);
    local.sin_port = htons(port);
    local.sin_family = AF_INET;

    int res = connect(s, (struct sockaddr*)&local,sizeof local);
    
    printf("client %d   socket%d  conn%d\n",port,s,res);

    char  buf[BUFSIZ];
    
    while(1){
	scanf("%s",buf); 
	int len = write(s,buf,strlen(buf)+1);
        
	int lenr = read(s, buf, BUFSIZ);
        
	printf("%s -> %d\n",buf,lenr);
        if (strcmp(buf, "OFF") == 0)
	     break;
    }
    close(s);
    printf("client closed\n"); 
    
    return 0;
} 

int main(int argc, char *argv[])
{ 
    int p = 12345;
    if(argc>1) p = atoi(argv[1]);
    
    //printf("port %d\n",p);

    if(argc>2){
	client(p);
    }
    else{
	server(p);
    }
    return 0;
}
