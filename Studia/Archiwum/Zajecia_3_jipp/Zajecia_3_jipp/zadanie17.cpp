//Liczba s≥Ûw w linii tekstu (2) - tablice w argumentach funkcji
#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)
#define MAX_LINE 256
int ile_slow_1(char*), ile_slow_2(char*), ile_slow_3(char*), ile_slow(char*);
int main() {
	char d[MAX_LINE], * dd, t[MAX_LINE], * tt;
	int l = 0, p;

	printf("podaj tekts 1\n");
	dd = gets(d);
	printf("podaj tekts 2\n");
	tt = gets(t);
	printf("podaj pozycje znaku w tekscie 2\n");
	scanf("%d", &p);


	while (*dd)
	{
		dd++;
	}
	while (*tt)
	{
		dd++;
		dd++, tt++;
	}

}


int ile_slow_1(char te[])
{
	/* Ile jest slow w linii tekstu. Tablice w argumentach funkcji*/
	char p = ' ', b;
	int l = 0, i = 0;
	while (b = te[i++])
	{
		if (b != ' ')
			if (p == ' ') l++;
		p = b;
	}
	return l;
}
int ile_slow_2(char* te)
{
	/* Ile jest slow w linii tekstu. Wskaüniki w argumentach funkcji*/
	char p = ' ', b;
	int l = 0;
	while (b = *te)
	{
		if (b != ' ')
			if (p == ' ') l++;
		p = b;
		te++;
	}
	return l;
}
int ile_slow_3(char* te)
{
	/* Ile jest slow w linii tekstu. Elementy tablic == wskazanie poúrednie*/
	char p = ' ', b;
	int l = 0, i = 0;
	while (b = te[i])
	{
		if (b != ' ')
			if (p == ' ') l++;
		p = b;
		i++;
	}
	return l;
}
int ile_slow(char* te)
{
	char p, b = ' ';
	int l = 0;
	while (p = b, b = *te++)
		if (b != ' ' && p == ' ') l++;
	return(l);
}