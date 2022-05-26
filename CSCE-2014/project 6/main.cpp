//-----------------------------------------------------------
// Author:  Ethan May
//-----------------------------------------------------------
#include "helper.h"
#include "hash.h"

int main()
{
    Helper helper;
    
    int size = 300;
    HashTable hash(2 * size);

// Menu for user: START --------------------------------------------------------
    cout << "Welcome to Ethan's address finder!\n"; // tweek this later
    
    string command = "";
    while (command != "0")
    {
       // Read user command
       cout << "\nCommand Menu:\n";
       cout << "0) Quit\n";
       cout << "1) Call the address read and write functions\n";
       cout << "2) Call the hash read and write functions\n";
       cout << "3) Search hash table by zip code\n"; 
       cout << "Enter command: ";
       cin >> command;

       // Call ADDRESS read and write
       if (command == "1")
       {
           helper.read_address();
           helper.write_address();
       }
      
       // Call HASH TABLES read and write
       else if (command == "2")
       {
           hash.read_hash();
           hash.write_hash();
       }
      
       // Search the Hash Table
       else if (command == "3")
       {
           cout << "\nWhat zip code would you like to search for?: ";
           string zip;
           cin >> zip;
           int value = 1;
           hash.read_hash();
           hash.search_h(zip, value);
       }
    }
// Menu for user: END ----------------------------------------------------------

    return 0;
}
