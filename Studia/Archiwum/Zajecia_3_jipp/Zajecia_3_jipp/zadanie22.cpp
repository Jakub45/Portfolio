//Liczba s³ów w wielu liniach tekstu (2) - alokacja pamiêci
#pragma warning (disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 256
#define MAX_LINES 200
FILE* fd = NULL;
int ile_slow(char*);
int main()
{
	/* Ile slow w wielu liniach tekstu, alokacja pamieci */
	char* d[MAX_LINES], bufor[MAX_LINE];
	int len, i, l;
	if (!(fd = fopen("DANE.txt", "r")))
	{
		printf("Blad otwarcia zbioru\n");
		exit(2);
	}
	i = 0;
	l = 0;

		while (i < MAX_LINES && fgets(bufor, MAX_LINE, fd))
		{
			len = strlen(bufor);
			bufor[len - 1] = '\0';
			if ((d[i] = (char*)malloc((unsigned)len)) == (char*)NULL)
			{
				printf("Brak pamieci\n");
				exit(3);
			}
			strcpy(d[i], bufor);
			l += ile_slow(d[i]);
			i++;
		}
	fclose(fd);
	fd = NULL;
	printf("%d\n", l);
	/* Tekst w pamiêci, tablica d przechowuje wskaŸniki do linii tekstu */
}
int ile_slow(char* te)
{
	char p, b = ' ';
	int l = 0;
	while (p = b, b = *te++)
		if (b != ' ' && p == ' ') l++;
	return(l);
}