/*
create a class MyMatrix.
It should have
int m_;
int n_;
int *p_;
In the constructor, allocate a block of m X n int to p.
Provide ctors, dtor, assignment op and copy constructor.
Write functions to add matrices.
*/

#include <iostream>

#include "my_matrix.h"

void demo_constructor();

void demo_copy_constructor();

void demo_assignment_operator();

void demo_plus_operator();

int main()
{
    demo_constructor();
    demo_copy_constructor();
    demo_assignment_operator();
    demo_plus_operator();
    return 0;
}

void demo_constructor()
{
    std::cout << "***CONSTRUCTOR***\n";
    my_matrix matrix(3, 3);
    for (auto index = 0; index < matrix.m * matrix.n; index++)
        matrix.p[index] = index;
    matrix.display();
}

void demo_copy_constructor()
{
    std::cout << "***COPY CONSTRUCTOR***\n";
    my_matrix matrix1(3, 3);
    for (auto index = 0; index < matrix1.m * matrix1.n; index++)
        matrix1.p[index] = index;
    my_matrix matrix2(matrix1);
    std::cout << "Matrix 1:\n";
    matrix1.display();
    std::cout << "Matrix 2:\n";
    matrix2.display();
}

void demo_assignment_operator()
{
    std::cout << "***ASSIGNMENT OPERATOR***\n";
    my_matrix matrix1(3, 3);
    for (auto index = 0; index < matrix1.m * matrix1.n; index++)
        matrix1.p[index] = index;
    my_matrix matrix2(2, 2);
    for (auto index = 0; index < matrix2.m * matrix2.n; index++)
        matrix2.p[index] = index + 10;
    matrix1 = matrix2;
    std::cout << "Matrix 1:\n";
    matrix1.display();
    std::cout << "Matrix 2:\n";
    matrix2.display();
}

void demo_plus_operator()
{
    std::cout << "***PLUS OPERATOR***\n";
    my_matrix lhs(3, 3);
    for (auto index = 0; index < lhs.m * lhs.n; index++)
        lhs.p[index] = index;
    my_matrix rhs(3, 3);
    for (auto index = 0; index < rhs.m * rhs.n; index++)
        rhs.p[index] = index + 10;
    std::cout << "LHS:\n";
    lhs.display();
    std::cout << "RHS:\n";
    rhs.display();
    std::cout << "Sum:\n";
    (lhs + rhs).display();
}
