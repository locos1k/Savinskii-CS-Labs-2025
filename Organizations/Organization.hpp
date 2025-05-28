#pragma once

#include <iostream>

class Organization {
 protected:
    char* name;
    int year;

 public:
    Organization(const char* n, int y) : year(y) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);

        std::cout << "Organization()" << std::endl;
    }
    virtual ~Organization() {
        delete[] name;

        std::cout << "~Organization()" << std::endl;
    }  

    virtual void show() const = 0;
};