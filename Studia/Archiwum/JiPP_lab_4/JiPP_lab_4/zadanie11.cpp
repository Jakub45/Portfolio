/*
11. Napisz program, który utworzy dynamicznie(za pomoc¹ funkcji malloc) dwie tablice t1 i t2 liczb
ca³kowitych o rozmiarze n wczytywanym z klawiatury.Je¿eli operacja przydzia³u pamiêci dla t1
i t2 zakoñczy³a siê pomyœlnie(wskaŸniki t1 i t2 s¹ ró¿ne od NULL), to zainicjuj tablicê t1
losowymi liczbami.Napisz funkcjê, która korzystaj¹c z funkcji : srand, time, rand oraz operatora
dzielenia modulo uzupe³ni przekazan¹ do niej tablicê typu int o losowe liczby z zakresu od 0 do
99. Tablica niech bêdzie przekazywana przez wskaŸnik.ZnaleŸæ minimalny i maksymalny
element w tablicy oraz jego po³o¿enie.Wyprowadziæ na ekran zawartoœæ tablicy t1, a tak¿e
znalezione wartoœci i po³o¿enie(indeksy) minimum i maksimum.Przekopiowaæ tablicê t1 do t2
wykorzystuj¹c standardow¹ funkcjê memmove lub memcpy.Wyprowadziæ zawartoœæ tablicy
t2 na ekran.Przed zakoñczeniem programu zwolniæ pamiêæ przydzielon¹ t1 i t2.

*/


#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <time.h>
#pragma warning (disable:4996)

void fun(int* t, int n) {

	srand(time(0));
	for (int i = 0; i < n; i++) {

		t[i] = rand() % 100;
	}
}

int main(){

	int* t1, * t2, n;
	t1 = t2 = NULL;

	scanf("%d", &n);
	t1 = (int*)malloc((unsigned)n * sizeof(int));
	t2 = (int*)malloc((unsigned)n * sizeof(int));

	if (!(t1 || t2)) {

		printf("blad alokacji");
		exit(1);
	}

	fun(t1, n);
	for (int i = 0; i < n; i++) printf("%d, ", t1[i]);
	memcpy(t2, t1, n * sizeof(int));

	printf("\n");
	for (int i = 0; i < n; i++) printf("%d, ", t2[i]);

	if (t1) {
		free(t1);
		t1 = NULL;
	}
	if (t2) {
		free(t2);
		t2 = NULL;
	}
	
}