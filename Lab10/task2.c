#include<stdio.h>
#include<string.h>
int main(){
	char firstName[50];
	char lastName[50];
	char fullName[105]="";
	printf("Enter first name: ");
	scanf("%49s", firstName);
	printf("Enter last name: ");
	scanf("%49s", lastName);
	strcpy(fullName, firstName);
	strcat(fullName, " ");
	strcat(fullName, lastName);
	printf("Full name: %s\n", fullName);
	return 0;
}
