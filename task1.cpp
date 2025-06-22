#include <iostream>
#include <string>

int main() {
    std::string str1;
    std::cout << "Введите первое слово: ";
    std::cin >> str1;
   
    std::string str2;
    std::cout << "Введите второе слово: ";
    std::cin >> str2;

    std::string result;
    int maxLenght = std::max(str1.length(), str2.length());
    
    for (int i = 0; i < maxLenght; ++i) {
        if (i < str1.length()) result += str1[i];
        if (i < str2.length()) result += str2[i];
    }
    std::cout << "Новое слово, в котором чередуются буквы первого и второго слова: " << result << std::endl;
}
