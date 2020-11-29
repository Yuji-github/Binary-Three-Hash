/*
 * c3338047 Yuji Ishikawa 
 * Node.hpp
 * To connect to #include "Node.h" 
 * To write functions which I mentioned on Node.h 
 * Node:: for return functions
 */   

#include "BTNode.h" 
#include <string>
#include <cstdlib>
#include <iostream>

//constructor section 
template <typename Item>
BTNode<Item>::BTNode()
{
    parent = NULL; 
    left = NULL; 
    right = NULL;
    data = "";
}

template <typename Item>
BTNode<Item>::BTNode(const Item& new_Item, BTNode<Item>* new_mama, BTNode<Item>* new_left, BTNode<Item>* new_right) //don't know why we need Node<DiscData>* in hpp
{
    parent = new_mama; 
    left = new_left; 
    right = new_right;
    data = new_Item;
}

template <typename Item>
BTNode<Item>::~BTNode()
{
    parent = NULL; 
    left = NULL; 
    right = NULL;
    data = "";
}

template <typename Item>
void BTNode<Item>::setParent(BTNode<Item>* new_mama) 
{
    parent = new_mama;
}

template <typename Item>
void BTNode<Item>::setLeft(BTNode<Item>* new_left)
{
    left = new_left;
}

template <typename Item>
void BTNode<Item>::setRight(BTNode<Item>* new_right)
{
    right = new_right;
}

template <typename Item>
void BTNode<Item>::setData(const Item& new_Item)
{
    data = new_Item;
}

template <typename Item>
const BTNode<Item>* BTNode<Item>::getParent() const
{
    return parent;
}

template <typename Item>
BTNode<Item>* BTNode<Item>::getParent() 
{
    return parent;
}

template <typename Item>
const BTNode<Item>* BTNode<Item>::getLeft() const
{
    return left;
}

template <typename Item>
BTNode<Item>* BTNode<Item>::getLeft() 
{
    return left;
}

template <typename Item>
const BTNode<Item>* BTNode<Item>::getRight() const
{
    return right;
}

template <typename Item>
BTNode<Item>* BTNode<Item>::getRight() 
{
    return right;
}

template <typename Item>
Item& BTNode<Item>::getData() 
{
    return data;
}

template <typename Item>
Item BTNode<Item>::getData() const
{
    return data;
}

template <typename Item>
bool BTNode<Item>::is_leaf()const
{
    if((left == NULL) && (right == NULL))
    {
        //Are you empty? Yes I am.
        return true;
    }
    else 
    {
        return false;
    }
}

template <typename Item>
bool BTNode<Item>::has_one_child()const
{
     if(((left == NULL) && (right != NULL)) || ((left != NULL) && (right == NULL)))
    {
        //One of you guys empty? Yes.
        return true;
    }
    else 
    {
        return false;
    }
}

template <typename Item>
bool BTNode<Item>::is_right_child()const
{
    if(data > parent->getData())
    {
        return true;
    }
    else 
    {
        return false;
    }
}