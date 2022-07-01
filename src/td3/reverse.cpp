// Compile with -O2

#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <memory>
#include <vector>

template <typename T, template <typename...> class Container>
void reverse_swap(Container<T> &c)
{
    auto begin = c.begin();
    auto end = c.end();
    while (begin != end       // The range is no empty
           && begin != --end) // The range size is > 1
    {
        std::iter_swap(begin, end);
        ++begin;
    }
}

std::ostream &operator<<(std::ostream &os, const std::list<int> &list)
{
    std::copy(list.begin(), list.end(), std::ostream_iterator<int>(os, " "));
    return os;
}

// This function repeats the call to function f
// the number of times specified by n
template <typename Function>
void repeat(Function f, unsigned int n)
{
    while (n-- > 0)
        f();
}

template <typename Function>
double measure_execution(Function f, unsigned int n)
{
    using namespace std::chrono;
    using clock = steady_clock;

    clock::time_point start = clock::now();

    repeat(f, n);

    clock::time_point end = clock::now();

    return (double)duration_cast<milliseconds>(end - start).count() / n;
}

int main()
{
    struct data
    {
        char x[64];
    };

    struct fill_data
    {
        char v[10][64];
    };

    const int n = 1E6;

    // Reverse container
    {
        std::cout
            << std::endl
            << "## Reverse container"
            << std::endl;

        std::list<data> list;

        std::vector<data> vector;
        vector.reserve(n);

        repeat([&] {
            list.push_back(data{});
            auto x = new fill_data{};
            (void)x;
            vector.push_back(data{});
        },
               n);

        const int nb_repeat = 10;

        std::cout << "Reverse swap on list : "
                  << measure_execution([&] { reverse_swap(list); }, nb_repeat)
                  << std::endl;

        std::cout << "Reverse on list : "
                  << measure_execution([&] { list.reverse(); }, nb_repeat)
                  << std::endl;

        std::cout << "Reverse swap on vector : "
                  << measure_execution([&] { reverse_swap(vector); }, nb_repeat)
                  << std::endl;
    }

    // Reverse container with pointers
    {
        std::cout
            << std::endl
            << "## Reverse container with pointers"
            << std::endl;

        std::list<data *> list_p;

        std::vector<data *> vector_p;

        vector_p.reserve(n);

        repeat([&] {
            list_p.push_back(new data{});
            auto x = new fill_data{};
            (void)x;
            vector_p.push_back(new data{});
        },
               n);

        const int nb_repeat = 10;

        std::cout << "Reverse swap on list : "
                  << measure_execution([&] { reverse_swap(list_p); }, nb_repeat)
                  << std::endl;

        std::cout << "Reverse on list : "
                  << measure_execution([&] { list_p.reverse(); }, nb_repeat)
                  << std::endl;

        std::cout << "Reverse swap on vector : "
                  << measure_execution([&] { reverse_swap(vector_p); }, nb_repeat)
                  << std::endl;
    }

    return 0;
}
