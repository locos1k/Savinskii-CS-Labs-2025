#pragma once

#include "Organization.hpp"

class ShipbuildingCompany : public Organization {
 protected:
   int shipsBuilt;

 public:
   ShipbuildingCompany(const char* name, int year, int ships) : Organization(name, year), shipsBuilt(ships) {
      std::cout << "ShipbuildingCompany()" << std::endl;
   }
   ~ShipbuildingCompany() override {
      std::cout << "~ShipbuildingCompany()" << std::endl;
   }

   void show() const override {
      std::cout << "Судостроительная компания: " << name << ", основана в " 
                << year << " году, построено судов: " << shipsBuilt << std::endl;
   }
};