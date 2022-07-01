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
    std::cout << "Min : " << min<int>(1, 0.9) << std::endl;
    std::cout << "Min : " << min<double>(1, 0.9) << std::endl;
}

