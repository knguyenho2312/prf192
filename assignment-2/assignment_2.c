#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LEN 50
#define MAX_RECORDS 100

struct Student{
	int id;
	char firstName[MAX_NAME_LEN];
	char lastName[MAX_NAME_LEN];
	float gpa;
};

void addStudent(const char *filename);
void displayStudents(const char *filename);
void searchStudentById(const char *filename, int id);
void searchStudentByLastName(const char *filename, const char *lastName);
void sortStudentByLastName(const char *filename);


int checkStudentID(const char *filename, int id);

void clear(){
	while(getchar() != '\n');
}

int main(){
	const char *filename = "students.txt";
	int choice, id;
	char lastName[MAX_NAME_LEN];
	
	do {
		printf("\n===== Student Management System =====\n");
		printf("1. Add Student\n");
		printf("2. Search Student by ID\n");
		printf("3. Search Student by Last Name\n");
		printf("4. Sort and Display Student by Last Name\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		clear();
		
		switch (choice){
			case 1:
				addStudent(filename);
				break;
			case 2:
				printf("\nEnter student ID to search: ");
				scanf("%d", &id);
				searchStudentById(filename, id);
				break;
			case 3:
				printf("\nEnter last name to search: ");
				scanf("%49s", lastName);
				searchStudentByLastName(filename, lastName);
				break;
			case 4:
				sortStudentByLastName(filename);
				displayStudents(filename);
				break;
			case 5:
				printf("Exitting.....\n");
				break;
			default:
				printf("Invalid choice. Please try again\n");
		}
	}while(choice != 5);
	return 0;
}

int checkStudentID(const char *filename, int id){
	FILE *Fp;
	struct Student s;
	
	int studentID;
	Fp = fopen(filename, "r");
	if(Fp == NULL)return 0;
	
	while(fscanf(Fp, "%d", &s.id) == 1){
		if(s.id == id){
			fclose(Fp);
			return 1;
		}
	}
	fclose(Fp);
	return 0;
}

void addStudent(const char *filename){
	FILE *Fp;
	struct Student s;
	
	Fp = fopen(filename, "a");
	if(Fp == NULL){
		printf("Can't open file. The program will close.");
		exit(1); // exit 0 is terminated the program without error while exit 1 that have errors
	}
	do{
		printf("\nEnter student ID: ");
		scanf("%d", &s.id);
		if(checkStudentID(filename, s.id)){
			printf("This ID is already exists ! Please enter another ID.\n");
		}
	}while(checkStudentID(filename, s.id));
	
	clear();
	printf("Enter first name: ");
	scanf("%49s", s.firstName);
	printf("Enter last name: ");
	scanf("%49s", s.lastName);
	printf("Enter GPA: ");
	scanf("%f", &s.gpa);
	
	clear();
	
	fprintf(Fp, "%d,%s,%s,%.2f\n", s.id, s.firstName, s.lastName, s.gpa);
	
	fclose(Fp);
	printf("Student added successfully.\n");	
}

void searchStudentById(const char *filename, int id){
	FILE *Fp;
	struct Student s;
	int studentID, found = 0; //found is a flag to break the loop; 
	
	Fp = fopen(filename, "r");
	if(Fp == NULL){
		printf("Can't open file. The program will close.");
		exit(1);
	}
	while(fscanf(Fp,"%d,%49[^,],%49[^,],%f", &s.id, s.firstName, s.lastName, &s.gpa) == 4){
		if(s.id == id){
			printf("Student found:\n");
			printf("----------------------------------\n ");
			printf("ID: %d\nFirst Name: %s\nLast Name: %s\nGPA: %.2f\n", s.id, s.firstName, s.lastName, s.gpa);
			found = 1;
			break;
		}
	}
	if(found == 0){
		printf("There is no student with this ID %d\n", id);
	}
	
	fclose(Fp);
}

void searchStudentByLastName(const char *filename, const char *lastName){
	FILE *Fp; 
	struct Student s;
	int found = 0; //a flag
	
	Fp = fopen(filename, "r");
	if(Fp == NULL){
		printf("Can't open file. The program will close.");
		exit(1);
	}
	
	while(fscanf(Fp, "%d,%49[^,],%49[^,],%f", &s.id, s.firstName, s.lastName, &s.gpa) == 4){
		if(strcmp(s.lastName, lastName) == 0){
			printf("Student Found:\n");
			printf("----------------------------------\n");
			printf("ID: %d\nFirst Name: %s\nLast Name: %s\nGPA: %0.2f\n",s.id, s.firstName, s.lastName, s.gpa);
			found = 1;
		}
	}
	if(found == 0){
		printf("There is no student with this name %s ", lastName);
	}
	
	fclose(Fp);
}

void displayStudents(const char *filename){
	FILE *Fp;
	struct Student s;
	
	Fp = fopen(filename,"r");
	if(Fp == NULL){
			printf("Can't open file. The program will close.");
			exit(1);
	}
	
	printf("\nStudents Sorted by Last Name: \n");
    printf("-------------------------------------------------\n");
    printf("ID        First Name        Last Name       GPA\n");
    printf("-------------------------------------------------\n");
    
	while(fscanf(Fp, "%d,%[^,],%[^,],%f", &s.id, s.firstName, s.lastName, &s.gpa) == 4) {
        printf("%-10d %-15s %-15s %.2f\n", s.id, s.firstName, s.lastName, s.gpa);
    }		
    printf("-------------------------------------------------\n");
    
    fclose(Fp);
}

void sortStudentByLastName(const char *filename){
	FILE *Fp;
	struct Student students[MAX_RECORDS];
	int count = 0; 
	
	Fp = fopen(filename, "r");
	if(Fp == NULL){
		printf("Can't open file. The program will close.");
		exit(1);
	}
	
	while(fscanf(Fp, "%d,%[^,],%[^,],%f", &students[count].id, students[count].firstName, students[count].lastName, &students[count].gpa) == 4){
		count++;
	}		
	fclose(Fp);
	
	for(int i = 0; i < count - 1; i++){
		for(int j = 0; j < count - 1 - i; j++){
			if(strcmp(students[j+1].lastName, students[j].lastName) > 0){
				struct Student temp = students[j+1];
				students[j+1] = students[j];
				students[j] = temp; 
			}
		}
	}
	
	Fp = fopen(filename, "w");
	for(int i = 0; i < count; i++){
		fprintf(Fp, "%d,%s,%s,%.2f\n", students[i].id, students[i].firstName, students[i].lastName, students[i].gpa);
	}
	
	fclose(Fp);
}
