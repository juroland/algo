#include <iostream>

// Déclaration
template<typename T>
T min(T a, T b);

// Définition
template<typename T>
T min(T a, T b) {
    return (b < a) ? b : a;
}

int main() {
    double x, y;
    std::cin >> x >> y;
    std::cout << "Min : " << min(x, y) << std::endl;
}
