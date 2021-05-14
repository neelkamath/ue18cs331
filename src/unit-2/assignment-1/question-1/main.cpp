/*
create a class my_vector.
It should have
int n_;
int* p_;
In the constructor, allocate a block of n int to p.
Provide ctors, dtor, assignment op and copy constructor.
Write functions to add vectors.
*/

#include <iostream>

#include "my_vector.h"

void demo_constructor();

void demo_copy_constructor();

void demo_assignment_op();

void demo_plus_op();

int main()
{
    demo_constructor();
    demo_copy_constructor();
    demo_assignment_op();
    demo_plus_op();
    return 0;
}

void demo_constructor()
{
    std::cout << "***CONSTRUCTOR***\n";
    my_vector vector(3);
    vector.p[0] = 1;
    vector.p[1] = 2;
    vector.p[2] = 3;
    vector.display();
}

void demo_copy_constructor()
{
    std::cout << "***COPY CONSTRUCTOR***\n";
    my_vector vector1(3);
    vector1.p[0] = 1;
    vector1.p[1] = 2;
    vector1.p[2] = 3;
    my_vector vector2(vector1);
    vector2.display();
}

void demo_assignment_op()
{
    std::cout << "***ASSIGNMENT OPERATOR***\n";
    my_vector vector1(3);
    vector1.p[0] = 1;
    vector1.p[1] = 2;
    vector1.p[2] = 3;
    my_vector vector2(1);
    vector2 = vector1;
    std::cout << "Vector 1: ";
    vector1.display();
    std::cout << "Vector 2: ";
    vector2.display();
}

void demo_plus_op()
{
    std::cout << "***PLUS OPERATOR***\n";
    my_vector lhs(3);
    lhs.p[0] = 1;
    lhs.p[1] = 2;
    lhs.p[2] = 3;
    my_vector rhs(2);
    rhs.p[0] = 4;
    rhs.p[1] = 5;
    (lhs + rhs).display();
}
