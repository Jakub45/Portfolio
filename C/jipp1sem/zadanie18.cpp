#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable : 4996)


int hello_world();

int x;

int main() {
	hello_world();
}

int hello_world() {

	printf("jak duzo razy chcesz wypisac 'Hello World!' ? \n\n\n");
	scanf("%d\n", &x);
	while (x != 0) {
		x = x - 1;
		printf("Hello World!\n"); }
	return 0;
}