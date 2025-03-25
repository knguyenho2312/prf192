#include <stdio.h>
#include <stdlib.h>
//-----------------------------------------------
double calculateS(int n) {
	//Begin your codes here=====================
	double sum = 0;
	int i = 1;
    while(i <= n)
    {
        sum = sum + 1.0 / i; 
        i++;
    }
	return sum;
	//End your codes============================
}
//====DO NOT ADD NEW OR CHANGE STATEMENTS IN THE MAIN FUNCTION====
int main() {
	system("cls");
	printf("\nTEST Q2 (3 marks):\n");
	int n;
	double sum;
	do {
		printf("Enter n = ");
		scanf("%d",&n);
	} while(n<=0);
	printf("\nOUTPUT:\n");
	sum = calculateS(n);
	printf("%.2lf",sum);
	printf("\n");
	system ("pause");
	return(0);

}
//===============================================================

