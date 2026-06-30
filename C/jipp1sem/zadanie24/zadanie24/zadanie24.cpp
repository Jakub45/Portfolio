#include <stdio.h>
#include<stdlib.h>
#pragma warning (disable: 4996)
int main()
{
    int a;
    int b;
    int c;
    int d;

    printf("podaj 4 liczby calkowite, oddzielone przyciskiem Enter.\n\n");
    scanf("%d%d%d%d", &a,&b, &c, &d);

    int max_wartosc = a;
    int i = 1;
    while (i) {
        if (a < b)
            max_wartosc = b;
            if (b < c)
                max_wartosc = c;
                if (c < d)
                    max_wartosc = d; 
        if (a < c)
            max_wartosc = c;
            if (c < d)
                max_wartosc = d;
        if (a < d)
            max_wartosc = d;

        printf("najwieksza liczba jest : %d \n\n", max_wartosc);
        i = 0;
    exit(1); }
}