cmake_minimum_required(VERSION 3.6)
project(tree)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp tree.h tree.cpp)
add_executable(tree ${SOURCE_FILES})