#include <iostream>

int main()
{
    int a_nom{0}, a_den{0}, b_nom{0}, b_den{0}, c_nom{0}, c_den{0};
    char op{'+'};

    std::cout << "a nominator and denomimator: ";
    std::cin >> a_nom >> a_den;

    std::cout << "operator: ";
    std::cin >> op;

    std::cout << "b nominator and denomimator: ";
    std::cin >> b_nom >> b_den;

    if (a_den == 0 || b_den == 0) {
        std::cout << "Error: no denominator can be 0" << std::endl;
    } else if (op == '+') {
        c_nom = a_nom * b_den + a_den * b_nom;
        c_den = a_den * b_den;
    } else if (op == '-') {
        c_nom = a_nom * b_den - a_den * b_nom;
        c_den = a_den * b_den;
    } else if (op == '*') {
        c_nom = a_nom * b_nom;
        c_den = a_den * b_den;
    } else if (op == '/') {
        if (b_nom == 0) {
            std::cout << "Error: the second nominator can not be 0" << std::endl;
        } else {
            c_nom = a_nom * b_den;
            c_den = a_den * b_nom;
        }
    }

    std::cout << c_nom << " / " << c_den << std::endl;
}
