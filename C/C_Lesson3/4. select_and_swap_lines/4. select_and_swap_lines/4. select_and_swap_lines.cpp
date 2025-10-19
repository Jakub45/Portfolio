

#pragma warning (disable: 4996) 
#include <locale.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>


int main() {
	setlocale(LC_ALL, ""); // wprowadzenie polskich znakow
	int lines_amount = 0;
	char line[256];
	char* matrix[22];
	char sel_line1[256] = { 0 };
	char sel_line2[256] = { 0 };
	char str_buffer[256] = { 0 };
	int m = 0;
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
			fprintf(stderr, "Błąd alokacji pamięci dla matrix[%d]\n", i);	 // Sprawdzanie alokacji
			exit(EXIT_FAILURE);
			printf("%s", matrix[i]);
		}

		if (matrix[i] != NULL) {
			if (i == 1) {
				strncpy(sel_line1, line, 255);
				sel_line1[255] = '\0'; // Zapewnia poprawne zakończenie stringa
				printf("%s\n\n", sel_line1);
			}

			if (i == 2) {
				strncpy(sel_line2, line, 255);
				sel_line2[255] = '\0'; // Zapewnia poprawne zakończenie stringa
				printf("%s\n\n", sel_line2);
			}
			if (sel_line1 != NULL && sel_line2 != NULL) {
				strcpy(str_buffer, sel_line1);
				str_buffer[255] = '\0'; // Zapewnia poprawne zakończenie stringa
				printf("%s", str_buffer);
				// Zamiana linii
				strcpy(sel_line2, sel_line1);
				fprintf(file2, "%d || %s", i, matrix[i]);

				strcpy(sel_line1, str_buffer);
				fprintf(file2, "%d || %s", i, matrix[i]);

				continue;

			}
			fprintf(file2, "%d || %s", i, strcpy(matrix[i], line));
		}
	}


	fclose(file2);
	fclose(file);


	//zwalnianie pamieci
	for (int z = 0; z < lines_amount; z++) {
		if (matrix[z] != NULL) {
			printf("Zwalnianie pamięci dla matrix[%d]: %p\n", z, matrix[z]);
			free(matrix[z]);
			matrix[z] = NULL;
		}
		else {
			printf("matrix[%d] jest NULL, pomijanie\n", z);
		}
	}
	printf("program zadziałał poprawnie\n\n\n");
	return 0;
}


