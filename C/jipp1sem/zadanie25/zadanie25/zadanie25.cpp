#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#pragma warning (disable: 4996)


// Typy zmiennych. Deklaracje.
double bok_a_lub_r, bok_b, bok_c;


int warunek_istnienia_trojkata()
{
	if (bok_a_lub_r >= bok_b + bok_c || bok_b >= bok_a_lub_r + bok_c || bok_c >= bok_a_lub_r + bok_b) {
		printf("To nie jest trojkat. Bok nie moze byc wiekszy badz rowny sumie pozostalych.\n");
		exit(1);
	}
	if (bok_a_lub_r == 0 || bok_b == 0 || bok_c == 0) {
		printf("To nie jest trojkat. Bok nie moze byc mniejszy badz rowny zero.\n");
		exit(1);
	}

}

//==================funkcje do obliczen obwodow i pol figur.
double pole_trojkata()
{
	double p = (bok_a_lub_r + bok_b + bok_c) / 2.0;
	double S = (sqrt(p * (p - bok_a_lub_r) * (p - bok_b) * (p - bok_c)));
	return S;
}
double obw_trojkata()
{
	double p = (bok_a_lub_r + bok_b + bok_c);
	return p;
}
double pole_kwadratu()
{
	double S = (bok_a_lub_r * bok_b);
	return S;
}
double obw_kwadratu()
{
	double p = (bok_a_lub_r + bok_b + bok_a_lub_r + bok_b);
	return p;
}
double pole_kola()
{
	double R = (3.14159265359 * pow(bok_a_lub_r, 2));
	return R;
}
double obw_kola()
{
	double p = (2 * 3.14159265359 * bok_a_lub_r);
	return p;
}
//==========================================================



int main()
{
	// Odpowiedz uzytkownika.
	int decision;
	printf("Pole i obwod jakiej figury chcesz policzyc ? Podaj odpowiednia cyfre: trojkat = 1, prostokat = 2, kolo = 3.\n\n");
	scanf("%d", &decision);

	// Sprawdzanie prawdziwosci podanych danych.
	if (decision != 1 && decision != 2 && decision != 3 ) {
		printf("Podana zostala zla wartosc\n\n");
		exit(1);
	}

	// Reszta danych podawanych prez uzytkownika.
	printf("Podaj odpowiednie wymiary.\n");
	printf("W stuacji, kiedy wybrany byl trojkat, podaj bok a, b, c, w sytuacji prostokata, podaj bok a, b.\n");
	printf("W przypadku kola pierwsza podana wartosc jest promieniem\n");
	printf("Za reszte wartosci wstaw 0... lub cokolwiek innego.\n");
	scanf("%le%le%le", &bok_a_lub_r, &bok_b, &bok_c);


	if (decision == 1) {
		warunek_istnienia_trojkata();
		double obwod = obw_trojkata();
		printf("Obwod trojkata wynosi %f jednostek miary.\n\n", obwod);
		double pole = pole_trojkata();
		printf("Pole trojkata wynosi %f jednostek kwadratowych miary. \n", pole);
		exit(1);
	}
	if (decision == 2) {
		double obwod = obw_kwadratu();
		printf("Obwod czworokata %f jednostek miary. \n\n", obwod);
		double pole = pole_kwadratu();
		printf("Pole czworokata %f jednostek kwadratowych miary. \n", pole);
		exit(1);
	}
	if (decision == 3) {
		double obwod = obw_kola();
		printf("Obwod kola %f jednostek miary. \n\n", obwod);
		double pole = pole_kola();
		printf("Pole kola %f jednostek kwadratowych miary. \n", pole);
		exit(1);
	}
	else {
		printf("Podana zostala zla wartosc\n\n");
		exit(1);
	}
}
