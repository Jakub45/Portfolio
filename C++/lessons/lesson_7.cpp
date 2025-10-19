//Poziom: średnio-trudny

//Zaprojektuj klasę Prostokat z polami szerokosc i wysokosc. Dodaj metody:

//obwod()
//pole()
//czyKwadrat() (zwraca true jeśli to kwadrat)

#include <iostream>
#include <math.h>

class Rectangle {
private:
    double side_a, side_b;
public:
    Rectangle(double a, double b){
        side_a = a;
        side_b = b;
    }

    double circuit_calc() const {
        return (2* side_a) + (2* side_b);
    }

    double area_calc() const {
        return side_a * side_b;
    }
    
    bool is_rectangle()const {
        return side_a > 0 && side_b > 0 && side_a != side_b;
    }

};


int main(){

    Rectangle figure1 (5, 5);


    std::cout << figure1.circuit_calc() << '\n';
    std::cout << figure1.area_calc() << '\n';
    std::cout << (figure1.is_rectangle() ? "Yes" : "No") << '\n';
}