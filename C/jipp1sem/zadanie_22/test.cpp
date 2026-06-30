// WW4_1.cpp : Defines the entry point for the console application.
//
// Wyklad 4
// Temat: Otwieranie i zamkniecie plikow. Operacje petli

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
# pragma warning (disable:4996)


//definicja zmiennych globalnych
static FILE* pInp = NULL; //ta zmienna jest dostepna w dowoljnym miescu pliku biezacego
static FILE* pOut = NULL; //ta zmienna jest dostepna w dowoljnym miescu pliku biezacego
//deklaracja: funkcji sà dostepny tylko w pliku biezacym
static int my_fun(double x_start, double x_end, double d_x);
static void my_exception_print(char* str);
static void All_Free();
int main(int argc, char* argv[])
{
	int retval = -1;
	double x_st = 0.0, x_en = 0.0, inc_x = 0.0;
	//Otwieranie pliku z danymy zrodlowymi
	pInp = fopen("input.txt", "r");
	if (!pInp)
	{
		my_exception_print("Plik input.txt nie pozostal otwarty");
	}
	//Otwieranie pliku dla zapisu wynikow
	pOut = fopen("output.txt", "w");
	if (!pOut)
	{
		my_exception_print("Plik output.txt nie pozostal otwarty");
	}
	//Czytaj dane z pliku input.txt
	retval = fscanf(pInp, "%lf%lf%lf", &x_st, &x_en, &inc_x);
	if (retval != 3)
		my_exception_print("Blad przy czytanii danych z pliku input.txt");
	//Oblicz tablice wartosci funkcji
	if (!my_fun(x_st, x_en, inc_x))
	{
		printf("Wprowadzone dane: x_st = %lf x_en = %lf inc_x = %lf\n",
			x_st, x_en, inc_x);
		my_exception_print("my_fun: blad danych");
	}
	//zamkni pliki

All_Free();
system("notepad.exe output.txt");
//system("pause");
return 0;
}
int my_fun(double x_start, double x_end, double d_x)
/*= ==========================================================================
============
Obliczenie tablicy wartosci funkcji 1.0 / (sqrt(1.0 - x * x + 5.0 * x * x * x))
IN: x_start - poczatkowe znaczenie argumentu x
x_end - koncowe znaczenie
d_x - przyrost argumenty(krok obliczenia)
OUT :
	RetVal : 1 - sukces
	0 - blad
	==============================================================================
	==========*/
{
	double x; //biezaca wartosc argumentu
	double f; //biezaca wartosc funkcji
	double tmp;
	const double eps = 1.0e-40;
	if (x_start > x_end || !pOut || d_x < eps)
		return 0;
	fprintf(pOut, "\n\tTablicowanie funkcji\n\t poczatek: %lf \tkoniec: %lf\tkrok: % lf\n",x_start, x_end, d_x);
	fprintf(pOut, "\n\t x\t\t f(x)\n");
	x = x_start;
	while (x <= x_end)
	{
		tmp = 1.0 - x * x + 5.0 * pow(x, 3.0);
		if (tmp < eps)
		{
			x += d_x; //jest koniecznie zeby uniknac nieskonczonej petli
			continue; //Uwazamy, ze jesli to jest wartosc mala - powstanie
				//dzielenie przez 0 - obejsc ten punkt
				//lub wartosc ujemna - sqrt(...) problem - obejsc
		}
		f = sqrt(tmp);
		f = 1.0 / f;
		//drukuj wynik. Uwaga: obiekt pOut jest zmienna globalna.
		fprintf(pOut, "\t %e\t %e\n", x, f);

		x += d_x;
	}
	return 1;
}
void All_Free()
/*= ==========================================================================
============
Zamykamy pliki
==============================================================================
==========*/
{
	if (pInp)
	{
		fclose(pInp);
		pInp = NULL;
	}
	if (pOut)
	{
		fclose(pOut);
		pOut = NULL;
	}
}
void my_exception_print(char* str)
{
	printf("%s\n", str);
	All_Free();
	int ch;
	while ((ch = getchar()) != EOF)
		;
	exit(1);
}