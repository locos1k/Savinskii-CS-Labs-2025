#include <iostream>
#include <map>

void Print(std::map<char, int> m) {
    std::map<char, int>::iterator i;
    for (i = m.begin(); i != m.end(); ++i) {
        std::cout << i->first << " -> " << i->second << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    std::map<char, int> m;
    for (int i = 0; i < 5; ++i) {
        m['A' + i] = i + 1;
    }
    Print(m);

    m.erase('C');
    std::cout << "После удаления пары с ключом С:\n";
    Print(m);
}