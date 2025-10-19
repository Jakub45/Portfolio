
// Zadanie 25

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
