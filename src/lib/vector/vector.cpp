#include "vector.hpp"

#include <gsl/gsl>

Vector::Vector(int size): size_(size)
{
    this->elem_ = new double[size];
}

Vector::~Vector()
{
    delete[] this->elem_;
}

double &Vector::operator[](int i)
{
    Expects(i >= 0 && i < size_);
    return this->elem_[i];
}

const double &Vector::operator[](int i) const
{
    Expects(i >= 0 && i < size_);
    return this->elem_[i];
}

int Vector::size() const
{
    return this->size_;
}
