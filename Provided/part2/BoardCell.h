//
// Created by karen on 20-Jan-22.
//

#ifndef HW5_OOP_BOARDCELL_H
#define HW5_OOP_BOARDCELL_H
#include "CellType.h"
#include "Direction.h"

template<CellType C, Direction D, int L>
struct BoardCell{
    constexpr static CellType type = C ;
    constexpr static Direction direction = D ;
    constexpr static int length = L ;
};


#endif //HW5_OOP_BOARDCELL_H
