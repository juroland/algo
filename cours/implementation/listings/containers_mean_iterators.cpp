#include <vector>
#include <list>
#include <numeric>

template<typename Iter>
typename Iter::value_type arithmetic_mean(Iter first, Iter last)
{
    using Val = Iter::value_type;
    Val sum = std::accumulate(first, last, 0);
    return sum / v.size();
} 