#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include <gsl/gsl>

template <typename Iterator>
struct EvenForwardIterator
{
    Iterator it_;
    Iterator end_;

  public:
    using value_type = typename Iterator::value_type;
    using difference_type = typename Iterator::difference_type;
    using pointer = typename Iterator::pointer;
    using reference = typename Iterator::reference;
    using iterator_category = std::forward_iterator_tag;

    EvenForwardIterator(Iterator begin, Iterator end)
        : it_(begin), end_(end) {}

    reference operator*() const { return *it_; }
    pointer operator->() const { return &(*it_); }

    bool operator==(const EvenForwardIterator& other) const { return it_ == other.it_; }
    bool operator!=(const EvenForwardIterator& other) const { return !(*this == other); }

    EvenForwardIterator &operator++()
    {
        if (std::distance(it_, end_) >= 2)
            std::advance(it_, 2);
        else
            it_ = end_;
        return *this;
    }

    EvenForwardIterator operator++(int)
    {
        auto tmp = *this;
        ++*this;
        return tmp;
    }
};

template <typename Iterator>
EvenForwardIterator<Iterator>
make_EvenForwardIterator(Iterator begin, Iterator end)
{
    return EvenForwardIterator<Iterator>{begin, end};
}

int main()
{

    std::vector<std::string> v{"zero", "one", "two", "three", "four",
                               "five", "six", "seven", "eight", "nine", "ten"};
    std::list<std::string> l{v.begin(), v.end()};

    std::copy(v.begin(), v.end(), std::ostream_iterator<std::string>(std::cout, " "));

    std::cout << '\n';

    {
        auto begin = make_EvenForwardIterator(v.begin(), v.end());
        auto end = make_EvenForwardIterator(v.end(), v.end());
        std::copy(begin, end, std::ostream_iterator<std::string>(std::cout, " "));
    }

    std::cout << '\n';

    {
        auto begin = make_EvenForwardIterator(l.begin(), l.end());
        auto end = make_EvenForwardIterator(l.end(), l.end());
        std::copy(begin, end, std::ostream_iterator<std::string>(std::cout, " "));
    }

    std::cout << std::endl;

    return 0;
}