#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define UTOL 'A'-'a'

int isletter(char ch){
	if((ch >='A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')){
		return 1;
	}else{
		return 0;
	}
}

int isequal(char ch1, char ch2){
	
	if(ch1==ch2 || ch1==ch2+UTOL || ch1==ch2-UTOL){
		return 1;
	}else{
		return 0;
	}
}

int main(int argc, char * argv[]){
	FILE * fp;
	char c;
	char s[90000], s1[20];
	int i,j;
	int count=0;

	fp=fopen(argv[1], "r");
	if(fp==NULL){
		exit(0);
	}
	
	while(fgets(s1,sizeof(s1),fp)!=NULL){
		//fgets(s1,sizeof(s1),fp);
		strcat(s,s1);

	}
	fclose(fp);

	for(i=0;i<sizeof(s);i++){
		if(isequal(s[i],argv[2][0])){
			for(j=0;j<(strlen(argv[2]));j++){
				if(!isequal(s[i+j],argv[2][j])){
					break;
				}
			}
			if(j==(strlen(argv[2]))&&!isletter(s[i+j])){
				count++;
			}
		}
	}
	printf("The number is %d\n",count);
}
