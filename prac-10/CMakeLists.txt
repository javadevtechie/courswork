cmake_minimum_required(VERSION 3.22.2)

project(coursework)
add_subdirectory(test)
include_directories(${PROJECT_SOURCE_DIR})
add_executable(app main.cpp Event.cpp Film.cpp TheaterBooking.cpp StandupComedy.cpp LiveMusic.cpp TheaterUtility.cpp Customer.cpp)