#include <iostream>

int main() {
    int number;

    while (true) {
        std::cout << "Podaj liczbe (0 aby zakonczyc): ";
        std::cin >> number;
        
        if (number % 2 == 0) {
            std::cout << "parzysta" << std::endl;
        } else {
            std::cout << "nieparzysta" << std::endl;
        }
    }

    return 0;
}
