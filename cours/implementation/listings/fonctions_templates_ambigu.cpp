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
    // error: no matching function for call to ‘min(int, double)’
    // template argument deduction/substitution failed
    std::cout << "Min : " << min(1, 0.9) << std::endl;
}

