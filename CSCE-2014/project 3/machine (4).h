#ifndef MACHINE_H
#define MACHINE_H
//-----------------------------------------------------------
// Author:  Ethan May
//-----------------------------------------------------------
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

class Machine
{
public:
   // Constructor methods --------------------------------------------
   Machine();
   Machine(string title, string manufacturer, int year, string type);
   Machine(const Machine & machine);
   ~Machine();
   
   // Get Methods ----------------------------------------------------
   string getTitle() const;
   string getManufacturer() const;
   int getYear() const;
   string getType() const;
   
   // Set Methods ----------------------------------------------------
   void setTitle(string title);
   void setManufacturer(string manufacturer);
   void setYear(int year);
   void setType(string type);
   
   // Print and Read methods -----------------------------------------
   void print() const;

private:
   // Object Attributes-----------------------------------------------
   string Title;
   string Manufacturer;
   int Year;
   string Type;
   
};
#endif