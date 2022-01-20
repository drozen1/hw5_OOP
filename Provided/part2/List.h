//
// Created by Dor on 1/19/2022.
//

#ifndef HW5_OOP_LIST_H
#define HW5_OOP_LIST_H


template<typename ... TT>
struct List;

template<>
struct List<> {
    constexpr static int size = 0;
};

template<typename T, typename ...TT>
struct List<T, TT...> {
    constexpr static int size = 1 + sizeof...(TT);
    typedef T head;
    typedef List<TT...> next;
};

template<typename X, typename ...TT>
struct PrependList;

template<typename X , typename ...TT>
struct PrependList<X , List<TT...>> {
    typedef List<X, TT...> list;
};


template<int N, typename T>
struct GetAtIndex {};

template<int N, typename T, typename... TT >
struct GetAtIndex<N, List<T, TT... > > {
typedef typename GetAtIndex<N-1, List<TT... >>::value
        value;
};

template<typename T, typename... TT>
struct GetAtIndex<0, List<T, TT... > > {
typedef T value;
};

template<int N, typename X, typename T>
struct SetAtIndex {};

template<int N, typename X, typename T, typename... TT >
struct SetAtIndex<N, X, List<T, TT...>> {
    typedef typename PrependList<T,typename SetAtIndex<N-1, X, List<TT... >>::list> ::list
    list;
};

template<typename T, typename X, typename... TT>
struct SetAtIndex<0, X, List<T, TT... > > {
    typedef List<X,TT...> list;
};
















#endif //HW5_OOP_LIST_H
