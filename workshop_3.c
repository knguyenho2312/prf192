#include <stdio.h>

#define MAX_SIZE 100

void inputArray(int arr[], int *size);
void displayArray(int arr[], int size);
int searchValue(int arr[], int size, int target);
void calculateStatistics(int arr[], int size);

int main(){
	int arr[MAX_SIZE], size = 0, target, index, choice;
	
	do{
		printf("\n--- Menu ---\n");
		printf("1. Input Data\n");
		printf("2. Display Array\n");
		printf("3. Search for a number\n");
		printf("4. Calculate statistics (Sum, Average, Max, Min)\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				inputArray(arr, &size);
				break;
			case 2:
				if(size > 0){
					displayArray(arr, size);
				}else{
					printf("No data to display. Please input data first.\n");
				}
				break;
			case 3:
				if(size > 0){
					printf("Enter the number u want to search for: ");
					scanf("%d", &target);
					index = searchValue(arr, size, target);
					if(index == -1){
						printf("The number %d is not found in the array.\n", target);
					}
					else{
						printf("The number %d is found at index %d.\n", target, index);
					}
				}else{
					printf("No data available to search. Please input data first.\n");
				}
				break;
			case 4:
				if(size > 0){
					calculateStatistics(arr, size);
				}else{
					printf("No data available to calculate statistics. Please input data first.\n");
				}
			case 5:
				printf("\nExitting the program.\n");
				break;
			default:
				printf("Invalid choice. Please try again.\n");
		}
	} while (choice != 5);
	return 0;
}
void inputArray(int arr[], int *size){
	printf("Enter the number of elements (1-100): ");
	scanf("%d", size);
	while(*size < 1 || *size > MAX_SIZE){
		printf("Invalid size! Please enter the number between 1 and 100");
		printf("Enter the number of elements (1-100): ");
		scanf("%d", size);
	}
	printf("Enter %d numbers: ", *size);
	for(int i = 0; i < *size ; i++)
	{
		printf("\nNumber %d: ", i+1);
		scanf("%d", &arr[i]);
	}
}

void displayArray(int arr[], int size){
	printf("\nArray elements:\n");
	for(int i = 0; i < size; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int searchValue(int arr[], int size, int target){
	for(int i = 0; i < size; i++){
		if(arr[i] == target){
			return i;
		}
	}
}

void calculateStatistics(int arr[], int size){
	int sum = 0, min = arr[0], max = arr[0];
	float avg;
	for(int i = 0; i < size; i++){
		sum += arr[i];
		avg = (float)sum/i;				
		if(arr[i] > max){
			max = arr[i];
		}else if(arr[i] < min){
			min = arr[i];
		}
	}
	printf("Sum: %d\n", sum);
    printf("Avg: %.2f\n", avg);
    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);
}


