

#pragma warning (disable: 4996) 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int main() {

	FILE* file = fopen("output.txt", "r");
	if (file == NULL) {
		printf("Nie mozna otworzyc pliku!\n");
	}

	//obliczenie długośći pliku
	fseek(file, 0, SEEK_END);
	long file_length = ftell(file);
	rewind(file);


	// alokacja pamięci
	char* buffer = (char*)malloc(file_length + 1);
	if (buffer == NULL) {
		printf("Blad alokacji pamieci!\n");
		fclose(file);
		return 1;
	}

	// Wczytanie pliku do pamięci
	fread(buffer, 1, file_length, file);
	buffer[file_length] = '\0'; // Dodanie końca stringa
	fclose(file); // Zamknięcie pliku po odczycie


	// usuwanie pierwszego znaku 's'
	long j = 0; // Indeks dla nowej pozycji w buforze
	for (int i = 0; i < file_length; i++) {
		if (buffer[i] != 's') {
			buffer[j++] = buffer[i];
		}
	}
	buffer[j] = '\0';

	// modyfikacja pliku
	file = fopen("output.txt", "w");
	if (file == NULL) {
		printf("Nie mozna otworzyc pliku do zapisu!\n");
		free(buffer);
		return 1;
	}
	fwrite(buffer, 1, j - 1, file);

	free(buffer);
	fclose(file);

	printf("all done (look input.txt , output.txt");

	return 0;

}

