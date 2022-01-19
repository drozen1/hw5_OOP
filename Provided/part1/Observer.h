//
// Created by Dor on 1/19/2022.
//

#ifndef HW5_OOP_OBSERVER_H
#define HW5_OOP_OBSERVER_H

template <typename T>
class Observer {

public:
    virtual void handleEvent (const T& t) = 0;
};



#endif //HW5_OOP_OBSERVER_H
