#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable : 4996)

int silnia();
int x;
int wynik = 1;

int main(){
	silnia();
}

int silnia() {
	printf("podaj liczbe, ktorej chcesz policzyc silnie :");
	scanf("%d", &x);
	while (x > 1) {
		wynik = wynik * x;
		x = x - 1;
	}
	printf("%d\n", wynik);
	return 0;
}
