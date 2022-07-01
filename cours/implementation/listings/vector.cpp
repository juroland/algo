#include "vector.hpp"

Vector::Vector(int size): size_{size}, elem_{new double[size]} {}

Vector::~Vector() { delete[] elem_; }

double&
Vector::operator[](int i) { return elem_[i]; }

const double&
Vector::operator[](int i) const { return elem_[i]; }

int 
Vector::size() const { return size_; }