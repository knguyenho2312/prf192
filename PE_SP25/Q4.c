#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
int countDigits(char* s);
int main(int argc, char *argv[]) {
	//=== Do not add new or change statements in the main function.===
	system("cls");
	printf("\nTEST Q4 (3 marks):\n");
	char s[21];
	fflush(stdin);
	printf("Please enter a string: ");
	scanf("%20[^\n]", s);
	//=== The output will be used to mark your program.===============
	printf("\nOUTPUT:\n");
	printf("%d",countUpperLetters(s));
	printf("\n");
	system ("pause");
	return 0;
}
int countUpperLetters(char* s) {
	//Begin your codes here=====================
    int count = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (isupper(s[i])) {
            count++;
        }
    }
    return count;
	//End your codes============================
}

