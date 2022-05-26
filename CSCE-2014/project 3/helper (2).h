#ifndef HELPER_H
#define HELPER_H
//-----------------------------------------------------------
// Author:  Ethan May
//-----------------------------------------------------------
#include <vector>
#include "machine.h"

class Helper
{
public:
   // Constructor methods -------------------------------
   Helper();
   ~Helper();

   // Print and Read methods ----------------------------
   void printMachines();
   void printMachinesYear();
   void readMachines();
   void readMachinesYear();
   
   // Search methods ------------------------------------
   void searchTitle(int checker);
   void searchYear();

private:
   // Object Attributes ---------------------------------
   vector<Machine> machines;
   vector<Machine> machines_year;
};
#endif