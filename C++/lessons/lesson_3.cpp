//Poziom: średni
//Napisz funkcję int silnia(int n), która oblicza silnię liczby (n!) i przetestuj ją w main().


#include <iostream>

int silnia(double *x);

int main(){
double number;

std::cout << "input a number to calculate factorial" << "\n";
std::cin >> number;

silnia(&number);
std::cout << number << "\n";
}


int silnia(double *x){
    int i;
    i = *x;
    do {
        *x = *x * i;
        i--;
    } while (i > 0 );

    return *x;
}