#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#pragma warning(disable: 4996)

int main()
{
	double bok_a;
	double bok_b;
	double bok_c;

	printf("Podaj 3 boki trojkata\n");
	scanf("%le%le%le", &bok_a, &bok_b, &bok_c);


	if (bok_a == 0 || bok_b == 0 || bok_c == 0) {
		printf("To nie jest trojkat. Bok nie moze byc mniejszy badz rowny zero.\n");
		exit(1);
	}
	if (bok_a >= bok_b + bok_c || bok_b >= bok_a + bok_c || bok_c >= bok_a + bok_b) {
		printf("To nie jest trojkat. Bok nie moze byc wiekszy badz rowny sumie pozostalych.\n");
		exit(1);
	}
	else {
		printf("To jest trojkat, jest ok.\n");
		double p_obw = (bok_a + bok_b + bok_c) / 2.0;
		double pole_trojkata = sqrt(p_obw*(p_obw - bok_a)*(p_obw - bok_b)*(p_obw - bok_c));
		double promien_kola = (pole_trojkata / p_obw);

		printf("\n\nPole kola wpisanego w ten trojkat wynosi:  %f  ,\n promien tego kola wynosi: %f \n\n\n", pole_trojkata, promien_kola);
		exit(1);
	}



}