/*

#include <memory.h> 
#include <string.h> 
#include <stdio.h> 


char str1[7] = "aabbcc";
int main(void)
{
	printf("The string: %s\n", str1);
	//Pokrywający się region! Kopiowanie może nie być poprawne 
	memcpy(str1 + 2, str1, 4);
	printf("New string: %s\n", str1);
	strcpy_s(str1, sizeof(str1), "aabbcc"); // reset string 
	printf("The string: %s\n", str1);
	//Pokrywający się region! Kopiowanie poprawne 
	memmove(str1 + 2, str1, 4);
	printf("New string: %s\n", str1);
}

*/




/*
#include <memory.h> 
#include <stdio.h> 
int main(void)
{
	char buffer[] = "This is a test of the memset function";
	printf("Before: %s\n", buffer);
	memset(buffer, '*', 4);
	printf("After: %s\n", buffer);
}

*/



/*
#include <memory.h> 
#include <stdio.h> 
int main(void)
{
	char str[256];
	double aa[200];
	double cc[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	double dd[5] = { 20, 30, 40, 50, 60 };
	memset((void*)str, 0, 256 * sizeof(char)); //OK 
	memset((void*)str, ' ', 256 * sizeof(char)); //!OK–pisanie po pamięci 
	memset((void*)str, ' ', 255 * sizeof(char)); //OK 
	memset((void*)aa, 0, 200 * sizeof(double)); //OK 
	memcpy((void*) & cc[3], (const void*) & dd[2], 2 * sizeof(double));
}

*/















//====================================(zadanie 11)=============================//

/*

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

*/











//===================================(zadanie 12)==================================//
/*


#include <string.h> 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Defining macros.
#define PI 3.14159265358979323846

struct Vector {
	int x_axis;
	int y_axis;p
	int z_axis;
};

int main() {

	struct Vector vector1 { 5, 5, 7 };

	//Calculing vector_length.
	double vector_magnitude = sqrt(pow(vector1.x_axis, 2) + pow(vector1.y_axis, 2) + pow(vector1.z_axis, 2));
	printf("vector value = %f, \n", vector_magnitude);


	//Calculing direction (yaw).
	double yaw = atan2(vector1.x_axis, vector1.y_axis);
	double angle_xy = yaw * (180 / PI); 		//Representation of yaw in degrees.
	printf("direction of XY (yaw) = %.2f degrees\n ",angle_xy);


	//Caculing inlination (pitch) relative to XY vector (yaw).
	double horizontal_magnitude = sqrt(pow(vector1.x_axis, 2) + pow(vector1.y_axis, 2));
	double pitch = atan2(vector1.z_axis, horizontal_magnitude);
	double inclination = pitch * (180 / PI);	//Representation of pitch in degrees.
	printf("angle of inclination = %f, \n", inclination);
}



*/
//===================================(zadanie 12.1)==================================//
/*

#include <string.h> 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct Vector {
	int x_axis;
	int y_axis;
	int z_axis;

	double (*vector_length)(struct Vector* self); // wskaźnik do funkcji
	struct Vector(*add)(struct Vector* self, struct Vector* other); // metoda dodawania
} Vector;

double vector_length(Vector* self) {
	return sqrt(pow(self->x_axis, 2) + pow(self->y_axis, 2) + pow(self->z_axis, 2));
}

Vector vector_add(Vector* self, Vector* other) {
	Vector result = {
		result.x_axis = self->x_axis + other->x_axis,
		result.y_axis = self->y_axis + other->y_axis,
		result.z_axis = self->z_axis + other->z_axis,
		result.vector_length = self->vector_length,  // kopiujemy wskaźnik do funkcji
		result.add = self->add
	};
	return result;
}

int main() {
	Vector vector1 = { 5, 5, 7, NULL, NULL };
	Vector vector2 = { 7, 0, -1, NULL, NULL };

	// Przypisanie wskaźników do funkcji (metod)
	vector1.vector_length = vector_length;
	vector1.add = vector_add;

	vector2.vector_length = vector_length;
	vector2.add = vector_add;


	printf("Vector1 length = %f\n", vector1.vector_length(&vector1));
	printf("Vector2 length = %f\n", vector2.vector_length(&vector2));

	Vector vector_sum = vector1.add(&vector1, &vector2);
	printf("Sum vector length = %f\n", vector_sum.vector_length(&vector_sum));
	printf("Sum vector components = (%d, %d, %d)\n", vector_sum.x_axis, vector_sum.y_axis, vector_sum.z_axis);

	return 0;
}

*/
//===================================(zadanie 12.2)==================================//
/*





#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Vector {
	int x_axis;
	int y_axis;
	int z_axis;

	struct Vector(*vector_sum)(struct Vector* self, struct Vector* other);

	double (*vector_length)(struct Vector* self);
	double (*vector_scalar)(struct Vector* self, struct Vector* other);
} Vector;


static double vector_length(Vector* self) {
	return sqrt(pow(self->x_axis, 2) + pow(self->y_axis, 2) + pow(self->z_axis, 2));
}

static double vector_scalar(Vector* self, Vector* other) {
	return self->x_axis * other->x_axis + self->y_axis * other->y_axis + self->z_axis * other->z_axis;
}


Vector vector_sum(Vector* self, Vector* other) {
	Vector result;
	result.x_axis = self->x_axis + other->x_axis;
	result.y_axis = self->y_axis + other->y_axis;
	result.z_axis = self->z_axis + other->z_axis;

	// Przypisz wskaźniki funkcji do nowego wektora
	result.vector_length = self->vector_length;
	result.vector_sum = self->vector_sum;

	return result;
}



int main() {
	//objects initiation.
	Vector vector1 = { 1, 5, 0, NULL, NULL };
	Vector vector2 = { 8, -5, 10, NULL, NULL };



	//assign objects to method (lenght).
	vector1.vector_length = vector_length;
	vector2.vector_length = vector_length;

	printf("Vector1 length = %f\n", vector1.vector_length(&vector1));
	printf("Vector2 length = %f\n", vector2.vector_length(&vector2));



	//assign objects 
	vector2.vector_sum = vector_sum;
	vector1.vector_sum = vector_sum;

	Vector sum = vector1.vector_sum(&vector1, &vector2);

	printf("Sum vector: (%d, %d, %d)\n", sum.x_axis, sum.y_axis, sum.z_axis);
	printf("Sum vector length = %f\n", sum.vector_length(&sum));



	//assing objects to method (scalar).
	vector1.vector_scalar = vector_scalar;
	vector2.vector_scalar = vector_scalar;

	double scalar = vector1.vector_scalar(&vector1, &vector2);

	printf("Vector scalar = %f\n\n", scalar);


	return 0;
}



*/

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
	for (int i = 0; i < m; i++){
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
