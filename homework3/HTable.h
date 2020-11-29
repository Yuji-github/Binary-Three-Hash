/*
 * c338047 Yuji Ishikawa
 * This H file creating binary tree 
 * add / hasfun / remove / printout 
 */

#ifndef YUJI_HTABLE_H //macrogurad 
#define YUJI_HTABLE_H //macrogurad

#include <cstdlib>
#include <iostream>
#include <string> //to make sure array type 
#include <cstring> //do not delete this for hasfun function 

const int max = 150; //global variable for the array size and hasFun loop 
std::string* arrayString[max]; //global array to store the name values

template <typename Item>
class HTable
{
    public: 
        
        //constructor 
        /*
        *pre-condition: none
        *post-condition: create constructors 
        */
        HTable();
        
        //constructor 
        /*
        *pre-condition: string(name) and int(index number for array)
        *post-condition: create constructors 
        */
        HTable(const Item& newData, const int index);
        
        //destructor
        /*
        *pre-condition: none
        *post-condition: delete array  
        */
        ~HTable();
        
        //add function
        /*
        *pre-condition: string type 
        *post-condition: store the data in the array 
        */
        void add(const Item& data);
        
        //hashfun function
        /*
        *pre-condition: string type 
        *post-condition: calculate the string value between 0 to 149 and return the number to the add function  
        */
        int hashFun(std::string value);
        
        //remove function
        /*
        *pre-condition: string type 
        *post-condition: find the array with the index number and delate 
        */
        void remove(const Item& data);
        
        //print function
        /*
        *pre-condition: none 
        *post-condition: print out from array index 0 to 149 
        */
        void print();
        
    private:
        std::string* ptr;
};

template <typename Item>
std::ostream& operator <<(std::ostream& out, HTable<Item>& traveler);

#include "HTable.hpp"
#endif