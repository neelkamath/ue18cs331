/*
template<typename ptr_t>
void disp(ptr_t first, ptr_t last)
{
	while(first != last)
	{
		disp_one(*first);
		++first;
	}
	cout << "\n";
}

Write suitable disp_one function or functions to display
a) array of int
b) array of double
c) array of c strings
d) array of structures having a couple of fields -
	name : array of char
	age : int
*/

#include <iostream>

struct student
{
    int age;
    std::string name;
};

template<typename ptr_t>
void disp(ptr_t first, ptr_t last);

template<typename ptr_t>
void disp_one(ptr_t t);

int main()
{
    int ints[] = {1, 2, 3};
    disp(ints, ints + 3);
    std::cout << std::endl;
    double doubles[] = {1.1, 2.2, 3.3};
    disp(doubles, doubles + 3);
    std::cout << std::endl;
    std::string strings[] = {"hello", "bob", "!"};
    disp(strings, strings + 3);
    std::cout << std::endl;
    struct student students[] = {
        {20, "Neel"},
        {21, "Rashaad"},
        {17, "Rahul"},
    };
    disp(students, students + 3);
    return 0;
}

template<typename ptr_t>
void disp(ptr_t first, ptr_t last)
{
	while(first != last)
	{
		disp_one(*first);
		++first;
	}
}

template<typename T>
void disp_one(T t)
{
    std::cout << t << std::endl;
}

void disp_one(struct student s)
{
    std::cout << s.name << ": " << s.age << std::endl;
}
