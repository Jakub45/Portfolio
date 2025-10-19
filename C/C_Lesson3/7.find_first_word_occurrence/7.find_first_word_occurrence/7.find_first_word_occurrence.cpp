
#include <locale.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

#pragma warning (disable: 4996) 
int main() {
	setlocale(LC_ALL, ""); // wprowadzenie polskich znakow

	char line[256];         // Bufor do przechowywania pojedynczej linii z pliku
	const char* steel = "steel";
	const char* Steel = "Steel";

	FILE* file = fopen("intput.txt", "r");  // Otwieramy plik do odczytu
	if (file == NULL) {
		printf("Nie udało się otworzyć pliku.\n");
		return 1;  // Jeśli plik nie istnieje, zakończ program z kodem błędu
	}


	int i = 0;
	while (fgets(line, sizeof(line), file) != NULL && i < 20) {
		i++;
		if ((strncmp(line, steel, 5) == 0) || (strncmp(line, Steel, 5) == 0)) {
			printf("wybrany tekst 'Steel', lub 'steel', znajduje się w %d linii\n\n", i);
			printf("%s\n\n", line);
			break;

		}
	}

	fclose(file);
	return 0;
}



