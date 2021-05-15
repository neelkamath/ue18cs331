/*
template<typename ptr1_t>
bool is_sorted(ptr1_t first1, ptr1_t last1)
{
// TODO
}
check whether the elements in ascending order
*/

#include <iostream>

/** Returns whether the elements in the range of [<first>, <last>) are sorted in ascending order. */
template<typename T>
bool is_sorted(T first, T last);

int main()
{
    int sorted[] {1, 2, 3};
    int unsorted[] {2, 1, 3};
    std::cout
        << std::boolalpha
        << "Expected: true Actual: "
        << is_sorted(sorted, sorted + 3)
        << "\nExpected: false Actual: "
        << is_sorted(unsorted, unsorted + 3)
        << '\n';
    return 0;
}

template<typename T>
bool is_sorted(T first, T last)
{
    for (auto curr = first; curr != last; curr++)
        if (curr != first && *(curr - 1) > *curr)
            return false;
    return true;
}
