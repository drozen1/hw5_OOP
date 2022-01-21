//
// Created by karen on 21-Jan-22.
//

#ifndef HW5_OOP_LASTLOCATION_H
#define HW5_OOP_LASTLOCATION_H

#include "CellType.h"
#include "Direction.h"
#include "GameBoard.h"
#include "Utilities.h"

//CALL WITH W-1

template<int X, int Y>
struct Coordinate{
    constexpr static int row = X;
    constexpr static int column = Y;
};

//Last location: returns the right or left edge of the car
//depending if we are going right or left
template<int R, int C, Direction D, CellType GivenType, CellType ActualType, int W, typename G>
struct LastLocation;

//Case: Right +  GivenType != ActualType, we stop
template<int R, int C, CellType GivenType, CellType ActualType, int W, typename G>
struct LastLocation<R, C, RIGHT, GivenType, ActualType, W, G>{
    typedef Coordinate<R,C-1> value;
};

//Case: Right +  GivenType == GivenType, we continue
template<int R, int C, CellType GivenType, int W, typename G>
struct LastLocation<R, C, RIGHT, GivenType, GivenType, W, G>{
    constexpr static CellType nextType =  GetAtIndex<C+1, typename GetAtIndex<R,typename G::board>::value>::value::type;
    typedef typename LastLocation<R, C+1 , RIGHT, GivenType, nextType ,W, G>::value
            value;
};

//Case: Right +  GivenType == GivenType, we are at the end of the board so we stop
template<int R, CellType GivenType, int W, typename G>
struct LastLocation<R, W, RIGHT, GivenType, GivenType, W, G>{
    typedef Coordinate<R,W> value;
};

//Case: Left +  GivenType != ActualType, we stop
template<int R, int C, CellType GivenType, CellType ActualType, int W, typename G>
struct LastLocation<R, C, LEFT, GivenType, ActualType, W, G>{
    typedef Coordinate<R,C+1> value;
};

//Case: Left +  GivenType == GivenType, we continue
template<int R, int C, CellType GivenType, int W, typename G>
struct LastLocation<R, C, LEFT, GivenType, GivenType, W, G>{
    constexpr static CellType nextType =  GetAtIndex<C-1, typename GetAtIndex<R,typename G::board>::value>::value::type;
    typedef typename LastLocation<R, C-1 , LEFT, GivenType, nextType ,W, G>::value
            value;
};

//Case: Left +  GivenType == GivenType, we are at the end of the board so we stop
template<int R, CellType GivenType, int W, typename G>
struct LastLocation<R, 0, LEFT, GivenType, GivenType, W, G>{
    typedef Coordinate<R,0> value;
};


#endif //HW5_OOP_LASTLOCATION_H
