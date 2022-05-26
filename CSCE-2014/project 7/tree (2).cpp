//-----------------------------------------------------------
//  Purpose:    Implementation of BinaryTree class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include "tree.h"
#include <stdlib.h>

//-----------------------------------------------------------
// Constructor function.
//-----------------------------------------------------------
BinaryTree::BinaryTree()
{
   Root = NULL;
}

//-----------------------------------------------------------
// Destructor function helper function.
//-----------------------------------------------------------
void BinaryTree::DestroyHelper(Node * Tree)
{
   // Delete node and it's children
   if (Tree != NULL)
   {
      DestroyHelper(Tree->Left);
      DestroyHelper(Tree->Right);
      delete Tree;
   }
}

//-----------------------------------------------------------
// Destructor function.
//-----------------------------------------------------------
BinaryTree::~BinaryTree()
{
   // Call tree destroy function
   DestroyHelper(Root);
}

//-----------------------------------------------------------
// Search helper function.
//-----------------------------------------------------------
bool BinaryTree::SearchHelper(string key, Machine &value, Node * Tree)
{
   // Data value not found 
   if (Tree == NULL)
      return false;

   // Data value found 
   else if (Tree->Key == key)
   {
      value = Tree->Value;
      return true;
   }

   // Recursively search for data value
   else if (Tree->Key > key)
      return (SearchHelper(key, value, Tree->Left));
   else if (Tree->Key < key)
      return (SearchHelper(key, value, Tree->Right));
   else
      return false;
}

//-----------------------------------------------------------
// Search for data in the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Search(string key, Machine &value)
{
   // Call tree searching function
   return (SearchHelper(key, value, Root));
}

//-----------------------------------------------------------
// Insert helper function.
//-----------------------------------------------------------
bool BinaryTree::InsertHelper(string key, Machine value, Node * &Tree)
{
   // Insert key and value into the tree
   if (Tree == NULL)
   {
      Tree = new Node;
      Tree->Key = key;
      Tree->Value = value;
      Tree->Left = NULL;
      Tree->Right = NULL;
      return true;
   }

   // Update value if key found
   else if (Tree->Key == key)
   {
      Tree->Value = value;
      return true;
   }

   // Recursively search for insertion position
   else if (Tree->Key > key)
      return (InsertHelper(key, value, Tree->Left));
   else if (Tree->Key <= key)
      return (InsertHelper(key, value, Tree->Right));
   else
      return false;
}

//-----------------------------------------------------------
// Insert data into the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Insert(string key, Machine value)
{
   // Call tree insertion function
   return (InsertHelper(key, value, Root));
}

//-----------------------------------------------------------
// Delete a single node from the binary tree.
//-----------------------------------------------------------
bool BinaryTree::DeleteNode(Node * &Tree)
{
   Node *Temp = Tree;

   // Node has 0 children
   if ((Tree->Left == NULL) && (Tree->Right == NULL))
      Tree = NULL;

   // Node has 1 child
   else if (Tree->Left == NULL)
      Tree = Tree->Right;
   else if (Tree->Right == NULL)
      Tree = Tree->Left;


   // Node has 2 children
   else
   {
      // Find leftmost node in right subtree
      Node *Parent = Tree;
      Temp = Tree->Right;
      while (Temp->Left != NULL)
      {
	 Parent = Temp;
	 Temp = Parent->Left;
      }

      // Replace deleted data with leftmost value
      if (Parent == Tree)
	 Parent->Right = Temp->Right;
      else
	 Parent->Left = Temp->Right;
      Tree->Key = Temp->Key;
      Tree->Value = Temp->Value;
   }

   // Delete node
   delete Temp;
   return true;
}

//-----------------------------------------------------------
// Delete helper function.
//-----------------------------------------------------------
bool BinaryTree::DeleteHelper(string key, Node * &Tree)
{
   // Data value not found
   if (Tree == NULL)
      return false;

   // Data value found and deleted
   else if (Tree->Key == key)
      return (DeleteNode(Tree));

   // Recursively search for node to delete
   else if (Tree->Key > key)
      return (DeleteHelper(key, Tree->Left));
   else if (Tree->Key < key)
      return (DeleteHelper(key, Tree->Right));
   else
      return false;
}

//-----------------------------------------------------------
// Delete data from the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Delete(string key)
{
   // Call tree deletion function
   return (DeleteHelper(key, Root));
}

//-----------------------------------------------------------
// Print helper function.
//-----------------------------------------------------------
void BinaryTree::PrintHelper(Node * Tree)
{
   // Check terminating condition
   if (Tree != NULL)
   {
      // Print left subtree
      PrintHelper(Tree->Left);

      // Print node value
      //cout << "(" << Tree->Key << "," << Tree->Value ")\n";

      // Print right subtree
      PrintHelper(Tree->Right);
   }
}

//-----------------------------------------------------------
// Print all records in the binary tree.
//-----------------------------------------------------------
void BinaryTree::Print()
{
   // Call tree printing function
   PrintHelper(Root);
   cout << endl;
}
