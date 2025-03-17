#pragma once

namespace AppRunner {
enum class Tasks {
    Read = 1,
    Write = 2,
    Sort = 3,
    Add = 4,
    Delete = 5,
    Edit = 6,
    Print = 7,
    Exit = 0,
};

enum class AppTasks {
    Planets = 1,
    Diet = 2,
    Exit = 0,
};

void RunPlanetsApp();
void RunDietApp();
void RunApp();
}  // namespace AppRunner
