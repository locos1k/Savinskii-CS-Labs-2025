#pragma once

#include "Organization.hpp"

class Factory : public Organization {
 protected:
   int employees;

 public:
   Factory(const char* name, int year, int employees) : Organization(name, year), employees(employees) {
      std::cout << "Factory()" << std::endl;
   }
   ~Factory() override {
      std::cout << "~Factory()" << std::endl;
   }

   void show() const override {
      std::cout << "Завод: " << name << ", основан в " << year 
                << " году, количество сотрудников: " << employees << std::endl;
   }
};