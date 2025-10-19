//Poziom: średni
//Napisz funkcję, która dla danej liczby całkowitej zwraca sumę jej cyfr. Np. dla 123 → 6.

#include <iostream>
#include <string>

int main(){
    int sum = 0;
    std::string number;

    std::cout << "enter a number" << "\n";
    std::cin >> number;
 
    for (char digit : number) {
        if (isdigit(digit)) {  // tylko jeśli to cyfra
            sum += digit - '0';
        }
    }

    std::cout << sum << "\n";
}