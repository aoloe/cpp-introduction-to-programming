#include <iostream>

void show_digits(int number)
{
    if (number > 10) {
        show_digits(number / 10);
    }
    std::cout << number % 10 << std::endl;
}

int main()
{
    show_digits(1234);
}
