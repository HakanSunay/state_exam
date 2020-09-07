//
// Created by Hakan Halil on 6.09.20.
//

#include <cstdlib>

#ifndef C___STATIC_QUEUE_H
#define C___STATIC_QUEUE_H


const size_t STATIC_QUEUE_SIZE = 81406;

template<typename T>
class StaticQueue {
    T data[STATIC_QUEUE_SIZE];
    size_t size;

    StaticQueue(): size(0){};

    // O(n), could be decreased to O(1) if we keep first and last element index at all times
    // I am too lazy to do that atm
    T Pop() {
        if (!Empty()) {
            T toBeReturned = data[0];
            shiftLeft();
            size--;
        }

        return T();
    }

    void Peek() {
        if (!Empty()) {
            return data[0];
        }
    }

    void Push(T data) {
        data[size++] = data;
    }

    bool Empty() {
        return size == 0;
    }

    bool Full() {
        return size == STATIC_QUEUE_SIZE;
    }

private:
    void shiftLeft() {
        for (int i = 0; i < this->size - 1; ++i) {
            data[i] = data[i + 1];
        }
    }
};

#endif //C___STATIC_QUEUE_H