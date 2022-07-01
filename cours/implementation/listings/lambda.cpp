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

int main()
{
    std::vector<int> v {31, 1, 464, 233, 12};
    std::cout << count(v, [](int x) { return x < 42; }) << std::endl;
    int val = 42;
    std::cout << count(v, [&val](int x) { return x < val; }) << std::endl;
}