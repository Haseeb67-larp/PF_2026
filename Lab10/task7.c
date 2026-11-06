#include<stdio.h>
#include<string.h>
int main(){
	FILE *fp=fopen("students.txt", "w");
	if(fp==NULL){
		printf("Error opening file for writing.\n");
		return 1;
	}
	char name[50];
	printf("Enter 3 student names:\n");
	for(int i=0; i<3; i++){
		scanf("%49s", name);
		fprintf(fp, "%s\n", name);
	}
	fclose(fp);
	fp=fopen("students.txt", "r");
	if(fp==NULL){
		printf("Error opening file for reading.\n");
		return 1;
	}
	printf("\nNames read from students.txt:\n");
	int count=0;
	while(fscanf(fp, "%49s", name)==1){
		count++;
		printf("%d. %s\n", count, name);
	}
	fclose(fp);
	printf("Total students in file: %d\n", count);
	return 0;
}
