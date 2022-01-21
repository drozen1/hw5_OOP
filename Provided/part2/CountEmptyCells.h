//
// Created by karen on 21-Jan-22.
//

#ifndef HW5_OOP_COUNTEMPTYCELLS_H
#define HW5_OOP_COUNTEMPTYCELLS_H

#include "LastLocation.h"

//CALL WITH W-1


//Returns how many empty blocks we have from this R and C to the end
//of the board/other car
template<int R, int C, Direction D,CellType GivenType, CellType ActualType, int W, typename G, int Counter>
struct CountEmptyCells;

//We are going right, we see empty so we continue
template<int R, int C, CellType GivenType, int W, typename G, int Counter>
struct CountEmptyCells<R, C, RIGHT, GivenType, EMPTY, W, G, Counter>{
    constexpr static CellType nextType =  GetAtIndex<C+1, typename GetAtIndex<R,typename G::board>::value>::value::type;
    constexpr static int value =  CountEmptyCells<R, C+1 , RIGHT, GivenType, nextType ,W, G, Counter + 1>::value;
};

//We are going right, we dont see empty so we stop
template<int R, int C, CellType GivenType, CellType ActualType, int W, typename G, int Counter>
struct CountEmptyCells<R, C, RIGHT, GivenType, ActualType, W, G, Counter>{
    constexpr static int value = Counter;
};

//We are going right, we see our type so we are at the beginning of the function
template<int R, int C, CellType GivenType, int W, typename G, int Counter>
struct CountEmptyCells<R, C, RIGHT, GivenType, GivenType, W, G, Counter>{
    constexpr static CellType nextType =  GetAtIndex<C+1, typename GetAtIndex<R,typename G::board>::value>::value::type;
    constexpr static int value = CountEmptyCells<R, C+1 , RIGHT, GivenType, nextType ,W, G, Counter>::value;
};

//We are going right, it is empty till the end of the board
template<int R, CellType GivenType, int W, typename G , int Counter >
struct CountEmptyCells<R, W, RIGHT, GivenType, EMPTY, W, G, Counter>{
    constexpr static int value = Counter + 1;
};

//We are going right, we have our type till the end of the board
template<int R, CellType GivenType, int W, typename G , int Counter >
struct CountEmptyCells<R, W, RIGHT, GivenType, GivenType, W, G, Counter>{
    constexpr static int value = 0;
};


//We are going left, we see empty so we continue
template<int R, int C, CellType GivenType, int W, typename G, int Counter>
struct CountEmptyCells<R, C, LEFT, GivenType, EMPTY, W, G, Counter>{
    constexpr static CellType nextType =  GetAtIndex<C-1, typename GetAtIndex<R,typename G::board>::value>::value::type;
    constexpr static int value =  CountEmptyCells<R, C-1 , LEFT, GivenType, nextType ,W, G, Counter + 1>::value;
};

//We are going left, we dont see empty so we stop
template<int R, int C, CellType GivenType, CellType ActualType, int W, typename G, int Counter>
struct CountEmptyCells<R, C, LEFT, GivenType, ActualType, W, G, Counter>{
    constexpr static int value = Counter;
};

//We are going left, we see our type so we are at the beginning of the function
template<int R, int C, CellType GivenType, int W, typename G, int Counter>
struct CountEmptyCells<R, C, LEFT, GivenType, GivenType, W, G, Counter>{
    constexpr static CellType nextType =  GetAtIndex<C-1, typename GetAtIndex<R,typename G::board>::value>::value::type;
    constexpr static int value = CountEmptyCells<R, C-1 , LEFT, GivenType, nextType ,W, G, Counter>::value;
};

//We are going left, it is empty till the end of the board
template<int R, CellType GivenType, int W, typename G , int Counter >
struct CountEmptyCells<R, 0, LEFT, GivenType, EMPTY, W, G, Counter>{
    constexpr static int value = Counter + 1;
};

//We are going left, we have our type till the end of the board
template<int R, CellType GivenType, int W, typename G , int Counter >
struct CountEmptyCells<R, 0, LEFT, GivenType, GivenType, W, G, Counter>{
    constexpr static int value = 0;
};



#endif //HW5_OOP_COUNTEMPTYCELLS_H
