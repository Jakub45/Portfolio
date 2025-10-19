
#pragma warning (disable: 4996)
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double recursion();
double pochodna();
double wtf();

int n;
double long* y;
double long wynik;
double long x, a, z;
double long n_silnia ,dwa_n_silnia;
double long WTF;
double long wtff;
double long epsilon;
int c;

int main() {
	y = &wynik;
	*y = 1;
	x = 0.95;
	n_silnia = 1;
	dwa_n_silnia = 1;
	epsilon = 1;
	recursion();
	printf("y=%lf\n", epsilon);
}

double recursion() {
	if (n >= 20) {
		return 0;
	}
	n += 1;
	n_silnia *= n;
	dwa_n_silnia *= (n * 2);
	wtf();
	wtff = pochodna();

	*y = ((pow(-1, n)*(-1)) * ((pow(2, n) - 1) / pow(2, 2 * n)) * (dwa_n_silnia / (n_silnia * 2)));
	epsilon += *y * pow(x, n);
	printf("PUCH\n");
	return recursion();
}

double pochodna() {

	return ((pow((1 + x), ((1.0 / 4) - n))) / (pow(4, n))) * (n_silnia / wtf());
}

double wtf() {
	//(1!)(2!)(3!)...(n−1)!
	int WTF = 1;
	for (c = 0; c >= n; c++) {
		WTF *= c;
	}
	return WTF;
}
