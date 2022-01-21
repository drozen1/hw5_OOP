//
// Created by karen on 20-Jan-22.
//

#ifndef HW5_OOP_RUSHHOUR_H
#define HW5_OOP_RUSHHOUR_H

#include "BoardCell.h"
#include "CellType.h"
#include "CountEmptyCells.h"
#include "Direction.h"
#include "GameBoard.h"
#include "LastLocation.h"
#include "List.h"
#include "MoveVehicle.h"
#include "Utilities.h"
#include "getTypeCordinates.h"

// left empty colmns = G::width - columnMostRight-1
template<typename G>
struct CheckWin{
    constexpr static CellType actualType =  GetAtIndex<0, typename GetAtIndex<0,typename G::board>::value>::value::type;
    typedef typename getTypeCordinates<X, actualType, 0, 0, G::width-1, G>::value cordinates;
    constexpr static int column = cordinates::column;
    constexpr static int row = cordinates::row;
    constexpr static int columnMostRight  = LastLocation<row, column, RIGHT, X ,X , G::width-1, G>::value::column;
    constexpr static int counter =  CountEmptyCells<row,columnMostRight , RIGHT, X ,X, G::width-1, G, 0>::value;
    constexpr static bool result = (counter == (G::width - columnMostRight-1));
};


#endif //HW5_OOP_RUSHHOUR_H
