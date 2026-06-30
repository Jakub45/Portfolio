#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fun_3(int& k);
int main()
{
	int i = 1;
	int& r = i;
	fun_3(i);
	printf("i=%d\n", i);
	r = 20;
	printf("i=%d\n", i);
}
void fun_3(int& k)
{
	k = 10 * k;
}