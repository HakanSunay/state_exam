//
// Created by Hakan Halil on 23.08.20.
//


#include <vector>
#include <string>

struct Node {
    std::vector<Node*> children;

    Node(std::vector<Node *> children) : children(children) {}

    bool isLeaf() const {return children.empty();}
};

struct Edge {
    Node* first;
    Node* second;
    int value;
    std::string label;

    Edge() :
    first(nullptr), second(nullptr), value(0), label("") {}

    Edge(Node *first, Node *second, int value, const std::string &label) :
    first(first), second(second), value(value), label(label) {}
};

struct Tree {
    Node* root;
    std::vector<Edge> edges;

    Tree(Node *root, std::vector<Edge> edges) : root(root), edges(edges) {}

    Edge FindEdge(Node* first, Node* second) const {
        for (auto edge : edges) {
            if ((edge.first == first) && (edge.second == second)) {
                return edge;
            }
        }

        return Edge();
    }
};

// TODO:
std::vector<std::vector<Node*>> GetBranchesOf(Node* target) {
    // get all branches
    // might need to recurse into another function
}

int GetBranchValue(const Tree& tree, const std::vector<Node*>& branch) {
    int branchValue = 0;
    for (int i = 0; i < branch.size() - 1; ++i) {
        Edge edge = tree.FindEdge(branch.at(i), branch.at(i + 1));
        branchValue += edge.value;
    }

    return branchValue;
}

std::string GetBranchWord(const Tree& tree, const std::vector<Node*>& branch) {
    std::string branchLabel;
    for (int i = 0; i < branch.size() - 1; ++i) {
        Edge edge = tree.FindEdge(branch.at(i), branch.at(i + 1));
        branchLabel += edge.label;
    }

    return branchLabel;
}

// TODO: Possible improvements:
// O(N^2) --> O(N logN) if possible
// Words must be separated with newline (can use vector of str)
std::string CommonBranches(const Tree& tree, Node* u, Node* v, int k) {
    std:: string result;
    for (const auto& uPerm : GetBranchesOf(u)) {
        for (const auto& vPerm: GetBranchesOf(v)) {
            if (GetBranchWord(tree, uPerm) == GetBranchWord(tree, vPerm)) {
                if (GetBranchValue(tree, uPerm) + GetBranchValue(tree, vPerm) == k)
                {
                    result.append(GetBranchWord(tree, uPerm));
                }
            }
        }
    }

    return result;
}
