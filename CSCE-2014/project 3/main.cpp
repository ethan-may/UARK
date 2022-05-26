//----------------------------------------------
// Author: Ethan May
//----------------------------------------------

#include "helper.h"

// ------------------------------ MAIN FUNCTION -------------------------------- 
int main()
{
// Menu for user: START --------------------------------------
   // Declraring Class
   Helper helper;
   
   // Reading in both text files
   helper.readMachines();
   helper.readMachinesYear();

   // Loop for user interface command menu
   cout << "Welcome to Ethan's binary search pinball machine!\n";
   string command = "";
   string choice = "";
   while (command != "0")
   {
      // Read user command
      cout << "\nCommand Menu:\n";
      cout << "0) Quit\n";
      cout << "1) Use a recursive binary search for Game Title\n";
      cout << "2) Use an iterative search for all machines manufactured in a specific year\n";
      cout << "3) Print file(s) components\n";
      cout << "Enter command: ";
      cin >> command;

      // Search for GAME TITLE using a Recursive Binary Search 
      if (command == "1")
      {
         helper.searchTitle(0);
      }
      
      // Search for specific YEAR using an Iterative Binary Search 
      else if (command == "2")
      {
         helper.searchYear();
      }
      
      // Print the list(s)
      else if (command == "3")
      {
         // User interface for printing options
         cout << "\nPrinting Options:\n";
         cout << "1) Print only machines.txt (all machine names)\n";
         cout << "2) Print only machines_year.txt (all machine years)\n";
         cout << "3) Print both text files\n";
         cout << "What would you like to print?: ";
         cin >> choice;
         
         if (choice == "1")
         {
            cout << "\n--------------------------------------------------------\n";
            cout << "Machines.txt: \n";
            cout << "\n";
            helper.printMachines();
         }
         else if (choice == "2")
         {
            cout << "\n";
            cout << "--------------------------------------------------------\n";
            cout << "Machines_year.txt: \n";
            cout << "\n";
            helper.printMachinesYear();
         }
         else if (choice == "3")
         {
            cout << "\n--------------------------------------------------------\n";
            cout << "Machines.txt: \n";
            cout << "\n";
            helper.printMachines();
            cout << "\n";
            cout << "--------------------------------------------------------\n";
            cout << "Machines_year.txt: \n";
            cout << "\n";
            helper.printMachinesYear();
         }
      }
   }
// Menu for user: END -----------------------------------------
   cout << "\nI hope you enjoyed the program!";
   
   return 0;
}
