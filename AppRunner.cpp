#include "AppRunner.hpp"
#include "Polynomial/Polynomial.hpp"
#include "Term/Term.hpp"
#include <iostream>

namespace AppRunner {
void RunApp() {
    std::cout << "Enter first term: ";
    Term t1, t2, t3;
    std::cin >> t1;

    std::cout << "Enter second term: ";
    std::cin >> t2;
    std::cout << std::endl;

    t3 = t1 + t2;
    std::cout << "t1 + t2: " << t3 << std::endl;

    t1 = t1 * t2;
    std::cout << "t1 * t2: " << t1 << std::endl;
    std::cout << std::endl;

    std::cout << "Enter first polynomial: ";
    Polynomial p1 , p2 , p3, plus, minus;
    std::cin >> p1;
    p3 = p1;
    p1.sort(false);
    std::cout << p1 << std::endl;

    std::cout << "Enter second polynomial: ";
    std::cin >> p2;
    p2.sort(false);
    std::cout << p2 << std::endl;
    
    p3 *= p2;
    plus = p1 + p2;
    minus = p1 - p2;

    bool increase = false;
    std::cout << "Enter 1 to output in ascending degree, 0 to output in descending degree: ";
    std::cin >> increase;
    p3.sort(increase);
    plus.sort(increase);
    minus.sort(increase);

    std::cout << "p1 + p2: " << plus << std::endl;
    std::cout << "p1 - p2: " << minus <<std::endl;
    std::cout << "p1 * p2: " << p3 << std::endl;
}
}  // namespace AppRunner
