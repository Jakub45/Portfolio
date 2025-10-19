# include <stdio.h>
# include <math.h>
# pragma warning (disable:4996)
# include <stdlib.h>

double x, y;
double max;
double srednia;
double iloczyn = 1;
int i;
int main() {

	printf("Projekt A. Program do zliczania sredniej geometrycznej podanych wartosci. \n");

	printf("Z ilu elementow chcesz policzyc srednia geometryczna ?\n\n\n");

	scanf("%lf", &max);


	do{
		printf("podaj wartosc liczby dodatniej x\n");
		scanf("%lf", &x);

		if (x <= 0){
			printf("podane zle dane. x nie moze byc ujemny, ani miec wartosc zero.\n");
			printf("srednia z ostatnich wynikow = %lf.\nliczba elementow szeregu = %d.\n\n\n", srednia, i);
			return 0;
		}
		if (x >0){
			i += 1;
			iloczyn = (iloczyn * x);

			srednia = pow(iloczyn, (1.0 / i));

			printf("srednia = %lf\n\n", srednia);
		}
	} while (i < max);
}