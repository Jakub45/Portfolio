#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

char x;
char y;
int i = 0;
bool is_on = true;

int main() 
{
	char* ptr = NULL;
	char str[7] = "abcdef";
	while (is_on = true) {
		printf("%c", str[++i]);
	}
	char symb;
	ptr = &str[0]; //wskazuje na element str[0]
		ptr++;
		printf("%c", str);
	
}

