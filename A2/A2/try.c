#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char*argv[]){
if(argc==2&&atoi(argv[1])>0){

int num=atoi(argv[1]), b[2016];
b[0]=atoi(argv[1]);
int count=1;	
int pid;
pid =fork();
	
	while(num!=1){
	if(pid==0){
		if(num%2==0)
			num=num/2;
		else
			num=3*num+1;
			b[count]=num;
			count++;
		exit;	
	}
	else{
		wait(NULL);
	exit(0);
		}
	}

int i;
	for(i=0;i<count;i++)
		printf("%d ",b[i]);
		printf("\n");
	}
	else if(argc!=2)
	printf("Usage: %s <starting value>\n" ,argv[0]);
	else if(atoi(argv[1])<=0)
	printf("<starting value> Should be positive number \n" );
	else 
	printf("Invalid\n");


	
	return 0;
	
}
