//===============================================()===============================
/*




#include <stdio.h> 
#include <stdlib.h> 
#include <locale.h>


int main()
{
	setlocale(LC_ALL, ""); // wprowadzenie polskich znakow
	// Kody ASCII //
	int i = 32;
	// int i=' ';  jest poprawne //
	while (++i < 250)
	{
		printf("%3d %c ", i, i);
		if (!((i - 32) % 4)) printf("\n");
	}
	printf("\n");
}




*/
//=====================================()========================================
/*




#include <stdio.h> 
#include <stdlib.h> 
#include <locale.h>

#define MAX_LINE 256

int main() {
	setlocale(LC_ALL, ""); // wprowadzenie polskich znakow

	unsigned char alphabet[MAX_LINE];
	unsigned char *wskaznik;

	for (int i = 0; i < MAX_LINE; i++) {
		alphabet[i] = (char)i;

		wskaznik = &alphabet[i];
		printf("%d\n", *wskaznik);
		switch (*wskaznik) {
		case 'g':
			printf("g jest na %d miesjcu w tablicy znaków, o adresie &p\n", i, wskaznik);
			break;

		case 'ę':
			printf("ę jest na %d miejscu w tablicy znaków, o adresie %p\n", i, wskaznik);
			break;
		}
	}

	return 0;
}




*/
//========================================()=================================
/*




#include <stdio.h> 
#include <stdlib.h> 
#include <locale.h>

#define MAX_LINE 256

int main() {
	setlocale(LC_ALL, ""); // wprowadzenie polskich znakow

	unsigned char* wskaznik;
	int slowo = 0;

	char zdanie[1000] = "";
	fgets(zdanie, sizeof(zdanie), stdin);


	for (int i = 0; zdanie[i] != '\0'; i++) {
		zdanie[i];
		if (zdanie[i] == ' ') { //ilosc spacji w zdaniu, de facto ilosc slow -1
			slowo++; 
		}
	}

	if (zdanie[0] != '\n') {
		slowo++;
	}
	printf("ilosc slow w zdaniu wynosi %d", slowo);
	return 0;
}




*/
// =============( usówanie/zamienianie znaków w tekscie)============= //
/*




#include <stdio.h> 
#include <locale.h>
#include <string.h>

#define MAX_LINE 256

int main() {
	setlocale(LC_ALL, ""); // wprowadzenie polskich znakow

	char zdanie[100] = "Puchaka Misiaka Sznycel Szprycel";
	char zdanie_bez_a[100] = "";

	int j = 0;


	printf("%d\n", strlen(zdanie));

	for (int i = 0; i < strlen(zdanie); i++) {
		
		if (zdanie[i] != 'a') {
			zdanie_bez_a[j++] = zdanie[i];
		}
		
		if (zdanie[i] == 'a') {
			zdanie[i] = 'A';

		}
	}


	printf("%s\n", zdanie);
	printf("%s", zdanie_bez_a);

	return 0;
}





*/
//===========================()==============================
/*





#include <stdio.h> 
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#pragma warning(disable:4996)

#define MAX_LINE 256

int main() {
	setlocale(LC_ALL, ""); // wprowadzenie polskich znakow

	char nazwa_pliku[] = "C:\\Kuba\\inne\\jipp_lab3.txt";
	int i = 0;

	FILE* plik = fopen(nazwa_pliku, "r"); // Otwieranie pliku w trybie odczytu

	if (plik == NULL) {
		printf("Nie udało się otworzyć pliku: %s\n", nazwa_pliku);
		return 1;
	}
	if (plik != NULL) {
		fseek(plik, 0 , SEEK_END );
		long size = ftell(plik);
		printf("%d", size);
	}

	char* tablica = (char*)malloc(((i + 1) * 2) * sizeof(char));


	
	int i = strlen(plik);
	int k = 0;

	char* tablica = (char*)malloc(((i + 1) * 2) * sizeof(char));
	if (tablica == NULL) {
		printf("Błąd przydzielania pamięci.\n");
		return 1;
	}


	for (int j = 0; j < i; j++){
		tablica[j] = plik[j];  // Przepisujemy znak z `zdanie`
		tablica[j + i] = plik[j]; 

	}
	tablica[2 * i] = '\0'; // Dodanie znaku końca ciąg

	printf("%s", tablica);


	free(tablica);

	

	free(tablica);
	return 0;
}




*/
//Liczba słów w wielu liniach tekstu (1) - tablice o dwóch indeksach  
/*




#pragma warning (disable: 4996) 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define MAX_LINE 256 
#define MAX_LINES 200 

FILE* fd = NULL;

int ile_slow(char*);

int main() {
	char d[MAX_LINES][MAX_LINE];
	int i, l;

	if (!(fd = fopen("DANE.txt", "r")))
	{
		printf("Blad otwarcia zbioru\n");
		exit(2);
	}
	
	i = 0;
	l = 0;

	while (i < MAX_LINES && fgets(d[i], MAX_LINE, fd) != (char*)NULL)
	{
		l += ile_slow(d[i]);
		i++;
	}

	fclose(fd);
	fd = NULL;

	printf("%d\n", l);
}
int ile_slow(char* te)
{
	char p, b = ' ';
	int l = 0;
	while (p = b, b = *te++)
		if (b != ' ' && p == ' ') l++;
	return(l);
}




*/
//============================()=====================================
/*




#pragma warning (disable: 4996) 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define MAX_LINE 256 
#define MAX_LINES 200 

int main() {
	char *memory;

	FILE* file = fopen("output.txt", "w+");
	if (file == NULL){
	printf("Nie mozna otworzyc pliku!\n");
	}


	memory = (char*) malloc(200 * 2 * sizeof(char));

	char x[] = "puchaka, misiaka\n sznycel szprycel.";

	fprintf(file, "%s", x); // Dopisujemy do pliku

	fclose(file);

	free(memory);
	return 0;

}




*/
/* // ============================( 15 zadanie )============================//




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

	return 0;

}




*/
//===================================(zadanie 27)=====================================//
//program do sprawdzania długości linii, wystepowania znakow w liniach ilosci linii
/*




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


// char* strcat(char* strTo, const char* strFrom);




*/
// ====================================== ( Zadanie 28 ) ============================================= //
/*




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
			fprintf(stderr, "Błąd alokacji pamięci dla matrix[%d]\n", i);	 // Sprawdzanie alokacji
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
	for(int z = 0; z < lines_amount; z++) {
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

int num_of_capital_lett(char *d) {  // funkcja do zliaczania duzych liter
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




*/
// =================================== ( Zadanie 32  ) =========================== //
/*




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
			if (sel_line1 != NULL && sel_line2 != NULL){
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




*/
//======================================(zadanie 33)=================================
/*




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
			printf("wybrany tekst 'Steel', lub 'steel', znajduje się w %d linii\n\n",i);
			printf("%s\n\n", line);
			break;

		}
	}

	fclose(file); 
	return 0;
}




*/
//====================================================(Zadanie 34)======================
/*


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




*/



//==========================================(Zadanie 35)=================================
/*



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
		printf("Słowo %d: %s\n", j + 1, slowa[j]);
	}

	printf("\n\nkoniec\n\n");
	return 0;
}



*/
//==================================(Zadanie 36)======================//
/*




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



*/



// © 2025 Jakub.S.A. All Rights Reserved