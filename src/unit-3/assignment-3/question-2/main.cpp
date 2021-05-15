/*
sort an array of Persons
	in order of name
	in reverse order of age
*/

#include <iostream>

struct person
{
    std::string name;
    int age;

    person(std::string name, int age) : name(name), age(age)
    {
    }

    friend std::ostream& operator<<(std::ostream& stream, const person& p)
    {
        return stream << "Name: " << p.name << " Age: " << p.age;
    }
};

struct name_sorter
{
    bool operator()(person a, person b)
    {
        return a.name <= b.name;
    }
};

struct age_sorter
{
    bool operator()(person a, person b)
    {
        return a.age <= b.age;
    }
};

void display(person* first, person* last);

int main()
{
    person persons[] {
        {"C", 21},
        {"A", 20},
        {"B", 17},
        {"B", 16},
        {"B", 18},
    };
    auto size = 5;
    std::cout << "***SORTED BY NAME***\n";
    std::sort(persons, persons + size, name_sorter{});
    display(persons, persons + size);
    std::cout << "***SORTED BY AGE***\n";
    std::sort(persons, persons + size, age_sorter{});
    display(persons, persons + size);
    return 0;
}

void display(person* first, person* last)
{
    for (auto curr = first; curr != last; curr++)
        std::cout << *curr << '\n';
}
