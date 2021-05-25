//
// Created by eviat on 5/21/2021.
//

#ifndef BINARY_TREE_A_BINARYTREE_HPP
#define BINARY_TREE_A_BINARYTREE_HPP

#include "inorder_traversal.hpp"
#include "preorder_traversal.hpp"
#include "postorder_traversal.hpp"
#include "Node.hpp"
#include <set>
#include <exception>

using namespace std;

namespace ariel {
    template<typename T>
    class BinaryTree {
    private:
        //-------------------------------------------------------------------
        // Node related code:
        // inner class and methods that return instances of it
        //-------------------------------------------------------------------

        Node<T> *root;     //root of the tree
        set<Node<T>*> st;
    public:
        BinaryTree(){
            root = nullptr;
        }
        ~BinaryTree(){  //pre order travers and delete all
            for(Node<T>* node: st){
                delete node;
            }
        }
        BinaryTree& add_root(T value){
            if(!root) {     //if the root already exist
                root = new Node<T>(value, nullptr, nullptr);
                st.insert(root);
                return *this;
            }
            root ->val = value;     //otherwise change the value of the node
            return *this;
        }
        void order_all(Node<T>* node){
            if(node == nullptr){
                return;
            }
            st.insert(node);
            order_all(node ->left);
            order_all(node->right);
        }
        BinaryTree &add_left(T father, T value){
            st.clear();
            order_all(root);    //order all the nodes
            bool is_exist = false;
            for(Node<T>* node: st){
            if(node->val == father){
                if(!(node->left)){  //left isn't so change the value
                    (node->left) = new Node<T>(value, nullptr, nullptr);
                    is_exist = true;
                }
                else{
                    (node->left)->val = value;
                    is_exist = true;
                }
                break;
            }
        }
            st.clear();
            if(!is_exist) {
                throw invalid_argument("the node not exist in the set right!!");
            }

            return *this;
        }

        BinaryTree &add_right(T father, T value){
            st.clear();
            order_all(root);    //order all the nodes
            bool is_exist = false;
            for(Node<T>* node: st){
                if(node->val == father){
                    if(!(node->right)){  //left isn't so change the value
                        (node->right) = new Node<T>(value, nullptr, nullptr);
                        is_exist = true;
                    }
                    else{
                        (node->right)->val = value;
                        is_exist = true;
                    }
                    break;
                }
            }
            st.clear();
            if(!is_exist) {
                throw invalid_argument("the node not exist in the set left!!");
            }
            return *this;
        }
        friend ostream &operator<<(ostream &os, const BinaryTree<T> tree){
            return os;
        }

        preorder_traversal<T> begin_preorder(){
            return preorder_traversal<T>{root};
        }

        postorder_traversal<T> begin_postorder(){
            return postorder_traversal<T>{root};
        }

        inorder_traversal<T> begin_inorder(){
            return inorder_traversal<T>{root};
        }

        preorder_traversal<T> end_preorder(){
            return preorder_traversal<T>{nullptr};
        }

        postorder_traversal<T> end_postorder(){
            return postorder_traversal<T>{nullptr};
        }

        inorder_traversal<T> end_inorder(){
            return inorder_traversal<T>{nullptr};
        }

        inorder_traversal<T> begin(){
            return inorder_traversal<T>{root};
        }

        inorder_traversal<T> end(){
            return inorder_traversal<T>{nullptr};
        }

    };


};


















#endif //BINARY_TREE_A_BINARYTREE_HPP
