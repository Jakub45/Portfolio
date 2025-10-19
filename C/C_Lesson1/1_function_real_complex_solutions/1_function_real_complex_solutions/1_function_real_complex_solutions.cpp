

//Zadanie 22.

#include <stdio.h> // Standardowa biblioteka wejścia-wyjścia
#include <float.h>
#include <stdlib.h>
#include <tchar.h>
#include <math.h>
#include <complex.h>

#pragma warning (disable: 4996)


double a = 0.0, b = 0.0, c = 0.0;
int ret = -1;
double r1, r2, u1, u2;



typedef struct {
    double real;
    double imag;
} Complex;

Complex createComplex(double real, double imag) {
    Complex z;
    z.real = real;
    z.imag = imag;
    return z;
}


//to jest deklaracja funkcji
static void my_exit();
static void my_return();

void complex_numbers() {
    r1 = 0.0 - b / (2 * a);
    r2 = r1;

    u1 = (sqrt(fabs(pow((b/2*a),2))) - (c/a));
    u2 = (0.0 - sqrt(fabs(pow((b / 2 * a), 2))) - (c / a));

}

void printComplex(Complex z) {
    printf("%.2f + %.2fi\n", z.real, z.imag);
}

int main(int argc, _TCHAR* argv[])
{




    //input data
    printf("Program obliczenia rzeczywistych pierwiastkow rownania kwadratowego\n");
    printf("-------------------- a*x^2+b*x+c = 0 ------------------------------\n\n");
    printf("Podaj a,b,c\n");
    ret = scanf("%le%le%le", &a, &b, &c);
    if (ret != 3)
    {
        printf("Blad przy wczytaniu\n");
        printf("Wczytane: a = %e  b = %e  c = %e\n", a, b, c);
        //To jest blad oprogramowania
        my_exit();
    }
    //Sprawdzenie a
    if (a == 0.0)  //To nie jest dobry kod: a jest typu double!!!
    {
        //a == 0
        printf("To nie jest rownanie kwadratowe: a = 0.\n");
        //To jest blad uzytkownika przy wprowadzeniu danych
        my_exit();
    }
    //Obliczenie D
    double D = -1.0;  //to jest inicjalizacje zmiennej
    D = b * b - 4.0 * a * c;
    if (D < 0.0)
    {
        //brak pierwiastkow rzeczywistych
        printf("Brak pierwiastkow rzeczywistych: D = %e  < 0.\n", D);
        complex_numbers();

        Complex z1 = createComplex(r1, u1);
        Complex z2 = createComplex(r2, u2);

        printf("Liczba zespolona z1:\n");
        printComplex(z1);
        printf("Liczba zespolona z2:\n");
        printComplex(z2);
    }
    else {
        //Obliczenie pierwiastkow
        double p1, p2, x1, x2;
        p1 = -b / (2.0 * a);
        p2 = sqrt(D) / (2.0 * a);
        x1 = p1 + p2;
        x2 = p1 - p2;
        printf("Rownanie kwadratowe: %lf *X*X + %lf *X + %lf = 0\n\n", a, b, c);
        printf("Pierwiastki:  x1 = %e    x2 = %e\n", x1, x2);
        printf("---------------------------------------------------------");
        my_return();
    }
    return 0;
}
void my_exit()

{
    int ch;
    printf("Zakoncz - ctrl+Z Enter\n");
    while ((ch = getchar()) != EOF)
        ;
    exit(1);
}

void my_return()

{
    int ch;
    printf("Zakoncz - ctrl+Z Enter\n");
    while ((ch = getchar()) != EOF)
        ;
    exit(0);
}



