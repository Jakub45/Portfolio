/*

//*************************PLIK_2*****************************
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NULL 0

extern double fun1();
static double fun2();
int fun3();
static const char* c[] = { "slon","lew","pantera", NULL };
extern char* xx[];
static double fun2()
{
	static const char* zz[] = { "krzeslo","szafa","tapczan", NULL };
	puts("qqq fun2");
	return ((double)2.0);
}
int fun3()
{
	double ff;
	puts("qqq fun3");
	ff = fun2();
	return (5);
}

*/