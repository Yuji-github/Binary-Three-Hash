/*
 * c338047 Yuji Ishikawa
 * This H file creating binary tree 
 * add / compare / remove / search for remove particular words 
 */

#ifndef YUJI_BSTREE_H //macrogurad 
#define YUJI_BSTREE_H //macrogurad

#include <cstdlib> //not necessary in this case 
#include <iostream>
#include <string>
#include <cassert> //not necessary in this case 
#include "BTNode.h"

template <typename Item>
class BSTree
{
    public: 
        
        //constructor 
        /*
        *pre-condition: none
        *post-condition: create constructors 
        */
        BSTree(); 
        
        //constructor 
        /*
        *pre-condition: string type
        *post-condition: create constructors with top left and right node 
        */
        BSTree(const Item& data);
        
        //destructor
        /*
        *pre-condition: none
        *post-condition: call remove function  
        */
        ~BSTree();
        
        //add function
        /*
        *pre-condition: string type 
        *post-condition: create the top of node or calling insert function 
        */
        void add(const Item& data); //create Root node and others == initial function of insert
        
        //compare function
        /*
        *pre-condition: 2 strings in this case  
        *post-condition: return int value. -1 is right side, 0 is the same value, 1 is left
        */
        int compare(const Item& data, const Item& parent_data);
        
        
        //search function
        /*
        *pre-condition: 1 string in this case  
        *post-condition: call search function or return NULL
        */
        bool search(const Item& data) const; //initial function of the search
        
        //remove function
        /*
        *pre-condition: 1 string in this case  
        *post-condition: call remove function or return NULL
        */
        bool remove(const Item& data); 
        
        
        //inorder function
        /*
        *pre-condition: none   
        *post-condition: call inorder function or return NULL
        */
        void inorder(); //for print out <<
        
    private:
        
        BTNode<Item>* root;  
        std::size_t leaf;
       
        //remove function
        /*
        *pre-condition: BTNode  
        *post-condition: remove from the bottom of tree == destructor 
        */
        void remove(BTNode<Item>* current_parent); //for destructor 
        
        
        //inorder function
        /*
        *pre-condition: BTNode and int    
        *post-condition: print out from the left node and right
        */
        void inorder(BTNode<Item>* current_parent, int levels);
        
        //insert function
        /*
        *pre-condition: BTNode and string    
        *post-condition: create nodes under the top of the root
        */
        void insert(BTNode<Item>* current_parent, Item& data); //recursive calling == private 
        
        //search function
        /*
        *pre-condition: BTNode and string  
        *post-condition: return int value. -1 is right side, 0 is the same value, 1 is left
        */
        bool search(BTNode<Item>* current_parent, const Item& data)const; //recursive calling == private
        
        //remove function
        /*
        *pre-condition: BTNode and string
        *post-condition: remove from the tree or (swap and delete) 
        */
        bool remove(BTNode<Item>* current_parent, const Item& data); //recursive calling == private
        
        //min function
        /*
        *pre-condition: the node must have 2 children
        *post-condition: find the lowest value from the tree to remove/swap 
        */
        BTNode<Item>* min(BTNode<Item>* current_parent);
}; 

template <typename Item>
std::ostream& operator <<(std::ostream& out, BSTree<Item>& traveler); //call public inorder(), then call private inorder(BTNode* new_root)


#include "BSTree.hpp" //includeing hpp 
#endif // macroguard 