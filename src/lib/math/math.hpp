#include <vector>

double geometric_mean(const std::vector<double>& x);

template<typename T>
T dot(const std::vector<T>& x, const std::vector<T>& y)
{
    typename std::vector<T>::const_iterator px = x.cbegin();
    typename std::vector<T>::const_iterator py = y.cbegin();

    T value = 0;

    while (px != x.end()) {
         value += *px * *py;
         ++px;
         ++py;
    }

    return value;
}
