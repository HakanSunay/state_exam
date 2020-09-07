//
// Created by Hakan Halil on 6.09.20.
//

#ifndef C___BINARY_SEARCH_TREE_H
#define C___BINARY_SEARCH_TREE_H

#include <iostream>

template<typename T>
class Node {
public:
    T data;
    Node<T>* left;
    Node<T>* right;

    Node(const T& data, Node<T>* left=nullptr, Node<T>* right=nullptr): data(data), left(left), right(right) {};

    void AddLeft(const T& data) {
        this->left = new Node<T>(data);
    }

    void AddRight(const T& data) {
        this->right = new Node<T>(data);
    }
};

template<typename T>
class BinarySearchTree {
public:
    BinarySearchTree(const T& data) {
        this->root = new Node<T>(data);
    }

    BinarySearchTree(Node<T>* root= nullptr): root(root) {};

    BinarySearchTree(const BinarySearchTree<T>& other) {
        Copy(other.root, this->root);
    }

    BinarySearchTree& operator= (const BinarySearchTree<T>& other) {
        if (this != &other) {
            Delete();
            Copy(other.root, this->root);
        }

        return *this;
    }

    ~BinarySearchTree() {
        Delete();
    }

    BinarySearchTree(const T& data, const BinarySearchTree<T>& left, const BinarySearchTree<T>& right) {
        this->root = new Node<T>(data);
        Copy(left.root, root->left);
        Copy(right.root, root->right);
    }

    int Depth() {
        return depth(this->root);
    }

    void Insert(const T& data) {
        Node<T>* toBeInserted = new Node<T>(data);
        if (root == nullptr) {
            // root is empty
            this->root = toBeInserted;
            return;
        }

        _insert(toBeInserted, root);
    }

    // TODO:
    void Remove(const T& data) {
        // will remove first occurrence only

    }

    T Min() {
        Node<T>* iter = this->root;
        if (iter == nullptr) {
            return T();
        }

        while (iter->left != nullptr) {
            iter = iter->left;
        }

        return iter->data;
    }

    T Max() {
        Node<T>* iter = this->root;
        if (iter == nullptr) {
            return T();
        }

        while (iter->right != nullptr) {
            iter = iter->right;
        }

        return iter->data;
    }

private:
    Node<T>* root;

    void Copy(Node<T>* from, Node<T>*& to) {
        to = nullptr;
        if (from != nullptr) {
            to = new Node<T>(from->data);
            Copy(from->left, to->left);
            Copy(from->right, to->right);
        }
    }

    void Delete() {
        _delete(this->root);
    }

    void _delete(Node<T>*& ptr) {
        if (ptr) {
            _delete(ptr->left);
            _delete(ptr->right);
            delete ptr;
            ptr = nullptr;
        }
    }

    int depth(Node<T>* begin) {
        if (begin == nullptr)
            return 0;

        return 1 + std::max(depth(begin->left), depth(begin->right));
    }

    void _insert(Node<T>*& toBeInserted, Node<T>*& ptr) {
        if (ptr == nullptr) {
            ptr = toBeInserted;
            return;
        }
        if (toBeInserted ->data < ptr->data) {
            _insert(toBeInserted, ptr->left);
        } else if (toBeInserted -> data >= ptr->data) {
            _insert(toBeInserted, ptr->right);
        }
    }
};

#endif //C___BINARY_SEARCH_TREE_H
