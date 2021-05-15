/*
sort an array of int based on digital sum
*/

#include <iostream>

int sum_digits(int num);

struct sum
{
    bool operator()(int a, int b)
    {
        return sum_digits(a) <= sum_digits(b);
    }
};

int main()
{
    auto size = 8;
    int ints[size] {1, 2, 3, 131, 100, 101, 200, 10};
    std::sort(ints, ints + size, sum{});
    for (auto curr = ints; curr != ints + size; curr++)
        std::cout << *curr << ' ';
    std::cout << '\n';
    return 0;
}

int sum_digits(int num)
{
    for (auto sum = 0; ; num /= 10)
    {
        if (num == 0)
            return sum;
        sum += num % 10;
    }
}
