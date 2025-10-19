#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double funkcja(double x, double f(double))
{
	return x * x + (*f)(x);
}
int main()
{
	double x = 0.0;
	printf("dla x = %lf, f(x) = %lf, \n",x, funkcja(x, sin));
	printf("dla x = %lf, f(x) = %lf, \n",x, funkcja(x, cos));


}