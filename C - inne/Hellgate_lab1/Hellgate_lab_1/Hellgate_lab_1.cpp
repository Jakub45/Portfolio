// Pierwsza część Hellgate_1. Podstawowe zmienne, typy etc.

#include <stdio.h> // Standardowa biblioteka wejścia-wyjścia
#include <locale.h>
#include <limits>
#include <float.h> 
#pragma warning (disable: 4996)

#define MAX_USERS 5 // stala MAX_USERS

int main(int argc, char* argv[]) {

    setlocale(LC_ALL, ""); // wprowadzenie polskich znakow

    int a = 5, b = 0, c = 3;
    // Wyświetlenie "Hello world!" na ekranie
    printf("Hello world!\n");

    // Przykład użycia liczby całkowitej
    int exampleNumber = 500; // Zmienna przechowująca przykład liczby całkowitej
    printf("\tLiczbami całkowitymi są na przykład %d oraz %d.\n", 1, exampleNumber);

    // Pobranie liczby od użytkownika
    int userNumber = 0; // Zmienna do przechowywania liczby podanej przez użytkownika
    printf("Podaj liczbę: ");

    // Sprawdzenie poprawności wejścia
    if (scanf("%d", &userNumber) == 1) {
        printf("Podana liczba to: %d\n", userNumber);
    }
    else {
        printf("Niepoprawny format liczby. Spróbuj ponownie.\n");
    }

    printf("integer range:\t%d\t%d\n", INT_MIN, INT_MAX); //przedzialy mozliwych wartosci dla konkretnych typow zmiennyh -
    printf("long int range:\t%ld\t%ld\n", LONG_MIN, LONG_MAX);
    printf("float range:\t%e\t%e\n", FLT_MIN, FLT_MAX);
    printf("double range:\t%e\t%e\n", DBL_MIN, DBL_MAX);
    printf("long double range:\t%e\t%e\n", LDBL_MIN, LDBL_MAX);
    printf("float-double epsilon:\t%e\t%e\n", FLT_EPSILON, DBL_EPSILON); // -



    return 0; // Zakończenie programu
}


























// Druga część Hellgate_1, czyli zadania 21, 22, 23, 24, 25.

/* //Zadanie 21.

#include <stdio.h>
#include <locale.h>
#include <math.h>  
#pragma warning (disable: 4996)

float x, y, z;
int k, m;
double w1, w2, w3, w4, w5;

//funkcje do obliczania konkretnych wyrażeń arytmetycznych:

void funkcja_w1() {
    w1 = (pow((x / (y * z)), (1.0 / 3.0)) * log(pow(x, 2) + pow(y, 2)));
}

void funkcja_w2() {
    w2 = (sin(k * x / 2.0) * cos(m * y)) + (y * exp((2.0 * x) - 1));
}

void funkcja_w3() {
    w3 = fabs(x / ((2 * (pow(y, 2))) + 1)) + sqrt(y / (pow(z, 2) + 3)) + (5 * pow((y + z), 3));
}

void funkcja_w4() {
    w4 = (x / (y * z) * pow(z + 1, 1 / 3.0) + pow(pow(x, 2) + pow(z, 2) + 1, 1.0 / k) - fabs(y));
}

void funkcja_w5() {
    w5 = (1.0 / sqrt(pow(x,2) + pow(y,2) + pow(k,2))) + (1/x) * sin(k*y);
}

// -

int main() {

    setlocale(LC_ALL, ""); // wprowadzenie polskich znakow

    printf("Zmienić wartości zmiennych rzeczywistych x,y,x, oraz całkowitych k, m ?\n");
    printf("Jeżeli nie (n), podane zostaną wartości domyślne.W innym wypadku wpisać cokolwiek");
    char n = getchar();

    if (n != 'n') { //jezeli uzytkownik chce wprowadzic zmiany:
        printf("podaj rzeczywiste x,y,z oraz całkowite k,m");
        scanf("%f %f %f %d %d", &x, &y, &z, &k, &m);


    } else { // jeżeli użytkownik nie chce wprowadzać zmian:
        x = 3.14; // zmienne rzeczywiste
        y = 12.56;
        z = 7;

        k = 2; //zmienne całkowite
        m = 4;
    }

    printf("Wprowadzone wartości:\n"); //wyswietlanie wprowadzonej wartosci
    printf("x = %f, y = %f, z = %f, k = %d,m = %d\n", x, y, z, k, m );

    //obliczenia funkcji w1 w2 w3 w4 w5

    funkcja_w1();
    funkcja_w2();
    funkcja_w3();
    funkcja_w4();
    funkcja_w5();
    printf(" %.8e\n %.8lf\n %.8lf\n %.8lf\n %.8lf\n", w1, w2, w3, w4, w5);


    return 0;
}

*/
























/* //Zadanie 22.

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

*/






















/* // Zadanie 23

#include <stdio.h> // Standardowa biblioteka wejścia-wyjścia
#include <stdlib.h>
#include <math.h> 
#include <locale.h>
#include <tchar.h>

#pragma warning (disable: 4996)


int main() {

    setlocale(LC_ALL, ""); // wprowadzenie polskich znakow
    bool triangle_exist;
    double a, b, c;

    double pole, promien, polowa_obwodu;

    printf("Program do obliczania trójąta. Podaj kolejne boki x,y,z\n");
    scanf("%lf %lf %lf",&a, &b, &c);

    if ((a < 0) || (b < 0) || (c < 0)) {
        printf("boki nie mogą być ujemne\n");
        return 0;
    }
    if ((a == b + c) || (b == a + c) || (c == b + a)) {
        printf("Suma dwóch boków równa jest trzeciemu, czyli to jest trójkąt zdegenerowany\n");
        printf("Pole i promien koła wpisanego w trójkąt są równe zeru\n");

        pole = 0;
        promien = 0;

        printf("pole wynosi %lf, promien wynosi %lf", pole, promien);
        return 0;
    }

    polowa_obwodu = ((a + b + c) / 2);
    pole = sqrt(polowa_obwodu * (polowa_obwodu - a) * (polowa_obwodu - b) * (polowa_obwodu - c));
    promien = pole / polowa_obwodu;

    printf("pole trójkąta wynosi %lf, a promień koła wpisanego w trójkąt %lf \n", pole, promien);

    return 0;
    
}

*/



















/*  // Zadanie 24

#include <stdio.h> // Standardowa biblioteka wejścia-wyjścia
#include <stdlib.h>
#include <math.h> // biblioteka matematyczna
#include <locale.h>
#include <tchar.h>


#pragma warning (disable: 4996)

int main() {
    setlocale(LC_ALL, ""); // wprowadzenie polskich znakow

    double a, b, c, d;

    printf("podaj 4 liczby a b c d\n");
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);


    if ((a > b) && (a > c) && (a > d)) {
        printf("pozycja 1\n");
        printf("największa wartość to liczba %lf o adresie %e\n", a, &a);
    } if ((b > a) && (b > c) && (b > d)) {
        printf("pozycja 2\n");
        printf("największa wartość to liczba %lf o adresie %e\n", b, &b);
    } if ((c > a) && (c > b) && (c > d)) {
        printf("pozycja 3\n");
        printf("największa wartość to liczba %lf o adresie %e\n", c, &c);
    } if ((d > b) && (d > a) && (d > c)) {
        printf("pozycja 4\n");
        printf("największa wartość to liczba %lf o adresie %e\n", d, &d);
    }

    return  0;
}

*/ 



















/* // Zadanie 25

#include <stdio.h> // Standardowa biblioteka wejścia-wyjścia
#include <stdlib.h>
#include <math.h> 
#include <locale.h>
#include <tchar.h>
#include <iostream>
#include <conio.h>


#pragma warning (disable: 4996)

#define M_PI 3.14159265358979323846
double a, b, c;

double pole, promien, polowa_obwodu;
double wybor;

int trojkat() {

    printf("podaj trzy liczby wieksze od 0\n");
    scanf("%lf %lf %lf", &a, &b, &c);

    if ((a < 0) || (b < 0) || (c < 0)) {
        printf("boki nie mogą być ujemne\n");
        return 0;
    }
    if ((a == b + c) || (b == a + c) || (c == b + a)) {
        printf("Suma dwóch boków równa jest trzeciemu, czyli to jest trójkąt zdegenerowany\n");
        printf("Pole i promien koła wpisanego w trójkąt są równe zeru\n");

        pole = 0;
        promien = 0;

        printf("pole wynosi %lf, promien wynosi %lf", pole, promien);
        return 0;
    }

    polowa_obwodu = ((a + b + c) / 2);
    pole = sqrt(polowa_obwodu * (polowa_obwodu - a) * (polowa_obwodu - b) * (polowa_obwodu - c));
    promien = pole / polowa_obwodu;

    printf("pole trójkąta wynosi %lf. \n", pole);

    return 0;
}

int prostokat() {
    printf("podaj dwa boki prostokatu\n");
    scanf("%lf %lf", &a, &b);

    if ((a <= 0) || (b <= 0)) {
        printf("boki nie mogą być ujemne lub równe zero\n");
        return 0;
    }
    pole = a * b;
    printf("pole prostokatu wynosi %lf\n", pole);
    return 0;
}

int kolo() {
    
    printf("podaj promien kola\n ");
    scanf("%lf", &promien);

    if (promien <= 0) {
        printf("promien nie może być ujemny lub równy zero\n");
        return 0;
    }
    pole = pow(promien, 2) * M_PI;

    printf("pole koła wynosi %lf\n", pole);
    return 0;
}

int main() {

    setlocale(LC_ALL, ""); // wprowadzenie polskich znakow

    printf("Program do obliczania pola figur geometrycznych.\n");
    printf("Podaj jaka chcesz obliczyc figure, trojkat (1), prostokat (2), czy kolo (3)");
    scanf("%lf", &wybor);
    if ((wybor != 1) && (wybor!=2) && ( wybor !=3)) {
        printf("podana zla wartosc\n"); 
        return 0;
    }
    if (wybor == 1) { // trojkat
        trojkat();
    }
    if (wybor == 2) { // prostokat
        prostokat();
    }
    if (wybor == 3) { // kolo
        kolo();
    }


    return 0;
}


*/