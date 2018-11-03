#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define SEED 51234567



double count;
double x,y;
double pi;

double drand();
void *runner(void *param);


int main(int argc, char *argv[])
{

x=drand();
y=drand();


	pthread_t tid; 
	pthread_attr_t attr; 

	char v[]="51234567";
	
	pthread_attr_init(&attr);
	
	pthread_create(&tid,&attr,runner,v);
	
	pthread_join(tid,NULL);

	
	pi=4*count/(double)atoi(v);
	printf("Pi = %f\n",pi);

return 0;
}

void *runner(void *param)
{
	int i, upper = atoi(param);
	count = 0;
	srand(SEED);
	for (i = 1; i <= upper; i++){
	if(sqrt(x*x+y*y)<1.0){
	count ++;
	
	
	x=drand();
	y=drand();
	}
	else{

	x=drand();
	y=drand();
	}	
	}
	pthread_exit(0);
}
double drand(){
return rand()/((double)RAND_MAX+1);
}
