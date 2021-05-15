/*
template<typename ptr1_t, typename ptr2_t>
bool are_equal(ptr1_t first1, ptr1_t last1, ptr2_t first2, ptr2_t last2)
{
// TODO
}
Test whether the given two sequences have the same elements
should the two containers be of the same type?
should we require 4 parameters?
Test your code with
	array with array
	array with vector
	vector with list
*/

#include <iostream>
#include <vector>
#include <list>

template<typename ptr1_t, typename ptr2_t>
bool are_equal(ptr1_t first1, ptr1_t last1, ptr2_t first2, ptr2_t last2);

void demo_array_with_array();

void demo_array_with_vector();

void demo_array_with_list();

int main()
{
    std::cout << std::boolalpha;
    demo_array_with_array();
    demo_array_with_array();
    demo_array_with_list();
    return 0;
}

template<typename ptr1_t, typename ptr2_t>
bool are_equal(ptr1_t first1, ptr1_t last1, ptr2_t first2, ptr2_t last2)
{
    while (*(first1++) == *(first2++) && first1 != last1 && first2 != last2)
        ;
    return first1 == last1 && first2 == last2;
}

void demo_array_with_array()
{
    std::cout << "***ARRAY WITH ARRAY***\n";
    int first1[] {1, 2, 3};
    int second1[] {1, 2, 3};
    std::cout << "Expected: true Actual: " << are_equal(first1, first1 + 3, second1, second1 + 3) << '\n';
    std::cout << "Expected: false Actual: " << are_equal(first1, first1 + 2, second1, second1 + 3) << '\n';
    std::cout << "Expected: false Actual: " << are_equal(first1, first1 + 3, second1, second1 + 2) << '\n';
    int first2[] {1, 2};
    int second2[] {2, 1};
    std::cout << "Expected: false Actual: " << are_equal(first2, first2 + 2, second2, second2 + 2) << '\n';
}

void demo_array_with_vector()
{
    std::cout << "***ARRAY WITH VECTOR***\n";
    int array[] = {1, 2, 3};
    std::vector v{1, 2, 3};
    std::cout << "Expected: true Actual: " << are_equal(array, array + 3, v.begin(), v.end()) << '\n';
    std::cout << "Expected: false Actual: " << are_equal(array, array + 2, v.begin(), v.end()) << '\n';
    std::cout << "Expected: false Actual: " << are_equal(array, array + 3, v.begin(), v.end() - 1) << '\n';
}

void demo_array_with_list()
{
    std::cout << "***ARRAY WITH LIST***\n";
    int array[] = {1, 2, 3};
    std::list l{1, 2, 3};
    std::cout << "Expected: true Actual: " << are_equal(array, array + 3, l.begin(), l.end()) << '\n';
    std::cout << "Expected: false Actual: " << are_equal(array, array + 2, l.begin(), l.end()) << '\n';
    std::cout << "Expected: false Actual: " << are_equal(array, array + 3, l.begin(), --l.end()) << '\n';
}
