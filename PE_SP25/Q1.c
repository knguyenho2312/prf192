#include <stdio.h>
#include <stdlib.h>

void convertToFahrenheit(float c)
{
	// Write your statements here
	//The output result is formatted in two decimal places
	float f = 0;
	f = c * 9/5 + 32;
	printf("%0.2f", f); 
    // End your statements  
}
//=============DO NOT ADD NEW OR CHANGE STATEMENTS IN THE MAIN FUNCTION=============
int main()
{
	system("cls");
	printf("\nTEST Q1 (2 marks):\n");
	float celsius;
	printf("Enter the temperature in Celsius: ");
	scanf("%f", &celsius);	
	printf("\nOUTPUT:\n");
	convertToFahrenheit(celsius);
	printf("\n");
	system ("pause");
	return 0;
}
//=================================================================================
