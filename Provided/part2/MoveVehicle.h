//
// Created by karen on 20-Jan-22.
//

#ifndef HW5_OOP_MOVEVEHICLE_H
#define HW5_OOP_MOVEVEHICLE_H
#include "CellType.h"
#include "Direction.h"
#include "GameBoard.h"
#include "Utilities.h"

template <CellType C, Direction D, int A>
struct Move{
    constexpr static CellType type = C ;
    constexpr static Direction direction = D ;
    constexpr static int amount = A ;
    static_assert(EMPTY != C, "Compilation error");
};

template<typename G, int R, int C, Direction D, int A>
struct MoveVehicle{

    //Check row and column index
    static_assert(G::length > R, "Compilation error");
    static_assert(R >= 0 , "Compilation error");
    static_assert(G::width > C , "Compilation error");
    static_assert(C >= 0 , "Compilation error");

    //Check if the cell is empty
    constexpr static CellType type =  GetAtIndex<C, typename GetAtIndex<R,typename G::board>::value>::value::type;
    static_assert(type != EMPTY, "Compilation error");

    //Check if direction is possible
    constexpr static Direction actualDirection = GetAtIndex<C, typename GetAtIndex<R,typename G::board>::value>::value::direction;
    //typedef typename GetAtIndex<C, typename GetAtIndex<R,typename G::board>::value>::value::direction actualDirection;
    constexpr static bool cond1 = (D == RIGHT || D == LEFT ) && (actualDirection == RIGHT || actualDirection == LEFT );
    constexpr static bool cond2 = (D == UP || D == DOWN ) && (actualDirection == UP || actualDirection == DOWN );
    static_assert(cond1 || cond2, "Compilation error");

    //Check if we have another car


    typedef G board;
};

template<int X, int Y>
struct Coordinate{
    constexpr static int row = X;
    constexpr static int column = Y;
};

template<int R, int C, Direction D, CellType T, int W, typename G>
struct LastLocation;

template<int R, int C, CellType T, int W, typename G>
struct LastLocation<R, C, RIGHT, T,W, G>{
    constexpr static CellType actualType =  GetAtIndex<C, typename GetAtIndex<R,typename G::board>::value>::value::type;
    typedef LastLocation<R, C+1 , RIGHT, T,W, G> continueSearching  ;
    typedef typename Conditional<(actualType == T), typename continueSearching::result, Coordinate<R,C-1> >::value result;

};



#endif //HW5_OOP_MOVEVEHICLE_H
