#include <iostream>
#include <list>
#include <string>
#include <algorithm>

class Planet {
private:
    std::string name;
    int moons;
public:
    Planet(const std::string& name, int moons) : name(name), moons(moons) {}

    std::string getName() const { return name; }
    int getMoons() const { return moons; }

    void Print() const {
        std::cout << "Планета: " << name << ", спутников: " << moons << std::endl;
    }

    bool operator<(const Planet& other) {
    return moons < other.moons;
}
};

void PrintPlanets(std::list<Planet>& planets) {
    for (Planet planet : planets) {
        planet.Print();
    }
}

int main() {
    std::list<Planet> planets = {
        {"Меркурий", 0},
        {"Венера", 0},
        {"Земля", 1},
        {"Марс", 2},
        {"Юпитер", 69},
        {"Сатурн", 62},
        {"Уран", 27},
        {"Нептун", 14},
        {"Плутон", 10}
    };
    std::cout << "Список планет:\n";
    PrintPlanets(planets);

    std::list<Planet>::iterator maxPlanet = std::max_element(planets.begin(), planets.end(),
    [](const Planet& a, const Planet& b) {
        return a.getMoons() < b.getMoons();
    });

    std::cout << "\nПланета с максимальным числом спутников:\n";
    maxPlanet->Print();
}