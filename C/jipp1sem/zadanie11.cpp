#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable : 4996)

void policz(float*z);
double x, y;


int main()
{
	float wynik;
	policz(&wynik);
	printf("wynik operacji wynosi: %lf\n\n", wynik);
}


void policz(float* z) {
	printf("podaj liczbe x,y\n");
	scanf("%le%le", &x,&y);

	if (pow(x, 2) + pow(y, 2) <= 1){
		*z = pow(x, 2) + y;
	}
	if (y > x - 5) {
		*z = 2 * x + pow(y, 2);
	}
	if (pow(x, 2) + pow(y, 2) > 1 && (y <= x + 5)) {
		*z = 0.5 * pow(x, 2) + y;
	}
}