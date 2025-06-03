#include "AppRunner.hpp"

#include <iostream>

void print(MyStack::MyStack<Organization*>& container) {
    if (container.empty()) {
        std::cout << "Стек пустой." << std::endl;
        return;
    }

    MyStack::MyStack<Organization*> tempStack;
    std::cout << "Содержимое стека:" << std::endl;
    int i{};
    while (!container.empty()) {
        Organization* org = container.top_inf();
        std::cout << i++ << ". ";
        org->show();
        tempStack.push(org);
        container.pop();
    }

    while (!tempStack.empty()) {
        container.push(tempStack.top_inf());
        tempStack.pop();
    }

    std::cout << std::endl;
}

bool remove(MyStack::MyStack<Organization*>& container, int index) {
    if (container.empty()) {
        return false;
    }

    MyStack::MyStack<Organization*> tempStack;
    int currentIndex = 0;

    while (!container.empty()) {
        if (currentIndex == index) {
            Organization* org = container.top_inf();
            delete org;
            container.pop();
            ++currentIndex;
            continue;
        }

        Organization* org = container.top_inf();
        tempStack.push(org);
        container.pop();
        ++currentIndex;
    }

    while (!tempStack.empty()) {
        container.push(tempStack.top_inf());
        tempStack.pop();
    }

    return true;
}

void clear(MyStack::MyStack<Organization*>& container) {
    while (!container.empty()) {
        Organization* org = container.top_inf();
        delete org;
        container.pop();
    }
}

void addElement(MyStack::MyStack<Organization*>& organizations) {
    int type;
    std::cout << "Выберите тип организации:" << std::endl;
    std::cout << "1. Страховая компания" << std::endl;
    std::cout << "2. Завод" << std::endl;
    std::cout << "3. Судостроительная компания" << std::endl;
    std::cin >> type;

    char name[100];
    int year;
    std::cin.ignore();
    std::cout << "Введите название: ";
    std::cin.getline(name, 100);
    std::cout << "Введите год основания: ";
    std::cin >> year;

    switch (static_cast<Type>(type)) {
        case Type::Insurance: {
            double capital;
            std::cout << "Введите сумму капитала: ";
            std::cin >> capital;
            organizations.push(new InsuranceCompany(name, year, capital));
            break;
        }
        case Type::Plant: {
            int employees;
            std::cout << "Введите количество сотрудников: ";
            std::cin >> employees;
            organizations.push(new Factory(name, year, employees));
            break;
        }
        case Type::Ship: {
            int ships;
            std::cout << "Введите количество построенных судов: ";
            std::cin >> ships;
            organizations.push(new ShipbuildingCompany(name, year, ships));
            break;
        }
        default:
            std::cout << "Неверный выбор типа! Элемент не добавлен." << std::endl;
    }
    std::cout << std::endl;
}

void demo(MyStack::MyStack<Organization*>& organizations) {
    organizations.push(new InsuranceCompany("State Farm", 1922, 123131));
    organizations.push(new ShipbuildingCompany("Huntington Ingalls Industries", 2007, 120));
    organizations.push(new Factory("Toyota Motomachi Factory", 1959, 4100));

    print(organizations);

    std::cout << "Удаление первого элемента:" << std::endl;
    remove(organizations, 0);
    print(organizations);

    std::cout << "Очистка контейнера:" << std::endl;
    clear(organizations);
    print(organizations);
}

void menu() {
    MyStack::MyStack<Organization*> organizations;
    int choice = 0;

    while (true) {
        std::cout << "------------------------------------------------------------------------\n";
        std::cout << "1. Добавить элемент в контейнер\n"
                  << "2. Печать содержимого контейнера\n"
                  << "3. Удалить элемент по индексу\n"
                  << "4. Очистить контейнер\n"
                  << "5. Инициализация демо\n"
                  << "6. Выход\n"
                  << "Выберите задание: ";
        std::cin >> choice;
        std::cout << std::endl;

        switch (static_cast<Task>(choice)) {
            case Task::Add:
                addElement(organizations);
                break;
            case Task::Print:
                print(organizations);
                break;
            case Task::Delete: {
                int index;
                std::cout << "Введите индекс элемента для удаления: ";
                std::cin >> index;
                remove(organizations, index);
                break;
            }
            case Task::Clear:
                clear(organizations);
                break;
            case Task::Initialize:
                demo(organizations);
                return;
            case Task::Exit:
                clear(organizations);
                return;
            default:
                std::cout << "Неверный номер задания" << std::endl;
        }
    }
}
