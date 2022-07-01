#include <vector>
#include <list>
#include <numeric>

template<typename Container>
double arithmetic_mean(const Container& v)
{
    using Val = typename Container::value_type;
    Val sum = std::accumulate(v.cbegin(), v.cend(), 0);
    return sum / v.size();
} 
