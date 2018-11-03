#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
	 
	void *avg_func(void *str);
	void *min_func(void *ptr);
	void *max_func(void *ptr);
	
	double avg; 
	int min;
	int max;
	
		typedef struct datastruct
		{
		 int size;
	 	int * values;
		}datastruct;
	
			main(int argc, char *argv[])
			{
			
	 		while(argc <=1)
	 		{
	 		
	 		printf("Please enter one or more inputs.\n");
	 		exit(0);
			}
	 
	 int m = 0;
	 int copy[argc-1];
	 for(m; m < (argc -1); m++)
	 {
	 copy[m] = atoi(argv[m+1]);
	 }
	 
	 pthread_t thread1, thread2, thread3;
	 const char *message1 = "This is Thread 1";
	 const char *message2 = "This is Thread 2";
	 const char *message3 = "This is Thread 3";
	 int t1, t2, t3;
	 
	 
	 
	 datastruct ds = {argc - 1, copy};
	 
	 
	 t1 = pthread_create(&thread1, NULL, (void *) avg_func, (void *) &ds);
	 if(t1)
	 {
	 
	 exit(EXIT_FAILURE);
	 }
	 
	 t2 = pthread_create(&thread2, NULL, (void *) min_func, (void *) &ds);
	 if(t2)
	 {
	 
	 exit(EXIT_FAILURE);
	 }
	 
	 t3 = pthread_create(&thread3, NULL, (void *) max_func, (void *) &ds);
	 if(t3)
	 {
	 
	 exit(EXIT_FAILURE);
	 }
	 
	
	 
	
	 
	 pthread_join(thread1, NULL);
	 pthread_join(thread2, NULL);
	 pthread_join(thread3, NULL);
	 
	 printf("The average: %g\n", avg);
	 printf("The minimum: %d\n", min);
	 printf("The maximum: %d\n", max);
	 
	 exit(EXIT_SUCCESS);
	}
	 
	void *avg_func(void *ptr)
	{
	 datastruct * copy;
	 copy = (datastruct *) ptr;
	 
	 int sz = copy->size;
	 int m;
	 
	 for(m = 0; m < sz; m++)
	 {
	 avg += (copy->values[m]); 
	 } 
	 avg = (int)(avg / sz); 
	}
	
	void *min_func(void *ptr)
	{
	 datastruct * copy;
	 copy = (datastruct *) ptr;
	 
	 int sz = copy->size;
	 int m;
	 
	 min = (copy->values[0]);
	 for(m = 1; m < sz; m++)
	 {
	 if(min > (copy->values[m]))
	 {
	 min = (copy->values[m]);
	 }
	 }
	}
	
	void *max_func(void *ptr)
	{
	 datastruct * copy;
	 copy = (datastruct *) ptr;
	 
	 int sz = copy->size;
	 int m;
	 
	 max = copy->values[0];
	 
	 for(m = 1; m < sz; m++)
	 {
	 if(max < copy->values[m])
	 {
	 max = copy->values[m];
	 }
	 }
	}
