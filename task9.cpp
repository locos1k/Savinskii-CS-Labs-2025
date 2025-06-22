#include <iostream>
#include <string>
#include <map>

void Print(std::map<std::string, int>& m) {
    std::map<std::string, int>::iterator i;
    for (i = m.begin(); i != m.end(); ++i) {
        std::cout << "В штате " << i->first << " живет " << i->second << " тыс людей" << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    std::string states[] = { "Wyoming", "Colorado", "Nevada", "Montana", "Arizona", "Idaho"};
    int pops[] = { 470, 2890, 800, 787, 2718, 944 };

    std::map<std::string, int> map;
    const int size = sizeof(states) / sizeof(states[0]);
    for (int i = 0; i < size; ++i) {
        map[states[i]] = pops[i];
    }
    Print(map);

    std::cout << "Введите название штата: ";
    std::string state;
    std::cin >> state;
    std::map<std::string, int>::iterator iter = map.find(state);
    if (iter != map.end()) {
        std::cout << "В штате " << iter->first << " живет " << iter->second << " тыс людей" << std::endl;
    } else {
        std::cout << "Штат не найден\n";
    }
}