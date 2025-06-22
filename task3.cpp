#include <iostream>
#include <string>
#include <fstream>

int main() {
    std::ifstream in("task3IN.txt");
    std::ofstream out("task3OUT.txt");
    
    if (!(in && out)) {
        std::cout << "Файл не удалось открыть" << std::endl;
    }

    std::string line;

    while(std::getline(in, line)) {
        for (int i = 0; i < line.length(); ++i) {
            if (line[i] == ' ') out << ' ';
            out << line[i];
        }
        out << std::endl;

        if (in.eof()) break;
    }
}
