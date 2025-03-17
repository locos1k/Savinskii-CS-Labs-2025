#include "AppRunner.hpp"

#include <iostream>

#include "diets/Diets.hpp"
#include "planets/Planets.hpp"

namespace {}

namespace AppRunner {
void RunPlanetsApp() {
    int task = 0;

    int size = 1;
    Planets::Planet* planets = new Planets::Planet[size]();

    while (true) {
        std::cout << "Выберите номер задания для работы с БД:\n"
                  << "1 - Чтение БД из файла\n"
                  << "2 - Запись БД в файл\n"
                  << "3 - Сортировка БД\n"
                  << "4 - Добавление нового объекта в БД\n"
                  << "5 - Удаление объекта из БД\n"
                  << "6 - Редактирование БД\n"
                  << "7 - Вывод БД на экран\n"
                  << "0 - Выход\n";
        std::cin >> task;
        std::cout << std::endl;

        switch (static_cast<Tasks>(task)) {
            case Tasks::Read: {
                Planets::Planet::ReadDB(planets, size);
                break;
            }
            case Tasks::Write: {
                Planets::Planet::WriteDB(planets, size);
                break;
            }
            case Tasks::Sort: {
                Planets::Planet::SortDB(planets, size);
                break;
            }
            case Tasks::Add: {
                Planets::Planet::AddElement(planets, size);
                break;
            }
            case Tasks::Delete: {
                Planets::Planet::DeleteElement(planets, size);
                break;
            }
            case Tasks::Edit: {
                Planets::Planet::EditDB(planets, size);
                break;
            }
            case Tasks::Print: {
                Planets::Planet::PrintDB(planets, size);
                break;
            }
            case Tasks::Exit: {
                Planets::Planet::DeleteDB(planets);
                return;
            }
            default: {
                std::cout << "Введен несуществующий номер задания." << std::endl;
                break;
            }
        }
    }
}
void RunDietApp() {
    int task = 0;

    int size = 1;
    Diet::Diet* diets = new Diet::Diet[size]();

    while (true) {
        std::cout << "Выберите номер задания для работы с БД:\n"
                  << "1 - Чтение БД из файла\n"
                  << "2 - Запись БД в файл\n"
                  << "3 - Сортировка БД\n"
                  << "4 - Добавление нового объекта в БД\n"
                  << "5 - Удаление объекта из БД\n"
                  << "6 - Редактирование БД\n"
                  << "7 - Вывод БД на экран\n"
                  << "0 - Выход \n";
        std::cin >> task;
        std::cout << std::endl;

        switch (static_cast<Tasks>(task)) {
            case Tasks::Read: {
                Diet::Diet::ReadDB(diets, size);
                break;
            }
            case Tasks::Write: {
                Diet::Diet::WriteDB(diets, size);
                break;
            }
            case Tasks::Sort: {
                Diet::Diet::SortDB(diets, 0, size - 1);
                break;
            }
            case Tasks::Add: {
                Diet::Diet::AddElement(diets, size);
                break;
            }
            case Tasks::Delete: {
                Diet::Diet::DeleteElement(diets, size);
                break;
            }
            case Tasks::Edit: {
                Diet::Diet::EditDB(diets, size);
                break;
            }
            case Tasks::Print: {
                Diet::Diet::PrintDB(diets, size);
                break;
            }
            case Tasks::Exit: {
                Diet::Diet::DeleteDB(diets);
                return;
            }
            default: {
                std::cout << "Введен несуществующий номер задания." << std::endl;
                break;
            }
        }
    }
}

void RunApp() {
    int task = 0;

    while (true) {
        std::cout << "Введите номер режима работы с приложением:\n"
                  << "1 - Планеты\n"
                  << "2 - Пищевой набор диеты\n"
                  << "0 - Выход\n";
        std::cin >> task;
        std::cout << std::endl;

        switch (static_cast<AppTasks>(task)) {
            case AppTasks::Planets:
                RunPlanetsApp();
                break;
            case AppTasks::Diet:
                RunDietApp();
                break;
            case AppTasks::Exit:
                return;
                break;
            default:
                std::cout << "Введен несуществующий номер режима работы\n";
                break;
        }
    }
}
}  // namespace AppRunner
