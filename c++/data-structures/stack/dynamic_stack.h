//
// Created by Hakan Halil on 6.09.20.
//

#ifndef C___DYNAMIC_STACK_H
#define C___DYNAMIC_STACK_H

template<typename T>
class DynamicStack;

template<typename T>
class Item {
public:
    friend class DynamicStack<T>;
    Item(const T& data) {
        this->data = data;
        link = nullptr;
    }

private:
    T data;
    Item* link;
};

template<typename T>
class DynamicStack {
public:
    DynamicStack(): top(nullptr) {};

    DynamicStack(const DynamicStack& other) {
        Copy(other);
    }

    DynamicStack& operator= (const DynamicStack& other) {
        if (this != &other) {
            Delete();
            Copy(other);
        }

        return *this;
    }

    ~DynamicStack() {
        Delete();
    }

    T Pop() {
        if (!Empty()) {
            Item<T>* toBeDeleted = top;
            top = top->link;

            T data = toBeDeleted->data;
            delete toBeDeleted;

            return data;
        }

        return T();
    }

    void Push(T const & X) {
        Item<T>* toBeAdded = new Item<T>;
        toBeAdded->data = X;
        toBeAdded->link = top;
        top = toBeAdded;
    }

    T Peek() {
        if (!Empty()) {
            return top->data;
        }

        return T();
    }

    bool Empty() {
        return top == nullptr;
    }

private:
    Item<T>* top;
    void Delete() {
        Item<T>* iter = top;
        while (top != nullptr) {
            iter = top;
            top = top->link;
            delete iter;
        }
    }

    void Copy(const DynamicStack& other) {
        Item<T>* otherIter = other.top;
        while (otherIter != nullptr) {
            this->Push(otherIter->data);
            otherIter = otherIter->link;
        }
    }

};

#endif //C___DYNAMIC_STACK_H