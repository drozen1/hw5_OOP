//
// Created by karen on 21-Jan-22.
//

#ifndef HW5_OOP_MAKEMOVE_H
#define HW5_OOP_MAKEMOVE_H

template<int LastRow, int LastColumn, typename G, Direction D, int A>
struct MakeMove;


template<int R, int C, typename G, Direction D, int A, CellType Type, int CarSize>
struct OneMove;

template<int R, int C, typename G, int A, CellType Type, int CarSize>
struct OneMove<R,C,G,RIGHT,A, Type, CarSize>{
    typedef BoardCell<EMPTY, RIGHT, 0 > newEmptyCell;
    typedef BoardCell<Type, RIGHT, CarSize > newCopyCell;

    typedef typename GetAtIndex<R, typename G::board>::value rowToChange;
    typedef typename SetAtIndex<C, newEmptyCell, rowToChange>::list newRow;
    typedef typename SetAtIndex<R, newRow, typename G::board>::list newBoard;

    typedef typename GetAtIndex<R, typename G::board>::value rowToChange;
    typedef typename SetAtIndex<C, newEmptyCell, rowToChange>::list newRow;
    typedef typename SetAtIndex<R, newRow, typename G::board>::list newBoard;

};

#endif //HW5_OOP_MAKEMOVE_H
