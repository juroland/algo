#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <tuple>
// #include <gsl/gsl>

struct Person
{
    std::string first_name, last_name;
    bool is_empty()
    {
        return first_name.size() == 0 && last_name.size() == 0;
    }
};

class ReverseTelephoneDictionary
{
    std::vector<Person> persons_;
    using iterator = std::vector<Person>::iterator;
  public:
    ReverseTelephoneDictionary(): persons_(10'000) {}

    std::pair<Person, bool> find(int number)
    {
        iterator it = std::next(persons_.begin(), number);
        return std::make_pair(*it, !it->is_empty());
    }

    void insert(int number, Person p)
    {
        persons_[number] = p;
    }

    void erase(int number)
    {
        persons_[number].first_name.clear();
        persons_[number].last_name.clear();
    }

    void check_preconditions(int number);
};

int main()
{
    ReverseTelephoneDictionary dict;
    dict.insert(4426, Person{"Julien", "ROLAND"});
    dict.insert(4024, Person{"Gabriel", "CHENEVERT"});
    dict.insert(4032, Person{"Pascal", "MOSBAH"});

    Person p;
    bool ok;

    std::tie(p, ok) = dict.find(4024);
    if (!ok) {
        std::cerr << "Number not found" << std::endl;
        return -1;
    }
    std::cout << p.first_name << " " << p.last_name;
}