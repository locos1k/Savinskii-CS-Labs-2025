#include <iostream>
#include "AppRunner.hpp"

int main() {
    try {
        AppRunner::RunApp();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}