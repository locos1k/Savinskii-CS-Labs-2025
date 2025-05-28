#pragma once

#include "MyStack/MyStack.hpp"
#include "Organizations/Factory.hpp"
#include "Organizations/InsuranceCompany.hpp"
#include "Organizations/Organization.hpp"
#include "Organizations/ShipbuildingCompany.hpp"

enum class Task {
    Add = 1,
    Print = 2,
    Delete = 3,
    Clear = 4,
    Initialize = 5,
    Exit = 6
};

enum class Type {
    Insurance = 1,
    Plant = 2,
    Ship = 3
};

void print(MyStack::MyStack<Organization*>& container);
bool remove(MyStack::MyStack<Organization*>& container, int index);
void clear(MyStack::MyStack<Organization*>& container);

void addElement(MyStack::MyStack<Organization*>& organizations);

void demo(MyStack::MyStack<Organization*>& organizations);
void menu();
