#ifndef HELPER_H
#define HELPER_H
//-----------------------------------------------------------
// Author:  Ethan May
//-----------------------------------------------------------
#include <vector>
#include "address.h"

class Helper
{
public:
   // Constructor Methods -------------------------------
   Helper();
   ~Helper();
   
   // Insertion Sort Method -----------------------------
   void insertion_sort();
   
   // Read and Write Methods ----------------------------
   void read_address();
   void write_address();

private:
   // Object Attributes ---------------------------------
   vector<Address> addresses;
};
#endif