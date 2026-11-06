#include<stdio.h>
#include<string.h>
int main(){
	char secretPassword[]="lab10pass";
	char userInput[100];
	printf("Enter password: ");
	if(scanf("%99s", userInput)==1){
		if(strcmp(userInput, secretPassword)==0){
			printf("Access granted\n");
		}else{
			printf("Access denied\n");
		}
		if(strncmp(userInput, secretPassword, 3)==0){
			printf("First 3 characters match.\n");
		}else{
			printf("First 3 characters do not match.\n");
		}
	}
	return 0;
}
