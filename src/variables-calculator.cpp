#include <iostream>

int main()
{
    int a_nom{1};
    int a_den{2};
    int b_nom{1};
    int b_den{3};
    int c_nom{0};
    int c_den{0};

    c_nom = a_nom * b_den + a_den * b_nom;
    c_den = a_den * b_den;

    std::cout << c_nom << " / " << c_den << std::endl;
}
