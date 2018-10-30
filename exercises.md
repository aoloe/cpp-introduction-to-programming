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

## Age control in a club

At the entry of a club there is a age check:

- People younger than 16 cannot entry.
- People who are exactly 18 years old have a free entry.
- People who are younger than 18 pay 20.— and get 4 _free_ soft drinks.
- People who are younger than 18 pay 50.— and get 4 _free_ drinks.

### Small exercises

- Numbers:
    - Write a function that gets a number and returns its doubl.
    - Write a function that gets two numbers and returns their sum.
    - Write a function that gets one number and returns its square.
    - Write a function that gets two numbers and returns the sum of their square.
    - Write a function that gets a number and returns true when it is even and false otherwise.
- Strings:
  - Write a function that gets a character and a number n and returns a string with the character repeated n times.
  - Write a function that gets a string and a number n and returns the first n characters.
  - Write a function that gets a string and a number n and retunrs the last n characters

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

### The checksum

Sum of all digits in a number: `1234` is transformed in `1 + 2 + 3 + 4 = 10`

```cpp
#include <iostream>

int checksum(int number)
{
    int result{0};

    while (number > 0) {
        result += number %10;
        number /= 10;
    }

    return result;
}

int main()
{
    std::cout << checksum(123456) << std::endl;
}
```

What happens if you want to calculate the checksum of `123123123123`?  

We can use an `unsigned int` or even an `unsigned long` as the argument for `checksum(unsigned long number)`.

Is there a simple way to calculate the checksum of any integer number, ?  

```cpp
#include <iostream>
#include <string>

const int ASCII_ZERO = 48;

int checksum(std::string number)
{
    int result{0};

    for (char i: number) {
        result += i - ASCII_ZERO;
    }

    return result;
}

int main()
{
    std::cout << checksum("123456") << std::endl;
}
```

### Get the digits numbers in the right number

Given the number 12345, output:

```
1
2
3
4
5
```

The simplest solution is to use the same algorithm as for the checksum and put each digit in a list, which you, then can output in the right order.

There is also an elegant recursive solution:

```cpp
#include <iostream>

void show_digits(int number)
{
    if (number > 10) {
        show_digits(number / 10);
    }
    std::cout << number % 10 << std::endl;
}

int main()
{
    show_digits(1234);
}
```

### Fibonacci

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

std::string get_stars(int i)
{
    return std::string(i, '*');
}

int main()
{
    std::cout << get_stars(4) << std::endl;
    std::cout << get_stars(8) << std::endl;
    std::cout << get_stars(12) << std::endl;
    std::cout << get_stars(8) << std::endl;
    std::cout << get_stars(4) << std::endl;
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

## Loops

### Get the digits numbers in the right number

<!-- ```src/loops-digits.cpp``` -->
```cpp
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
```

### Fibonacci Series

A Fibonacci serie is a serie of numbers in which each number is the sum of the two preceding numbers. The simplest is the series 1, 1, 2, 3, 5, 8, etc.

fib(n) = fib(n-1) + fib(n-2)

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

