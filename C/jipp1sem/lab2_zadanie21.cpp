#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable : 4996)

bool is_on = true;
char x;
char text;
int a = 0;

int main(char x) {
	printf("podaj znaki, jakie chcesz zapetlic:\n");
	scanf("%c\n",&x);
	while (is_on) {
		printf("%c",x);
		char x[(a = a + 1)];
		if (x == 'e') {
			printf("'e' nie mozna zapetlic, takie byly wymogi.");
			break;
		}
	}

}