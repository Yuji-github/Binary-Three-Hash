//TreeHashTableDemo - Main Program
/******************************/
//Author: SENG1120 Staff
//Course: SENG1120
//Program Description: This program demonstrates the basic functionality of binary seach trees and hash tables. 

#include <iostream>
#include <cstdlib>
#include <time.h>
#include "BSTree.h"
#include "HTable.h"
using namespace std;

int main()
{
	clock_t t;
	BSTree<string> treeValues;
	HTable<string> tableValues;

	string vectorStudents[] = {"Alex", "John", "Mary", "Peter" , "Miranda" , "Claudia" , "Sandy" , "Daniel" , "Rick" , "Patricia" , "Adam" , "Bianca" , "Nadia", "Sylvia", "Pamela", "Travis", "Michelle", "Steve", "Phil", "Hugh", "Oliver", "Kate", "Tim", "David", "Ingrid", "Tom", "Fred", "Bill"};
	int numberOfElements = 28;
	
	cout << "==================" << endl << "BINARY SEARCH TREE" << endl;
	t = clock(); // gets current time

	for (int i=0; i<numberOfElements; i++) 
	{
		treeValues.add(vectorStudents[i]);
	} // populates the tree.
    
    cout << "Initial tree: " << treeValues << endl; // prints the contents of the tree.

    for (int i=0; i<500000; i++)
    { // add and remove over and over again
       	treeValues.remove("Alex");
			treeValues.remove("Peter");
			treeValues.remove("John");
			treeValues.remove("Pamela");
			treeValues.remove("Kate");
			treeValues.remove("Tim");
			treeValues.remove("Steve");
			treeValues.remove("Rick");
			treeValues.remove("Sam");
       	treeValues.add("Alex");
			treeValues.add("Peter");
			treeValues.add("John");
			treeValues.add("Pamela");
			treeValues.add("Kate");
			treeValues.add("Tim");
			treeValues.add("Steve");
			treeValues.add("Rick");
	}
	
	cout << "Final tree  : " << treeValues << endl << endl; // prints the contents of the tree.
	cout << "Time elapsed: " << (clock() - t)/1000.0 << " seconds" << endl; // prints elapsed time.
	cout << "Time per ins/del operation: " << 1000.0*(double)(clock() - t)/(double)(500000*17) << " milliseconds." << endl << endl;


	cout << "==================" << endl << "HASH TABLE" << endl;
	t = clock(); // gets current time
	
	for (int i=0; i<numberOfElements; i++) 
	{
		tableValues.add(vectorStudents[i]);
	} // populates the hash table.
	
	cout << "Initial hash table: " << tableValues << endl; // prints the contents of the hash table.

	for (int i=0; i<500000; i++)
	{ // add and remove over and over again
        tableValues.remove("Alex");
			tableValues.remove("Peter");
			tableValues.remove("John");
			tableValues.remove("Pamela");
			tableValues.remove("Kate");
			tableValues.remove("Tim");
			tableValues.remove("Steve");
			tableValues.remove("Rick");
			tableValues.remove("Sam"); //might remove Steve if implementation is not done properly.
        tableValues.add("Alex");
			tableValues.add("Peter");
			tableValues.add("John");
			tableValues.add("Pamela");
			tableValues.add("Kate");
			tableValues.add("Tim");
			tableValues.add("Steve");
			tableValues.add("Rick");
	}

	cout << "Final hash table  : " << tableValues << endl << endl; // prints the contents of the hash table.
	cout << "Time elapsed: " << (clock() - t)/1000.0 << " seconds" << endl; // prints elapsed time.
	cout << "Time per ins/del operation: " << 1000.0*(double)(clock() - t)/(double)(500000*17) << " milliseconds." << endl << endl;
	cout << "The program has finished." << endl;
	
	return 0;
}