//
// Created by karen on 20-Jan-22.
//

#ifndef HW5_OOP_MOVEVEHICLE_H
#define HW5_OOP_MOVEVEHICLE_H
#include "CellType.h"
#include "Direction.h"

template <CellType C, Direction D, int A>
struct Move{
    constexpr static CellType type = C ;
    constexpr static Direction direction = D ;
    constexpr static int amount = A ;
    static_assert(EMPTY != C, "Compilation error");
};

//template <Direction D, int A>
//struct Move<EMPTY, D, A>{
//    static_assert(0 == 1, "Compilation error");
//};

#endif //HW5_OOP_MOVEVEHICLE_H
