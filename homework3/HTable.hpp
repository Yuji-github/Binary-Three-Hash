/*
 * c338047 Yuji Ishikawa
 * This Hpp file creating hash table  
 * add / compare / remove / search for remove particular words 
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>

#include "HTable.h"

template<typename Item>
HTable<Item>::HTable()
{
    for(int i = 0; i < max; i++)
    {
        arrayString[i] = new std::string(); //create array index from 0 to 149
    }
    ptr = arrayString[max];
}

template<typename Item>
HTable<Item>::HTable(const Item& newData, const int index)
{
    arrayString[index] = new std::string(newData); //store the value array index and  name value 
    ptr = arrayString[index]; //point at array index
}

template<typename Item>
HTable<Item>::~HTable()
{
    ptr = NULL;
    for(int start = 0; start < max; start++)
    {
        delete arrayString[start]; //using c++ delete function from 0 to 149
    }
}

template<typename Item>
void HTable<Item>::add(const Item& data)
{
    std::string value = data; //data is now string type data
    int index = hashFun(value); //calculating the name value 
    HTable<Item>* newTable = new HTable<Item>(value, index); //adding the value to constructor 
}

template<typename Item>
int HTable<Item>::hashFun(std::string value)
{
    int index = 0;
    std::string name = value; //to make sure the value is string (Unnecessary)
    int nameLength = name.length(); //for the below loop function 
    
    //splitting the value as a char ex) ALEX => 'A' + 'L' + 'E' + 'X'
    char* charArray = new char [nameLength+1]; 
    std::strcpy(charArray, name.c_str()); //might have a waring message, but it works due to syntax (missing 1 argument) *strcpy requires 3 arguments 
    
    for (int end = 0; end <= nameLength; nameLength--)
    {
        char a =  char (charArray[nameLength]); 
        index += (int)(a); //convert to char to int 
    }
    return index % max; //reminder values are return as the index for the array 
}

template<typename Item>
void HTable<Item>::remove(const Item& data)
{
    if(ptr == NULL)
    {
        return; //no array in this case 
    }
    else
    {
        std::string value = data; //to make sure the value is string 
        int index = hashFun(value); //call hasFun to remove the data 
        
        //if pointer and remove data is the same => gonna be a problem 
        int result = memcmp(ptr, arrayString[index], sizeof(arrayString)); //to avoid collision using cstring library memcmp is comparing heap address 
        if (result == 0) //return 0 is the same address == big NONO
        {
            do 
            {
                index++; //to remove the pointer index is ++
                ptr = arrayString[index]; // 
            }
            while (ptr->length() == 0); //ptr length 0 is nothing inside the array
        }
        
        //from here compare the given value and arrayString value
        //to compare the string values, length is okay HOWEVER, if the same length and index number but different name = compare with length does not work well
        //so compare char is better (I am not sure that ignoreCase works like "A" == 'a')
        
        char* original = new char [arrayString[index]->length()+1]; //convert to char type the stored name in the arrayString
        std::strcpy (original, arrayString[index]->c_str()); //copy the value
        
        char* removal = new char [value.length()+1]; //convert to char type the given name here 
        std::strcpy (removal, value.c_str());//copy the given name 
        
        int check = strcmp (original, removal); //if the both values are the same return with 0 (ZERO)      
        if (check == 0)
        {
            arrayString [index] = new std::string(); //delete the data
        }
    }
}

template<typename Item>
void HTable<Item>::print()
{
    for(int start = 0; start < max; start ++)
    {
        ptr = arrayString[start];
        if(ptr->length() != 0) //ptr length 0 is nothing inside the array => ignore print out 
        {
            std::cout << *ptr <<" "; //print out the value DO NOT delete * as that is saying print out the name values in the array, otherwise, it will be odd numbers like mk198741546  
        }
    }
}

template <typename Item>
std::ostream& operator <<(std::ostream& out, HTable<Item>& traveler)
{
    traveler.print(); //calling the print out function
    return out;
}


///Finals 

template <typname Item>
int LStack<Item>::removeAll (const Item& target) 
{
    int count = 0; 
    int size = size();
    int tempSize;
    LStack* temp = new LSack<Item>();
    
    if(size == 0)
    {
            return count;
    }
    
    for(int start = 0; strat < size; start++)
    {
        if(top == target)
        {
            count++; 
            pop();
        }
        temp->push(pop());
    }
    
    tempSize = temp->size();
    for(int startT = 0; startT < size; startT++)
    {
        push(temp->pop());
    }
    
    delete(temp);
    return count; 
}

template <typname Item>
void LStack<Item>::removeDuplicates () 
{
    LStack* temp1 = new LSack<Item>();
    LStack* temp2 = new LSack<Item>();
    int size = size();
    if(size==0 || size==1)
    {
        return;
    }
    
    do
    {
        temp1->push(pop());
        if(temp1->top() == top())
        {
            pop();
        }
        else
        {
            temp1->push(pop());
        }

        while(!temp1->isEmpty())
        {
            if(temp1->top() == temp2->top())
            {
                temp1->pop();
            }
            temp2->push(temp1->pop());
        }
        
        temp1->push(pop());
        
         while(!temp2->isEmpty())
        {
            if(temp2->top() == temp1->top())
            {
                temp2->pop();
            }
            temp1->push(temp2->pop());
        }
        
    }while(!isEmpty());
    delete(temp1);
    delete(temp2);
}

template <typname Item>
bool LinkedList<Item>::find (const Item& value) 
{
    bool find = false; 
    int size = size();
    
    if(size == 0)
    {
        return find; // false
    }
    
    Node* temp = NULL; //avoid memory leaks 
    do
    {
        for(temp = head; temp != NULL; temp = temp->get_next())
        {
            if (temp -> get_data() == value)
                find == true;
                return find;
        }
    }while (temp != NULL);
    
    return find; 
}

template <typname Item>
void LinkedList<Item>::removeDuplicates () 
{
    int size = size();
    Node* copy = NULL;
    if(size ==0 || size == 1)
    {
        return count;
    }
    for (copy = tail; copy !=NULL; copy->get_prev())
    {
        Node* temp = NULL;
        for(temp = head; head!= NULL; temp->get_next())
        {   
            if(temp->get_data()== copy->get_data())
            {
                temp->get_next()->set_prev(temp->get_prev());
                temp->get_prev()->set_next(temp->get_next());
                temp->set_next(NULL);
                temp->set_prev(NULL);
                delete(temp);
            }
            copy->addToHead(removeFromHead()); 
        }
        delete (temp);
    } 
    return count; 
}


int BSTree::add (BTNode* startNode) 
{
    int result = 0; 
    if(startNode == NULL)
    {
        return result; 
    }
    else
    {
        add(startNode->getLeft());
        result += startNode->getData(); 
        add(startNode->getRight());
    }
}


void BSTree::removeAll (BTNode* startNode) 
{
    if(startNode != NULL)
    {
        // go left
        removeALL(startNode->getLeft());

        // go right
        removeALL(startNode->getRight());

        // delete node
        delete startNode;
    }
}


int HashString::numHash (const string str) 
{
    int index =0; 
    for(for (int i = 0; i < str.length(); i++))
    {
        index = str.at(i);
    }
    return index % max_size;
}

bool HashString::add (const string str) 
{
    int index = numHash(str);
    if(data[index] == NULL || *data[index] == str)
    {
        data[index] = new String(str);
        return true;
    }
    return false;
}

void HashString::printAll() 
{
    for (int i = 0; i < max_size; i++)
    {
        // only if content -> print
        if (data[i] != NULL)
        {
            out << *data[i] << " ";
        }
    }
}


2-3-7-8-10-15-20
template <typname Item>
void BTree<Item>::bubbleMin(int index)
{
    int parentIndex = floor((index - 1) / 2);

    if (data[parentIndex] > data[index]) {
        swap(parentIndex, index);
        bubbleMin(parentIndex);
    }
}

template <typname Item>
void BTree<Item>::downHeap()
{
    int index = 0;
    int leftIndex = 2 * index + 1;
    int rightIndex = 2 * index + 2;
    int lastIndex = size - 1;

    int smallestIndex = index;

    if (leftIndex <= lastIndex && data[smallestIndex] > data[leftIndex]) {
        smallestIndex = leftIndex;
    }

    if (rightIndex <= lastIndex && data[smallestIndex] > data[rightIndex]) {
        smallestIndex = rightIndex;
    }

    if (index != smallestIndex) {
        swap(index, smallestIndex);
        downHeap();
    }
}