//Poziom: średni+
//Zdefiniuj strukturę Punkt z polami x i y. Napisz funkcję, która oblicza odległość między dwoma punktami w przestrzeni 2D.


#include <iostream>
#include <math.h>

struct Punkt {
    double x;
    double y;
};

int distance(double *x1, double*x2, double*y1, double*y2);

int main() {
    double dist;
    Punkt p1;
    // x,y for p1.
    std::cout << "choose x value for p1" << "\n";
    std::cin >> p1.x;

    std::cout << "choose y value for p1" << "\n";
    std::cin >> p1.y;


    Punkt p2;
    // x,y for p2.
    std::cout << "choose x value for p2" << "\n";
    std::cin >> p2.x;

    std::cout << "choose y value for p2" << "\n";
    std::cin >> p2.y;

    dist = distance(&p1.x, &p2.x, &p1.y , &p2.y);
    std::cout << dist << "\n";
}

int distance(double *x1, double*x2, double*y1, double*y2){
    double dist = sqrt(pow(*x2 - *x1, 2)+ pow(*y2 - *y1,2));
    return dist;
}