#include<stdio.h>
#include<string.h>
#define MAX 50

struct movie{
	char title[50];
	char genre[30];
	char director[30];
	int year;
	float rating;
};

void addMovie(struct movie m[], int *count){
	if(*count>=MAX){
		printf("Movie list is full.\n");
		return;
	}
	printf("Enter movie title:\n");
	scanf(" %[^\n]", m[*count].title);
	printf("Enter movie genre:\n");
	scanf(" %[^\n]", m[*count].genre);
	printf("Enter Director:\n");
	scanf(" %[^\n]", m[*count].director);
	printf("Enter Release Year:\n");
	scanf("%d", &m[*count].year);
	printf("Enter Rating:\n");
	scanf("%f", &m[*count].rating);
	
	(*count)++;
	printf("Movie added successfully.\n");
}

void searchByGenre(struct movie m[], int count){
	char searchGenre[30];
	int found=0, i;
	
	printf("Search Genre:\n");
	scanf(" %[^\n]", searchGenre);
	
	for(i=0;i<count;i++){
		if(strcmp(m[i].genre, searchGenre)==0){
			printf("Title:%s | Director:%s | Year:%d | Rating:%.1f\n", m[i].title, m[i].director, m[i].year, m[i].rating);
			found=1;
		}
	}
	if(found==0){
		printf("No movies of this genre.\n");
	}
}

void displayMovies(struct movie m[], int count){
	int i;
	for(i=0;i<count;i++){
		printf("Title:%s | Genre:%s | Director:%s | Year:%d | Rating:%.1f\n", m[i].title, m[i].genre, m[i].director, m[i].year, m[i].rating);
	}
}

int main(){
	struct movie movies[MAX]={
		{"Inception", "Sci-Fi", "Christopher Nolan", 2010, 8.8},
		{"The Godfather", "Crime", "Francis Ford Coppola", 1972, 9.2},
		{"Interstellar", "Sci-Fi", "Christopher Nolan", 2014, 8.7}
	};
	int count=3;
	int choice;
	
	while(1){
		printf("\n--- Movie Management System ---\n");
		printf("1. Add New Movie\n");
		printf("2. Search Movies by Genre\n");
		printf("3. Display All Movies\n");
		printf("4. Exit\n");
		printf("Enter your choice:\n");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				addMovie(movies, &count);
				break;
				
			case 2:
				searchByGenre(movies, count);
				break;
				
			case 3:
				displayMovies(movies, count);
				break;
				
			case 4:
				return 0;
				
			default:
				printf("Invalid Choice.\n");
		}
	}
	return 0;
}
