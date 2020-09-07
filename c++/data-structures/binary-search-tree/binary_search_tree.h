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

    // TODO: A recursive solution might be better fitting here
    void Remove(const T& data) {
        Node<T>* father = root;
        Node<T>* current = root;
        while (current->data != data) {
            father = current;
            if (data < current->data) {
                current = current->left;
            } else if (data > current->data) {
                current = current->right;
            }
        }

        // Current is leaf
        if (current->left == nullptr && current -> right == nullptr) {
            if (current == root) {
                delete root;
                root = nullptr;
                return;
            } else if (current->data < father->data) {
                // current node is left child
                father->left = nullptr;
            } else {
                // current node is right child
                father->right = nullptr;
            }

            delete current;
            return;
        }

        // Current has 1 child only
        // No need to XOR, previous case will handle both being nullptr
        if (current->left == nullptr || current->right == nullptr) {
            if (current->left == nullptr) {
                // current node has right child only
                // updating value depending on current node's left/right child relation to its father
                current->data < father->data ? father->left = current->right : father->right = current->right;
            } else {
                // current node has left child only
                // updating value depending on current node's left/right child relation to its father
                current->data < father->data ? father->left = current->left : father->right = current->left;
            }

            delete current;
            return;
        }

        // Current has 2 children, must find its highest element in left subtree
        Node<T>* lowerIter = current->left;
        Node<T>* lowerIterFather = current;
        while (lowerIter->right != nullptr) {
            lowerIterFather = lowerIter;
            lowerIter = lowerIter->right;
        }

        // replace highest leftree subtree element with current
        T newData = lowerIter -> data;
        delete lowerIter;

        if (lowerIterFather->data > newData) {
            lowerIterFather->left = nullptr;
        } else {
            lowerIterFather->right = nullptr;
        }

        current->data=newData;
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
