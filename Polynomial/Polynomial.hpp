#pragma once

#include "../Term/Term.hpp"

#include <sstream>

class Polynomial {
    Term* poly;
    int degree;
    int size;
    bool order_;

 public:
    Polynomial();
    Polynomial(int p);
    Polynomial(const Term& t);
    Polynomial(const Polynomial& p);
    ~Polynomial();

    void sort(bool increase);

    Polynomial& operator=(const Polynomial& p);
    Polynomial& operator+=(const Polynomial& p);
    Polynomial& operator*=(const Polynomial& p);

    friend Polynomial operator+(const Polynomial& p1, const Polynomial& p2);
    friend Polynomial operator*(const Polynomial& p1, const Polynomial& p2);
    friend Polynomial operator-(const Polynomial& p1, Polynomial& p2);

    friend std::istream& operator>>(std::istream& in, Polynomial& p);
    friend std::ostream& operator<<(std::ostream& out, Polynomial& p);
};
