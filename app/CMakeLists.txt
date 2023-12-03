cmake_minimum_required(VERSION 3.12)

project(unitTesting)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE project_lib)
