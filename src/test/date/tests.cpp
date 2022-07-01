#include <vector>
#include <sstream>

#include <catch/catch.hpp>

#include <date/date.hpp>
#include <algorithm>

TEST_CASE ("constructor", "[date]") {
    CHECK_NOTHROW(Date{2017, 11, 9});
    CHECK_THROWS(Date{9, 11, 2017});
    CHECK_THROWS(Date{2017, 8, 32});
    CHECK_THROWS(Date{-50, 8, 9});
}

TEST_CASE ("output stream", "[date]") {
    std::vector<std::pair<Date, std::string>> dates {
            { Date{2017, 11, 9}, "2017/11/9" },
            { Date{1977, 2, 28}, "1977/2/28" }
    };


    for (const auto& date : dates) {
        std::ostringstream os;
        os << date.first;
        CHECK(os.str() == date.second);
    }
}

TEST_CASE ("operator==", "[date]") {
    std::vector<std::tuple<Date, Date, bool>> comparisons {
        std::make_tuple(Date{2017, 11, 9},  Date{2017, 11, 9}, true),
        std::make_tuple(Date{2017, 11, 9},  Date{2018, 11, 9}, false),
        std::make_tuple(Date{2017, 11, 9},  Date{2017, 10, 9}, false),
        std::make_tuple(Date{2017, 11, 9},  Date{2017, 10, 1}, false),
        std::make_tuple(Date{2017, 11, 9},  Date{20017, 11, 9}, false)
    };

    Date dt1, dt2;
    bool diff;
    for (const auto& comp : comparisons) {
        std::tie(dt1, dt2, diff) = comp;
        if (diff)
            CHECK(dt1 == dt2);
        else
            CHECK_FALSE(dt1 == dt2);
    }
}


TEST_CASE ("increment_day", "[date]") {
    std::vector<std::pair<Date, Date>> pairs {
            { Date{2001, 11, 9}, Date{2001, 11, 10} },
            { Date{1977, 2, 28}, Date{1977, 3, 1} },
            { Date{2017, 12, 31}, Date{2018, 1, 1 }}
    };

    Date dt1, dt2;
    for (const auto& p : pairs) {
        std::tie(dt1, dt2) = p;
        dt1.increment_day();
        CHECK(dt1 == dt2);
    }
}