#pragma once

#include <iostream>

class Term {
    int coefficient;
    int exponent;

 public:
    Term() : coefficient(0), exponent(0) {}
    Term(int c) : coefficient(c), exponent(0) {}
    Term(int c, int d) : coefficient(c), exponent(d) {}

    int GetCoefficient() { return coefficient; }

    friend Term operator+(const Term& t1, const Term& t2);
    friend Term operator*(const Term& t1, const Term& t2);

    friend std::istream& operator>>(std::istream& in, Term& t);
    friend std::ostream& operator<<(std::ostream& out, Term& t);

    friend class Polynomial;
};