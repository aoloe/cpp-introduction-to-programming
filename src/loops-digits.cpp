#include <iostream>
#include <vector>

std::vector<int> get_digits(int number)
{
    std::vector<int> result{};
    while (number > 0) {
        result.insert(result.begin(), number % 10);
        number /= 10;
    }
    return result;
}

int main()
{
    for (auto digit: get_digits(1234)) {
        std::cout << digit << std::endl;
    }
}
