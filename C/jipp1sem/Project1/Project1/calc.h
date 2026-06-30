#pragma once
#include "parameters_changes.h"
#include <math.h>
#include <float.h>
#include <cmath>

double round(double fValue)
{
	return fValue < 0 ? ceil(fValue - 0.5)
		: floor(fValue + 0.5);
}

// funkcja musi zliczac wyniki z okreslonego przesuniecia dx. czyli dla pierwszego dx, funckja zlicza wsyzstkie wyniki,
// jesli zostanie osiagnieta dokladnosc (suma zliczonych wynikow jest juz wieksza niz dokladnosc), podaje wynik,
// jesli nie, zlicza pierwszych 1000 wynikow.

// dx, 
//zeby osiagnac max ilosc wynikow 1000, trzeba podzielic obszar miedzy dx na 1000 czesci, czyli dx na 1000 czesci

double srednia;
double suma;
double n;
double a, b;
double x, y, dx;
double e = 0.0001;

void view();
double epsilon();

void calc() {
	for (a = -1; a <= 1;a+=0.002) {
		suma = 0;
		for (n = 1; n <=1000;n++) {
			dx = 0.002 / 2000;
			x = x + dx;
			y = pow(1 + x, (1.0 / 4));
			suma += y;
			epsilon();
			//printf("%f\n", y);
		}
		srednia = suma / 1000;
		view();
	}
	printf("%f", x);
}

void view() {
	printf("|%f\t|-------\t|%f\t|--------\t|-------|\n",x, srednia);

}

double epsilon() {
	return y = round(y * 1.0f) / 1.0f;

}