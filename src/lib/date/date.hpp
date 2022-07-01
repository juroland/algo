#include <ostream>

class Date
{
    int y_, m_, d_;

  public:
    Date(int y = 1, int m = 1, int d = 1);

    void increment_day();

    bool operator==(const Date& other) const;
    
    friend std::ostream &operator<<(std::ostream &, const Date &);
};

bool is_leap_year(int y);
int days_in_ith_month(int y, int m);