//
// Created by karen on 20-Jan-22.
//

#ifndef HW5_OOP_GAMEBOARD_H
#define HW5_OOP_GAMEBOARD_H
#include "BoardCell.h"
#include "List.h"

template<typename list>
struct GameBoard{
    typedef list board;
    constexpr static int width = board::head::size;
    constexpr static int length = board::size;
};

#endif //HW5_OOP_GAMEBOARD_H
