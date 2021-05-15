/*
c) create a map of map of vector : lang => author => title.
Develop functions to play with them.
*/

#include <iostream>
#include <map>
#include <vector>

using author_name = std::string;
using fav_nums = std::vector<long>;
using author_metadata = std::map<fav_nums, author_name>;
using author_title = std::string;
using authors = std::map<author_metadata, author_title>;

std::pair<author_metadata, author_title> build_author(std::string name, std::vector<long> nums, std::string title);

void display(authors a);

int main()
{
    authors a{
        build_author("J. K. Rowling", {1, 2}, "Mrs."),
        build_author("Douglas Adams", {2}, "Mr."),
    };
    display(a);
    return 0;
}

std::pair<author_metadata, author_title> build_author(author_name name, std::vector<long> nums, author_title title)
{
    author_metadata metadata{
        {nums, name},
    };
    return {metadata, title};
}

void display(authors a)
{
    for (auto [metadata, title] : a)
    {
        std::cout << "Title: " << title << '\n';
        for (auto [nums, name] : metadata)
        {
            std::cout << "Name: " << name << "\nFavorite numbers: ";
            for (auto num : nums)
            {
                std::cout << num << ' ';
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }
}
