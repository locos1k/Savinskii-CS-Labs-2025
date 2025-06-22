#include <iostream>
#include <vector>

class Point {
 private:
    double x;
    double y;
 public:
    Point() : x(0), y(0) {}
    Point(double a, double b) : x(a), y(b) {}

    bool operator<(Point& other) { 
        return (x * x + y * y) < (other.x * other.x + other.y * other.y);
    }
    Point operator+(double r) { 
        return Point(x + r, y); 
    }
    friend std::ostream& operator<<(std::ostream& out, Point& obj) { 
        return out << '(' << obj.x << ", " << obj.y << ")";
    }
};

void Print(std::vector<Point> v) {
    std::cout << "Содержимое вектора:\n";
    for (int i = 0; i < v.size(); ++i) {
        std::cout << i + 1 << ": " << v[i] << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    std::vector<Point> vec = {Point(1.2, 6.3), Point(4.0, 0.7), Point(7.2, 0.8), 
                              Point(5.3, 3.0), Point(4.9, 6.6), Point(9.3, 0.2)};
    Print(vec);
    
    Point maxPoint;
    for (int i = 0; i < vec.size(); ++i) {
        if (maxPoint < vec[i]) maxPoint = vec[i];
    }
    std::cout << "Наиболее удаленная от начала координат точка: " << maxPoint << std::endl << std::endl;

    double r = 0;
    std::cout << "Введите расстояние на которое хотите сдвинуть все точки по оси абцисс: ";
    std::cin >> r;

    for (int i = 0; i < vec.size(); ++i) {
        vec[i] = vec[i] + r;
    }
    Print(vec);
}
