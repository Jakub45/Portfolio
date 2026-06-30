#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable : 4996)

int x = 0;
int n;


int kolejne_liczby();

int main(){
	kolejne_liczby();
}

int kolejne_liczby() {
	scanf("%d\n", &n);
	while (n != 0) {
		x = x + 1;
		n = n - 1;
		printf("%d\n", x);
	}
	return x;
}