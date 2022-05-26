#ifndef P_LIST_H
#define P_LIST_H
//-----------------------------------------------------------
// Author:  Ethan May
//-----------------------------------------------------------
#include "person_node.h"
#include <iostream>
#include <fstream>
using namespace std;

class List
{
public:
   // Constructor methods -------------------------------
   List();
   List(const List & list);
   ~List();

   // Print and Read methods ----------------------------
   void printAll() const;
   void printPerson() const;
   void readFile(const string file_name);

   // Insert methods ------------------------------------
   void insertAtHead(string first, string last, int birth, int death, string contribution);
   void insertPerson();
   void sortedInsert();
   
   // Delete method -------------------------------------
   bool deletePerson();
   
   // Search methods ------------------------------------
   void searchFirst() const;
   void searchBirth() const;
   
   // Write Method --------------------------------------
   void writeFile(const string file_name);

private:
   // Debugging flag ------------------------------------
   static const bool DEBUG = false;  

   // Object attributes ---------------------------------
   static const int TABLE_SIZE = 30;
   PersonNode data[TABLE_SIZE];
   PersonNode *Head;
   int count;
   
};
#endif