#include "Term.hpp"

#include <iostream>
#include <cstring>


Term operator+(const Term& t1, const Term& t2) {
    if (t1.exponent != t2.exponent) {
        throw std::invalid_argument("Error: addition terms with different degrees is impossible!");
    }

    return Term(t1.coefficient + t2.coefficient, t1.exponent);
}

Term operator*(const Term& t1, const Term& t2) {
    return Term(t1.coefficient * t2.coefficient, t1.exponent + t2.exponent);
}

std::istream& operator>>(std::istream& in, Term& t) {
    char buffer[50]{};
    in.getline(buffer, 50);

    char* xPos = strchr(buffer, 'x');

    if (xPos) {
        *xPos = '\0';

        if (*buffer == '\0' || strcmp(buffer, "+") == 0) {
            t.coefficient = 1;
        } else if (strcmp(buffer, "-") == 0) {
            t.coefficient = -1;
        } else {
            t.coefficient = atoi(buffer);
        }

        char* expPart = strchr(xPos + 1, '^');
        if (expPart) {
            t.exponent = atoi(expPart + 1);
        } else {
            t.exponent = 1;
        }
    } else {
        t.coefficient = atoi(buffer);
        t.exponent = 0;
    }

    return in;
}

std::ostream& operator<<(std::ostream& out, Term& t) {
    if (t.exponent != 0) {
        if (t.coefficient == 1) {
            out << "x";
        } else if (t.coefficient == -1) {
            out << "-x";
        } else {
            out << t.coefficient << "x";
        }
        if (t.exponent != 1 && t.exponent != 0) {
            out << "^" << t.exponent;
        }
    } else {
        out << t.coefficient;
    }

    return out;
}