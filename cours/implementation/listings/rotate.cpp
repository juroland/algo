#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << '[';
    std::string sep;
    for (const auto& x : v) {
        os << sep << x;
        sep = ", ";
    }
    return os << ']';
}

int main()
{
    std::vector<int> v(10);
    std::iota(v.begin(), v.end(), 1);
    std::cout << v << '\n';

    {
        std::vector<int> w = v;
        std::rotate(w.begin(), std::next(w.begin()), w.end());
        std::cout << w << '\n';
    }

    {
        std::vector<int> w = v;
        std::rotate(w.begin(), std::next(w.begin()), std::next(w.begin(), 6));
        std::cout << w << '\n';
    }

    {
        std::vector<int> w = v;
        std::rotate(w.rbegin(), std::next(w.rbegin()), w.rend());
        std::cout << w << '\n';
    }
}