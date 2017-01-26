cmake_minimum_required(VERSION 3.6)
project(Maze_Solver)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp stack.cpp stack.h)
add_executable(Maze_Solver ${SOURCE_FILES})