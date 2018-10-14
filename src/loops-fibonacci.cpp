/**
 * display the first n fibonacci numbers
 */
#include <iostream>

int get_fibonacci(int number)
{
    if (number <= 1) {
        return number;
    } else {
        return get_fibonacci(number - 1) + get_fibonacci(number - 2);
    }
}

int main()
{
    for (int i = 1; i < 10; i++) {
        std::cout << get_fibonacci(i) << std::endl;
    }
}
