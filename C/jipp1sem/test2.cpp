#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable : 4996)

double pi = 3.14;
double r = 2.5;
double* w1, * w2;

void kolo(double r, double* w1, double* w2);

int main() {
	double *pole = &w1;
	double *obwod = &w2;


	kolo(r);

}

void kolo(double r, double* w1, double* w2) {
	*w1 = (r * pi);
}