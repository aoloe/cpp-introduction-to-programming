#include <iostream>
#include <string>
#include <array>

std::string get_stars(int i)
{
     return std::string(i, '*');
}

int main()
{
    /*
    for (auto i: std::array<int, 5>{4, 8, 12, 8, 4}) {
        std::cout << get_stars(i) << std::endl;
    }
    */
    std::cout << get_stars(4) << std::endl;
    std::cout << get_stars(8) << std::endl;
    std::cout << get_stars(12) << std::endl;
    std::cout << get_stars(8) << std::endl;
    std::cout << get_stars(4) << std::endl;
}
