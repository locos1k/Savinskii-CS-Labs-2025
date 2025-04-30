#include "AppRunner.hpp"
#include "MyStack/MyStack.hpp"
#include <iostream>

namespace AppRunner {
void RunApp() {
    int N{};
    std::cout << "Введите натуральное число N:\t";
    std::cin >> N;
    if (N <= 0) {
        throw std::runtime_error("Число должно быть положительным");
    }

    MyStack<int> stack;
    Multipliers(N, stack);
    MyStack<int> stack2 = stack;
    Reverse(stack2);
    Print(stack, N);
    Print(stack2, N);
    MyStack<int> stackSum = stack + stack2;
    std::cout << "stack + stack1 = " << stackSum << std::endl;
}
}  // namespace AppRunner
