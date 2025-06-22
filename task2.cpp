#include <iostream>
#include <string>

int FindSpace(std::string str, int startIndex = 0) {
    for (int i = startIndex; i < str.length(); ++i) {
        if (str[i] == ' ') return i;
    }
    return -1;
}

int main() {
    std::cout << "Введите ФИО учащегося:\t";
    std::string fullName;
    std::getline(std::cin, fullName);

    int firstSpace = FindSpace(fullName);
    int secondSpace = FindSpace(fullName, firstSpace + 1);
    if (firstSpace == -1 || secondSpace == -1) {
        std::cout << "ФИО введено некорректно" << std::endl;
        return 0;
    }

    std::cout << "ФИ учащегося:\t";
    for (int i = 0; i < secondSpace; ++i) {
        std::cout << fullName[i];
    }
    std::cout << std::endl;
    
    return 0;
}
