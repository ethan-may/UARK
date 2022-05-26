//-----------------------------------------------------------
// Author:  Ethan May
//-----------------------------------------------------------
#include "hash.h"
#include <stdlib.h>

// Constructor methods ---------------------------------------------------------
HashTable::HashTable(int size)
{
   Size = size;
   Value = new int[Size];
   Key = new string[Size];

   for (int index = 0; index < Size; index++)
   {
      Value[index] = NONE;
      Key[index] = EMPTY;
   }
}

//-----------------------------------------------------------
HashTable::HashTable(const HashTable & ht)
{
   Size = ht.Size;
   Value = new int[Size];
   Key = new string[Size];

   for (int index = 0; index < Size; index++)
   {
      Value[index] = ht.Value[index];
      Key[index] = ht.Key[index];
   }
}

//-----------------------------------------------------------
HashTable::~HashTable()
{
   if (Value != NULL)
      delete[]Value;
   if (Key != NULL)
      delete[]Key;
   Value = NULL;
   Key = NULL;
   Size = 0;
}

// Insert Functions ------------------------------------------------------------
bool HashTable::insert(string key, int value)
{
    // Find desired key
   int index = Hash(key);
   while ((Key[index] != key) && (Key[index] != EMPTY))
      index = Hash2(index);

   // Insert value into hash table
   Value[index] = value;
   Key[index] = key;
   return true;
}

// Search Functions ------------------------------------------------------------
bool HashTable::search_h(string key, int value)
{
   // Find desired key
   int index = Hash(key);
   while ((Key[index] != key) && (Key[index] != EMPTY))
      index = Hash2(index);

   // Return value from hash table
   if (Key[index] == key)
      value = Value[index];
   return (Key[index] == key);
}

// Read File Function ----------------------------------------------------------
void HashTable::read_hash()
{
   ifstream din;
   din.open("address_1.txt");
   
   string line;
   int count = 300; 
    
    for (int temp = 1; temp < count && !din.eof(); temp++)
    {
        Address input;
        
        getline(din, line);
        insert(line, temp);
        
        getline(din, line);
        insert(line, temp);
        
        getline(din, line);
        insert(line, temp);
        
        getline(din, line);
        insert(line, temp);
        
        getline(din, line);
        insert(line, temp);
    }
   
   din.close();
}

// Hash Functions --------------------------------------------------------------
int HashTable::Hash(string key)
{
    int num = 100;
   for (int i = 0; i < int(key.length()); i++)
      num = (num * 17 + key[i]) % Size;
   return num;
}

//-----------------------------------------------------------
int HashTable::Hash2(int index)
{
    // cout << "collision\n";
    return (index + 1) % Size;
}

// Write File Function ---------------------------------------------------------
void HashTable::write_hash()
{
    ofstream dout;
    dout.open("hash_address.txt");
    
    for (int index = 0; index < Size; index++)
      if (Value[index] > 0)
	 cout << Value[index] << "\t" << Key[index] << "\n";
    
    dout.close(); 
}