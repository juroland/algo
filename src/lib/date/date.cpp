#include "date.hpp"

#include <array>

#include <gsl/gsl>

Date::Date(int y, int m, int d): y_{y}, m_{m}, d_{d}
{
    Expects(y >= 1 && m >= 1 && d >= 1);
    Expects(m <= 12);
    Expects(d <= days_in_ith_month(y, m));
}

void Date::increment_day()
{
    if (d_ == days_in_ith_month(y_, m_)) {
        d_ = 1;
        if (m_ != 12) {
            ++m_;
        } else {
            m_ = 1;
            ++y_;
        }
    } else {
        ++d_;
    }
}

bool Date::operator==(const Date& other) const
{
    return (y_ == other.y_) && (m_ == other.m_) && (d_ == other.d_);
}

std::ostream &operator<<(std::ostream &os, const Date &dt)
{
    os << dt.y_ << '/' << dt.m_ << '/' << dt.d_;
    return os;
}

bool is_leap_year(int y)
{
    Expects( y >= 1);
    bool fourth = y % 4 == 0;
    bool hundredth = y % 100 == 0;
    bool four_hundredth = y % 400 == 0;
    return fourth && (!hundredth || four_hundredth);
}

int days_in_ith_month(int y, int m)
{
    Expects( y >= 1 && m >= 1 && m <= 12 );
    static const std::array<int, 13> days { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int n = days[m];
    if (m == 2 && is_leap_year(y))
        ++n;
    return n;
}