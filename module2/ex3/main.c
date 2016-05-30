#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#define dd 0


int main (int argc, char *argv[]){

	const char* short_options = "q:iv";

	const struct option long_options[] = {
		{"query",required_argument,NULL,'q'},
		{"longinformationrequest",optional_argument,NULL,'i'},
		{"version",optional_argument,NULL,'v'},
		{NULL,0,NULL,0}
	};

	int rez;
	int option_index;
	char s = '-';

	if ((rez=getopt_long(argc,argv,short_options,
		long_options,&option_index))!=-1){

	if(dd) printf("%d\n",rez);

	switch(rez){
		case 'q':	s = '+';
				if(dd) printf("query ok %s\n",optarg);
				break;			
		case 'i':	s = '+'; 
				break;
		case 'v': 	s = '+';
				break;
		case '?': default: 
				s = '-';
				break;
	}
	}		
	printf("%c\n",s);		
	
	return 0;
}
