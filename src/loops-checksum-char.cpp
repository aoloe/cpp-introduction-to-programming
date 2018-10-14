#include <iostream>
#include <string>

const int ASCII_ZERO = 48;

int checksum(std::string number)
{
    int result{0};

    for (char i: number) {
        result += i - ASCII_ZERO;
    }

    return result;
}

int main()
{
    std::cout << checksum("123456") << std::endl;
}
