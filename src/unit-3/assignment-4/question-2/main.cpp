/*
b) create a map of author's name(string) and a vector of his books.
Display all.
Find the number of books of each of the authors.
Find the author who has the highest # of books
*/

#include <iostream>
#include <vector>
#include <map>

using author_name = std::string;
using book_names = std::vector<std::string>;
using library = std::map<author_name, book_names>;

void display_lib(library lib);

void display_book_counts(library lib);

void display_highest_books(library lib);

int main()
{
    library lib {
        {
            "J. K. Rowling",
            book_names {"Harry Potter 1", "Harry Potter 2"},
        },
        {
            "Douglas Adamns",
            book_names {"H2G2 1", "H2G2 2", "H2G2 3"},
        },
        {
            "Edward Stratemeyer",
            book_names {"Nancy Drew"},
        },
    };
    display_lib(lib);
    display_book_counts(lib);
    display_highest_books(lib);
    return 0;
}

void display_lib(library lib)
{
    std::cout << "***DISPLAY_LIB***\n";
    for (auto [author, books] : lib)
    {
        std::cout << "Author: " << author << "\nBooks:\n";
        for (auto book : books)
            std::cout << '\t' << book << '\n';
    }
}

void display_book_counts(library lib)
{
    std::cout << "***DISPLAY_BOOK_COUNTS***\n";
    for (auto [author, books] : lib)
        std::cout << author << ": " << books.size() << '\n';
}

void display_highest_books(library lib)
{
    std::cout << "***DISPLAY_HIGHEST_BOOKS***\n";
    std::string name{};
    auto count{0};
    for (auto [author, books] : lib)
    {
        auto size = books.size();
        if (size > count)
        {
            name = author;
            count = size;
        }
    }
    std::cout << name << ": " << count << '\n';
}
