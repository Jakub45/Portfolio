//Poziom: łatwy 
//Wypisz wszystkie liczby od 1 do 100, które są podzielne przez 3. Skorzystaj z pętli for.

#include <stdio.h>
#include <iostream>

int main(){
    for (int number = 0; number <=100; number++ ){
        if (number % 3 == 0 && number > 0){
            std::cout << number << "\n";
        }
    }
}