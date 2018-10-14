#include <iostream>

int factorial(int number)
{
    if (number > 1) {
        return number * factorial(number - 1);
    } else {
        return 1;
    }
}

int main()
{
    std::cout << factorial(5) << std::endl;
}
