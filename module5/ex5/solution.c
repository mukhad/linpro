#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc, char **argv) {
   
   int *buf1, *buf2,*buf;
   int sz = 1000;

   key_t key=0,key1=0, key2=0;

   key1 = atoi(argv[1]);
   key2 = atoi(argv[2]);

   //printf("%d\n%d\n",key1,key2);
   
   int id1 = shmget(key1,sz,0660);
   buf1 = (int*)shmat(id1,NULL,0);

   int id2 = shmget(key2,sz,0660);
   buf2 = (int*)shmat(id2,NULL,0);

   int id = shmget(key,sz,0660|IPC_CREAT);
   buf = (int*)shmat(id,NULL,0);

   if(id<0 || id1<0 || id2<0) printf("shmget error\n");

   int i;
   
   for(i=0;i<100;i++){
	buf[i] = buf1[i]+buf2[i];
   }
 	
   shmdt(buf1);
   shmdt(buf2);

   printf("%d\n",key);
   return 0;
}
