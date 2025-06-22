#include <iostream>
#include <list>

void Print(std::list<int>& l) {
    std::list<int>::iterator iter;
    int i = 0;
    if (!l.empty()) {
        for (iter = l.begin(); iter != l.end(); iter++, i++) {
        std::cout << "l[" << i << "] = " << *iter << std::endl;
        }
    } else std::cout << "Список пуст!" << std::endl;
}

void ReverseSignsList(std::list<int>& l) {
    std::list<int>::iterator iter;
    for (iter = l.begin(); iter != l.end(); ++iter) {
        iter = l.insert(std::next(iter), -(*iter));
    }

    Print(l);

    l.remove_if([](int x) { return x < 0; });
}


int main() {
    std::list<int> list = {1, -2, 3, -4};
    std::list<int>::iterator iter;
    std::cout << "До иземенений:\n";
    Print(list);

    ReverseSignsList(list);
    std::cout << "После иземенений:\n";
    Print(list);
}