//
// Created by Dor on 1/21/2022.
//

#ifndef HW5_OOP_GETTYPECORDINATES_H
#define HW5_OOP_GETTYPECORDINATES_H

#include "LastLocation.h"

template <CellType givernType,CellType type, int R, int C, int width, typename G>
struct getTypeCordinates{
    constexpr static CellType nextType =  GetAtIndex<C+1, typename GetAtIndex<R,typename G::board>::value>::value::type;
    typedef typename getTypeCordinates<givernType, nextType,R, C+1,width,G >::value
            value;
};


/// we found the type
template <CellType type, int R, int C, int width, typename G>
struct getTypeCordinates<type, type, R,C, width,G>{
    typedef Coordinate<R,C> value;
};

/// we found the type in the last coulmn
template <CellType type, int R, int width, typename G>
struct getTypeCordinates<type, type, R,width, width,G>{
    typedef Coordinate<R,width> value;
};

/// we reach the end of the row
template <CellType givernType,CellType type, int R, int width, typename G>
struct getTypeCordinates<givernType, type, R, width, width,G>{
    constexpr static CellType nextType =  GetAtIndex<0, typename GetAtIndex<R+1,typename G::board>::value>::value::type;
    typedef typename getTypeCordinates<givernType, nextType,R+1, 0,width,G >::value
            value;
};





#endif //HW5_OOP_GETTYPECORDINATES_H
