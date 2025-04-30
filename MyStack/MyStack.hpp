#include <iostream>

#ifndef MyStack_hpp
#define MyStack_hpp

template<class INF>
class MyStack;
template<class INF, class FRIEND>
class ListNode {
 private:
    INF d;
    ListNode* next;
    ListNode(void) { next = nullptr; }
    friend FRIEND;
};

template<class INF>
std::ostream& operator<<(std::ostream& out, const MyStack<INF>& el);

template<class INF>
class MyStack {
    typedef class ListNode<INF, MyStack<INF>> Node;
    Node* top;

 public:
    MyStack(void);
    ~MyStack(void);
    bool empty(void);
    bool push(INF n);
    bool pop(void);
    INF top_inf(void);
    MyStack(const MyStack& other);
    MyStack<INF>& operator=(const MyStack<INF>& other);
    MyStack<INF> operator+(const MyStack<INF>& other) const;

    friend std::ostream& operator<< <>(std::ostream& out, const MyStack& el);
};

template<class INF>
std::ostream& operator<<(std::ostream& out, const MyStack<INF>& el) {
    typename MyStack<INF>::Node* p = el.top;
    out << p->d;
    p = p->next;
    while (p) {
        out << "*" << p->d;
        p = p->next;
    }

    return out;
}
template<class DATA>
void Multipliers(int n, MyStack<DATA>& stack) {
    for (int i = 2; i <= n; ++i) {
        while (n % i == 0) {
            n /= i;

            stack.push(i);
        }
    }
}
template<class DATA>
void Reverse(MyStack<DATA>& stack) {
    MyStack<DATA> temp;

    while (!stack.empty()) {
        temp.push(stack.top_inf());
        stack.pop();
    }
    stack = temp;
}
template<class INF>
void Print(const MyStack<INF>& stack, int n) {
    std::cout << n << "=";
    std::cout << stack;
    std::cout << '\n';
}

template<class INF>
MyStack<INF>::MyStack(void) {
    top = nullptr;
}
template<class INF>
MyStack<INF>::~MyStack(void) {
    while (!empty()) {
        Node* old = top;
        top = top->next;
        delete old;
    }
}
template<class INF>
MyStack<INF>::MyStack(const MyStack& other) {
    top = nullptr;
    if (other.top) {
        Node* current = other.top;
        Node* prev = nullptr;
        while (current) {
            Node* newNode = new Node;
            newNode->d = current->d;
            if (!top) {
                top = newNode;
            } else {
                prev->next = newNode;
            }
            prev = newNode;
            current = current->next;
        }
    }
}
template<class INF>
MyStack<INF>& MyStack<INF>::operator=(const MyStack& other) {
    if (this == &other) {
        return *this;
    }
    while (!empty()) {
        pop();
    }
    if (other.top) {
        Node* current = other.top;
        Node* prev = nullptr;
        while (current) {
            Node* newNode = new Node;
            newNode->d = current->d;
            if (!top) {
                top = newNode;
            } else {
                prev->next = newNode;
            }
            prev = newNode;
            current = current->next;
        }
    }
    return *this;
}
template<class INF>
bool MyStack<INF>::empty(void) {
    if (top) {
        return false;
    }
    return true;
}
template<class INF>
bool MyStack<INF>::push(INF n) {
    Node* newNode = new Node{};
    newNode->d = n;
    newNode->next = top;
    top = newNode;
    return true;
}
template<class INF>
bool MyStack<INF>::pop(void) {
    if (!empty()) {
        Node* t = top;
        top = top->next;
        delete t;
        return true;
    }
    return false;
}
template<class INF>
INF MyStack<INF>::top_inf(void) {
    if (empty()) {
        throw std::runtime_error("Стек пуст");
    }
    return top->d;
}

template<class INF>
MyStack<INF> MyStack<INF>::operator+(const MyStack<INF>& other) const {
    MyStack<INF> result;
    MyStack<INF> temp;
    Node* current = other.top;
    while (current) {
        temp.push(current->d);
        current = current->next;
    }

    while (!temp.empty()) {
        result.push(temp.top_inf());
        temp.pop();
    }
    temp = *this;
    MyStack<INF> temp2;
    while (!temp.empty()) {
        temp2.push(temp.top_inf());
        temp.pop();
    }
    while (!temp2.empty()) {
        result.push(temp2.top_inf());
        temp2.pop();
    }
    MyStack<INF> finalResult;
    while (!result.empty()) {
        finalResult.push(result.top_inf());
        result.pop();
    }

    return finalResult;
}

#endif
