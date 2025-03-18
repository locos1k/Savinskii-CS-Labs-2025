#include "Fraction.hpp"

#include <iostream>

namespace {
const int kAccuracy = 1000;
}  // namespace

namespace Fractions {
void Fraction::GetStr(const char* str) {
    char buffer[50];
    std::strcpy(buffer, str);

    char* wholePart = std::strtok(buffer, " ");
    char* fractionPart = std::strtok(nullptr, " ");

    int whole = 0;
    int num = 0;
    int denom = 1;

    if (fractionPart != nullptr) {
        whole = std::atoi(wholePart);
        char* numPart = std::strtok(fractionPart, "/");
        char* denomPart = std::strtok(nullptr, "/");

        if (numPart == nullptr || denomPart == nullptr) {
            std::cout << "Ошибка: неверный формат дроби" << std::endl;
            numerator = 0;
            denominator = 1;
            return;
        }

        num = std::atoi(numPart);
        denom = std::atoi(denomPart);
    } else if (std::strchr(wholePart, '/')) {
        char* numPart = std::strtok(wholePart, "/");
        char* denomPart = std::strtok(nullptr, "/");

        if (numPart == nullptr || denomPart == nullptr) {
            std::cout << "Ошибка: неверный формат дроби" << std::endl;
            numerator = 0;
            denominator = 1;
            return;
        }

        num = std::atoi(numPart);
        denom = std::atoi(denomPart);
    } else {
        whole = std::atoi(wholePart);
    }

    if (denom == 0) {
        std::cout << "Ошибка: знаменатель не может быть равен 0" << std::endl;
        numerator = 0;
        denominator = 1;
        return;
    }
    if (denom < 0) {
        std::cout << "Ошибка: знаменатель должен быть положительным" << std::endl;
        numerator = 0;
        denominator = 1;
        return;
    }

    //std::cout << "whole = " << whole << ", num = " << num << ", denom = " << denom << std::endl;
    
    numerator = whole * denom + (whole >= 0? num : -num);
    denominator = denom;

    //std::cout << ", num = " << numerator << ", denom = " << denominator << std::endl;

    ReduceFraction();
}

Fraction::Fraction(const char* str) {
    GetStr(str);
}

Fraction::Fraction(double decimal) {
    denominator = kAccuracy;
    numerator = static_cast<int>(decimal * kAccuracy);

    ReduceFraction();
}

Fraction::Fraction(int num, int denom) {
    if (denom <= 0) {
        std::cout << "Ошибка: знаменатель должен быть положительным" << std::endl;
        numerator = 0;
        denominator = 1;
        return;
    }

    numerator = num;
    denominator = denom;

    ReduceFraction();
}

Fraction::Fraction(const Fraction& other) {
    numerator = other.numerator;
    denominator = other.denominator;
}

std::istream& operator>>(std::istream& in, Fraction& fraction) {
    char buffer[50];
    in.getline(buffer, sizeof(buffer));
    fraction.GetStr(buffer);

    return in;
}

std::ostream& operator<<(std::ostream& out, Fraction& fraction) {
    int whole = fraction.numerator / fraction.denominator;
    int remainder = std::abs(fraction.numerator % fraction.denominator);

    if (fraction.denominator == 1) {
        out << fraction.numerator;
    } else if (whole != 0 && remainder != 0) {
        out << whole << " " << remainder << "/" << fraction.denominator;
    } else {
        out << fraction.numerator << "/" << fraction.denominator;
    }

    return out;
}

Fraction Fraction::operator+(Fraction& other) {
    return Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
}

Fraction Fraction::operator+(int x) {
    Fraction temp(x, 1);
    return *this + temp;
}

Fraction Fraction::operator+(double x) {
    Fraction temp(x);
    return *this + temp;
}

Fraction operator+(int x, Fraction& other) {
    Fraction temp(x, 1);
    return temp + other;
}

Fraction operator+(double x, Fraction& other) {
    Fraction temp(x);
    return temp + other;
}

Fraction& Fraction::operator+=(Fraction other) {
    *this = *this + other;
    return *this;
}

Fraction& Fraction::operator+=(int x) {
    Fraction temp(x);
    *this = *this + temp;
    return *this;
}

Fraction& Fraction::operator+=(double x) {
    Fraction temp(x);
    *this = *this + temp;
    return *this;
}
}  // namespace Fractions
