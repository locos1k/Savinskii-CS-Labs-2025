#include "Diets.hpp"

#include <fstream>
#include <iostream>

namespace {
const int kBuffSize = 100;

int BinarySearch(Diet::Diet* diets, int size, const char* target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (diets[mid] == target) {
            return mid;
        } else if (diets[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
}  // namespace

namespace Diet {
Diet::Diet(const char* n, int p, int f, int ch) {
    name = new char[strlen(n) + 1];
    strcpy(name, n);

    proteins = p;
    fats = f;
    carbohydrates = ch;
}

Diet::Diet(const Diet& other) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);

    proteins = other.proteins;
    fats = other.fats;
    carbohydrates = other.carbohydrates;
}

Diet::~Diet() {
    delete[] name;
}

void Diet::SetName(const char* n) {
    if (name) {
        delete[] name;
    }

    name = new char[strlen(n) + 1];
    strcpy(name, n);
}

Diet& Diet::operator=(const Diet& other) {
    if (this == &other)
        return *this;

    delete[] name;

    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);

    proteins = other.proteins;
    fats = other.fats;
    carbohydrates = other.carbohydrates;

    return *this;
}

std::ofstream& operator<<(std::ofstream& file, Diet& diet) {
    file << diet.name << " " << diet.proteins << " " << diet.fats << " " << diet.carbohydrates << std::endl;
    return file;
}

std::ifstream& operator>>(std::ifstream& file, Diet& diet) {
    char n[kBuffSize] = {};
    int p = 0;
    int f = 0;
    int ch = 0;

    file >> n >> p >> f >> ch;

    diet.SetName(n);
    diet.proteins = p;
    diet.fats = f;
    diet.carbohydrates = ch;

    return file;
}

bool Diet::operator==(const char* n) {
    if (strcmp(this->name, n) == 0) {
        return true;
    } else {
        return false;
    }
}

bool Diet::operator<(Diet& diet2) {
    if (strcmp(this->name, diet2.name) < 0) {
        return true;
    } else {
        return false;
    }
}

bool Diet::operator<(const char* n) {
    if (strcmp(this->name, n) < 0) {
        return true;
    } else {
        return false;
    }
}

void Diet::Resize(Diet*& diets, int& size) {
    Diet* newDiets = new Diet[size + 1];

    for (int i = 0; i < size; ++i) {
        newDiets[i] = diets[i];
    }

    DeleteDB(diets);
    diets = newDiets;
    ++size;
}

void Diet::DeleteDB(Diet*& diets) {
    if (!diets) {
        return;
    }

    delete[] diets;
    diets = nullptr;
}

void Diet::ReadDB(Diet*& diets, int& size) {
    std::ifstream file("Diets.txt");
    if (!file) {
        std::cout << "Ошибка открытия файла\n\n";
        return;
    }

    Diet temp;

    while (file >> temp) {
        if (size == 1 && diets[0] == "\0") {
            diets[0] = temp;
        } else {
            Resize(diets, size);
            diets[size - 1] = temp;
        }
    }

    file.close();
}

void Diet::WriteDB(Diet*& diets, int size) {
    if (!diets) {
        return;
    }

    std::ofstream file("Diets.txt");
    if (!file) {
        std::cout << "Ошибка открытия файла\n\n";
        return;
    }

    for (int i = 0; i < size; ++i) {
        file << diets[i];
    }

    file.close();
}

void Diet::SortDB(Diet*& diets, int left, int right) {
    if (!diets || left >= right) {
        return;
    }

    Diet pivot = diets[right];
    int partitionIndex = left;

    for (int i = left; i < right; ++i) {
        if (diets[i] < pivot) {
            std::swap(diets[i], diets[partitionIndex]);
            ++partitionIndex;
        }
    }
    std::swap(diets[right], diets[partitionIndex]);

    SortDB(diets, left, partitionIndex - 1);
    SortDB(diets, partitionIndex + 1, right);
}

void Diet::AddElement(Diet*& diets, int& size) {
    if (!diets) {
        return;
    }

    Resize(diets, size);

    char n[kBuffSize]{};
    int p = 0;
    int f = 0;
    int ch = 0;

    std::cout << "Введите название диеты, кол-во белков, кол-во жиров, кол-во углеводов: ";
    std::cin >> n >> p >> f >> ch;
    std::cout << std::endl;

    diets[size - 1].SetName(n);
    diets[size - 1].proteins = p;
    diets[size - 1].fats = f;
    diets[size - 1].carbohydrates = ch;
}

void Diet::DeleteElement(Diet*& diets, int& size) {
    if (!diets) {
        return;
    }

    char n[kBuffSize]{};
    std::cout << "Введите название диеты для удаления: ";
    std::cin >> n;
    std::cout << std::endl;

    SortDB(diets, 0, size - 1);
    int point = BinarySearch(diets, size, n);

    if (point == -1) {
        std::cout << "Диета не найдена\n\n";
        return;
    }

    Diet* newDiets = new Diet[size - 1];

    for (int i = 0, j = 0; i < size; ++i) {
        if (i == point) {
            continue;
        }
        newDiets[j++] = diets[i];
    }

    DeleteDB(diets);
    diets = newDiets;
    --size;
}

void Diet::EditDB(Diet*& diets, int size) {
    if (!diets) {
        return;
    }

    char nameToEdit[kBuffSize]{};
    std::cout << "Введите название диеты, которую хотите изменить: ";
    std::cin >> nameToEdit;
    std::cout << std::endl;

    SortDB(diets, 0, size - 1);

    int point = BinarySearch(diets, size, nameToEdit);

    if (point == -1) {
        std::cout << "Диета не найдена\n\n";
        return;
    }

    char n[kBuffSize]{};
    int p = 0;
    int f = 0;
    int ch = 0;

    std::cout << "Введите измененные название диеты, кол-во белков, кол-во жиров, кол-во углеводов: ";
    std::cin >> n >> p >> f >> ch;
    std::cout << std::endl;
    diets[point].SetName(n);
    diets[point].proteins = p;
    diets[point].fats = f;
    diets[point].carbohydrates = ch;
}

void Diet::PrintDB(Diet*& diets, int size) {
    if (!diets) {
        return;
    }

    if (diets[0] == "\0") {
        std::cout << "БД пуста\n\n";
        return;
    }

    for (int i = 0; i < size; ++i) {
        std::cout << "Название диеты: " << diets[i].name << '\n'
                  << "Кол-во белков: " << diets[i].proteins << '\n'
                  << "Кол-во жиров: " << diets[i].fats << '\n'
                  << "Кол-во углеводов: " << diets[i].carbohydrates << '\n'
                  << '\n';
    }
}
}  // namespace Diet
