//
// Created by Hakan Halil on 6.09.20.
//

#include "binary-search-tree/binary_search_tree.h"
#include "binary-tree/binary_tree.h"


int main() {
    BinaryTree<int> bt = BinaryTree<int>(7);
    bt.Root()->AddLeft(6);
    bt.Root()->AddRight(7);

    BinaryTree<int> copyTree = BinaryTree<int>(bt);

    BinaryTree<int> empty;
    empty = copyTree;
    std::cout<< empty.Depth() << std::endl;

    BinaryTree<int> emb = BinaryTree<int>(1, BinaryTree<int>(2), BinaryTree<int>(3));
    std::cout<< emb.Depth() << std::endl;

    BinarySearchTree<int> bst;
    bst.Insert(3);
    bst.Insert(2);
    bst.Insert(4);
    bst.Insert(4);
    int depth = bst.Depth();
    int min = bst.Min();
    int max = bst.Max();
}
