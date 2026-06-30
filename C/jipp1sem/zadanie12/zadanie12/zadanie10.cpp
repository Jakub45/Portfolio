#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable : 4996)


void zamien(int* x, int* y);

int main()
{
	int wartosc_x = 2;
	int wartosc_y = 10;
	
	zamien(&wartosc_x, &wartosc_y);
	printf("Po zamianie wartosci, x rowna sie %d, y rowna sie %d\n\n", wartosc_x, wartosc_y);
}

void zamien(int* x, int* y) {
	int z = *x;
	*x = *y;
	*y = z;
}