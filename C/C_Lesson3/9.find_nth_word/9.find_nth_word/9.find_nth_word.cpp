

#include <locale.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

#pragma warning (disable: 4996) 

int main() {
	setlocale(LC_ALL, ""); // wprowadzenie polskich znakow

	char line[256];         // Bufor do przechowywania pojedynczej linii z pliku
	int word_position = 25;
	char slowa[100][50];

	//otwarcie pliku, sprawdzenie poprawnosci otwarcia
	FILE* file = fopen("intput.txt", "r");
	if (file == NULL) {
		printf("Błąd otwarcia pliku.");
		return 1;
	}

	// tablicowanie slow z pliku file i wyszukiwanie slowa n'tego
	int n = 14;
	int i = 0;
	while (i < 30 && fscanf(file, "%49s", slowa[i]) == 1) {
		if (i == n - 1) {
			printf("Szukane slowo o pozycji %d, : %s\n\n", n, slowa[i]);
		}
		i++;
	}


	for (int j = 0; j < i; j++) {
		printf("Slowo %d: %s\n", j + 1, slowa[j]);
	}

	printf("\n\nkoniec\n\n");
	return 0;
}


