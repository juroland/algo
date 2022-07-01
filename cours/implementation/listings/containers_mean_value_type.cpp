#include <numeric>

template<typename Container>
double arithmetic_mean(const Container& v)
{
    typename Container::value_type sum;
    sum = std::accumulate(v.cbegin(), v.cend(), 0);
    return sum / v.size();
} 
