/*
sort an array of dates
	in the order of month
	in the reverse chronological order
*/

#include <iostream>

/** Human-readable date (i.e., not zero-based indexed). */
struct date
{
    int year;
    int month;
    int day;

    explicit date(int year, int month, int day) : year(year), month(month), day(day)
    {
    }

    friend std::ostream& operator<<(std::ostream& stream, const date& d)
    {
        return stream << d.year << '-' << d.month << '-' << d.day;
    }
};

struct month_sorter
{
    bool operator()(date a, date b)
    {
        return a.month <= b.month;
    }
};

struct reverse_chronology_sorter
{
    bool operator()(date a, date b)
    {
        if (a.year > b.year)
            return true;
        if (a.year < b.year)
            return false;
        if (a.month > b.month)
            return true;
        if (a.month < b.month)
            return false;
        if (a.day >= b.day)
            return true;
        return false;
    }
};

void display(date* first, date* last);

int main()
{
    date dates[] {
        date{2000, 1, 1},
        date{2000, 1, 1},
        date{2000, 1, 2},
        date{2000, 1, 3},
        date{2000, 2, 1},
        date{2000, 2, 2},
        date{2000, 2, 3},
        date{2000, 3, 1},
        date{2000, 3, 2},
        date{2000, 3, 3},
        date{2001, 1, 1},
        date{2001, 1, 1},
        date{2001, 1, 1},
        date{1999, 1, 1},
        date{1999, 1, 1},
        date{1999, 1, 1},
    };
    std::cout << "***SORT BY MONTH***\n";
    std::sort(dates, dates + 16, month_sorter{});
    display(dates, dates + 16);
    std::cout << "***SORT BY REVERSE CHRONOLOGY***\n";
    std::sort(dates, dates + 16, reverse_chronology_sorter{});
    display(dates, dates + 16);
    return 0;
}

void display(date* first, date* last)
{
    for (auto curr = first; curr != last; curr++)
        std::cout << *curr << '\n';
}
