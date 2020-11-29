/*
 * c338047 Yuji Ishikawa
 * This hpp file creating binary tree 
 * add / compare / remove / search for remove particular words 
 */

#include <cstdlib>
#include <iostream>
#include <string>

#include "BSTree.h"

template <typename Item>
BSTree<Item>::BSTree()
{
    root = NULL; 
    leaf = 0;
}

template <typename Item>
BSTree<Item>::BSTree(const Item& data)
{
    BTNode<Item>* new_node = new BTNode<Item>(data); 
    root = new_node; //this root point at the top of the node  
    leaf = 1;
}

template <typename Item>
BSTree<Item>::~BSTree()
{
    if(root != NULL)
    {
        remove(root->getRight()); //delete right side node 
        remove(root->getLeft()); //delete left side node 
    }
    root = NULL;
}

template <typename Item>
void BSTree<Item>::remove(BTNode<Item>* current_parent)
{
    if (current_parent == NULL)
    {
        return; //no more nodes
    }
    else if(current_parent->is_leaf()) //current node is leaf 
    {
        current_parent->setParent(NULL); //set NULL
        delete current_parent; //Hasta La Vista 
    }
    else if(current_parent->has_one_child()) //node has 1 child but do not know which side is 
    {
        if(current_parent->is_right_child()) //parent node is the right side 
        {
            if(current_parent->getRight()!=NULL) 
            {
                remove(current_parent->getRight());
            }
            else
            {
                remove(current_parent->getLeft());
            }
        }
        else //parent node is the left side 
        {
            if(current_parent->getRight()!=NULL)
            {
                remove(current_parent->getRight());
            }
            else
            {
                remove(current_parent->getLeft());
            }
        }
    }
    else
    {   
        remove(current_parent->getRight()); //call remove function it self
        remove(current_parent->getLeft()); //call remove function it self
    }
}

template <typename Item>
void BSTree<Item>::add(const Item& data)
{
    std::string name = data; //data is string type here
        
    if(root == NULL)
    {
        root = new BTNode<Item>(name); //create top of the tree 
        leaf++;
    }
    else
    {
        insert(root, name); //call insert function
    }
}

template <typename Item>
int BSTree<Item>::compare(const Item& data,  const Item& parent_data) 
{
    //if data is bigger than the current parent == data right side 
    if(data > parent_data)
    {
        return -1; 
    }
    //if current parent is bigger than children == data left side 
    else if (parent_data > data)
    {
        return 1;
    }
    //if parent and children is the same == already I have the value
    else 
    {
        return 0;
    }
}

//private function 
template <typename Item>
void BSTree<Item>::insert(BTNode<Item>* current_parent, Item& data)
{
    //check which data is bigger 
    int result = compare(data, current_parent->getData()); 
    //assume the data is bigger than current_mama == go right side 
    if (result < 0)
    {
        if(current_parent->getRight() == NULL) //right side is free
        {
            //create temp node here 
            BTNode<Item>* temp = new BTNode<Item>(data); 
            
            current_parent->setRight(temp); 
            temp->setParent(current_parent); 
            
            leaf++;
            
            temp = NULL;
            return;
        }
        //assume current right is full == move to the the child node
        else
        {
            insert(current_parent->getRight(), data);
        }
    }
    
    //assume the data is smaller than current_mama == go Left side 
    else if(result > 0)
    {
        if(current_parent->getLeft() == NULL) //right side is free
        {
            //create temp node here 
            BTNode<Item>* temp = new BTNode<Item>(data); 
            
            current_parent->setLeft(temp); 
            temp->setParent(current_parent); 
            
            leaf++;
            
            temp = NULL; 
            return;
        }
        //assume current left is full == move to the the child node
        else
        {
            insert(current_parent->getLeft(), data);
        }
    }
    
    //assume the data value is already exist 
    else
    {
        current_parent->setData(data);
    }
}

template <typename Item>
bool BSTree<Item>::search(const Item& data) const
{
    if(leaf == 0)
    {
        return false;
    }
    else
    {
        return search(root, data); //calling the bottom of the search function here 
    }
}

//private function due to recursive 
template <typename Item>
bool BSTree<Item>::search(BTNode<Item>* current_parent, const Item& data) const
{
    //base case to finish this recursive function Do NOT change this other wise forever loop 
    if(current_parent == NULL)
    {
        return false; // assume there is no matching the data 
    }
    
    else
    {
        //check which data is bigger 
        int result = compare(data, current_parent->getData());
        
        if (result == 0) //if parent and children is the same
        {
            return true;
        }
        
        //assume the data is bigger than current_mama == go right side
        else if (result == -1)
        {
            return search(current_parent->getRight(), data);
        }
         
        //assume the data is smaller than current_mama == go Left side 
        else //result == 1 or 
        {
            return search(current_parent->getLeft(), data); 
        }
    }
}

template <typename Item>
bool BSTree<Item>::remove(const Item& data)
{
    //std::string name = data; //name (string) links data
    //just in case the item is existing  
    if(leaf == 0)
    {
        return false;
    }
    else //assume there is no target is false 
    {
        return remove(root, data);
    }
}

//private function 
template <typename Item>
bool BSTree<Item>::remove(BTNode<Item>* current_node, const Item& data)
{
    //base case 
    if(current_node == NULL)
    {
        //assume there is no data
        return false; 
    }
    
    //step 1 travel the tree right or left 
    // then(else)
    //step 2 has 3 cases and deleting and re-connecting nodes
    // 2-1 no children == just delete 
    // 2-2 one child is existing 
    // 2-3 both children are existing
    
    int result = compare(data, current_node->getData()); 
    // -1 is right side 
    // 0 is find 
    // 1 is right side 
      
    if (result == -1 ) // travel right side (step 1) 
    {
        remove(current_node->getRight(), data);
    }
    else if (result == 1) // travel left side (step 1) 
    {
        remove(current_node->getLeft(), data);
    }
    
    else 
    {
        //case 2-1 no children == just delete
        if(current_node->is_leaf())//assume this node is no children 
        {
            if(leaf == 1) //special case only 1 node
            {
                root = NULL;
            }

            else //other cases or end of nodes 
            {
                //which one?right or left 
                if(current_node->is_right_child()) //assume this data is right side 
                {
                    current_node->getParent()->setRight(NULL);
                    current_node->setParent(NULL);
                }
                else //assume this is left side 
                {
                    current_node->getParent()->setLeft(NULL);
                    current_node->setParent(NULL);
                }

                delete current_node; 
                leaf--;
            }
        }
            
        //case 2-2 one child is existing
        else if(current_node->has_one_child()) //assume one of leaf is exist 
        {
            //case top of the tree
            int case2; 
            case2 = compare(root->getData(), data); //compare the top of node and given data 
            if(case2 == 0) //delete the top of the tree 
            {
                if(current_node->getRight() != NULL )//assume right side is stores
                {
                    root = current_node->getRight();
                    current_node->setRight(NULL);
                    root->setParent(NULL);
                    delete current_node;
                    leaf--;
                }
                else //assume left side is stored
                {
                    root = current_node->getLeft();
                    current_node->setLeft(NULL);
                    root->setParent(NULL);
                    delete current_node;
                    leaf--;
                }
            }
            
            //general case here I assume 4 cases 
            /*
             * 
             * grandpa         grandpa           grandpa          grandpa
             *    current        current       current          current (is_right_child() function is from the GRANDPA's point of view)
             *      right      left                 right     left
             * 
             */
            else if(current_node->getRight() != NULL ) 
            {
                    current_node->getRight()->setParent(current_node->getParent());

                    if(current_node->is_right_child())
                    {
                        current_node->getParent()->setRight(current_node->getRight());
                        current_node->setRight(NULL);
                        current_node->setParent(NULL);
                        delete current_node;
                        leaf--;
                    }

                    else
                    {
                        current_node->getParent()->setLeft(current_node->getRight());
                        current_node->setRight(NULL);
                        current_node->setParent(NULL);
                        delete current_node;
                        leaf--;
                    }
            }
                    
            else //left side
            {
                current_node->getLeft()->setParent(current_node->getParent());

                if(current_node->is_right_child())
                {
                    current_node->getParent()->setRight(current_node->getLeft());
                    current_node->setLeft(NULL);
                    current_node->setParent(NULL);
                    delete current_node;
                    leaf--;
                }

                else
                {
                    current_node->getParent()->setLeft(current_node->getLeft());
                    current_node->setLeft(NULL);
                    current_node->setParent(NULL);
                    delete current_node;
                    leaf--;
                }
            }  
        }
            
        else //assume this node has 2 nodes
        {
            BTNode<Item>* temp = new BTNode<Item>();
            temp = min(current_node->getRight());
            std::string value = temp->getData(); //value is the smallest data 
            remove(temp, temp->getData()); //remove the smallest node 
            current_node->setData(value); // swap the value from the smallest to the actual delete value
            temp = NULL;
        }
        
    return true;
    }
    return false;
}
    


template <typename Item>
BTNode<Item>* BSTree<Item>::min(BTNode<Item>* current_parent)
{
    if(current_parent->getLeft() != NULL)
    {
        min(current_parent->getLeft()); //assume the left side is the smallest value IF COMPARE function works correctly 
    }
    
    else
    {
        return current_parent; //return the node 
    }    
}

//public inorder 
template <typename Item>
void BSTree<Item>::inorder()
{
    if (root == NULL )
    {
        return; 
    }
    else 
    {
        inorder(root, 0); //calling private inorder function 
    }
}

//private inorder 
template <typename Item>
void BSTree<Item>::inorder(BTNode<Item>* current_parent, int levels)
{
    if (current_parent == NULL )
    {
        return; 
    }
    
    else 
    {
        inorder(current_parent->getLeft(), levels++);
       
        std::cout<< current_parent->getData() << " "; 
        
        inorder(current_parent->getRight(), levels++);
    }
}

//calling public inorder -> private inorder function 
template <typename Item>
std::ostream& operator <<(std::ostream& out, BSTree<Item>& traveler)
{
    out<< traveler.inorder();
    return out; 
}