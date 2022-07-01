#include <string>
#include <iostream>

struct Person { std::string first_name, last_name; };

Person* create_person(std::string first_name, std::string last_name)
{
    Person* p = new Person { first_name, last_name };
    return p;
}

int main () {
    Person* p1 = create_person("Alan", "Turin");
    Person* p2 = create_person("Ada", "Lovelace");

    // ...

    // Facile à oublier...
    // delete p1;
    // delete p2;
}
