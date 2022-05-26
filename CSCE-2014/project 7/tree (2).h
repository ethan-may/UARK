#ifndef TREE_H
#define TREE_H

//-----------------------------------------------------------
//  Purpose:    Header file for the BinaryTree class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include <iostream>
#include <fstream>
using namespace std;
#include "machine.h"

//-----------------------------------------------------------
// BinaryTree data node definition
//-----------------------------------------------------------
class Node
{
 public:
   string Key;
   Machine Value;
   Node *Left;
   Node *Right;
};

//-----------------------------------------------------------
// Define the BinaryTree class interface 
//-----------------------------------------------------------
class BinaryTree
{
 public:
   // Constructor functions
   BinaryTree();
    ~BinaryTree();

   // General binary tree operations
   bool Search(string key, Machine &value);
   bool Insert(string key, Machine value);
   bool Delete(string key);
   void Print();

 private:
   // Helper functions
   void DestroyHelper(Node * Tree);
   bool SearchHelper(string key, Machine &value, Node * Tree);
   bool InsertHelper(string key, Machine value, Node * &Tree);
   bool DeleteNode(Node * &Tree);
   bool DeleteHelper(string key, Node * &Tree);
   void PrintHelper(Node * Tree);

   // Tree pointer
   Node *Root;
};

#endif