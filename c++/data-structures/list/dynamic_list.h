//
// Created by Hakan Halil on 6.09.20.
//

#include <cstdlib>

#ifndef C___DYNAMIC_LIST_H
#define C___DYNAMIC_LIST_H

template<typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(const T& data, Node<T>* next = nullptr): data(data), next(next) {};
};

template<typename T>
class LinkedList {
    LinkedList(): head(nullptr), back(nullptr) {};

    LinkedList(const LinkedList<T>& other) {
        Copy(other);
    }

    LinkedList& operator= (const LinkedList<T>& other) {
        if (this != &other) {
            Delete();
            Copy(other);
        }

        return *this;
    }

    ~LinkedList() {
        Delete();
    }

    void InsertBegin(const T& data) {
        Node<T>* newNode = new Node<T>(data, head);
        if (Empty()) {
            back = newNode;
        }
        head = newNode;
    }

    void InsertEnd(const T& data) {
         if (Empty()) {
             InsertBegin(data);
         }

         Node<T>* newNode = new Node<T>(data);
         back->next = newNode;
         back = newNode;
    }

    void InsertAt(const T& data, size_t position) {
        if (position == 0) {
            InsertBegin(data);
        }
        size_t index = 0;
        Node<T>* iter = head;
        Node<T>* prev = head;

        while (iter != nullptr || index != position) {
            prev = iter;
            iter = iter->next;
            ++index;
        }

        if (iter == nullptr) {
            InsertEnd(data);
        }

        Node<T>* newNode = new Node<T>(data, iter);
        prev->next = newNode;
    }

    void DeleteAt(size_t position) {
        if (Empty()) {
            return;
        }

        if (position == 0) {
            // only 1 element
            Node<T>* toBeDeleted = head;

            if (head == back) {
                back = nullptr;
            }
            head = head->next;

            delete toBeDeleted;
            return;
        }

        size_t index = 0;
        Node<T>* iter = head;
        Node<T>* prev = head;

        while (iter != nullptr || index != position) {
            if (iter -> next == nullptr) {
                break;
            }

            prev = iter;
            iter = iter->next;
            ++index;
        }

        if (iter->next == nullptr) {
            // trying to delete last element
            delete iter;
            back = prev;
            return;
        }

        prev->next = iter->next;
        delete iter;
    }

    bool Empty() {
        return head == nullptr;
    }


private:
    Node<T>* head;
    Node<T>* back;

    void Copy(const LinkedList<T> & other) {
        Node<T>* otherIter = other.head;
        while (otherIter != nullptr) {
            InsertEnd(otherIter->data);
            otherIter = otherIter->next;
        }
    }

    void Delete() {
        while (!Empty()) {
            DeleteAt(0);
        }
    }

};

#endif //C___DYNAMIC_LIST_H