// Zadanie 23

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


