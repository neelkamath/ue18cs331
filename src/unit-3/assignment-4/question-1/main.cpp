/*
a) Develop vector of person's name and date of birth.
Develop map of month and # of people born in that month
*/

#include <iostream>
#include <vector>
#include <map>

struct date
{
    int year;
    int month;
    int day;

    date(int year, int month, int day) : year(year), month(month), day(day)
    {
    }

    friend std::ostream& operator<<(std::ostream& stream, date& d)
    {
        return stream << d.year << '-' << d.month << '-' << d.day;
    }
};

struct person
{
    std::string name;
    date date_of_birth;

    person(std::string name, date date_of_birth) : name(name), date_of_birth(date_of_birth)
    {
    }

    friend std::ostream& operator<<(std::ostream& stream, person& p)
    {
        return stream << "Name: " << p.name << " Date of birth: " << p.date_of_birth;
    }
};

int main()
{
    std::vector<person> v {
        {"Neel", {2000, 6, 7}},
        {"Rahul", {2003, 9, 7}},
        {"Naveen", {1999, 6, 8}},
    };
    std::map<int, int> m;
    for (auto curr = v.begin(); curr != v.end(); curr++)
        m[(*curr).date_of_birth.month]++;
    for (auto [month, num] : m)
        std::cout << "Number of people born in month " << month << ": " << num << '\n';
    return 0;
}
