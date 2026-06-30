#include<stdio.h>
#include <math.h>
#include <float.h>
#include <cmath>

double round(double fValue)
{
	return fValue < 0 ? ceil(fValue - 0.5)
		: floor(fValue + 0.5);
}


double x,y;
int e = 1000;

int main() {
	x = 5.12345;
	x = round(x * e) / e;
	printf("%f\n",x);

	printf("%e\n", y);
	return 0;
}