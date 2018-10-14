#include <iostream>

int checksum(int number)
{
    int result{0};

    while (number > 0) {
        result += number %10;
        number /= 10;
    }

    return result;
}

int main()
{
    std::cout << checksum(123456) << std::endl;
}
