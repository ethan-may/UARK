#ifndef STACK_H
#define STACK_H
//-----------------------------------------------------------
//  Author:     Ethan May
//-----------------------------------------------------------
#include <fstream>
#include <cmath>
#include <iostream>
using namespace std;

// Stack data node definition -------------------------------
struct StackNode
{
   string str;
   StackNode *Next;
};

// Define the Stack class interface -------------------------
class Stack
{
 public:
   // Constructors
   Stack();
   Stack(const Stack & stack);
   ~Stack();

   // Methods
   bool IsFull();
   bool IsEmpty();
   
   // Methods
   void Push(string str);
   void Pop(string &str);
   void Top(string &str);
   int GetLength();
   
   // Methods
   void Print();
   void SyntaxChecker(const string file_name);
   void Read(const string file_name);

 private:
   // Object Attributes
   StackNode *Head;
   int Length;
};

#endif