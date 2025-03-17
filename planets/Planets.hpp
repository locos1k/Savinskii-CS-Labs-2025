#pragma once
#include <fstream>

namespace Planets {
class Planet {
 private:
    char* name;
    int diameter;
    bool life;
    int satellitesNumber;

 public:
    Planet(const char* n = "\0", int d = 0, bool l = false, int sn = 0);
    Planet(const Planet& other);

    ~Planet();

    void SetName(const char* n);

    Planet& operator=(const Planet& other);
    friend std::ostream& operator<<(std::ostream& os, const Planet& planet);
    friend std::istream& operator>>(std::istream& is, Planet& planet);
    bool operator==(const char* n);
    bool operator<(const Planet& planet2);
    bool operator<(const char* n);

    static void Resize(Planet*& planets, int& size);
    static void DeleteDB(Planet*& planets);

    static void ReadDB(Planet*& planets, int& size);
    static void WriteDB(Planet*& planets, int size);
    static void SortDB(Planet*& planets, const int size);
    static void AddElement(Planet*& planets, int& size);
    static void DeleteElement(Planet*& planets, int& size);
    static void EditDB(Planet*& planets, int size);
    static void PrintDB(Planet*& planets, int size);
};
}  // namespace Planets