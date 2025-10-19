//Liczba słów w linii tekstu (2) - tablice w argumentach funkcji
#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE 256
int ile_slow_1(char*), ile_slow_2(char*), ile_slow_3(char*), ile_slow(char*);
int main() {
	char d[MAX_LINE], * dd,z,b;
	int l;
	dd = gets(d);
	/* Tu zostanie wyprowadzony caly wczytany tekst */
	printf("%s\n", dd);
	l = ile_slow_1(d);
	printf("%d\n", l);
	l = ile_slow_2(dd);
	printf("%d\n", l);
	/* I tu zostanie wyprowadzony caly wczytany tekst */

	while ((a = *dd) != '\0') {
		if (b == z){ 
			while (*dd) {
				*dd;

			}
		}

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
	/* Ile jest slow w linii tekstu. Wskaźniki w argumentach funkcji*/
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
	/* Ile jest slow w linii tekstu. Elementy tablic == wskazanie pośrednie*/
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