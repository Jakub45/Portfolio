
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "");

	int m = 3, n = 3; // zainicjalizowane
	double** tab1;
	double** tab2;
	double* vector;
	double* vector_output;


	// alokacja pamięci dla wskaźników
	tab1 = (double**)malloc(sizeof(double*) * m);
	if (!tab1) {
		fprintf(stderr, "Blad alokacji pamieci dla tab1.\n");
		return 1;
	}

	tab2 = (double**)malloc(sizeof(double*) * m);
	if (!tab2) {
		fprintf(stderr, "Blad alokacji pamieci dla tab1.\n");
		return 1;
	}

	//alokacja pamieci dla wektora.
	vector = (double*)malloc(sizeof(double) * m);
	if (!tab1) {
		fprintf(stderr, "Błąd alokacji pamięci dla vector.\n");
		return 1;
	}

	vector_output = (double*)malloc(sizeof(double) * m);
	if (!tab1) {
		fprintf(stderr, "Błąd alokacji pamięci dla vector.\n");
		return 1;
	}


	// alokacja pamięci dla każdego wiersza
	for (int i = 0; i < m; i++) {


		tab1[i] = (double*)malloc(sizeof(double) * n);
		tab2[i] = (double*)malloc(sizeof(double) * n);
		//jezeli wystapi blad
		if (!tab1[i] && !tab2[i]) {
			fprintf(stderr, "Blad alokacji pamieci wiersza %d dla tab1.\n", i);
			for (int j = 0; j < i; j++) free(tab1[j]);
			free(tab1);
			return 1;
		}
	}


	//generator przykladowych wektorow
	srand(time(NULL));

	printf("wektor1 = \n");
	for (int i = 0; i < m; i++) {
		vector[i] = rand() % 10;
		printf("|%.f|\n", vector[i]);
	}
	printf("\n");

	//generator przykladowej macierzy 
	printf("macierz1 = \n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			tab1[i][j] = rand() % 9;
			printf("|%.f|", tab1[i][j]);  // teraz powinno działać
		}
		printf("\n");
	}

	printf("\nmacierz1 pomnozona przez wektor1 =\n");
	for (int i = 0; i < m; i++) {
		vector_output[i] = 0;
		for (int j = 0; j < n; j++) {
			tab2[i][j] = tab1[i][j] * vector[j];
			printf("|%.f|", tab2[i][j]);


			vector_output[i] += tab2[i][j];
		}
		printf("\n");
	}

	printf("\niloczyn macierzy1 pomnożony przez wektor1 =\n");
	for (int i = 0; i < m; i++) {
		printf("|%.f|\n", vector_output[i]);
	}


	// zwalnianie pamięci
	for (int i = 0; i < m; i++) {
		free(tab1[i]);
		free(tab2[i]);
	}
	free(tab1);
	free(tab2);
	free(vector);
	free(vector_output);

	tab1 = NULL;
	tab2 = NULL;
	vector = NULL;
	vector_output = NULL;
	return 0;
}
