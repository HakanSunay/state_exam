//
// Created by Hakan Halil on 6.09.20.
//

#ifndef C___BINARY_TREE_H
#define C___BINARY_TREE_H

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
class BinaryTree {
public:
    BinaryTree(const T& data) {
        this->root = new Node<T>(data);
    }

    BinaryTree(Node<T>* root= nullptr): root(root) {};

    BinaryTree(const BinaryTree<T>& other) {
        Copy(other.root, this->root);
    }

    BinaryTree& operator= (const BinaryTree<T>& other) {
        if (this != &other) {
            Delete();
            Copy(other.root, this->root);
        }

        return *this;
    }

    ~BinaryTree() {
        Delete();
    }

    BinaryTree(const T& data, const BinaryTree<T>& left, const BinaryTree<T>& right) {
        this->root = new Node<T>(data);
        Copy(left.root, root->left);
        Copy(right.root, root->right);
    }

    int Depth() {
        return depth(this->root);
    }

    Node<T>* Root() {
        return this->root;
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
};

#endif //C___BINARY_TREE_H
