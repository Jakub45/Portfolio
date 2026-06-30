/*


//*************************PLIK_1*****************************
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NULL 0

double fun1();
static int fun2();
extern int fun3();
static int c = 5;
double a, b = 10;
const char* xx[] = { "mama","tato","stryjek", NULL };
double aa[] = { 1,2,3,4,5,6 };
int main()
{
	double x, y = 5;
	int i, j, k;
	static double aa[] = { 11,12,13,14,15,16 };
	printf("%lf %lf \n", aa[0], aa[1]);
	j = fun2();
	k = fun3();
	printf("j=%d, k= %d\n", j, k);
}
double fun1(int x, int y)
{
	const char* xx[] = { "pies","kot","mysz", NULL };
	int i = 0;
	i++;
	return 0;
}
const char* xxxx[] = { "zima","wiosna","lato", NULL };
static int fun2()
{
	static int k = 0;
	puts("ppp fun2");
	k++;
	return(k);
}

*/