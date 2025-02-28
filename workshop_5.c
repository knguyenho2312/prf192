//in order to run workshop 5 normally without changing anything, you have to put data file, result file and workshop 5 on the same folder//

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int readFileToArray(const char *filename, int arr[], int *size);
void displayArray(int arr[], int size);
void calculateStatistics(int arr[], int *size, float *avg, int *sum, int *max, int *min);
void writeResultToFile(const char *filename, float avg, int sum, int max, int min);
	
int main(){
	int arr[MAX_SIZE], size = 0;
	int sum = 0, max = 0, min = 0;
	float avg;
	if (readFileToArray("data.txt", arr, &size) == 0) {
   		printf("No data found in file.\n");
    	return 1;
    }
    displayArray(arr, size);
    
    calculateStatistics(arr, &size, &avg, &sum, &max, &min);
        
    writeResultToFile("results.txt", avg, sum, max, min);
    
	return 0;
}


int readFileToArray(const char *filename, int arr[], int *size){
	FILE *Fp;
	
	Fp = fopen("data.txt", "r");
	if(Fp == NULL){
		printf("Cannot read data from this file. The program will close.\n");
		exit(0);
	}
	while(fscanf(Fp, "%d", &arr[*size]) == 1){
		(*size)++;
		if(*size >= MAX_SIZE){
			break;
		}
	}
	fclose(Fp);
	return *size;
	
}
void displayArray(int arr[], int size){
	printf("Data in the array\n");
	for(int i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void calculateStatistics(int arr[], int *size, float *avg, int *sum, int *max, int *min){
	*sum = 0;
	*max = arr[0];
	*min = arr[0];

	for(int i = 0; i < *size; i++){
		*sum += arr[i];
		
		if(arr[i] > *max){
			*max = arr[i];
		}else if(arr[i] < *min){
			*min = arr[i];
		}
	}
	*avg = (float)(*sum) / *size;
	
	printf("\nStatistic\n");
	printf("Sum: %d\n", *sum);
	printf("Avg: %0.2f\n", *avg);
	printf("Max: %d\n", *max);
	printf("Min: %d\n", *min);
}

void writeResultToFile(const char *filename, float avg, int sum, int max, int min){
	FILE *Fp;
	Fp = fopen("results.txt", "w");
	if(Fp == NULL){
		printf("Cannot write data to the file. The program will close.\n");
		exit(1);
	}
	fprintf(Fp, "Sum: %d\n", sum);
	fprintf(Fp, "Avg: %0.2f\n", avg);
	fprintf(Fp, "Min: %d\n", min);
	fprintf(Fp, "Max: %d\n", max);
	
	fclose(Fp);
	printf("Results written to result.txt");
}

