#include <iostream>

int main(){

    char symbol;
    double first_num;
    double second_num;
    double result;


    std:: cout << "Simple calculator. type first number, then type symbol of operation and then type second number, separated by spaces";
    std:: cin >> first_num >> symbol >> second_num;


    switch(symbol) {

        case '+':
            result = first_num + second_num;
            break;
        case '-':
            result = first_num - second_num;
            break;
        case '*':
            result = first_num * second_num;
            break;
        case '/':
            result = first_num / second_num;
            break;
    }

    std::cout << "result is : " << result << "\n";
}