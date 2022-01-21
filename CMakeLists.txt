cmake_minimum_required(VERSION 3.21)
project(hw5_OOP)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Provided/part1)
include_directories(Provided/part2)

add_executable(hw5_OOP
#        Provided/part1/OOP5EventException.h
#        Provided/part1/Part1Examples.cpp
#        Provided/part1/Subject.h Provided/part1/Observer.h
#        Provided/part1/Subject.h Provided/part1/tests/Part2Main.h
#        Provided/part1/Subject.h Provided/part1/tests/staff/Part2Examples.h
#        Provided/part1/Subject.h Provided/part1/tests/partner/BaseTestFile.h
#        Provided/part1/Subject.h Provided/part1/tests/partner/PartnerPartTwoMain.h
#        Provided/part1/Subject.h Provided/part1/tests/partner/PartTwoObserverTests.h
#        Provided/part1/Subject.h Provided/part1/tests/partner/PartTwoSubjectTests.h
#        Provided/part1/Subject.h Provided/part1/tests/my/MyTest.h
#        Provided/part1/Subject.h Provided/part1/tests/my/TestUtils.h
        Provided/part2/List.h Provided/part2/myMain.cpp Provided/part2/Utilities.h Provided/part2/CellType.h Provided/part2/Direction.h Provided/part2/BoardCell.h Provided/part2/GameBoard.h Provided/part2/MoveVehicle.h Provided/part2/RushHour.h Provided/part2/LastLocation.h Provided/part2/CountEmptyCells.h Provided/part2/MakeMove.h)
