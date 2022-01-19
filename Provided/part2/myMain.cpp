#include <iostream>

#include "List.h"

template<int n>
class Int {

};

int main(){

    std::cout<<"myMain"<<std::endl;
    typedef List<Int<1>> l1;
    static_assert(l1::size == 1, "fail");
    typedef l1::head h1;
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

    return 0;
}

