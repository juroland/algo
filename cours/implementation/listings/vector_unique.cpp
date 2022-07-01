#include "vector_unique.hpp"

Vector::Vector(int size)
    : size_{size},
      elem_{std::make_unique<double[]>(size)} {}

double&
Vector::operator[](int i) { return elem_[i]; }

const double&
Vector::operator[](int i) const { return elem_[i]; }

int 
Vector::size() const { return size_; }