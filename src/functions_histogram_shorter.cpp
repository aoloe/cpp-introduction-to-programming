#include <iostream>
#include <string>
#include <array>

void stars(int i)
{
    std::cout << std::string(i, '*') << std::endl;
}

int main()
{
    for (auto i: std::array<int, 5>{4, 8, 12, 8, 4}) {
        stars(i);
    }
}
