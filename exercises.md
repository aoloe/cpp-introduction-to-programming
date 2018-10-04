## The standard output

### Contacts

Write a program that outputs the menu for a Contacts applications:

```
########## Contacts ##########

    I - Insert a contact
    D - Delete a contact
    F - Find a phone number
    A - Show all contacts
    Q - Quit

    Your choice:

##############################

```

Then add the code that outputs your

- name,
- adress,
- phone number, and
- address 

each on its own line.

## Variables

### Fractions calculator

Write a program that calculates the sum of two fractions:

- `1/2 + 1/3 = 3/6 + 2/6 = 5/6`

```cpp
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
```

## Functions


## Input

### Fractions calculator

Write a program that asks for two fractions and calculates the sum of the two numbers:
- `1/2 + 1/3 = 3/6 + 2/6 = 5/6`

Solution:

`a_nom/a_den + b_nom/b_den` = (a_nom * b_den + a_den * b_nom) / (a_den * b_den)

```cpp
#include <iostream>

int main()
{
    int a_nom{0}, a_den{0}, b_nom{0}, b_den{0}, c_nom{0}, c_den{0};

    std::cout << "a nominator and denomimator: ";
    std::cin >> a_nom >> a_den;

    std::cout << "b nominator and denomimator: ";
    std::cin >> b_nom >> b_den;

    c_nom = a_nom * b_den + a_den * b_nom;
    c_den = a_den * b_den;

    std::cout << c_nom << " / " << c_den << std::endl;
}
```

## Branching

### Fraction calculator

Write a program that:

  - asks for two fractions,
  - asks for an operator (`+`, `-`, `*`, `/`), and
  - calculates the results.

The valid operators are: `+`, `-`, `*`, `/`

```cpp
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

    if (op == '+') {
        c_nom = a_nom * b_den + a_den * b_nom;
        c_den = a_den * b_den;
    } else if (op == '-') {
        c_nom = a_nom * b_den - a_den * b_nom;
        c_den = a_den * b_den;
    } else if (op == '*') {
        c_nom = a_nom * b_nom;
        c_den = a_den * b_den;
    } else if (op == '/') {
        c_nom = a_nom * b_den;
        c_den = a_den * b_nom;
    }

    std::cout << c_nom << " / " << c_den << std::endl;
}
```

Add the error checking to the fraction calculator:

- Denominators cannot be zero.
- The second nominator cannot be zero.

```cpp
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
```

## Loops

### Fraction calculator

Write a program that:

  - asks for two fractions,
  - asks for an operator (`+`, `-`, `*`, `/`),
  - calculates the results,
  - simplifies the results, and
  - gives an error message if the result cannot be calculated.

```cpp
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

    std::cout << c_nom << " / " << c_den << std::endl;
}

## Functions

### Histogram

```cpp
#include <iostream>

void star_04()
{
    std::cout << "****" << std::endl;
}

void star_08()
{
    std::cout << "********" << std::endl;
}

void star_12()
{
    std::cout << "************" << std::endl;
}

int main()
{
    star_04()
    star_08()
    star_12()
    star_08()
    star_04()
}
```

Modify the code above, to produce the following result:

```
************
********
****
********
************
```

Do you have an idea, how to improve the code, reduce its length and make it more flexible?

```cpp
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
```

### Fraction calculator

- a function for GCD:
  - <https://en.wikipedia.org/wiki/Euclidean_algorithm>
  - <https://en.wikipedia.org/wiki/Binary_GCD_algorithm>
  - recursive solution:

	```cpp
	int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}
	```

  - 
	```cpp
    int gcd( int x, int y )
	{
        if (x < y) {
            return gcd(y, x);
        }

        int f = x % y;
        if (f == 0) {
            return y;
        } else {
            return gcd(y, f);
        }
    }
	```
  -  the same without recursion:

	```cpp
        int gcd(int x, int y)
        {
            if (x < y) {
                std::swap(x, y);
            }
            while (y > 0) {
                int f = x % y;
                x = y;
                y = f;
            }
            return x;
        }  
	```

## Struct

### Fraction calculator

- Create a struct for the FractionNumber

## Classes

### Fraction calculator

- Naïve: simply make the calculator OO
- Probaly better: make the fraction numbers OO and add the operations there


```cpp
class fraction {
    private:
        int numerator;
        int denominator;
    public:
        fraction(int n, int d); // this is the constructor
        operator + ();
        operator - ();
        operator * ();
        operator / ();
}
```

## Standard library, containers and algorithms

### Fraction calculator

- `std::gcd` (from C++ 17)

## Code Style

### Why always initialize?

What does the following code output?

```
#include <iostream>

int sum(int a)
{
    int b;
    int c{5};
    if (a >= 18) {
      b = 10;
    }
    return a + b + c;
}

void have_a_break()
{
    int d = 100;
}


int main()
{
    int a{0};
    std::cout << sum(18) << std::endl;
    have_a_break();
    std::cout << sum(16) << std::endl;
}
```


```
s()                         [2] [4]
	b
	c = 5

hab()                       [3]
	c = 100

m()
	a = 0                     [1]
	s()
	hab()
	s()


[1] |a| 0                    after defining the variables in m() 

[2] |a| 0                    after defining the variables in s() 
    |b| 0
    |c| 5

    |a| 0                    before the end of s()
    |b| 10
    |c| 5

    |a| 0                    after the end of s()
    | | 10
    | | 5

[3] |a| 0                    after defining the variables in hab() 
    |d| 100
    | | 5

    |a| 0                    after the end of the hab()
    | | 100
    | | 5

[4] |a| 0                    after defining the variables in s() 
    |b| 100
    |c| 5

    |a| 0                    before the end of the function
    |b| 100
    |c| 5

    |a| 0                    after the end of the function
    | | 100
    | | 5
```

output:

```
33
121
```

