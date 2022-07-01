#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>

template <typename Iter>
typename Iter::value_type
dot(Iter first1, Iter last1, Iter first2)
{
    auto it1 = first1;
    auto it2 = first2;

    typename Iter::value_type val = 0;
    while (it1 != last1)
    {
        val += *it1 * *it2;
        ++it1;
        ++it2;
    }

    return val;
}

template <typename T>
struct greater_or_equal_than
{
    T val;
    bool operator()(const T &other)
    {
        return other >= val;
    }
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
    std::string sep;
    for (const auto &x : v)
    {
        os << sep << x;
        sep = ", ";
    }
    return os;
}

int main()
{
    std::vector<int> v{4, 12, 5, 23, 1, 7, -4, 2};
    std::vector<int> w{1, 32, -7, 3, 11, 0, -21, 1};
    std::cout << "dot(v, w) : " << dot(v.cbegin(), v.cend(), w.cbegin()) << '\n';

    std::vector<int> u{1, 32, 7, 3, 11, 0, 21, 1};
    std::cout << std::boolalpha
              << std::all_of(u.cbegin(), u.cend(), greater_or_equal_than<int>{0}) << '\n'
              << std::all_of(v.cbegin(), v.cend(), greater_or_equal_than<int>{0}) << '\n';

    std::vector<int> t = w;
    std::cout << t << '\n';
    std::replace_if(t.begin(), t.end(), [](int v) { return v < 0; }, 0);
    std::cout << t << '\n';

    auto osit = std::ostream_iterator<int>(std::cout, " ");
    *osit++ = 42;
    *osit++ = 43;
    *osit = 44;
    std::cout << std::endl;

    std::copy_if(w.cbegin(), w.cend(),
                 std::ostream_iterator<int>(std::cout, " "),
                 [](int v) { return v > 0; });
    std::cout << '\n';

    auto is_negative = [](int v) { return v < 0; };
    auto first = std::find_if(w.begin(), w.end(), is_negative);
    auto last = std::find_if(w.rbegin(), w.rend(), is_negative);

    std::cout << std::distance(w.begin(), first) << '\n'
              << std::distance(last, w.rend()) - 1 << '\n';

    {
        std::vector<std::pair<std::string, std::string>> birthday;
        birthday.push_back(std::make_pair("Edsger W. Dijkstra", "11 May 1930"));
        birthday.emplace_back("Alan Turing", "23 June 1912");
        birthday.emplace_back("Donald E. Knuth", "10 January 1938");
        auto pred = [](const auto &pair) { return pair.first == "Alan Turing"; };
        auto it = std::find_if(birthday.begin(), birthday.end(), pred);
        std::cout << it->first << ": " << it->second << '\n';
    }

    {
        std::cout << "q5" << '\n';
        std::vector<int> s = v;
        std::stable_partition(s.begin(), s.end(), [](const auto &v) { return v % 2 == 0; });
        std::cout << v << '\n'
                  << s << '\n';
    }

    {
        std::cout << "q6" << '\n';
        std::vector<int> s = v;
        auto pos = s.begin() + 1;
        auto left = s.begin() + 3;
        auto right = left + 2;
        std::rotate(pos, left, right);
        std::cout << v << '\n'
                  << s << '\n';
    }

    {
        std::cout << "q7" << '\n';
        std::vector<int> s = v;
        std::rotate(s.rbegin(), std::next(s.rbegin()), s.rend());
        std::cout << v << '\n'
                  << s << '\n';
    }

    std::flush(std::cout);
    return 0;
}