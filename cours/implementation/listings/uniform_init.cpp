#include <string>

struct Date { int y, m, d; };

class Log {
    Date dt_;
    std::string msg_;
public:
    Log(int y, int m, int d, std::string msg)
        : dt_{y, m, d}, msg_{msg} {}
};

int main()
{
    Log l{2018, 1, 12, "new message"};
}
