#include "Fraction.hpp"

#include <exception>
#include <iostream>
#include <algorithm>

namespace {
const int kAccuracy = 10000;
}  // namespace

namespace Fractions {
void Fraction::GetStr(const char* str) {
    char buffer[50];
    std::strcpy(buffer, str);

    char* firstPart = std::strtok(buffer, " ");
    char* secondPart = std::strtok(nullptr, " ");

    int whole = 0;
    int num = 0;
    int denom = 1;

    if (firstPart == nullptr) {
        throw std::invalid_argument("Ошибка: пустой ввод");
    }

    if (secondPart != nullptr) {
        if (!isNumber(firstPart)) throw std::invalid_argument("Ошибка: целая часть не является числом");

        whole = std::atoi(firstPart);
        char* numPart = std::strtok(secondPart, "/");
        char* denomPart = std::strtok(nullptr, "/");

        if (numPart == nullptr || denomPart == nullptr || !isNumber(numPart) || !isNumber(denomPart)) {
            throw std::invalid_argument("Ошибка: неверный формат дроби");
        }

        num = std::atoi(numPart);
        denom = std::atoi(denomPart);
    } else if (std::strchr(firstPart, '/')) {
        char* numPart = std::strtok(firstPart, "/");
        char* denomPart = std::strtok(nullptr, "/");

        if (numPart == nullptr || denomPart == nullptr || !isNumber(numPart) || !isNumber(denomPart)) {
            throw std::invalid_argument("Ошибка: неверный формат дроби");
        }

        num = std::atoi(numPart);
        denom = std::atoi(denomPart);
    } else {
        if (!isNumber(firstPart)) throw std::invalid_argument("Ошибка: введено не число");
        whole = std::atoi(firstPart);
    }

    if (denom == 0) {
        throw std::invalid_argument("Ошибка: знаменатель не может быть равен 0");
    }

    numerator = whole * denom + (whole >= 0 ? num : -num);
    denominator = denom;

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
        throw std::invalid_argument("Ошибка: знаменатель должен быть положительным");
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

Fraction Fraction::operator-(Fraction& other) {
    return Fraction(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
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
