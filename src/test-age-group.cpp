#include <iostream>
#include <string>
#include <cassert>

std::string get_age_group(int age)
{
    std::string age_group{};

    if (age < 18) {
        age_group = "young";
    } else {
        age_group = "old";
    }
    return age_group;
}

int main()
{
    /*
    std::string age_group_01 = get_age_group(12);
    assert(typ_01 == "young");

    std::string age_group_02 = get_age_group(19);
    assert(typ_02 == "alt");
    */

    int age{0};
    std::cout << "Age? ";
    std::cin >> age;
    std::cout << get_age_group(age) << std::endl;
}

