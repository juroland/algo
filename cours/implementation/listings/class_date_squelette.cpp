class Date
{
    int y_, m_, d_;

  public:
    Date(int y = 1, int m = 1, int d = 1);

    void increment_day();

    bool operator==(const Date& other) const;
    
    friend std::ostream &operator<<(std::ostream &, const Date &);
};
