#include <stdio.h>
#include <stdlib.h>

#define MAX_DAYS 100

typedef struct {
	int sales[MAX_DAYS];
	int days[MAX_DAYS];
	int count;
} SalesData;


SalesData inputSales();
void displaySales(SalesData data);
SalesData sortAscending(SalesData data);
SalesData sortDescending(SalesData data);
void searchGreaterThan(SalesData data, int target);
	
int main() {
	SalesData data;
	int choice, target;

	do {
		printf("\n=== Enhanced Sales Data Management Menu ===\n");
		printf("1. Input Sales Data\n");
		printf("2. Displays Sales Data\n");
		printf("3. Display Sort Data in Ascending Order\n");
		printf("4. Display Sort Data in Descending Order\n");
		printf("5. Search for Sales Greater Than a Target\n");
		printf("6. Exit\n");
		printf("Enter ur choice: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				data = inputSales();
				break;
			case 2:
				displaySales(data);
				break;
			case 3:
				data = sortAscending(data);
				printf("Sales data sort in ascending order:\n");
				displaySales(data);
				break;
			case 4:
				data = sortDescending(data);
				printf("Sales data sort in descending order:\n");
				displaySales(data);
				break;
			case 5:
				printf("Enter the target sales value: ");
				scanf("%d", &target);
				searchGreaterThan(data, target);
				break;
			case 6:
				printf("Exiting the program.\n");
				break;
			default:
				printf("Invalid choice. Please try again.\n");
		}
	} while(choice != 6);
	return 0;
}

SalesData inputSales() {
	SalesData data;
	printf("Enter the number of days (0-100): ");
	scanf("%d", &data.count);
	while(data.count > MAX_DAYS || data.count < 1) {
		printf("Invalid number of days! Please try again.\n");
		printf("Enter the number of days (0-100): ");
		scanf("%d", &data.count);
	}
	printf("Enter sales data for %d days:\n", data.count);
	for(int i=0; i<data.count; i++) {
		printf("\nDay %d (Sales Value): ", i+1);
		scanf("%d", &data.sales[i]);
		data.days[i] = i + 1;
		
	}
	return data;
}

void displaySales(SalesData data) {
	if(data.count == 0){
		printf("There is no data to display");
		return;
	}
	printf("\nSales data\n");
	for(int i = 0; i < data.count; i++){
		printf("Day %d: %d\n", data.days[i], data.sales[i]);
	}
}

//both are bubble sort, suggest you goes to stackoverflow for better understanding

SalesData sortAscending(SalesData data) {
    for (int i = 0; i < data.count - 1; i++) {
        for (int j = 0; j < data.count - 1 - i; j++) {
            if (data.sales[j] > data.sales[j + 1]) {
            	
                int tempSales = data.sales[j];
                data.sales[j] = data.sales[j + 1];
                data.sales[j + 1] = tempSales;

                int tempDay = data.days[j];
                data.days[j] = data.days[j + 1];
                data.days[j + 1] = tempDay;
            }
        }
    }
    return data;
}

SalesData sortDescending(SalesData data) {
    for (int i = 0; i < data.count - 1; i++) {
        for (int j = 0; j < data.count - 1 - i; j++) {
            if (data.sales[j + 1] > data.sales[j]) {

                int tempSales = data.sales[j];
                data.sales[j] = data.sales[j + 1];
                data.sales[j + 1] = tempSales;
                
                int tempDay = data.days[j];
                data.days[j] = data.days[j + 1];
                data.days[j + 1] = tempDay;
            }
        }
    }
    return data;
}



void searchGreaterThan(SalesData data, int target) {
	printf("Sales value greater than %d:\n", target);
	for(int i = 0; i < data.count; i++){
		if(data.sales[i] > target){
			printf("Day %d: %d\n", data.days[i], data.sales[i]);
		}
	}
}
