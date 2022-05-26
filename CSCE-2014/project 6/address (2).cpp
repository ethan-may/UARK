//----------------------------------------------
// Author:  Ethan May
//----------------------------------------------
#include "address.h"

// Constructors ----------------------------------------------------------------
Address::Address()
{
   House = 0;
   Street = "";
   City = "";
   State = "";
   Zip = 0;
}

//----------------------------------------------
Address::Address(int house, string street, string city, string state, int zip)
{
   House = house;
   Street = street;
   City = city;
   State = state;
   Zip = zip;
}

//----------------------------------------------
Address::Address(const Address & address)
{
   House = address.House;
   Street = address.Street;
   City = address.City;
   State = address.State;
   Zip = address.Zip;
}

//----------------------------------------------
Address::~Address()
{
}

// Get Functions ---------------------------------------------------------------
int Address::getHouse() const
{
    return House;
}

//----------------------------------------------
string Address::getStreet() const
{
    return Street;
}

//----------------------------------------------
string Address::getCity() const
{
    return City;
}

//----------------------------------------------
string Address::getState() const
{
    return State;
}

//----------------------------------------------
int Address::getZip() const
{
    return Zip;
}

// Set Functions ---------------------------------------------------------------
void Address::setHouse(const int house)
{
    House = house;
}

//----------------------------------------------
void Address::setStreet(const string street)
{
    Street = street;
}

//----------------------------------------------
void Address::setCity(const string city)
{
    City = city;
}

//----------------------------------------------
void Address::setState(const string state)
{
    State = state;
}

//----------------------------------------------
void Address::setZip(const int zip)
{
    Zip = zip;
}

// Print and Read Functions ----------------------------------------------------
void Address::print() const
{
    // Print addresses in sorted order
    cout << House << endl
         << Street << endl
         << City << endl
         << State << endl
         << Zip << endl << endl;
}
