#include <stdio.h>
#include <stdlib.h>

float inputSalary();
float calculateAllowance(float basic_salary);
float calculateTax(float total_income);
float calculateNetIncome(float basic_salary, float allowance, float tax);

int main() {
	int num_employees;
	float total_salary_cost = 0;
	int count_25 = 0, count_15 = 0, count_10 = 0;
	
	printf("\nEnter the number of employees: "); //step 2
	scanf("%d", &num_employees);
	while(num_employees < 1){
		exit(0);
	}
	for(int i = 0; i < num_employees; i++){
		printf("\nProcessing employee %d:\n", i+1);
		
		float basic_salary = inputSalary();
		float allowance = calculateAllowance(basic_salary);
		
		if(basic_salary <= 6000000){
			count_25++;
		}
		else if(basic_salary <= 15000000){
			count_15++;
		}
		else{
			count_10++;
		}
		float total_income = basic_salary + allowance;
		float tax = calculateTax(total_income);
		float net_income = calculateNetIncome(basic_salary, allowance, tax);
		total_salary_cost += net_income;
		
		printf("\nBasic salary: %0.2f\n", basic_salary);
		printf("Allowance: %0.2f\n", allowance);
		printf("Total Income: %0.2f\n", total_income);
		printf("Tax Deduction: %0.2f\n", tax);
		printf("Net Income: %0.2f\n", net_income);
	}
	
	printf("\n=== Salary Statistic ===\n");
	printf("\nTotal salary cost of the company: %0.2f", total_salary_cost);
	printf("\nNumber of employees with allowance of 25%: %d\n", count_25);
	printf("Number of employees with allowance of 15%: %d\n", count_15);
	printf("Number of employees with allowance of 10%: %d\n", count_10);
	
	system("pause");
	return 0;	
}

float inputSalary(){
	float salary;
	printf("\nEnter the basic salary (>= 0): ");
	scanf("%f", &salary);
	while(salary < 0){
		printf("\nInvalid salary. Please enter a non-negative value.\n");
		printf("Enter the basic salary (>= 0): ");
		scanf("%f", &salary);
	}
	return salary;
}

float calculateAllowance(float basic_salary){
	if(basic_salary <= 6000000){
		return basic_salary * 0.25;
	}
	else if(basic_salary <= 15000000){
		return basic_salary * 0.15;
	}
	else{
		return basic_salary * 0.1;
	}
}

float calculateTax(float total_income){
	if(total_income <= 8000000){
		return 0;
	}
	else{
		return (total_income - 8000000) * 0.1;
	}
}

float calculateNetIncome(float basic_salary, float allowance, float tax){
	return basic_salary + allowance - tax;
}

