#include <iostream>
#include <chrono>
#include <string>
#include <unordered_map>
#include <random>
#include <algorithm>

// URNG (Uniform Random Generator) engine
std::default_random_engine& global_urng()
{
    static std::default_random_engine  u{};
    return u;
}

void randomize()
{
    static std::random_device  rd{};
    global_urng().seed( rd() );
}

template<typename IntType>
IntType pick_an_integer(IntType from, IntType thru)
{
    static std::uniform_int_distribution<IntType>  d{};
    using  parm_t  = typename decltype(d)::param_type;
    return d( global_urng(), parm_t{from, thru} );
}

template <typename Function>
void repeat(Function f, unsigned int n) {
    while (n-- > 0)
        f();
}

template <typename Function>
double measure_execution(Function f, unsigned int n) {
    using namespace std::chrono;
    using clock = steady_clock;

    clock::time_point start = clock::now();

    repeat(f, n);

    clock::time_point end = clock::now();

    return (double)duration_cast<milliseconds>(end - start).count() / n;
}

char random_char()
{
    static const std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    return alphabet[pick_an_integer<int>(1, alphabet.size())-1];
}

std::string random_word(int length)
{
    std::string word(length, ' ');
    std::generate(word.begin(), word.end(), random_char);
    return word;
}

int main() {
    const int min_length = 2;
    const int max_length = 10;
    const int n = 1000'000;

    std::unordered_map<std::string, int> map;
    repeat([&] {
        int len = pick_an_integer(min_length, max_length);
        std::string word = random_word(len);
        map[word] = word.size();
    }, n);

    std::cout << measure_execution([&map]{
        int len = pick_an_integer(min_length, max_length);
        std::string word = random_word(len);
        repeat([&word, &map] { int val = map[word]; (void)val; }, 1000);
    }, 30) << std::endl;

    return 0;
}

