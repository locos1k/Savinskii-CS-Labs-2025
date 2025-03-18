#pragma once
#include <iostream>

namespace Fractions {
class Fraction {
 private:
    int numerator;
    int denominator;

    int CalculateGCD(int a, int b) {
        while(b) {
            a %= b;
            std::swap(a, b);
        }
        return std::abs(a);
    }

    void ReduceFraction() {
        int gcd = CalculateGCD(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

 public:
    Fraction(): numerator(0), denominator(1) {};
    Fraction(const char* str);
    Fraction(double decimal);
    Fraction(int num, int denom);
    Fraction(const Fraction& other);

    void GetStr(const char*);

    friend std::istream& operator>>(std::istream& in, Fraction& fraction);
    friend std::ostream& operator<<(std::ostream& out, Fraction& fraction);

    Fraction operator+(Fraction& other);
    Fraction operator+(int x);
    Fraction operator+(double x);
    friend Fraction operator+(double x, Fraction& other);
    friend Fraction operator+(int x, Fraction& other);

    Fraction& operator+=(Fraction other);
    Fraction& operator+=(int x);
    Fraction& operator+=(double x);
    
};
}  // namespace Fractions
