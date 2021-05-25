//
// Created by eviat on 5/23/2021.
//

#ifndef BINARY_TREE_A_PREORDER_TRAVERSAL_HPP
#define BINARY_TREE_A_PREORDER_TRAVERSAL_HPP
#include "Node.hpp"
#include <vector>
#include <exception>

using namespace std;

namespace ariel {
    template<typename T>
    class preorder_traversal {
    private:
        Node<T> *pointer_to_current_node;
        vector<Node<T>*> pre_nodes;
        typename std::vector<Node<T>*>::iterator it;
    public:
        preorder_traversal(Node<T> *curr) : pointer_to_current_node(curr) {
            if(curr != nullptr) {
                traverse_preorder(pointer_to_current_node); //insert all the nodes to the vector
                it = pre_nodes.begin();}
            else {it = pre_nodes.end();}
        }

        void traverse_preorder(Node<T> *node){
            if(node == nullptr){
                return;
            }
            pre_nodes.emplace_back(node);
            traverse_preorder(node ->left);
            traverse_preorder(node->right);
        }

        T &operator*() const {
            //return *pointer_to_current_node;
            return pointer_to_current_node->val;
        }

        // ++i;
        preorder_traversal &operator++() {
            //++pointer_to_current_node;
            it+=1;
            if(it == pre_nodes.end()){pointer_to_current_node = nullptr;}
            else{pointer_to_current_node = *(it);}
            return *this;
        }

        // i++;
        // Usually iterators are passed by value and not by const& as they are small.
        const preorder_traversal operator++(int) {
            preorder_traversal<T> tmp = *this;
            it+=1;
            if(it == pre_nodes.end()){ pointer_to_current_node = nullptr;}
            else{ pointer_to_current_node = *(it);}
            return tmp;
        }

        bool operator==(const preorder_traversal<T>& rhs) const {
            return pointer_to_current_node == rhs.pointer_to_current_node;
        }

        bool operator!=(const preorder_traversal<T>& rhs) const {
            return pointer_to_current_node != rhs.pointer_to_current_node;
        }

        T* operator->() const {
            return &(pointer_to_current_node->val);
        }
    };
};
#endif //BINARY_TREE_A_PREORDER_TRAVERSAL_HPP
