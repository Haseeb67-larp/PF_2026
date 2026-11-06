#include<stdio.h>
#include<string.h>
int main(){
	char sentence[200];
	printf("Enter a sentence: ");
	if(fgets(sentence, sizeof(sentence), stdin)!=NULL){
		int len=strlen(sentence);
		if(len>0 && sentence[len-1]=='\n'){
			sentence[len-1]='\0';
		}
		char *p=strchr(sentence, 'a');
		if(p!=NULL){
			printf("First 'a' found at index %ld\n", (long)(p-sentence));
		}else{
			printf("'a' not found in sentence.\n");
		}
		if(strstr(sentence, "good")!=NULL){
			printf("Word 'good' found.\n");
		}else{
			printf("Word 'good' not found.\n");
		}
	}
	return 0;
}
