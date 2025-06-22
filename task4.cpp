#include <iostream>
#include <vector>

void Print(std::vector<float> v) {
    std::cout << "Содержимое вектора:\n";
    for (float val : v) {
    std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<float> vec;
    for (int i = 0; i < 25; ++i) {
        vec.push_back(0.5 + i);
    }
    Print(vec);

    vec.erase(vec.begin() + 1);
    Print(vec);
}