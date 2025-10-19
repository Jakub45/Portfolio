


#pragma warning (disable: 4996) 
#include <locale.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

int num_of_capital_lett(char* d);
int num_of_small_lett(char* d);
int num_of_all_symbols(char* d);

int main() {
	setlocale(LC_ALL, ""); // wprowadzenie polskich znakow
	int lines_amount = 0;
	char line[256];
	char* matrix[22];


	//otwieranie plikow
	FILE* file = fopen("intput.txt", "r");
	FILE* file2 = fopen("output.txt", "w");
	//sprawdzanie poprawnosci otwarcia plikow
	if (file == NULL) {
		printf("nie znaleziono pliku\n");
		return 1;
	}
	if (file2 == NULL) {
		printf("nie znaleziono pliku\n");
		return 1;
	}


	//peta ktora zlicza ilosc linii w tekscie
	while (fgets(line, sizeof(line), file) != NULL) {
		lines_amount++;
	}
	rewind(file);

	//petla ktora alokuje pamiec dla wszystkich linii i ustawia wartosc na null
	for (int i = 0; i < lines_amount; i++) {
		fgets(line, sizeof(line), file);

		matrix[i] = (char*)calloc(strlen(line) + 1, sizeof(char));           // Alokacja pamięci dla każdego wiersza


		if (matrix[i] == NULL) {
			fprintf(stderr, "Blad alokacji pamieci dla matrix[%d]\n", i);	 // Sprawdzanie alokacji
			exit(EXIT_FAILURE);
			printf("%s", matrix[i]);
		}

		if (matrix[i] != NULL) {

			fprintf(file2, "%d || Duze = %d || male = %d || wszystkie = %d || %s", i, // Kopiowanie zawartości
				num_of_capital_lett(line), num_of_small_lett(line), num_of_all_symbols(line), strcpy(matrix[i], line));
		}
	}


	fclose(file2);
	fclose(file);


	//zwalnianie pamieci
	for (int z = 0; z < lines_amount; z++) {
		if (matrix[z] != NULL) {
			printf("Zwalnianie pamieci dla matrix[%d]: %p\n", z, matrix[z]);
			free(matrix[z]);
			matrix[z] = NULL;
		}
		else {
			printf("matrix[%d] jest NULL, pomijanie\n", z);
		}
	}
	printf("program zadzialal poprawnie\n\n\n");
	return 0;
}

int num_of_capital_lett(char* d) {  // funkcja do zliaczania duzych liter
	int count = 0;
	for (int k = 0; d[k] != '\0'; k++) {
		if (d[k] >= 65 && d[k] <= 90) {
			count++;
		}
	}
	return count;
}

int num_of_small_lett(char* d) {    // funkcja do zliaczania malych liter
	int count = 0;
	for (int k = 0; d[k] != '\0'; k++) {
		if (d[k] >= 97 && d[k] <= 122) {
			count++;
		}
	}
	return count;
}

int num_of_all_symbols(char* d) {   // funkcja do zliaczania wszystkich symboli
	int count = 0;
	for (int k = 0; d[k] != '\0'; k++) {
		if (d[k] == 10) {
			continue;
		}
		if (d[k] >= 0 && d[k] <= 256) {
			count++;
		}
	}
	return count;
}


