//
// Created by eviat on 5/23/2021.
//

#ifndef BINARY_TREE_A_NODE_HPP
#define BINARY_TREE_A_NODE_HPP
using namespace std;

namespace ariel {
    template<typename T>
    struct Node {
        T val;
        Node *left;
        Node *right;

        //ls- left side rs- right side
        Node(T value, Node *ls = nullptr, Node *rs = nullptr) {
            this->val = value;
            this->left = ls;
            this->right = rs;
        }
    };
};
#endif //BINARY_TREE_A_NODE_HPP
