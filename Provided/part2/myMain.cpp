#include <iostream>

#include "RushHour.h"
#include "Printer.h"

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

    typedef GameBoard<List< List< BoardCell<EMPTY, UP, 0> , BoardCell<A, UP, 4>>,
            List< BoardCell<X, UP, 1> , BoardCell<A, UP, 4>>,
            List< BoardCell<EMPTY, UP, 1>, BoardCell<A, UP, 4>>,
            List< BoardCell<EMPTY, UP, 1>, BoardCell<A, UP, 4>>,
            List< BoardCell<EMPTY, UP, 1>, BoardCell<EMPTY, UP, 2>>,
            List< BoardCell<EMPTY, UP, 1>, BoardCell<EMPTY, UP, 2>>,
            List< BoardCell<EMPTY, UP, 1>, BoardCell<EMPTY, UP, 2>>>> gameBoard;

    typedef typename MoveVehicle<gameBoard, 2, 1, DOWN, 2>::board toPrint5;
    Printer<toPrint5>::print(std::cout);

    int l = gameBoard::length;
    int w = gameBoard::width;

    typedef List<Move<A, UP, 1>> moves;

    //MoveVehicle<gameBoard, 1, 0, RIGHT, 3>::board ;


    typedef GameBoard<List< List<
            BoardCell<EMPTY, RIGHT, 1>,
            BoardCell<EMPTY, RIGHT, 1>,
            BoardCell<EMPTY, RIGHT, 1>,
            BoardCell<X, RIGHT, 3>,
            BoardCell<X, RIGHT, 3>,
            BoardCell<X, RIGHT, 3>,
            BoardCell<A, RIGHT, 1>
            >>> testBoard2;

    typedef typename MoveVehicle<testBoard2, 0, 4, LEFT, 3>::board toPrint2;
    Printer<toPrint2>::print(std::cout);

    typedef GameBoard<List< List< BoardCell<B, UP, 0>, BoardCell<EMPTY, UP, 0>>,
            List< BoardCell<X, UP, 1>, BoardCell<A, UP, 1>>,
    List< BoardCell<EMPTY, UP, 0>, BoardCell<EMPTY, UP, 0>>>> gameBoard2;

    typedef typename OneMove<0,0,gameBoard2,RIGHT,B, 1>::newBoard toPrint;
    Printer<toPrint>::print(std::cout);
    //MoveVehicle<gameBoard2, 1, 1, DOWN, 1>::board ;

    Printer<gameBoard2>::print(std::cout);
    typedef typename Transpose<gameBoard2::board>::matrix transposeBoard;
    Printer<transposeBoard>::print(std::cout);
    int ef = gameBoard2::width;
    int eef = gameBoard2::length;
    typedef GameBoard<transposeBoard> transposeGameBoard;
    int e = transposeGameBoard::width;
    int ee = transposeGameBoard::length;
    //MoveVehicle<testBoard2, 0, 0, RIGHT, 2>::board ;

    int cc  = LastLocation<0, 4, LEFT, X ,X , 5, testBoard2>::value::column;
    int rr = LastLocation<0, 4, LEFT, X ,X , 5, testBoard2>::value::row;

    int counter =  CountEmptyCells<0,3, LEFT, X ,X, 7, testBoard2, 0>::value;

    return 0;
}

