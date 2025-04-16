#include "AppRunner.hpp"
#include <iostream>

int main() {
    try {
        AppRunner::RunApp();
    } catch(const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}