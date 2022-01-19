//
// Created by Dor on 1/19/2022.
//

#ifndef HW5_OOP_SUBJECT_H
#define HW5_OOP_SUBJECT_H


#include <vector>
#include<iostream>
#include<vector>
#include<algorithm>
#include "OOP5EventException.h"


using namespace std;

template <typename T>
class Subject {
    vector<Observer<T>*> observers;

    bool contains(const Observer<T>& elem)
    {
        bool result = false;
        if( find(observers.begin(), observers.end(), &elem) != observers.end() ) {
            result = true;
        }
        return result;
    }

public:
    void notify (const T& t) {
        for (Observer<T>* o : observers) {
            o->handleEvent(t);
        }
    }

    void addObserver (Observer<T>& o) {
        if (this->contains(o)) {
            throw ObserverAlreadyKnownToSubject();
        } else {
            observers.push_back(&o);
        }
    }

    void removeObserver (Observer<T>& o) {
        if (!this->contains(o)) {
            throw ObserverUnknownToSubject();
        } else {
            Observer<T>* to_remove = &o;

            for (int i=0; i< observers.size(); i++) {
                if (to_remove == observers[i]) {
                   observers.erase(observers.begin()+i);
                    return;
                }
            }
        }
    }

    Subject<T>& operator+= (Observer<T>& o) {
        this->addObserver(o);
        return *this;
    }

    Subject<T>& operator-= (Observer<T>& o) {
        this->removeObserver(o);
        return *this;
    }

    Subject<T>& operator() (const T& t) {
        this->notify(t);
        return *this;
    }


};






#endif //HW5_OOP_SUBJECT_H