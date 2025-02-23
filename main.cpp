#include <iostream>
#include "mymath/mymath.h"
#include "mymath2/mymath2.h"

int main() {
    std::cout << "Я умею суммировать! Зацени 10 + 32 = ";
    std::cout << mymath::sum(10, 32) << std::endl;

    std::cout << "Я умею умножать! Зацени 12 х 5 = ";
    std::cout << multiplication::Multiply(12, 5) << std::endl;
    return 0;
}