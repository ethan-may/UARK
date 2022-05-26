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

// Print Methods ---------------------------------------------------------------
void Helper::printMachines()
{
   // Print ALL and ONLY machines.txt
   for (int i = 0; i < int(machines.size()); i++)
   {
      machines[i].print();
   }
}

//----------------------------------------------
void Helper::printMachinesYear()
{
   // Print ALL and ONLY machines_year.txt
   for (int i = 0; i < int(machines_year.size()); i++)
   {
      machines_year[i].print();
   }
}

// Read Methods ----------------------------------------------------------------
void Helper::readMachines()
{
   ifstream din;
   din.open("machines.txt");
   
   // Error checking for opening file
   if (din.fail())
   {
      cout << "Could not open machines.txt\n";
   }

   // Initializing Variables
   string line;
   int count = 100;

   // Loop reading MACHINES text file into MACHINES vector
   for (int i = 0; i < count && !din.eof(); i++)
   {
      Machine input;
      
      getline(din, line, ',');
      input.setTitle(line);
      
      getline(din, line, ',');
      input.setManufacturer(line);
      
      getline(din, line, ',');
      input.setYear(stoi(line));
      
      getline(din, line);
      input.setType(line);
      
      machines.push_back(input); // sends values to MACHINES vector //
   }

   // Close input file
   din.close();
}

//----------------------------------------------
void Helper::readMachinesYear()
{
   ifstream din;
   din.open("machines_year.txt");
   
   // Error checking for opening file
   if (din.fail())
   {
      cout << "Could not open machines_year.txt\n";
   }

   // Initializing Variables
   string line;
   int count = 100;

   // Loop reading MACHINES_YEAR text file into MACHINES_YEAR vector
   for (int i = 0; i < count && !din.eof(); i++)
   {
      Machine input;
      
      getline(din, line, ',');
      input.setTitle(line);
      
      getline(din, line, ',');
      input.setManufacturer(line);
      
      getline(din, line, ',');
      input.setYear(stoi(line));
      
      getline(din, line);
      input.setType(line);
      
      machines_year.push_back(input); // sends values to MACHINES_YEAR vector //
   }

   // Close input file
   din.close();
}

// Search Methods --------------------------------------------------------------
void Helper::searchTitle(int checker)
{
   // Making sure the getline call works
   string choice = "";
   while ((choice != "y") && (choice != "n"))
   {
       // Error checking getline function
       if (checker == 0)
       {
           getline(cin, choice);
           checker = 1;
       }
       
       cout << "\nDo you know what you want to search for? (y = yes, n = no): ";
       getline(cin, choice);
   }

   // Error checking if they cannot think of/find a name
   if (choice == "n")
   {
       cout << "\nNo worries! You can either go back and print the files for some "
            << "examples, or you can just try it anyways!" << endl;
       cout << "Would you like to continue with the search still? (y or n): ";
       getline(cin, choice);
       if (choice == "n")
       {
           return;
       }
   }
   
   // Prompt user for game title name
   string search;
   if (choice == "y")
   {
       cout << "Enter title name (use spaces if needed): ";
       getline(cin, search);
       cout << "You selected " << search << endl;
   }

   // Search MACHINE vector to find correlating game title
   cout << "\n";
   int count = 0;
   for (int i = 0; i < int(machines.size()); i++)
   {
      if ((choice == "y") && (search == machines[i].getTitle()))
      {
          machines[i].print();
          count = count + 1;
      }
   }
   
   // Error checking if user input is not in the list
   if (count == 0)
   {
       cout << "Whoops, it seems that title was not in the list. Try again.";
       searchTitle(1);
   }
}

//----------------------------------------------
void Helper::searchYear()
{
   // Prompt user for the manufacturing year for machine
   int search;
   cout << "\nEnter the machines year you want to search for (1905-1965): ";
   cin >> search;
   
   // Error checking for correct range
   int min = 1905;
   int max = 1965;
   if (search < min || search > max)
   {
       cout << "\nWhoops, that year is not in the range. Try again.";
       searchYear();
       return;
   }

   // Search MACHINE_YEAR vector to find correlating year(s)
   int count = 0;
   for (int i = 0; i < int(machines_year.size()); i++)
   {
      if (search == machines_year[i].getYear())
      {
         if (count == 0)
         {
             cout << "\nThese are the machines manufactured in " << search << ":\n";
         }
         
         count = count + 1;
         // Making the output look correct
         if (count <= 9)
         {
             cout << "         " << count << ") ";
         }
         else if (count >= 10)
         {
             cout << "        " << count << ") ";
         }
         machines_year[i].print();
      }
   }
   
   // Additional info in output for the user
   if ((count != 0) && (count >= 2))
   {
       cout << "There were " << count << " machines found that were manufactured in "
            << search << ".\n";
   }
   else if (count == 1)
   {
       cout << "There was " << count << " machine found that was manufactured in "
            << search << ".\n";
   }
   
   // Error checking if user input is not in the list
   else if (count == 0)
   {
       cout << "\nSorry, nothing was created during that year. Try again.";
       searchYear();
   }
}