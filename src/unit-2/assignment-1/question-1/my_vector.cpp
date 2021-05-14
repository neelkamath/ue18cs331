#include "my_vector.h"

my_vector::my_vector(int n) : n(n), p(new int[n])
{
}

my_vector::my_vector(const my_vector& other)
{
    auto will_clean_up = false;
    assign(other, will_clean_up);
}

my_vector::~my_vector()
{
    delete[] p;
}

my_vector& my_vector::operator=(const my_vector& other)
{
    if (this != &other)
    {
        auto will_clean_up = true;
        assign(other, will_clean_up);
    }
    return *this;
}

my_vector my_vector::operator+(const my_vector& rhs)
{
    int* new_p = new int[n + rhs.n];
    std::copy(p, p + n, new_p);
    std::copy(rhs.p, rhs.p + rhs.n, new_p + n);
    my_vector vector(n + rhs.n);
    vector.p = new_p;
    return vector;
}

void my_vector::display()
{
    for (auto index = 0; index < n; index++)
        std::cout << p[index] << ' ';
    std::cout << '\n';
}

void my_vector::assign(const my_vector& other, bool will_clean_up)
{
    int* new_p = new int[other.n];
    std::copy(other.p, other.p + other.n, new_p);
    if (will_clean_up)
        delete[] p;
    n = other.n;
    p = new_p;
}
