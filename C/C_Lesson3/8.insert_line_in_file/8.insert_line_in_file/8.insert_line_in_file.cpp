
#include <locale.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

#pragma warning (disable: 4996) 

#define MAX_LENGTH 256

int main() {
	setlocale(LC_ALL, ""); // wprowadzenie polskich znakow

	char line[256] = { 0 };
	int num_n = 6;
	int lines_amount = 0;
	char lines[20][256] = { 0 };
	const char* titanium = "Titanium is a chemical element; it has symbol Ti and atomic number 22.\n";

	//otwiarcie pliku początkowego
	FILE* file = fopen("intput.txt", "r+");
	if (file == NULL) {
		printf("błąd otwarcia pliku, zamykanie programu");
		return(1);
	}

	//otwarcie pliku docelowego
	FILE* file2 = fopen("output.txt", "w");
	if (file2 == NULL) {
		printf("błąd otwarcia pliku, zamykanie programu");
		return(1);
	}


	//peta ktora zlicza ilosc linii w tekscie
	while (fgets(line, sizeof(line), file) != NULL) {
		lines_amount++;
	}
	rewind(file);

	////pobieranie tekstu do macierzy lines
	//petla zlicza ilosc linii w tekscie
	for (int i = 0; i < lines_amount; i++) {
		fgets(line, sizeof(line), file);
		strncpy(lines[i], line, 256);
	}


	////wczytywanie tekstu + dodatkowa treść do docelowego pliku
	for (int i = 0; i < lines_amount; i++) {
		if (i == num_n) {
			fprintf(file2, "%s", titanium);
		}
		fprintf(file2, "%s", lines[i]);
	}

	fclose(file2);
	fclose(file);
	printf("Program zadziałał poprawnie.\n\n");
	return 0;
}
