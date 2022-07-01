class Date
{
    int y, m, d;

  public:
    Date(int yy, int mm, int dd)
        : y{yy}, m{mm}, d{dd} { /* ... */}

    void add_day(int n) { /* ... */}
};

int main()
{
    Date alan_birthday{1912, 6, 23};
    // alan_birthday.d = 38
}