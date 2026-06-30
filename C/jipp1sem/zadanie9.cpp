#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable : 4996)

void pole(int *p, int*q );

int main() {
	int r = 3;
	int obwod = r;
	int pol = r;
	pole(&pol, &obwod);
	printf("Pole wynosi - %d jendnostek kwadratowych oraz obwod wynosi %d\n\n", pol, obwod);

}

void pole(int *p, int *q) {
	*p = 3.14 * pow(*p, 2);
	*q = 3.14 * 2 * (*q);
}

