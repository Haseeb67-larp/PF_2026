#include<stdio.h>
#include<string.h>
#define MAX_FLIGHTS 3
struct flight{
	int number;
	char departure[30];
	char destination[30];
	char date[15];
	int available;
};
void displayFlights(struct flight f[], int count);
void searchFlights(struct flight f[], int count);
void bookSeat(struct flight f[], int count);
void cancelSeat(struct flight f[], int count);

int main(){
	struct flight flights[MAX_FLIGHTS]={
		{101, "Hyderabad", "Islamabad", "10/02/2027", 12},
		{102, "Karachi", "Lahore", "11/02/2027", 5},
		{103, "Islamabad", "Karachi", "12/02/2027", 5}
	};
	int choice;
	
	while(1){
		printf("\n--- Flight Management System ---\n");
		printf("1. Display Flights\n");
		printf("2. Search Flights\n");
		printf("3. Book Seat\n");
		printf("4. Cancel Seat\n");
		printf("5. Exit\n");
		printf("Enter your choice:\n");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				displayFlights(flights, MAX_FLIGHTS);
				break;
				
			case 2:
				searchFlights(flights, MAX_FLIGHTS);
				break;
				
			case 3:
				bookSeat(flights, MAX_FLIGHTS);
				break;
				
			case 4:
				cancelSeat(flights, MAX_FLIGHTS);
				break;
				
			case 5:
				return 0;
				
			default:
				printf("Invalid Choice.\n");
		}
	}
	return 0;
}

void displayFlights(struct flight f[], int count){
	int i;
	for(i=0; i<count; i++){
		printf("Flight %d | From: %s | To: %s | Date: %s | Available Seats: %d\n", f[i].number, f[i].departure, f[i].destination, f[i].date, f[i].available);
	}
}

void searchFlights(struct flight f[], int count){
	char dep[30], dest[30];
	int found=0, i;
	
	printf("Enter Departure City:\n");
	scanf("%s", dep);
	printf("Enter Destination City:\n");
	scanf("%s", dest);
	
	for(i=0; i<count; i++){
		if(strcmp(f[i].departure, dep)==0 && strcmp(f[i].destination, dest)==0){
			printf("Flight %d | Date: %s | Available Seats: %d\n", f[i].number, f[i].date, f[i].available);
			found=1;
		}
	}
	if(found==0){
		printf("No flights");
	}
}

void bookSeat(struct flight f[], int count){
	int num, seats, found=0, i;
	
	printf("Enter Flight Number:\n");
	scanf("%d", &num);
	
	for(i=0; i<count; i++){
		if(f[i].number==num){
			found=1;
			printf("Enter number of seats to book:\n");
			scanf("%d", &seats);
			if(seats<=f[i].available && seats>0){
				f[i].available=f[i].available-seats;
				printf("Seat booked! Remaining seats: %d\n", f[i].available);
			}
			else{
				printf("Not enough seats available.\n");
			}
			break;
		}
	}
	if(found==0){
		printf("Flight not found.\n");
	}
}

void cancelSeat(struct flight f[], int count){
	int num, seats, found=0, i;
	
	printf("Enter Flight Number:\n");
	scanf("%d", &num);
	
	for(i=0; i<count; i++){
		if(f[i].number==num){
			found=1;
			printf("Enter number of seats to cancel:\n");
			scanf("%d", &seats);
			if(seats>0){
				f[i].available=f[i].available+seats;
				printf("Seat cancelled! Available seats: %d\n", f[i].available);
			}
			else{
				printf("Invalid seat count.\n");
			}
			break;
		}
	}
	if(found==0){
		printf("Flight not found.\n");
	}
}
