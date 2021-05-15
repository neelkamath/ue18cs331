/*
Write your function for the following.
a) count occurrence of a value
b) rightmost find
c) min
d) max
*/

#include <iostream>
#include <vector>

/* Returns the number of occurrences of the <element> in the range of [being, last). */
template <typename T, typename U>
int count(T first, T last, U element);

void demo_count();

/**
 * Returns an iterator to the last element in the range [first,last) that compares equal to <element>. If no such
 * element is found, the function returns <last?.
 */
template <typename T, typename U>
T rfind(T first, T last, U element);

void demo_rfind();

/** Returns the smallest of <a> and <b>. If both are equivalent, <a> is returned. */
template <typename T>
const T& min(const T& a, const T& b);

void demo_min();

/** Returns the largest of <a> and <b>. If both are equivalent, <a> is returned. */
template <typename T>
const T& max(const T& a, const T& b);

void demo_max();

int main()
{
    demo_count();
    demo_rfind();
    demo_min();
    demo_max();
    return 0;
}

template <typename T, typename U>
int count(T first, T last, U element)
{
    for (auto num = 0; ; first++)
    {
        if (first == last)
            return num;
        if (*first == element)
            num++;
    }
}

void demo_count()
{
    std::cout << "***COUNT***\n";
    auto size = 5;
    int ints[5] = {1, 2, 2, 4, 2};
    std::cout << "Expected: 0 Actual: " << count(ints, ints + size, -1) << '\n';
    std::cout << "Expected: 1 Actual: " << count(ints, ints + size, 4) << '\n';
    std::cout << "Expected: 3 Actual: " << count(ints, ints + size, 2) << '\n';
}

template <typename T, typename U>
T rfind(T first, T last, U element)
{
    for (auto curr = last - 1; curr != first; curr--)
        if (*curr == element)
            return curr;
    return last;
}

void demo_rfind()
{
    std::cout << "***RFIND***\n";
    std::vector<int> v{0, 10, 20, 30, 40, 50};
    auto zero = rfind(v.begin(), v.end(), 0);
    std::cout << "Expected: NOT FOUND Actual: " << (zero == v.end() ? "NOT FOUND" : "FOUND") << '\n';
    auto fifty = rfind(v.begin(), v.end(), 50);
    std::cout << "Expected: FOUND Actual: " << (fifty == v.end() ? "NOT FOUND" : "FOUND") << '\n';
    auto thirty = rfind(v.begin(), v.end(), 30);
    std::cout << "Expected: FOUND Actual: " << (thirty == v.end() ? "NOT FOUND" : "FOUND") << '\n';
}

template <typename T>
const T& min(const T& a, const T& b)
{
    return a <= b ? a : b;
}

void demo_min()
{
    std::cout << "***MIN***\n";
    auto a = 4;
    auto b = 4;
    std::cout << "EXPECTED: a ACTUAL: " << (min(a, b) == a ? "a" : "b") << '\n';
    a = 1;
    b = 2;
    std::cout << "EXPECTED: a ACTUAL: " << (min(a, b) == a ? "a" : "b") << '\n';
    a = 2;
    b = 1;
    std::cout << "EXPECTED: b ACTUAL: " << (min(a, b) == a ? "a" : "b") << '\n';
}

template <typename T>
const T& max(const T& a, const T& b)
{
    return a >= b ? a : b;
}

void demo_max()
{
    std::cout << "***MAX***\n";
    auto a = 4;
    auto b = 4;
    std::cout << "EXPECTED: a ACTUAL: " << (max(a, b) == a ? "a" : "b") << '\n';
    a = 1;
    b = 2;
    std::cout << "EXPECTED: b ACTUAL: " << (max(a, b) == a ? "a" : "b") << '\n';
    a = 2;
    b = 1;
    std::cout << "EXPECTED: a ACTUAL: " << (max(a, b) == a ? "a" : "b") << '\n';
}
