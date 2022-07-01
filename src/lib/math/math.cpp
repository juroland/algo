#include "math.hpp"

#include <cmath>
#include <numeric>
#include <functional>

double geometric_mean(const std::vector<double>& x)
{
    double prod = std::accumulate(x.cbegin(), x.cend(), 0, std::multiplies<double>());
    return std::pow(prod, 1./x.size());
}
