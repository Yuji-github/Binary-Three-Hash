/*
 * c338047 Yuji Ishikawa
 * This H file is for Binary Search Tree 
 * Store data type is string 
 */

#ifndef YUJI_BTNODE_H //macrogurad 
#define YUJI_BTNODE_H //macrogurad

#include <cstdlib>
#include <iostream>
#include <string>

template <typename Item>
class BTNode
{
    public: 
        
        //constructor 
        /*
        *pre-condition: none
        *post-condition: create constructors 
        */
        BTNode();
        
        //constructor 
        /*
        *pre-condition: int value
        *post-condition: create constructors with loop function 
        */
        BTNode(const Item& new_Item, BTNode* new_mama = NULL, BTNode* new_left = NULL, BTNode* new_right = NULL);
        
        //destructor
        /*
        *pre-condition: none
        *post-condition: all Node will be gone 
        */
        ~BTNode();
        
        //setter
        /*
         * pre-condition: none
         * post-condition: set the next and previous
         */
        void setParent(BTNode* new_mama);
        void setLeft(BTNode* new_left);
        void setRight(BTNode* new_right);
        void setData(const Item& new_Item);
        
        //getter
        /*
         * pre-condition: data should be stored
         * post-condition: get the next, previous, data value (int or string)
         */
        
        const BTNode* getParent() const; 
        BTNode* getParent(); 
        
        const BTNode* getLeft() const; 
        BTNode* getLeft(); 
        
        const BTNode* getRight() const;
        BTNode* getRight();
        
        Item& getData();
        Item getData()const;
        
        //assume this is the end of the tree
        /*
         * pre-condition: none;
         * post-condition: return if left is NULL AND Right is NULL
         */
        bool is_leaf() const;
        
        //assume this is the end of the tree
        /*
         * pre-condition: none;
         * post-condition: return if left is NULL AND Right is full || left is something AND right is NULL
         */
        bool has_one_child() const; 
        
        //from is_leaf and has_one_child => if both are false the node has 2 child already 
        
        
        
         //assume this is the end of the tree
        /*
         * pre-condition: none;
         * post-condition: return  if Item& data > current.getData()
         */
        
        bool is_right_child() const;
        
    private:
        
        Item data;
        BTNode* parent;
        BTNode* left;
        BTNode* right; 
}; 

#include "BTNode.hpp"

#endif //macrogurad