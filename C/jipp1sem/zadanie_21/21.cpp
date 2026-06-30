#include<stdio.h>
#include<math.h>
#include<cmath>
int main()
{
	double x = 3.14;
	double y = 12.56;
	double z = 7.0;

	int k = 2;
	int m = 4;

	double w1 = pow(x / (y * z), (1.0 / 3)) * log(pow(x, 2) + pow(y, 2));
	double w2 = sin(k * (x / 2)) * cos(m * y) + (y * exp((2 * x) - 1));
	double w3 = abs(x / (2 * pow(y, 2) + 1)) + sqrt(y / (pow(z, 2) + 3)) + 5 * pow((y + z), 3);
	double w4 = (x / (y * z)) * pow(z + 1, (1.0 / 3)) + pow(pow(x, 2) + pow(z, 2) + 1, (1.0 / k)) - fabs(y);
	double w5 = (1 / (sqrt(pow(x, 2) + pow(y, 2) + pow(k, 2))) + (1 / x) * sin(k * y));

	printf("%.8lf\n", w1);
	printf("%.8lf\n", w2);
	printf("%.8lf\n", w3);
	printf("%.8lf\n", w4);
	printf("%.8lf\n", w5);

}