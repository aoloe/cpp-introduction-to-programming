#include <iostream>
#include <complex>

int main() {
    std::complex<double> i;
    std::complex<double> a;
    double pi;
    pi = 2 * asin(1);
    i = -1;
    i = sqrt(i);
    a = exp(2 * pi * i);
    std::cout << "i is " << i << " and Euler was right: e(i pi) = " << a << std::endl;
} 
