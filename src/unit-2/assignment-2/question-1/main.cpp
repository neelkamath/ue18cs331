/*
Implement a list typename. Implement iterator with in.
- make acc work with this typename.

Implement the following functions.
- accumulate (reduce elements to a single element between a pair of iterators)
- find a position between a pair of iterators - compare for equality
- find the position of an element greater than a given element between
	a pair of iterators
- copy elements between a pair of iterators to another container

Try for both the vector and the list.
*/

#include <iostream>
#include <numeric>

#include "my_list.cpp"

void demo_constructor();

void demo_insert_first();

void demo_insert();

void demo_insert_last();

void demo_read();

void demo_update();

void demo_remove();

void demo_insertion_operator();

void demo_iterator();

void demo_accumulate();

int main()
{
    demo_constructor();
    demo_insert_first();
    demo_insert();
    demo_insert_last();
    demo_read();
    demo_update();
    demo_remove();
    demo_insertion_operator();
    demo_iterator();
    demo_accumulate();
    return 0;
}

void demo_constructor()
{
    std::cout << "***CONSTRUCTOR***\n";
    my_list<int> list;
    list.insert_first(5);
    std::cout << list << '\n';
}

void demo_insert_first()
{
    std::cout << "***INSERT_FIRST***\n";
    my_list<int> list;
    list.insert_last(1);
    list.insert_last(2);
    list.insert_last(3);
    std::cout << list << '\n';
}

void demo_insert()
{
    std::cout << "***INSERT***\n";
    my_list<int> list;
    list.insert_last(1);
    list.insert_last(3);
    list.insert_last(5);
    list.insert(0, 0);
    list.insert(2, 2);
    list.insert(4, 4);
    std::cout << list << '\n';
}

void demo_insert_last()
{
    std::cout << "***INSERT_LAST***\n";
    my_list<int> list;
    list.insert_last(1);
    list.insert_last(2);
    list.insert_last(3);
    std::cout << list << '\n';
}

void demo_read()
{
    std::cout << "***READ***\n";
    my_list<int> list;
    list.insert_last(10);
    list.insert_last(20);
    list.insert_last(30);
    std::cout << list.read(20) << '\n';
}

void demo_update()
{
    std::cout << "***UPDATE***\n";
    my_list<int> list;
    list.insert_last(1);
    list.insert_last(2);
    list.insert_last(3);
    list.update(0, 10);
    list.update(1, 20);
    list.update(2, 30);
    std::cout << list << '\n';
}

void demo_remove()
{
    std::cout << "***REMOVE***\n";
    my_list<int> list;
    list.insert_last(1);
    list.insert_last(2);
    list.insert_last(3);
    list.remove(1);
    std::cout << list << '\n';
}

void demo_insertion_operator()
{
    std::cout << "***OPERATOR<<***\n";
    my_list<int> list;
    list.insert_last(1);
    list.insert_last(2);
    list.insert_last(3);
    std::cout << list << '\n';
}

void demo_iterator()
{
    std::cout << "***BEGIN***\n";
    my_list<int> list;
    list.insert_last(1);
    list.insert_last(2);
    list.insert_last(3);
    std::cout << "POSTFIX INCREMENT: ";
    for (auto it = list.begin(), end = list.end(); it != end; it++)
        std::cout << *it << ' ';
    std::cout << "\nPREFIX INCREMENT: ";
    for (auto it = list.begin(), end = list.end(); it != end; ++it)
        std::cout << *it << ' ';
    std::cout << "\nPOSTFIX DECREMENT: ";
    for (auto it = list.rbegin(), end = list.rend(); it != end; it--)
        std::cout << *it << ' ';
    std::cout << "\nPREFIX DECREMENT: ";
    for (auto it = list.rbegin(), end = list.rend(); it != end; --it)
        std::cout << *it << ' ';
    std::cout << "\nRANGE: ";
    for (auto it : list)
        std::cout << it << ' ';
    std::cout << '\n';
}

void demo_accumulate()
{
    std::cout << "***ACCUMULATE***\n";
    my_list<int> list;
    list.insert_last(1);
    list.insert_last(2);
    list.insert_last(3);
    std::cout << std::accumulate(list.begin(), list.end(), 0) << '\n';
}
