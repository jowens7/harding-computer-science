cmake_minimum_required(VERSION 3.6)
project(Linked_List)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp List.cpp)
add_executable(Linked_List ${SOURCE_FILES})