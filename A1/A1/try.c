#include <stdio.h>
#include <stdlib.h>


int main(int argc, char*argv[]){
	if(argc==3 && strcmp(argv[1],"input.txt")==0 && strcmp(argv[2],"output.txt")==0){
	
	
	FILE *in;
	FILE *out;
	char c[25];
	char d[25];
	
	

	in = fopen (argv[1],"r");
	out = fopen (argv[2],"w");
	if(!in){
	printf("The file cannot be initiated ");	
	return 1;
	}
	if(!out){
	printf("The file cannot be initiated");	
	return 1;
	}
	
	while(fgets(c,25,in)!=NULL){
	fprintf(out,"%s",c);
	}
	fclose(in);

	fclose(out);
	printf("The integers on file output.txt are: \n");	
	out = fopen (argv[2],"r");
	while(fgets(d,25,out)!=NULL){
	printf("%s",d);		
	}
	
	}
		
	else{
	printf("\n%s \n%s \n",argv[1],argv[2]);
	printf("Please provide the input and output text file names as %s input.txt output.txt \n", argv[0]);
	}
	


	return 0;
	
}
