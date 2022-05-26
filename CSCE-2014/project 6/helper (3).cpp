//-----------------------------------------------------------
// Author:  Ethan May
//-----------------------------------------------------------
#include "helper.h"

// Constructors ----------------------------------------------------------------
Helper::Helper()
{
    
}

//----------------------------------------------
Helper::~Helper()
{
    
}

// Insert Sort Function --------------------------------------------------------
void Helper::insertion_sort()
{
    // // Insert each element of unsorted list into sorted list
    // for (int unsorted = 1; unsorted <= 300; unsorted++)
    // {
    //     // Select unsorted value to be inserted
    //     int value = addresses[unsorted];
    //     int posn = unsorted;

    //     // Make room for new data value
    //     while ((posn > 0) && (addresses[posn - 1] > value))
    //     {
	   //    addresses[posn] = addresses[posn - 1];
	   //    posn--;
    //     }

    //     // Put new value into array
    //     addresses[posn] = value;
    // }
}

// Read Method -----------------------------------------------------------------
void Helper::read_address()
{
    ifstream din;
    din.open("address_1.txt");
    
    string line;
    int count = 300; //subject to change due to max amount of addresses
    
    for (int i = 1; i < count && !din.eof(); i++)
    {
        Address input;
        
        getline(din, line);
        input.setHouse(stoi(line));
        
        getline(din, line);
        input.setStreet(line);
        
        getline(din, line);
        input.setCity(line);
        
        getline(din, line);
        input.setState(line);
        
        getline(din, line);
        input.setZip(stoi(line));
        
        addresses.push_back(input);
    }
    
    din.close();
}

// Write Method ----------------------------------------------------------------
void Helper::write_address()
{
    ofstream dout;
    dout.open("sort_address.txt");
    
    for (int i = 0; i < int(addresses.size()); i++)
    {
        addresses[i].print();
    }
    
    dout.close(); 
}
