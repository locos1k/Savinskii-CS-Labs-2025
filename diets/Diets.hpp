#pragma once
#include <fstream>

namespace Diet {
class Diet {
 private:
    char* name;
    int proteins;
    int fats;
    int carbohydrates;

 public:
    Diet(const char* n = "\0", int p = 0, int f = 0, int ch = 0);
    Diet(const Diet& other);

    ~Diet();

    void SetName(const char* n);

    Diet& operator=(const Diet& other);
    friend std::ofstream& operator<<(std::ofstream& file, Diet& diet);
    friend std::ifstream& operator>>(std::ifstream& file, Diet& diet);
    bool operator==(const char* n);
    bool operator<(Diet& diet2);
    bool operator<(const char* n);

    static void Resize(Diet*& diets, int& size);
    static void DeleteDB(Diet*& diets);

    static void ReadDB(Diet*& diets, int& size);
    static void WriteDB(Diet*& diets, int size);
    static void SortDB(Diet*& diets, int left, int right);
    static void AddElement(Diet*& diets, int& size);
    static void DeleteElement(Diet*& diets, int& size);
    static void EditDB(Diet*& diets, int size);
    static void PrintDB(Diet*& diets, int size);
};
}  // namespace Diet
