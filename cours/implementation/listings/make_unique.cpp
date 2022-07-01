#include <string>
#include <iostream>
#include <memory>

struct Person {
    std::string first_name, last_name;
    Person(std::string first, std::string last): first_name(first), last_name(last) {}
};

std::unique_ptr<Person> create_person(std::string first_name, std::string last_name)
{
    auto p = std::make_unique<Person>(first_name, last_name);
    return p;
}

int main () {
    auto p1 = create_person("Alan", "Turin");
    auto p2 = create_person("Ada", "Lovelace");

    std::cout << p1->first_name << " et " << p2->first_name << std::endl;
}
