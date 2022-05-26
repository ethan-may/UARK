//----------------------------------------------
// Author: Ethan May
//----------------------------------------------
#include "p_list.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
// Menu for user: START --------------------------------------------------------
   List list;
   list.readFile("people.txt");
   
   cout << "Welcome to Ethan's famous computer scientist database!\n";

   // Loop processing user commands
   string command = "";
   while (command != "0")
   {
      // Read user command
      cout << "\nCommand Menu:\n";
      cout << "0) Quit\n";
      cout << "1) Print all computer scientists\n";
      cout << "2) Insert a new person\n";
      cout << "3) Sort entire list by birth year\n";
      cout << "4) Delete a person\n";
      cout << "5) Search by first name\n";
      cout << "6) Search by birth year\n";
      cout << "7) Print list into another file\n";
      cout << "Enter command: ";
      cin >> command;

      // Read through the entire text file
      if (command == "1")
      {
         list.printAll();
      }
      
      // Add new person to the linked list
      else if (command == "2")
      {
         list.insertPerson();
      }
      
      // Sort every name in list in order of birth year
      else if (command == "3")
      {
         list.sortedInsert();
         list.printAll();
      }
      
      // Remove a person from the list
      else if (command == "4")
      {
         list.deletePerson();
         list.printAll();
      }
      
      // Search list based on first name
      else if (command == "5")
      {
         list.searchFirst();
      }
      
      // Search list based on birth year
      else if (command == "6")
      {
         list.searchBirth();
      }
      
      // Print list into output file
      else if (command == "7")
      {
         list.writeFile("peopleCopy");
         return 0;
      }
   }
// Menu for user: END ----------------------------------------------------------
   
   return 0;
}
