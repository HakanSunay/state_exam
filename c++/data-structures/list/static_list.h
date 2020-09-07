//
// Created by Hakan Halil on 6.09.20.
//

#ifndef C___STATIC_LIST_H
#define C___STATIC_LIST_H


#include <cstdlib>

const size_t STATIC_LIST_SIZE = 81406;

template<typename T>
class StaticList {
    T data[STATIC_LIST_SIZE];

};

#endif //C___STATIC_LIST_H
