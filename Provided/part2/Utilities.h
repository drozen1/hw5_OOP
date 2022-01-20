//
// Created by karen on 20-Jan-22.
//

#ifndef HW5_OOP_UTILITIES_H
#define HW5_OOP_UTILITIES_H
template<bool, typename ,typename >
struct Conditional;

template<typename X ,typename Y>
struct Conditional<false, X, Y>{
    typedef Y value;
};

template<typename X ,typename Y>
struct Conditional<true, X, Y>{
    typedef X value;
};

template <bool g, int T, int E>
struct ConditionalInteger;

template <int T, int E>
struct  ConditionalInteger <false, T, E> {
    constexpr static int value = E ;
};

template <int T, int E>
struct  ConditionalInteger <true, T, E> {
    constexpr static int value = T ;
};

#endif //HW5_OOP_UTILITIES_H
