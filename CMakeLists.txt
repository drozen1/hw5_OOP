cmake_minimum_required(VERSION 3.21)
project(hw5_OOP)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Provided/part1)
include_directories(Provided/part2)

add_executable(hw5_OOP
        Provided/part1/OOP5EventException.h
        Provided/part1/Part1Examples.cpp
        Provided/part2/Part2Examples.cpp
        Provided/part2/Printer.h
        Provided/part2/TransposeList.h
        OOP5_Part2_TestHeader.h
        testCheckWinSolved1.cpp)
