#include <vector>
#include <list>
#include <numeric>

double arithmetic_mean(const std::vector<double>& v)
{
    double sum = std::accumulate(v.cbegin(), v.cend(), 0);
    return sum / v.size();
} 

double arithmetic_mean(const std::list<double>& v)
{
    double sum = std::accumulate(v.cbegin(), v.cend(), 0);
    return sum / v.size();
} 