//
// Created by eviat on 5/23/2021.
//

#ifndef BINARY_TREE_A_POSTORDER_TRAVERSAL_HPP
#define BINARY_TREE_A_POSTORDER_TRAVERSAL_HPP
#include "Node.hpp"
#include <vector>
#include <exception>
using namespace std;

namespace ariel {
    template<typename T>
    class postorder_traversal {
    private:
        Node<T> *pointer_to_current_node;
        vector<Node<T> *> pre_nodes;
        typename std::vector<Node<T>*>::iterator it;
    public:
        postorder_traversal(Node<T> *curr) : pointer_to_current_node(curr) {
            traverse_postorder(pointer_to_current_node); //insert all the nodes to the vector
            if(curr != nullptr){
                pointer_to_current_node = pre_nodes[0];
                it = pre_nodes.begin();
            }
            else{
                it = pre_nodes.end();
            }
        }

        void traverse_postorder(Node<T> *node) {
            if (node == nullptr) {
                return;
            }
            traverse_postorder(node->left);
            traverse_postorder(node->right);
            pre_nodes.emplace_back(node);
        }

        T &operator*() const {
            //return *pointer_to_current_node;
            return pointer_to_current_node->val;
        }

        // ++i;
        postorder_traversal &operator++() {
            //++pointer_to_current_node;
            it+=1;
            if(it == pre_nodes.end()){
                pointer_to_current_node = nullptr;
            }
            else{
                pointer_to_current_node = *(it);
            }
            return *this;
        }

        // i++;
        // Usually iterators are passed by value and not by const& as they are small.
        const postorder_traversal operator++(int) {
            postorder_traversal<T> tmp = *this;
            it+=1;
            if(it == pre_nodes.end()){pointer_to_current_node = nullptr;}
            else{pointer_to_current_node = *(it);}
            return tmp;
        }

        bool operator==(const postorder_traversal<T> &rhs) const {
            return pointer_to_current_node == rhs.pointer_to_current_node;
        }

        bool operator!=(const postorder_traversal<T> &rhs) const {
            return pointer_to_current_node != rhs.pointer_to_current_node;
        }

        T* operator->() const {
            return &(pointer_to_current_node->val);
        }
    };
};
#endif //BINARY_TREE_A_POSTORDER_TRAVERSAL_HPP
