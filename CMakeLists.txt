cmake_minimum_required(VERSION 3.16)

project(
    WeatherAnalysis
    LANGUAGES CXX
)

add_library(Functions Functions.cpp Functions.h)
add_executable(WeatherAnalysis main.cpp)
target_link_libraries(WeatherAnalysis PRIVATE Functions)
