//----------------------------------------------
// Author:  Ethan May
//----------------------------------------------
#include "machine.h"

// Constructors ----------------------------------------------------------------
Machine::Machine()
{
   Title = "";
   Manufacturer = "";
   Year = 0;
   Type = "";
}

//----------------------------------------------
Machine::Machine(string title, string manufacturer, int year, string type)
{
   Title = title;
   Manufacturer = manufacturer;
   Year = year;
   Type = type;
}

//----------------------------------------------
Machine::Machine(const Machine & machine)
{
   Title = machine.Title;
   Manufacturer = machine.Manufacturer;
   Year = machine.Year;
   Type = machine.Type;
}

//----------------------------------------------
Machine::~Machine()
{
}

// Get Functions ---------------------------------------------------------------
string Machine::getTitle() const
{
    return Title;
}

//----------------------------------------------
string Machine::getManufacturer() const
{
    return Manufacturer;
}

//----------------------------------------------
int Machine::getYear() const
{
    return Year;
}

//----------------------------------------------
string Machine::getType() const
{
    return Type;
}

// Set Functions ---------------------------------------------------------------
void Machine::setTitle(const string title)
{
    Title = title;
}

//----------------------------------------------
void Machine::setManufacturer(const string manufacturer)
{
    Manufacturer = manufacturer;
}

//----------------------------------------------
void Machine::setYear(const int year)
{
    Year = year;
}

//----------------------------------------------
void Machine::setType(const string type)
{
    Type = type;
}

// Print Function --------------------------------------------------------------
void Machine::print() const
{
    // cout << Title << "," << Manufacturer << "," << Year << ","
    //      << Type << endl;
    cout << Title << ", a " << Type << " machine, was manufactured by "
         << Manufacturer << " in " << Year << ".\n";
}
