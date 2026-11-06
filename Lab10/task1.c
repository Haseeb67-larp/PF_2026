#include<stdio.h>
#include<string.h>
int main(){
	char name[100];
	char copyName[100];
	printf("Enter your name: ");
	if(fgets(name, sizeof(name), stdin)!=NULL){
		int len=strlen(name);
		if(len>0 && name[len-1]=='\n'){
			name[len-1]='\0';
			len--;
		}
		printf("Length of name: %d\n", len);
		strcpy(copyName, name);
		printf("Copied name: %s\n", copyName);
		printf("sizeof(name): %zu bytes\n", sizeof(name));
		printf("strlen(name): %zu characters\n", strlen(name));
	}
	return 0;
}
