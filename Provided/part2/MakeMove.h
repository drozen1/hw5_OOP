//
// Created by karen on 21-Jan-22.
//

#ifndef HW5_OOP_MAKEMOVE_H
#define HW5_OOP_MAKEMOVE_H

#include "Direction.h"
#include "CellType.h"

template<int R, int C, typename G, Direction D, CellType Type, int CarSize,Direction directionToSet>
struct OneMove;

template<int R, int C, typename G,CellType Type, int CarSize, Direction directionToSet>
struct OneMove<R,C,G,RIGHT, Type, CarSize, directionToSet> {
    typedef BoardCell<EMPTY, RIGHT, 0 > newEmptyCell;
    typedef BoardCell<Type, directionToSet, CarSize > newCopyCell;

    typedef typename GetAtIndex<R, typename G::board>::value rowToChangeEmpty;
    typedef typename SetAtIndex<C, newEmptyCell, rowToChangeEmpty>::list newRowEmpty;
    typedef typename SetAtIndex<R, newRowEmpty, typename G::board>::list newBoardEmpty;

    typedef typename GetAtIndex<R, newBoardEmpty>::value rowToChange;
    typedef typename SetAtIndex<C+CarSize, newCopyCell, rowToChange>::list newRow;
    typedef typename SetAtIndex<R, newRow, newBoardEmpty>::list newBoard;
};

template<int R, int C, typename G,CellType Type, int CarSize, Direction directionToSet>
struct OneMove<R,C,G,LEFT, Type, CarSize,directionToSet>{
    typedef BoardCell<EMPTY, LEFT, 0 > newEmptyCell;
    typedef BoardCell<Type, directionToSet, CarSize > newCopyCell;

    typedef typename GetAtIndex<R, typename G::board>::value rowToChangeEmpty;
    typedef typename SetAtIndex<C, newEmptyCell, rowToChangeEmpty>::list newRowEmpty;
    typedef typename SetAtIndex<R, newRowEmpty, typename G::board>::list newBoardEmpty;

    typedef typename GetAtIndex<R, newBoardEmpty>::value rowToChange;
    typedef typename SetAtIndex<C-CarSize, newCopyCell, rowToChange>::list newRow;
    typedef typename SetAtIndex<R, newRow, newBoardEmpty>::list newBoard;
};


template<int Row, int MostRightColumn, typename G, Direction D, int A,  CellType Type, int CarSize, Direction directionToSet>
struct MakeMove;

template<int Row, int MostRightColumn, typename G, CellType Type, int CarSize, Direction directionToSet>
struct MakeMove<Row, MostRightColumn, G, RIGHT, 0, Type, CarSize, directionToSet>{
    typedef G boardResult;
};

template<int Row, int MostRightColumn, typename G, int A,  CellType Type, int CarSize, Direction directionToSet>
struct MakeMove<Row, MostRightColumn, G, RIGHT, A, Type, CarSize, directionToSet>{
    constexpr static int MostLeftColumn = MostRightColumn - CarSize + 1;
    typedef typename OneMove<Row, MostLeftColumn, G, RIGHT, Type, CarSize, directionToSet>::newBoard boardAfterOneMove;
    typedef typename MakeMove<Row, MostRightColumn + 1, GameBoard<boardAfterOneMove>, RIGHT, A-1, Type, CarSize, directionToSet>::boardResult boardResult;
};

template<int Row, int MostLeftColumn, typename G, CellType Type, int CarSize, Direction directionToSet>
struct MakeMove<Row, MostLeftColumn, G, LEFT, 0, Type, CarSize, directionToSet>{
    typedef G boardResult;
};

template<int Row, int MostLeftColumn, typename G, int A,  CellType Type, int CarSize, Direction directionToSet>
struct MakeMove<Row, MostLeftColumn, G, LEFT, A, Type, CarSize, directionToSet>{
    constexpr static int MostRightColumn = MostLeftColumn + CarSize - 1;
    typedef typename OneMove<Row, MostRightColumn, G, LEFT, Type, CarSize, directionToSet>::newBoard boardAfterOneMove;
    typedef typename MakeMove<Row, MostLeftColumn - 1, GameBoard<boardAfterOneMove>, LEFT, A-1, Type, CarSize, directionToSet>::boardResult boardResult;
};



#endif //HW5_OOP_MAKEMOVE_H
