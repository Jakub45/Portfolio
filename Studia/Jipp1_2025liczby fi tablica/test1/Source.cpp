/*


#include <stdio.h>

int main() {

	int osiem = 0;
	double pi = 3.14;
	char z = 'c';



	printf("%d, \t%lf, \t%c",osiem, pi, z);

}

*/

//==============================================================================================


/*


#include <stdio.h>
#include <locale.h>
#include <windows.h>


int main() {

	char tablice1[7] = { 'k','r','a','k','o','w' };

	char tablice2[8] = { 'k','r','a','k','o','w',EOF};

	for (int i = 0; i <= 256; i++) {
		char x = i;
		printf("liczba %d odpowiada znakowi - ", i);
		printf("\t%c\n", x);
	}


	printf("\n\n%s\n", tablice1);
	printf("%s\n", tablice2);



}


*/


#include <stdio.h>
#include <stdlib.h>


#pragma warning(disable:4996)


int fibbonaci(int* lower, int* higher);


int main(){


	//ilosc liczb fibbonaciego
	unsigned long i;

	//poczatkowe deklaracje dla y,z,d
	int z = 0;
	int y = 1;
	int d = 1;

	printf("type number");
	scanf("%d", &i);


	int* tab = (int*)malloc(i * sizeof(int));  //tablica liczb fibonacciego
	int* tab2 = (int*)malloc(i * sizeof(int)); //tablica numeru liczb fibacciego

	for (int n = 0; n < i; n++) {
		y = d;
		d = fibbonaci(&y, &z);
		tab2[n] = n;  
		tab[n] = d;
		z = y;
	}



	//GUI
	printf("wypisanie wartosci tablicy\n");
	printf("%c---------------%c------------------%c\n", 218, 194, 191);
	printf("|    Liczba     |     liczba Fi    |\n");
	printf("%c---------------%c------------------%c",195,197,180);
	for (int n = 0; n < i; n++) {
		printf("\n|liczba %d\t", tab2[n]);
		printf("|%-10d        |", tab[n]);
	}
	printf("\n%c---------------%c------------------%c\n\n\n\n",192, 193,217);



	/*
	for (int i = 0; i <= 256; i++) {
		char x = i;
		printf("\nliczba %d odpowiada znakowi - ", i);
		printf("\t%c\n", x);
	}
	*/

	free(tab);
	free(tab2);

	return 0;
}



int fibbonaci(int* lower, int* higher) {
	int sum;
	sum = *lower + *higher;

	return sum;
}

