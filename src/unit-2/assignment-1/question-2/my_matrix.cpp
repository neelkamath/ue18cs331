#include "my_matrix.h"

my_matrix::my_matrix(int m, int n) : m(m), n(n), p(new int[m * n])
{
}

my_matrix::my_matrix(const my_matrix& other)
{
    auto will_clean_up = false;
    assign(other, will_clean_up);
}

my_matrix::~my_matrix()
{
    delete[] p;
}

my_matrix& my_matrix::operator=(const my_matrix& other)
{
    if (this != &other)
    {
        auto will_clean_up = true;
        assign(other, will_clean_up);
    }
    return *this;
}

my_matrix my_matrix::operator+(const my_matrix& rhs)
{
    if (m != rhs.m || n != rhs.n)
        throw std::invalid_argument("Only matrices having a matching number of rows and columns can be added.");
    my_matrix sum(m, n);
    for (auto index = 0; index < m * n; index++)
        sum.p[index] = p[index] + rhs.p[index];
    return sum;
}

void my_matrix::assign(const my_matrix& other, bool will_clean_up)
{
    auto length = other.m * other.n;
    int* new_p = new int[length];
    std::copy(other.p, other.p + length, new_p);
    if (will_clean_up)
        delete[] p;
    m = other.m;
    n = other.n;
    p = new_p;
}

void my_matrix::display()
{
    for (auto index = 0; index < m * n; index++)
    {
        if (index > 0 && index % n == 0)
            std::cout << '\n';
        std::cout << p[index] << ' ';
    }
    std::cout << '\n';
}
