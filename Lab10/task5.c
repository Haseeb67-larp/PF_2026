#include<stdio.h>
#include<string.h>
int main(){
	char cities[5][50];
	int longestIndex=0;
	int maxLength=0;
	for(int i=0; i<5; i++){
		printf("Enter city %d name: ", i+1);
		if(fgets(cities[i], sizeof(cities[i]), stdin)!=NULL){
			int len=strlen(cities[i]);
			if(len>0 && cities[i][len-1]=='\n'){
				cities[i][len-1]='\0';
			}
		}
	}
	printf("\nAll Cities:\n");
	for(int i=0; i<5; i++){
		printf("%d. %s\n", i+1, cities[i]);
		int currentLen=strlen(cities[i]);
		if(currentLen>maxLength){
			maxLength=currentLen;
			longestIndex=i;
		}
	}
	printf("\nLongest city name: %s (Length: %d)\n", cities[longestIndex], maxLength);
	return 0;
}
