/**
 * display the first n fibonacci numbers
 * by creating a list of values
 */
#include <iostream>
#include <vector>

std::vector<int> get_fibonacci(int number)
{
    static std::vector<int> result{0, 1};

    for (int i = 2; i < number; i++) {
        result.push_back(result.at(i - 1) + result.at(i - 2));
    }

    return result;
}

int main()
{
    for (int i: get_fibonacci(10)) {
        std::cout << i << std::endl;
    }
}
