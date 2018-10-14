/**
 * display the first n fibonacci numbers
 * without using recursion
 */
#include <iostream>

int get_fibonacci(int number)
{
    int previous{0};
    int result{1};

    for (int i = 2; i <= number; ++i) {
        int temp{result};
        result = previous + result;
        previous = temp;
    }
    return result;
}

int main()
{
    for (int i = 1; i < 10; i++) {
        std::cout << get_fibonacci(i) << std::endl;
    }
}

