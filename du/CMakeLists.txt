cmake_minimum_required(VERSION 3.22.2)

project(hello_world)

include_directories(${PROJECT_SOURCE_DIR})
add_executable(app main.cpp)