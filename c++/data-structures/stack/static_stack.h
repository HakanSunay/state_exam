//
// Created by Hakan Halil on 6.09.20.
//

#include <cstddef>

#ifndef C___STATIC_STACK_H
#define C___STATIC_STACK_H

const int STACK_SIZE = 81406;

template <typename T>
class StaticStack {
    T data[STACK_SIZE];
    size_t size;

    StaticStack(): size(0) {};

    T Pop() {
        if (!Empty()) {
            return data[--size];
        }
    }

    void Push(T item) {
        if (!Full()) {
            data[size++] = item;
        }
    }

    T Peek() {
        if (!Empty()) {
            data[size - 1];
        }
    }

    bool Empty() {
        return size == 0;
    }

    bool Full() {
        return size == STACK_SIZE;
    }
};

#endif //C___STATIC_STACK_H