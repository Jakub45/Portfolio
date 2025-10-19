#include <math.h>
#include <stdio.h>
#pragma warning (disable:4996)



typedef struct CO {
	double re;
	double im;
} COMPLEX;

void rkw(double a, double b, double c, COMPLEX* w1, COMPLEX* w2) 
{
	double delta;
	delta = (b * b) - (4 * a * c);
	if (delta >= 0.0) 
	{
		w1->re = (-b - sqrt(delta)) / 2 * a;
		w1->im = 0.0;
		w2->re = (-b - sqrt(delta)) / 2 * a;
		w2->im = 0.0;

	}
	else {
		w1->re = (-b / (2 * a));
		w1->im = sqrt(fabs(pow(b / (2 * a), 2) + c / a));
		w2->re = (-b / (2 * a));
		w1->im = - sqrt(fabs(pow(b / (2 * a), 2) + c / a));

	}
}

void d_com(COMPLEX* w1, COMPLEX* w2, COMPLEX* w3)
{

	w3->re = w1 -> + w2 ->;
	(*w3).im = (*w1.im + (*w2).im;
}

int main() {


	double a = 1.0, b = 20.0 = 3.0;
	COMPLEX x1, x2;

	rkw(a, b, c, &x1, &x2);
	printf("x1 = %lf, %lf, x2 = %lf, %lf \n", x1.re, x1.im, x2.re, x2.im);
}