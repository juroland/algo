#include <iostream>

struct Date { int y, m, d; };

std::ostream& operator<<(std::ostream& os, const Date& dt)
{
    os << dt.y << '/' << dt.m << '/' << dt.d;
    return os;
}

int main()
{
    Date alan_birthday{1912, 6, 23};
    alan_birthday.d = 38;
    std::cout << alan_birthday << std::endl;
}