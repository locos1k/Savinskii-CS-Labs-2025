#pragma once

#include "Organization.hpp"

class InsuranceCompany : public Organization {
 protected:
   double capital;

 public:
   InsuranceCompany(const char* name, int year, double cap) : Organization(name, year), capital(cap) {
      std::cout << "InsuranceCompany()" << std::endl;
   }
   ~InsuranceCompany() override {
      std::cout << "~InsuranceCompany()" << std::endl;
   }

   void show() const override {
      std::cout << "Страховая компания: " << name << ", основана в " << year
                << " году, общий капитал: $" << capital << "млрд"<< std::endl;
   }
};