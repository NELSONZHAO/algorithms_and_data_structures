cmake_minimum_required(VERSION 3.7)
project(SelectionSort)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Student.h SortTestHelper.h)
add_executable(SelectionSort ${SOURCE_FILES})