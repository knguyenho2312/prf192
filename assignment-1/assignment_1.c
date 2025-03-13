#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product{
	int product_id;
	char product_name[50];
	float price;
	int quantity;
};

void writeProducts(const char *filename, int numProducts);
void appendProducts(const char *filename, int numProducts);
void readProducts(const char *filename);
void modifyProducts(const char *filename);

//2 function below was added by myself
int findproductID(const char *filename, int ID, struct Product *foundProduct);
int checkproductID(const char *filename, int ID);

int main(){
	const char *filename ="products.bin";
	int choice, numProducts;
	
	do{
		printf("\n-- Product Management System --\n");
		printf("1. Write Products\n");
		printf("2. Append Products\n");
		printf("3. Read Products\n");
		printf("4. Modify Products\n");
		printf("5. Exit\n");
		printf("Please enter your choice: ");
		scanf("%d", &choice);
		
		
		switch(choice){
			case 1:
				printf("Enter the number of products to write: ");
				scanf("%d", &numProducts);
				while(numProducts < 0){
					printf("Invalid number of products. Please try again\n");
					printf("Enter the number of products to write: ");
					scanf("%d", &numProducts);}
				writeProducts(filename, numProducts);
				break;
			case 2:
				printf("Enter the number of products to append: ");
				scanf("%d", &numProducts);
				appendProducts(filename, numProducts);
				break;
			case 3:
				readProducts(filename);
				break;
			case 4:
				modifyProducts(filename);
				break;
			case 5:
				printf("Exitting...\n");
				break;
			default:
				printf("Invalid choice. Please try again.\n");
		}
	}while(choice != 5);
	
	return 0;
}

//for append product
int checkproductID(const char *filename ,int ID){
	FILE *Fp;
	struct Product product;
	Fp = fopen(filename, "rb");
	
	if(Fp == NULL)return 0;
	
	while(fread(&product, sizeof(struct Product), 1, Fp)){
		if(product.product_id == ID){
			fclose(Fp);
			return 1;
		}
	}
	fclose(Fp);
	return 0;
}

//for modify product
int findproductID(const char *filename, int ID, struct Product *foundProduct){
	FILE *Fp;
	struct Product product;
	Fp = fopen(filename, "rb");
	
	if(Fp == NULL)return 0;
	
	while(fread(&product, sizeof(struct Product), 1, Fp)){
		if(product.product_id == ID){
			*foundProduct = product; //copy product data in order to modify them
			fclose(Fp);
			return 1;
		}
	}
	fclose(Fp);
	return 0;
}

void writeProducts(const char *filename, int numProducts){
	FILE *Fp;
	struct Product product;
	
	Fp = fopen(filename, "wb");
	if(Fp == NULL){
		printf("Error opening file");
		exit(1);
	}
	
	for(int i = 0; i < numProducts; i++){
		printf("\nPlease enter detail for product %d\n", i+1);
		
		printf("Product ID: ");
		scanf("%d", &product.product_id);
		
		printf("Product Name: ");
		scanf(" %[^\n]s", product.product_name);
		
		printf("Price: ");
		scanf("%f", &product.price);
		//check value
		while(product.price < 0){
			printf("Invalid price of product. Please enter a non-negative value");
			printf("Price: ");
			scanf("%f", &product.price);
		}
		
		printf("Quantity: ");
		scanf("%d", &product.quantity);
		//check value
		while(product.quantity < 0){
			printf("Invalid quantity of products. Please try again");
			printf("Quantity: ");
			scanf("%d", &product.quantity);
		}
		
		fwrite(&product, sizeof(struct Product), 1, Fp);
	}
	fclose(Fp);
	printf("\nProducts have been written to the file successfully.\n");
}

void appendProducts(const char *filename, int numProducts){
	FILE *Fp;
	struct Product product;
	Fp = fopen(filename, "ab+");
	
	
	if(Fp == NULL){
		printf("Error opening file\n");
		exit(0);
	}
	
	for(int i = 0; i < numProducts; i++){
		int valid = 0; //a flag to check product ID 
		
		printf("Enter detail for product %d\n", i+1);
		while(valid == 0){
			printf("Enter product ID: ");
			scanf("%d", &product.product_id);
			if(checkproductID(filename, product.product_id)){
				printf("Product ID already exist! Please enter a different one\n");
			}else{
				valid = 1;
			}
		}
		printf("Enter product name: ");
		scanf(" %[^\n]s", product.product_name);
	
		printf("Enter product price: ");
		scanf("%f", &product.price);
		while(product.price < 0){
			printf("Error product price. Please enter a non-negative value\n");
			printf("Enter product price: ");
			scanf("%f", &product.price);
		}
	
		printf("Enter quantity: ");
		scanf("%d", &product.quantity);
		while(product.quantity < 0){
			printf("Error product quantity. Please enter a non-negative value\n");
			printf("Enter quantity: ");
			scanf("%d", &product.quantity);	
		}
		fwrite(&product, sizeof(struct Product), 1, Fp);
	}
	fclose(Fp);
	printf("\nProducts have been appended to the file successfully.\n");
}


void readProducts(const char *filename){
	FILE *Fp;
	struct Product p;
	
	Fp = fopen(filename, "rb");
	if(Fp == NULL){
		printf("Cannot read data from this file. The program will close\n");
		exit(0);
	}
	
	printf("\nReading products from file:\n");
	printf("-----------------------------------------------------\n");
	printf("Product ID      Product Name        Price    Quantity\n");
	printf("-----------------------------------------------------\n");
	
	while(fread(&p, sizeof(struct Product), 1, Fp)){
		printf("%-15d %-20s %-8.2f %-10d\n", p.product_id, p.product_name, p.price, p.quantity);
	}
	printf("-----------------------------------------------------\n");

	fclose(Fp);
}

void modifyProducts(const char *filename){
	FILE * Fp;
	struct Product p, foundProduct;
	Fp = fopen(filename, "rb+");
	if(Fp == NULL){
		printf("Cannot read data from this file. The program will close\n");
		exit(0);
	}
	
	printf("\nEnter the Product ID to modify: ");
	scanf("%d", &p.product_id);
	
	if(findproductID(filename, p.product_id, &foundProduct)){
		printf("Product found. Enter new details:\n");
		printf("New product name: ");
		scanf(" %[^\n]s", p.product_name);
		
		printf("New price: ");
		scanf("%f", &p.price);
		while(p.price < 0){
			printf("Invalid price. Please enter a non-negative value\n");
			printf("New price: ");
			scanf("%f", &p.price);
		}
		
		printf("New quantity: ");
		scanf("%d", &p.quantity);
		while(p.quantity < 0){
			printf("Invalid price. Please enter a non-negative value\n");
			printf("New quantity: ");
			scanf("%d", &p.quantity);
		}
		fseek(Fp, -sizeof(struct Product), SEEK_CUR);
		
		fwrite(&p, sizeof(struct Product), 1, Fp);
		
		printf("Product updated successfully.\n");
	}else{
		printf("There is no product with ID %d. The program will exit now", p.product_id);
		exit(0);
	}
	fclose(Fp);
}
