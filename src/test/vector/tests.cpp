#include <limits>

#include <catch/catch.hpp>

#include <vector/vector.hpp>
#include <algorithm>

TEST_CASE ("operator[]", "[vector]") {
    Vector x{4};
    x[0] = 4;
    x[1] = 5;
    x[2] = 9;
    x[3] = 14;

    CHECK(x[1] == 5);
    CHECK(x[2] == 9);

    CHECK_THROWS(x[4] == 0);
}

TEST_CASE ("size", "[vector]") {
    Vector x{4};
    Vector y{0};
    CHECK(x.size() == 4);
    CHECK(y.size() == 0);
}

TEST_CASE ("operator[] expression", "[vector]") {
    Vector x{3};
    CHECK((x[1] = 5) == 5);
}
