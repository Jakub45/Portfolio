


//====================================(zadanie 11)=============================//


#include <memory.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "zmienne.h"

#define _CRT_SECURE_NO_WARNINGS

void t1_to_t2_assignment(int size, int* src, int* dest);
int max_min_num(int *d1, int* min_val, int* max_val);

int main() {

	int size;

	int min_val = INT_MAX;
	int max_val = INT_MIN;

	printf("Choose a quantity of random numbers to generate. Only natural numbers\n");
	scanf_s("%d", &size);


	//alokacja pamieci t1
	int* t1 = (int*) malloc (size * sizeof(int));
	if (t1 == NULL) {
		printf("Wrong memory allocation t1");
		return 0;
	}

	//alokacja pamieci t2
	int* t2 = (int*)malloc(size * sizeof(int));
	if (t2 == NULL) {
		printf("Wrong memory allocation t2");
		return 0;
	}


	// Ziarno generatora liczb pseudolosowych wzgledem czasu
	srand(time(NULL));

	//generowanie liczb losowych od 1 do 99, minimalna wartosc, maksymalna wartosc
	for (int i = 0; i < size;) {
		int rand_number = rand() % 100;

		t1[i] = rand_number;

		printf("random numer %d = %d \n",i, t1[i]);
		max_min_num(&t1[i], &min_val, &max_val);

		i++;
	}

	printf("Min value = %d, Max value = %d\n\n", min_val, max_val);


	//kopiowanie tablicy t1 do t2
	t1_to_t2_assignment(size,t1,t2);

	//wypisywanie tablicy t2 na monitorze
	for (int k = 0; k < size;k++) {
		printf("%d ", t2[k]);
	}

	//zwalnianie pamieci dla t1,t2
	free(t1);
	t1 = NULL;
	free(t2);
	t2 = NULL;

	printf("\nkoniec.\n");
}


void t1_to_t2_assignment(int size, int* src, int* dest) {
	for (int k = 0; k < size; k++) {
		dest[k] = src[k];
	}
}



int max_min_num(int *d1, int* min_val, int* max_val) {
	int input = *(int*)d1;


	if (input < *min_val) {
		*min_val = input;
	}
	if (input > *max_val) {
		*max_val = input;
	}
	return *min_val, *max_val;
}

