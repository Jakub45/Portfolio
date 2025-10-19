
#include <stdio.h> 
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#pragma warning(disable:4996)

#define MAX_LINE 256

int main() {
    setlocale(LC_ALL, ""); // wprowadzenie polskich znaków

    char nazwa_pliku[] = "dane.txt";
    int i = 0;

    FILE* plik = fopen(nazwa_pliku, "r"); // Otwieranie pliku w trybie odczytu

    if (plik == NULL) {
        printf("Nie udalo się otworzyc pliku: %s\n", nazwa_pliku);
        return 1;
    }

    // Ustalenie rozmiaru pliku
    fseek(plik, 0, SEEK_END);
    long size = ftell(plik);
    rewind(plik); // wracamy na początek pliku
    printf("Rozmiar pliku: %ld\n", size);

    // Wczytanie zawartości pliku do bufora
    char* buffer = (char*)malloc((size + 1) * sizeof(char));
    if (buffer == NULL) {
        printf("Blad przydzielania pamieci.\n");
        fclose(plik);
        return 1;
    }

    fread(buffer, 1, size, plik);
    buffer[size] = '\0';
    fclose(plik);

    i = strlen(buffer);
    int k = 0;

    char* tablica = (char*)malloc(((i + 1) * 2) * sizeof(char));
    if (tablica == NULL) {
        printf("Blad przydzielania pamieci.\n");
        free(buffer);
        return 1;
    }

    for (int j = 0; j < i; j++) {
        tablica[j] = buffer[j];      // kopiowanie znaków
        tablica[j + i] = buffer[j];  // druga kopia
    }
    tablica[2 * i] = '\0'; // koniec ciągu

    printf("%s", tablica);

    free(tablica);
    free(buffer);

    return 0;
}
