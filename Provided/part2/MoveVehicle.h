//
// Created by karen on 20-Jan-22.
//

#ifndef HW5_OOP_MOVEVEHICLE_H
#define HW5_OOP_MOVEVEHICLE_H
#include "CellType.h"
#include "Direction.h"
#include "GameBoard.h"
#include "Utilities.h"
#include "LastLocation.h"
#include "CountEmptyCells.h"
#include "TransposeList.h"

template <CellType C, Direction D, int A>
struct Move{
    constexpr static CellType type = C ;
    constexpr static Direction direction = D ;
    constexpr static int amount = A ;
    static_assert(EMPTY != C, "Compilation error");
};

template<typename G, int R, int C, Direction D, int A>
struct MoveVehicle;

template<typename G, int R, int C, int A>
struct MoveVehicle<G,R,C,RIGHT, A>{

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
    static_assert(actualDirection == RIGHT || actualDirection == LEFT , "Compilation error");

    //Check if we have another car
    //call with W-1
    constexpr static int lastColumn  = LastLocation<R, C, RIGHT, type ,type , G::width-1, G>::value::column;
    constexpr static int counter =  CountEmptyCells<R ,lastColumn, RIGHT, type ,type, G::width-1, G, 0>::value;
    static_assert(A <= counter, "Compilation error");

    //Move the car

    typedef G board;
};

template<typename G, int R, int C, int A>
struct MoveVehicle<G,R,C,LEFT, A>{
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
    static_assert(actualDirection == RIGHT || actualDirection == LEFT , "Compilation error");

    //Check if we have another car
    //call with W-1
    constexpr static int lastColumn  = LastLocation<R, C, LEFT, type ,type , G::width-1, G>::value::column;
    constexpr static int counter =  CountEmptyCells<R ,lastColumn, LEFT, type ,type, G::width-1, G, 0>::value;
    static_assert(A <= counter, "Compilation error");

    typedef G board;
};

template<typename G, int R, int C, int A>
struct MoveVehicle<G,R,C,UP, A>{
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
    static_assert(actualDirection == UP || actualDirection == DOWN , "Compilation error");

    //Transpose
    typedef typename Transpose<typename G::board>::matrix transposeBoard;
    typedef GameBoard<transposeBoard> transposeGameBoard;

    //Check if we have another car
    //call with W-1
    constexpr static int lastColumn  = LastLocation<C, R, LEFT, type ,type , transposeGameBoard::width-1, transposeGameBoard>::value::column;
    constexpr static int counter =  CountEmptyCells<lastColumn ,R, LEFT, type ,type, transposeGameBoard::width-1, transposeGameBoard, 0>::value;
    static_assert(A <= counter, "Compilation error");

    typedef G board;
};

template<typename G, int R, int C, int A>
struct MoveVehicle<G,R,C,DOWN, A>{
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
    static_assert(actualDirection == UP || actualDirection == DOWN , "Compilation error");

    //Transpose
    typedef typename Transpose<typename G::board>::matrix transposeBoard;
    typedef GameBoard<transposeBoard> transposeGameBoard;

    //Check if we have another car
    //call with W-1
    constexpr static int lastColumn  = LastLocation<C, R, RIGHT, type ,type , transposeGameBoard::width-1, transposeGameBoard>::value::column;
    constexpr static int counter =  CountEmptyCells<lastColumn ,R, RIGHT, type ,type, transposeGameBoard::width-1, transposeGameBoard, 0>::value;
    static_assert(A <= counter, "Compilation error");

    typedef G board;
};


#endif //HW5_OOP_MOVEVEHICLE_H
