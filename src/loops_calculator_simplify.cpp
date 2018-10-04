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

    // https://en.wikipedia.org/wiki/Euclidean_algorithm
    int gcd_a{c_nom}, gcd_b{c_den};
    while(gcd_a != gcd_b) {
        if (gcd_a > gcd_b) {
            gcd_a -= gcd_b;
        } else {
            gcd_b -= gcd_a;
        }
    }

	c_nom /= gcd_a;
	c_den /= gcd_b;

	/*
    int gcd{0}, gcd_a{c_nom}, gcd_b{c_den};
    while (gcd == 0) {
        gcd_a = gcd_a % gcd_b;
        if (gcd_a == 0) {
            gcd = gcd_b;
        }
        if (gcd == 0) {
            gcd_b = gcd_b % gcd_a;
            if (gcd_b == 0) {
                gcd = gcd_a;
            }
        }
    }

	c_nom /= gcd;
	c_den /= gcd;
    */

    /*
    // #include <algorithms>
	// for (int i = 1; i <= std::min(c_nom; c_den); i++) {
	int  gcd{1};
	for (int i = 1; i <= c_nom < c_den ? c_nom : c_den); i++) {
		if (c_nom % i == 0 && second_number % i == 0 ) {
			gcd = i;
		}
	   }
	}

	c_nom /= gcd;
	c_den /= gcd;
    */

	/*
    int gcd_a{c_nom}, gcd_b{c_den};
	if (gcd_a < gcd_b) {
		std::swap(gcd_a, gcd_b);
    }

	while (gcd_b > 0) {
		int f = gcd_a % gcd_b;
		gcd_a = gcd_b;
		gcd_b = f;
	}

	c_nom /= gcd_a;
	c_den /= gcd_a;

	*/


    std::cout << c_nom << " / " << c_den << std::endl;
}
