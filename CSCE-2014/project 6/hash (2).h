#ifndef HASH_H
#define HASH_H
//-----------------------------------------------------------
// Author:  Ethan May
//-----------------------------------------------------------
#include "address.h"
#include "helper.h"
const int NONE = 0;
const string EMPTY = "-1";
const string DELETED = "-2";

class HashTable
{
public:
   // Constructor methods -------------------------------
   HashTable(int size);
   HashTable(const HashTable & ht);
   ~HashTable();
   
   // Insert method -------------------------------------       
   bool insert(string key, int value);
   
   // Search Method -------------------------------------
   bool search_h(string key, int value);
   
   // Write Method --------------------------------------
   void read_hash();
   void write_hash();

private:
   // Private Methods ----------------------------------- 
   int Hash(string key);
   int Hash2(int index);
   
   // Object attributes ---------------------------------
   int Size;
   int *Value;
   string *Key;
};
#endif