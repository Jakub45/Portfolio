# include<stdio.h>
# include<stdlib.h>
# include<math.h>
# pragma warning(disable:4996)
double fun(double x)
{
	return 1 / (x * x + sqrt(1 + 2 * x + 3 * x * x));
}

int main(int argc, char* argv[]) {
	double a, b, x, dx, y;
	printf("podaj poaczatek, koniec przedzialu oraz krok \n");
	scanf("%lf%lf%lf", &a, &b, &dx);

	for (x = a; x <= b; x = x + dx)
	{
		printf("x=%lf f(x)=%lf\n", x, fun(x));

	}
	return 0;
}