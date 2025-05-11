#ifndef INHERITANCE_MYSET_H
#define INHERITANCE_MYSET_H

#include <iostream>
#include "MyVector.h"

template<class T=const char*>
class MySet : public MyVector<T> {
 public:
    MySet(T el = NULL) : MyVector<T>(el) {}
    template <class F>
    friend bool operator==(const MySet<F>& a,const MySet<F>& b);
    template <class F>
    friend MySet<F>& operator+=( MySet<F>& a,const MySet<F>& b);
    template <class F>
    friend MySet<F>& operator-=( MySet<F>& a,const MySet<F>& b);
    template <class F>
    friend MySet<F>& operator*=( MySet<F>& a,const MySet<F>& b);
    
    void add_element(T el);
    void delete_element(T el);
    bool is_element(T el) const;

    template <class F>
    friend std::ostream& operator<<(std::ostream& out, const MySet<F>& s);

    template <class F>
    friend MySet<F> operator+(const MySet<F>& s1, const MySet<F>& s2);

    template <class F>
    friend MySet<F> operator-(const MySet<F>& s1, const MySet<F>& s2);

    template <class F>
    friend MySet<F> operator*(const MySet<F>& s1, const MySet<F>& s2);
};
template <class F>
std::ostream& operator<<(std::ostream& out, const MySet<F>& s) {
    out << "{";
    for (int i = 0; i < s.size; ++i) {
        if (i > 0) {
            out << ", ";
        }
        out << s[i];
    }
    out << "}";
    return out;
}
template <class F>
bool operator==(const MySet<F>& a,const MySet<F>& b){
    if (a.size != b.size) {
        return false;
    }
    for (int i = 0; i < a.size; ++i) {
        if (!b.is_element(a[i])) {
            return false;
        }
    }
    return true;
}
template <class F>
MySet<F>& operator+=(MySet<F>& a,const MySet<F>& b) {
    for (int i = 0; i < b.size; ++i) {
        a.add_element(b[i]);
    }
    return a;
}
template <class F>
MySet<F>& operator-=( MySet<F>& a,const MySet<F>& b) {

    for (int i = 0; i < a.size; ++i) {

        if (b.is_element((a[i]))) {
            a.delete_element(a[i--]);
        }
    }
    return a;
}
template <class F>
MySet<F>& operator*=( MySet<F>& a,const MySet<F>& b) {
    for (int i = 0; i < a.size; ++i) {
        if (!b.is_element(a[i])) {
            a.delete_element(a[i--]);
        }
    }
    return a;
}
template <class T>
void MySet<T>::add_element(T el) {
    if (!this->is_element(el)) {
        MyVector<T>::add_element(el);
        this->sort();
    }
}

template <class T>
void MySet<T>::delete_element(T el) {
    int index = this->find(el);
    if (index != -1) {
        MyVector<T>::delete_element(index);
    }
}

template <class T>
bool MySet<T>::is_element(T el)const  {

    int left = 0;
    int right = this->size - 1;

    while (left <= right) {
        int middle = (left + right) / 2;
        if ((*this)[middle] > el) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }

        if ((*this)[middle] == el) {
            return true;
        }
    }

    return false;
}
template <>
bool MySet<const char*>::is_element(const char* el) const{
    int left = 0;
    int right = this->size - 1;

    while (left <= right) {
        int middle = (left + right) / 2;
        if (std::strcmp((*this)[middle],  el) > 0) {
            right = middle - 1;
        }
         else {
            left = middle + 1;
        }

        if (std::strcmp((*this)[middle],  el) == 0) {
            return true;
        }
    }

    return false;
}
template <>
bool MySet<char*>::is_element(char* el) const{
    int left = 0;
    int right = this->size - 1;

    while (left <= right) {
        int middle = (left + right) / 2;
        if (std::strcmp((*this)[middle],  el) > 0) {
            right = middle - 1;
        }
         else {
            left = middle + 1;
        }

        if (std::strcmp((*this)[middle],  el) == 0) {
            return true;
        }
    }

    return false;
}
template<class F>
MySet<F> operator+(const MySet<F>& s1, const MySet<F>& s2) {
    MySet<F> result = s1;
    result += s2;
    return result;
}
template<class F>
MySet<F> operator-(const MySet<F>& s1, const MySet<F>& s2) {
    MySet<F> result = s1;
    result -= s2;
    return result;
}
template<class F>
MySet<F> operator*(const MySet<F>& s1, const MySet<F>& s2) {
    MySet<F> result = s1;
    result *= s2;
    return result;
}

#endif  // INHERITANCE_MYSET_H