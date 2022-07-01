#include <iostream>

// Déclaration
int min(int a, int b);

// Définition
int min(int a, int b) {
    return (b < a) ? b : a;
}

int main() {
    double x, y;
    std::cin >> x >> y;
    std::cout << "Min : " << min(x, y) << std::endl;
    return 0; // facultatif (par défaut)
}
