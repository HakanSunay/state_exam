//
// Created by Hakan Halil on 6.09.20.
//

#ifndef C___DYNAMIC_QUEUE_H
#define C___DYNAMIC_QUEUE_H

template<typename T>
class Element {
// avoiding friend class with public
public:
    T data;
    Element<T>* next;

    Element(const T& data): data(data), next(nullptr) {};
};

template<typename T>
class DynamicQueue {
public:
    DynamicQueue(): first(nullptr), last(nullptr) {};
    DynamicQueue(const DynamicQueue<T>& other) {
        Copy(other);
    }

    DynamicQueue& operator= (const DynamicQueue<T>& other) {
        if (this != &other) {
            Delete();
            Copy(other);
        }

        return *this;
    }

    ~DynamicQueue() {
        Delete();
    }

    void Push(const T& X) {
        Element<T>* newElement = new Element<T>(X);

        if (!Empty()) {
            last->next = newElement;
        } else {
            first = newElement;
        }

        last = newElement;
    }

    T Peek() {
        if (!Empty()) {
            return first->data;
        }
    }

    T Pop() {
        if (!Empty()) {
            T toBeReturned = first->data;

            Element<T>* toBeDeleted = first;
            first = first->next;
            if (first == nullptr) {
                last = nullptr;
            }

            delete toBeDeleted;
            return toBeReturned;
        }
    }

    bool Empty() {
        return last == nullptr;
    }

private:
    Element<T>* first;
    Element<T>* last;

    void Delete() {
        while (!Empty()) {
            Pop();
        }
    }

    void Copy(const DynamicQueue<T>& other) {
        Element<T>* otherFirst = other.first;
        while (otherFirst != nullptr) {
            Push(otherFirst->data);
            otherFirst = otherFirst->next;
        }
    }

};

#endif //C___DYNAMIC_QUEUE_H