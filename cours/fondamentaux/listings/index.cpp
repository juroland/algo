#include <iostream>

int index(const char *s, char ch)
{
    const char *p = s;
    for (;; ++p)
    {
        if (*p == ch)
            return p - s;
        if (!*p)
            return -1;
    }
}

int main()
{
    std::cout << index("one two", 't') << '\n'
              << index("one two", 'e') << '\n'
              << index("one two", 'y') << '\n'
              << index("one two", 'o') << '\n'
              << index("", 't') << std::endl;
    return 0;
}