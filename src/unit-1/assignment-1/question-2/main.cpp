/*
template<typename T>
void mysort(T a[], int n, bool (*comp)(const T&, const T&))
{
	int i;
	int j;
	for(i = 0; i < n - 1; ++i)
	{
		for(j = i + 1; j < n; ++j)
		{
			if(! comp(a[i], a[j]))
			{
				myswap(a[i], a[j]);
			}
		}
	}
}

use this sort using comparator to
a) sort an array of int
b) sort an array of double
c) sort an array of c strings
d) sort an array of structures : having name : array of char, age: int
	- in order of name
	- in decreasing order of age
*/

#include <iostream>

template<typename T>
void sort(T a[], int n, bool comp(const T&, const T&));

template<typename T>
void swap(T& a, T& b);

template<typename T>
bool compare(T a, T b);

template<>
bool compare(const struct student& a, const struct student& b);

template<typename T>
void display(T a[], int n);

template<>
void display(struct student a[], int n);

struct student
{
    std::string name;
    int age;
};

int main()
{
    int ints[] = {3, 5, 7, 4, 1, 0, 2, 9, 8, 6};
    display(ints, 10);
    sort(ints, 10, compare);
    display(ints, 10);

    double doubles[] = {3.3, 5.5, 7.7, 4.4, 1.1, 0.0, 2.2, 9.9, 8.8, 6};
    display(doubles, 10);
    sort(doubles, 10, compare);
    display(doubles, 10);

    std::string strings[] = {"a", "b", "d", "c", "2", "21", "1", "02", "010", "01", "ab"};
    display(strings, 10);
    sort(strings, 10, compare);
    display(strings, 10);

    struct student students[] = {
        {"Neel", 20},
        {"Neel", 21},
        {"Neel", 19},
        {"Rashaad", 21},
        {"Rahul", 17},
    };
    display(students, 5);
    sort(students, 5, compare);
    display(students, 5);

    return 0;
}

template<typename T>
void sort(T a[], int n, bool comp(const T&, const T&))
{
	for (auto i = 0; i < n - 1; ++i)
		for (auto j = i + 1; j < n; ++j)
			if (!comp(a[i], a[j]))
				swap(a[i], a[j]);
}

template<typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
bool compare(T a, T b)
{
    return a <= b;
}

template<>
bool compare(const struct student& a, const struct student& b)
{
    auto comparison = a.name.compare(b.name);
    if (comparison < 0)
        return true;
    if (comparison > 0)
        return false;
    return a.age >= b.age;
}

template<typename T>
void display(T a[], int n)
{
    for (auto index = 0; index < n; index++)
        std::cout << a[index] << '\t';
    std::cout << std::endl;
}

template<>
void display(struct student a[], int n)
{
    for (auto index = 0; index < n; index++)
        std::cout << a[index].name << ": " << a[index].age << '\t';
    std::cout << std::endl;
}
