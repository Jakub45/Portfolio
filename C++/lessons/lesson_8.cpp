#include <iostream>
#include <string>
#include <vector>

class Product {
private:
    std::string name;
    double value;
    int quantity;

    static double sum;

public:
    Product(std::string n, double v, int q) {
        name = n;
        value = v;
        quantity = q;
    }

    void display() const {
        std::cout << name << '\n';
        std::cout << value << '\n';
        std::cout << quantity << '\n';
    }

    double cart() {
        sum += value * quantity;
        std::cout << "Aktualna suma: " << sum << '\n';
        return sum;
    }
};

double Product::sum = 0;

int main() {
    std::vector<Product> produkty;

    produkty.push_back(Product("oat milk", 3.99, 2));
    produkty.push_back(Product("oat bread", 3.99, 1));
    produkty.push_back(Product("oat water", 1.99, 4));
    produkty.push_back(Product("oil", 7, 1));

    for (const auto& p : produkty) {
        p.display();
    }

    std::cout << "\n--- Podsumowanie koszyka ---\n";
    for (auto& p : produkty) {
        p.cart();
    }

    return 0;
}
