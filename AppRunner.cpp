#include "AppRunner.hpp"
#include "fractions/Fraction.hpp"

#include <iostream>

namespace AppRunner {
void RunApp() {
    std::cout << "Введите дробь:   ";
    Fractions::Fraction z;
    std::cin >> z;
    std::cout << "z = " << z << std::endl;

    Fractions::Fraction fr1(1, 2), fr2;
    std::cout << "fr2 = " << fr2 << std::endl;
    std::cout << "fr1 = " << fr1 << std::endl;

    fr2 = z - fr1;
    std::cout << "fr2 = z - fr1 = " << fr2 << std::endl;

    Fractions::Fraction fr = "-1 4/8";
    std::cout << "fr = " << fr << std::endl;

    Fractions::Fraction x(z), y;
    std::cout << "x = " << x << std::endl;

    double dbl = -1.25;
    Fractions::Fraction f = dbl;
    std::cout << "f = " << f << std::endl;

    y = x + z;
    std::cout << "y = " << y << std::endl;

    y += x;
    std::cout << "y = " << y << std::endl;

    f += dbl / 2;
    std::cout << "f = " << f << std::endl;

    y = x + dbl;
    std::cout << "y = " << y << std::endl;

    y = dbl + y;
    std::cout << "y = " << y << std::endl;

    y += dbl;
    std::cout << "y = " << y << std::endl;

    int i = 5;
    y += i;
    std::cout << "y = " << y << std::endl;

    y = i + x;
    std::cout << "y = " << y << std::endl;

    y = x + i;
    std::cout << "y = " << y << std::endl;

    y += dbl + i + x;
    std::cout << "y = " << y << std::endl;
}
}  // namespace AppRunner
