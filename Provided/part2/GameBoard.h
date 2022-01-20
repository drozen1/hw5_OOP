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
    typedef typename board::head::size width;//columns
    typedef typename board::size length; //rows
};

#endif //HW5_OOP_GAMEBOARD_H
