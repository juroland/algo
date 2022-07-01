#include <iostream>
#include <vector>

template<typename C, typename P>
int count(const C& c, P pred)
{
    int cnt = 0;
    for (const auto& x: c) {
        if (pred(x))
            ++cnt;
    }
    return cnt;
}

template<typename T>
class Less_than {
    const T val;
public:
    Less_than(const T& v): val(v) {}
    bool operator()(const T& x) const { return x < val; }
};

int main()
{
    std::vector<int> v {31, 1, 464, 233, 12};
    std::cout << count(v, Less_than<int>{42}) << std::endl;
}