struct Date
{
    int y, m, d;

    Date(int yy, int mm, int dd)
        : y{yy}, m{mm}, d{dd} { /* ... */}

};

int main()
{
    Date alan_birthday(1912, 6, 23);
    alan_birthday.d = 38;
}
