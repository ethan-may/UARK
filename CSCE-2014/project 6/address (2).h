#ifndef ADDRESS_H
#define ADDRESS_H
//-----------------------------------------------------------
// Author:  Ethan May
//-----------------------------------------------------------
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

class Address
{
public:
   // Constructor methods -------------------------------
   Address();
   Address(int house, string street, string city, string state, int zip);
   Address(const Address & address);
   ~Address();
   
   // Get Methods -------------------------------
   int getHouse() const;
   string getStreet() const;
   string getCity() const;
   string getState() const;
   int getZip() const;
   
   // Set Methods -------------------------------
   void setHouse(const int house);
   void setStreet(const string street);
   void setCity(const string city);
   void setState(const string state);
   void setZip(const int zip);
   
   // Print and Read methods ----------------------------
   void print() const;

private:
   // Object Attributes
   int House;
   string Street;
   string City;
   string State; // already chosen to be TEXAS
   int Zip;
};
#endif