#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v {31, 1, 464, 233, 12} ;

    for (int i = 0; i < v.size(); ++i)
        std::cout << v[i] << std::endl;
    
    for (auto it = v.begin(); it != v.end(); ++it)
        std::cout << *it << std::endl;

    for (int x : v)
        std::cout << x << std::endl;

    for (auto x : v)
        std::cout << x << std::endl;

    for (auto& x : v)
        std::cout << x << std::endl;
}