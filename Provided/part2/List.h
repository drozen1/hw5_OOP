//
// Created by Dor on 1/19/2022.
//

#ifndef HW5_OOP_LIST_H
#define HW5_OOP_LIST_H


template<typename ... TT>
struct List;

template<typename T, typename ...TT>
struct List<T, TT...> {
    constexpr static int size = 1 + sizeof...(TT); //constexpr static ?
    typedef T head;
    typedef List<TT...> next;
};

template<>
struct List<> {
    constexpr static int size = 0; //constexpr static ?
};











#endif //HW5_OOP_LIST_H
