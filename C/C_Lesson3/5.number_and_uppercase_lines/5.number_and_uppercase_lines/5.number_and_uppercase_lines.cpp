
//===================================(zadanie 27)=====================================//
//program do sprawdzania długości linii, wystepowania znakow w liniach ilosci linii



#pragma warning (disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//otwietanie plikow;
FILE* file = fopen("intput.txt", "r");
FILE* file2 = fopen("output.txt", "w");

int lines_amount = 0; // bramka logiczna pomija wliczenie ostatniej linii
char line[256];

void numeric_lines();
void all_letters_capital();

int main() {
	//sprawdzanie poprawnosci otwarcia plikow
	if (file == NULL) {
		printf("nie znaleziono pliku\n");
		return 1;
	}
	if (file2 == NULL) {
		printf("nie znaleziono pliku\n");
		return 1;
	}

	numeric_lines();      // numerowanie linii

	fclose(file2);
	fclose(file);

	printf("all done.");
	return 0;
}

void numeric_lines() {
	while (fgets(line, sizeof(line), file) != NULL) {
		lines_amount++;
		all_letters_capital(); // zamiana malego s na duze S
		fprintf(file2, "%d | %s", lines_amount, line);

	}
}

void all_letters_capital(){
	for (int i = 0; i <= 256; i++) {
		if (line[i] >= 97 && line[i] <= 122) {
			line[i] -= 32; //przesuniecie w kodzie ASCI o 32 miejsca(odpoewiednik malej litery)
		}
	}
}
