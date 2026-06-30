#include <stdio.h>
#include<stdarg.h>
int max(int ile, int jeden, ...)
{
	va_list arg;
	va_start(arg, jeden);
	int max = jeden;
	for (int i = 2; i <= ile; i++) {
		int a = va_arg(arg, int);
		if (a > max) max = a;
	}
	va_end(arg);
	return max;
}
int main() {
	printf("%d\n", max(9, 1, 2, 3, 4, 5, 60, 7, 8, 9));
	return 0;
}