#include "Planets.hpp"

#include <fstream>
#include <iostream>

namespace {
const int kBuffSize = 100;

int BinarySearch(Planets::Planet* planets, int size, const char* target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (planets[mid] == target) {
            return mid;
        } else if (planets[mid] < target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}
}  // namespace

namespace Planets {
Planet::Planet(const char* n, int d, bool l, int sn) {
    name = new char[strlen(n) + 1];
    strcpy(name, n);

    diameter = d;
    life = l;
    satellitesNumber = sn;
}

Planet::Planet(const Planet& other) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);

    diameter = other.diameter;
    life = other.life;
    satellitesNumber = other.satellitesNumber;
}

Planet::~Planet() {
    delete[] name;
}

void Planet::SetName(const char* n) {
    if (name) {
        delete[] name;
    }

    name = new char[strlen(n) + 1];
    strcpy(name, n);
}

Planet& Planet::operator=(const Planet& other) {
    if (this == &other)
        return *this;

    delete[] name;

    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);

    diameter = other.diameter;
    life = other.life;
    satellitesNumber = other.satellitesNumber;

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Planet& planet) {
    os << planet.name << " " << planet.diameter << " " << planet.life << " " << planet.satellitesNumber << std::endl;

    return os;
}

std::istream& operator>>(std::istream& is, Planet& planet) {
    is >> planet.name >> planet.diameter >> planet.life >> planet.satellitesNumber;

    return is;
}

bool Planet::operator==(const char* n) {
    if (strcmp(this->name, n) == 0) {
        return true;
    } else {
        return false;
    }
}

bool Planet::operator<(const Planet& planet2) {
    if (strcmp(this->name, planet2.name) < 0) {
        return true;
    } else {
        return false;
    }
}

bool Planet::operator<(const char* n) {
    if (strcmp(this->name, n) < 0) {
        return true;
    } else {
        return false;
    }
}

void Planet::Resize(Planet*& planets, int& size) {
    Planet* newPlanets = new Planet[size + 1];

    for (int i = 0; i < size; ++i) {
        newPlanets[i] = planets[i];
    }

    DeleteDB(planets);
    planets = newPlanets;
    ++size;
}

void Planet::DeleteDB(Planet*& planets) {
    if (!planets) {
        return;
    }

    delete[] planets;
    planets = nullptr;
}

void Planet::ReadDB(Planet*& planets, int& size) {
    std::ifstream file("Planets.txt");
    if (!file) {
        std::cout << "Ошибка открытия файла\n\n";
        return;
    }

    Planet temp;

    while (file >> temp) {
        if (size == 1 && planets[0] == "\0") {
            planets[0] = temp;
        } else {
            Resize(planets, size);
            planets[size - 1] = temp;
        }
    }

    file.close();
}

void Planet::WriteDB(Planet*& planets, int size) {
    if (!planets) {
        return;
    }

    std::ofstream file("Planets.txt");
    if (!file) {
        std::cout << "Ошибка открытия файла\n\n";
        return;
    }

    for (int i = 0; i < size; ++i) {
        file << planets[i];
    }

    file.close();
}

void Planet::SortDB(Planet*& planets, const int size) {
    if (!planets) {
        return;
    }

    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1 - i; ++j) {
            if (planets[j] < planets[j + 1]) {
                std::swap(planets[j], planets[j + 1]);
            }
        }
    }
}

void Planet::AddElement(Planet*& planets, int& size) {
    if (!planets) {
        return;
    }

    Resize(planets, size);

    std::cout << "Введите название планеты, диаметр, жизнь (есть - 1, нет - 0), количество спутников: ";
    std::cin >> planets[size - 1];
    std::cout << std::endl;
}

void Planet::DeleteElement(Planet*& planets, int& size) {
    if (!planets) {
        return;
    }

    char n[kBuffSize]{};
    std::cout << "Введите название планеты для удаления: ";
    std::cin >> n;
    std::cout << std::endl;

    SortDB(planets, size);
    int point = BinarySearch(planets, size, n);

    if (point == -1) {
        std::cout << "Планета не найдена\n\n";
        return;
    }

    for (int i = point; i < size - 1; ++i) {
        planets[i] = planets[i + 1];
    }

    --size;
}

void Planet::EditDB(Planet*& planets, int size) {
    if (!planets) {
        return;
    }

    char nameToEdit[kBuffSize]{};
    std::cout << "Введите название планеты, которую хотите изменить: ";
    std::cin >> nameToEdit;
    std::cout << std::endl;

    SortDB(planets, size);

    int point = BinarySearch(planets, size, nameToEdit);

    if (point == -1) {
        std::cout << "Планета не найдена." << std::endl;
        return;
    }

    std::cout << "Введите измененные название планеты, диаметр, наличие жизни (есть - 1, нет - 0), количество спутников: ";
    std::cin >> planets[point];
    std::cout << std::endl;
}

void Planet::PrintDB(Planet*& planets, int size) {
    if (!planets) {
        return;
    }

    if (planets[0] == "\0") {
        std::cout << "БД пуста\n\n";
        return;
    }

    for (int i = 0; i < size; ++i) {
        std::cout << planets[i];
    }
    std::cout << std::endl;
}
}  // namespace Planets
