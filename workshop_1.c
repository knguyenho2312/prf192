#include <stdio.h>
#include <stdlib.h>


int main(){
	int pass = 0, fail = 0, n, tong = 0;
	float avg; 
	printf("Enter the number of student (>= 1): ");
	scanf("%d", &n);
	while(n < 1){
		printf("\nInvalid number of students. Please try again");
		printf("\nEnter the number of student (>=1): ");
		scanf("%d", &n);
	}
	int score[n]; //i have no idea how can i store student score by using other method beside Array 
	for(int i = 0; i < n; i++){
		printf("\nEnter the score for student %d (0-10): ", i+1);
		scanf("%d", &score[i]);
		while(score[i] < 0 || score[i] > 10){
			printf("\nInvalid score. Please try again");
			printf("\nEnter the score for student %d (0-10): ", i+1);
			scanf("%d", &score[i]);
		}
		tong += score[i];
       }
	avg = (float)tong / n;
	for(int i = 0; i < n; i++){
		if(score[i] >= 5){
			pass++; 
		}
		else{
			fail++;
		}
	}
	printf("\nStatistic: ");
	printf("\nTotal score of the class: %d", tong);
	printf("\nAverage score of the class: %0.2f", avg);
	printf("\nNumber of students who passed (>=5): %d", pass);
	printf("\nNumber of students who failed (< 5): %d\n", fail);
	
	system("pause");
	return 0;
}
