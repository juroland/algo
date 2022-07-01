#include <iostream>
#include "vector_generique.hpp"

template<typename T>
typename Vector<T>::value_type
sum(const Vector<T>& c) {
    typename Vector<T>::value_type v = 0;
    for (int i = 0; i < c.size(); ++i)
        v += c[i];
    return v;
}

int main() {
    Vector<double> v{3};
    v[0] = 12.7; v[1] = 2; v[2] = -3.5;
    std::cout << sum(v) << std::endl;
}
