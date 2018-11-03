#include <stdio.h>
#include <stdlib.h>


int main(int argc, char*argv[]){
	if(argc==3 && strcmp(argv[1],"input.txt")==0 && strcmp(argv[2],"output.txt")==0){
	
	
FILE *in;
FILE *out;
char c[25];
int count=0;
char d[25];
int *ptr;
int value;
ptr = malloc(sizeof(int));
int fsize;

in = fopen (argv[1],"r");
if(!fin){
printf("False");	
return 1;
	}

int y=0;
while(fscanf(in,"%d ",&value)==1){
	ptr[y] =value;
	y++;
	}
	
	
	fclose(in);
	
	int m, n, token;
	for(m=0;m<y;m++){
	for (n=m+1;n<y;n++){
		if(ptr[m]>ptr[n]){
		token=ptr[n];
		ptr[m]=ptr[n];
		ptr[n]=token;
	}
	}
	}
	
	printf("The integers in file input.txt after sorting: \n");
	
	out = fopen (argv[2],"w");
	for(m=0;m<y;m++){
	fprintf(out,"%d ",ptr[m]);
	}
	fclose(out);
	out = fopen (argv[2],"r");
	while(fgets(d,25,out)!=NULL){
	printf("%s\n",d);		
	}
	free(ptr);
	}
		
	else{
	printf("\n%s \n%s \n",argv[1],argv[2]);
	printf("Please provide the input and output text file names as %s input.txt output.txt \n", argv[0]);
	}
	
	

	return 0;
	
}
