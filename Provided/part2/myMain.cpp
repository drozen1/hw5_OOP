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

    return 0;
}

