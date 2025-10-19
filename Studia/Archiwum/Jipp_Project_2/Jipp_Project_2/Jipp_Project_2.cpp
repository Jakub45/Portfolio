// Otwieranie pliku txt i zapisanie linia po linii do zmiennej 
// dynamiczna alokacja, tzn musze znac ilosc linii i pozniej dlugosc kazdej linii
// wypisanie na pulpicie linii.



#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>  // Potrzebne dla SetConsoleOutputCP()


#pragma warning (disable: 4996)


int num_of_sym;
int main() {
	SetConsoleOutputCP(65001);     // Ustawienie kodowania konsoli na UTF-8
	setlocale(LC_CTYPE, ".UTF8");  //ustawienie polskich znakow na plik.


	char x[250];

	FILE* file = fopen("jipp_lab3.txt", "r");
	if (file == NULL) {
		printf("Blad otwarcia pliku txt.");
		return 1;
	}

	int i = 0;
	while (i < 735) {
		fgets(x, sizeof(x), file);
		printf("%s", x);

		while (getc(file) != '\n') {
			num_of_sym++;
		}
		//printf("%d\n", num_of_sym);
		i++;
	}



	printf("program zadzialal poprawnie");
	return 0;
}