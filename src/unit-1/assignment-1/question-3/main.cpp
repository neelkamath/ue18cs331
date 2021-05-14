/*
write generic search function to find
a) the key in an array
b) the key which satisfies a particular condition
*/

#include <iostream>

/**
 * Returns the index of the first <element> in the <array> which has the <length>, or <-1> if the element wasn't found.
 */
template <typename T>
int search(T element, T array[], int length);

/** Returns whether the <element> satisfies a condition. */
template <typename T>
bool condition(T element);

/**
 * Returns the index of the first element which satisfies the <condition> in the <array> which has the <length>, or <-1>
 * if the element wasn't found.
 */
template <typename T>
int search(bool condition(T element), T array[], int length);

int main()
{
    auto length = 5;
    int array[length] = {10, 20, 30, 40, 50};
    std::cout << search(20, array, length) << std::endl << search(-10, array, length) << std::endl;
    std::cout << search(condition, array, length) << std::endl;
    return 0;
}

template <typename T>
int search(T element, T array[], int length)
{
    for (auto index = 0; index < length; index++)
        if (array[index] == element)
            return index;
    return -1;
}

template <typename T>
int search(bool condition(T element), T array[], int length)
{
    for (auto index = 0; index < length; index++)
        if (condition(array[index]))
            return index;
    return -1;
}

template <typename T>
bool condition(T element)
{
    return element > 10 && element < 30;
}
