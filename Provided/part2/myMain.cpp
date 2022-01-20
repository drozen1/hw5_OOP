#include <iostream>

#include "List.h"
#include "Utilities.h"
#include "CellType.h"
#include "MoveVehicle.h"
#include "GameBoard.h"
#include "Direction.h"

template<int n>
class Int {

};

int main(){

    std::cout<<"myMain"<<std::endl;
    typedef List<Int<1>> l1;
    static_assert(l1::size == 1, "fail");
    l1::head h1;
    l1::next t1;
    //static_assert(typeid(Int<1>) == typeid(Int<1>), "fail"); //use conditional

    constexpr List<Int<1>, Int<2>, Int<3>> l2;
    static_assert(l2.size == 3, "fail");


    typedef List<Int<1>, Int<2>, Int<3>> list;
//    GetAtIndex<0, list>::value; // = Int<1>
//    GetAtIndex<2, list>::value; // = Int<3>


    typedef List<Int<1>, Int<2>, Int<3>> list;
    typedef typename SetAtIndex<0, Int<5>, list>::list listA; // = List<Int<5>,Int<2>, Int<3>>
    listA::head a;

    typedef typename SetAtIndex<2, Int<7>, list>::list listB; // = List<Int<1>,Int<2>, Int<7>>
    listB::head b;

    typedef typename SetAtIndex<1, Int<111>, list>::list listC; // = List<Int<1>,Int<2>, Int<7>>
    listC::head c;


    int val = ConditionalInteger<(0 != 1), 0, 1>::value; // = 0
    val = ConditionalInteger<(0 == 1), 0, 1>::value; // = 1
    typedef typename Conditional<(0 != 1), Int<0>, Int<1>>::value test1; // = Int<0>
    typedef typename Conditional<(0 == 1), Int<0>, Int<1>>::value test2;

    if (typeid(Int<0>) == typeid(test1)){
        int x = 4;
        x++;
    }

    if (typeid(Int<1>) == typeid(test2)){
        int x = 4;
        x++;
    }

    //int amount = Move<EMPTY, UP, 1>::amount;

    int amount1 = Move<X, RIGHT, 1>::amount;

    typedef GameBoard<List< List< BoardCell<EMPTY, UP, 0>, BoardCell<EMPTY, UP, 0>>,
            List< BoardCell<X, RIGHT, 1>, BoardCell<A, UP, 1>>,
            List< BoardCell<EMPTY, UP, 0>, BoardCell<EMPTY, UP, 0>>>> gameBoard;

    int l = gameBoard::length;
    int w = gameBoard::width;

    typedef List<Move<A, UP, 1>> moves;

    MoveVehicle<gameBoard, 1, 0, UP, 3>::board ;


    return 0;
}

