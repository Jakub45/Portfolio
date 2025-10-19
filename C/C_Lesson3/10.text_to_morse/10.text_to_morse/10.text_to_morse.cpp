

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning (disable: 4996)

int main() {
	setlocale(LC_ALL, ""); // Wprowadzenie polskich znaków

	char tekst[100];

	char litery[] = {
		'a', 165, 'b', 'c', 134, 'd', 'e', 169, 'f', 'g', 'h', 'i', 'j', 'k', 'l', 136, 'm', 'n', 228, 'o', 162, 'p', 'q', 'r', 's', 152, 't', 'u', 'v', 'w', 'x', 'y', 'z', 190, 171,
		'A', 164, 'B', 'C', 143, 'D', 'E', 168, 'F', 'G', 'H', 'I', 'J', 'K', 'L', 157, 'M', 'N', 227, 'O', 224, 'P', 'Q', 'R', 'S', 151, 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 189, 141,
		'.', ',', '?', ';', ':', '-', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '!', '\0', ' '
	};

	const char* mors[] = {
		".-", ".-.-", "-...", "-.-.", "-.-..", "-..", ".", "..-..", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", ".-..-", "--", "-.", "--.--", "---", "---.", ".--.", "--.-", ".-.", "...", "...-...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "--..-",
		".-", ".-.-", "-...", "-.-.", "-.-..", "-..", ".", "..-..", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", ".-..-", "--", "-.", "--.--", "---", "---.", ".--.", "--.-", ".-.", "...", "...-...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "--..-", "--..-",
		".-.-.-", "--..--", "..--..", "-.-.-.", "---...", "-....-", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-.-.--", NULL, " "
	};


	printf("Program do translacji na kod morsoe'a. Nie podawaj wiecej niz 100 znakow na raz\n");


	// Wczytanie tekstu
	bool is_on = true;
	while (is_on) {
		printf("\n\n");
		fgets(tekst, sizeof(tekst), stdin);
		printf("\nWpisano    : %s", tekst);
		printf("Kod Morsoe : ");

		for (int i = 0; i < strlen(tekst); i++) {
			// Jesli napotka spacje
			if (tekst[i] == ' ') {
				printf(" ");
				continue;
			}

			// Sprawdzamy, czy dany znak występuje w tablicy 'litery'
			char* wskaznik = strchr(litery, tekst[i]);

			if (wskaznik != NULL) {
				int pozycja = wskaznik - litery;
				printf("%s", mors[pozycja]);
			}
		}
	}
	return 0;
}



// © 2025 Jakub.S.A. All Rights Reserved