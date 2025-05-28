cmake_minimum_required(VERSION 3.23)

set(project "lab7")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        AppRunner.cpp
        main.cpp)

add_subdirectory(MyStack)
add_subdirectory(Organizations)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES})

add_executable(${project}
        ${${project}_SOURCE_LIST})

target_link_libraries(${project} MyStack)
target_link_libraries(${project} Organizations)