cmake_minimum_required(VERSION 3.21)
project(restsdk)

find_package(cpprestsdk REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_executable(restsdk main.cpp)
target_link_libraries(restsdk PRIVATE cpprestsdk::cpprest)