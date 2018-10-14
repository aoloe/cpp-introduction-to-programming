/**
 * display the first n fibonacci numbers
 * without recalculating the values
 */
#include <iostream>
#include <map>

int get_fibonacci(int number)
{
    static std::map<int, int> cache {{0, 0}, {1, 1}};
    auto found = cache.find(number);

    if (found != cache.end()) {
        return found->second;

    }
    int result = get_fibonacci(number - 1) + get_fibonacci(number - 2);
    cache[number] = result;
    return result;
}

int main()
{
    for (int i = 1; i < 10; i++) {
        std::cout << get_fibonacci(i) << std::endl;
    }
}
