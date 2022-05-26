#include "machine.h"
#include "tree.h"

void read_file()
{
    cout << "\nEnter input filename: ";
    string file_name = "";
    cin >> file_name;
    cout << endl;
    
    ifstream din;
    din.open(file_name.c_str());
   
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
       
       input.print();
    }

    // Close input file
    din.close();
}

void read_file_BST()
{
    cout << "\nEnter input filename: ";
    string file_name = "";
    cin >> file_name;
    cout << endl;
    
    ifstream din;
    din.open(file_name.c_str());
   
    // Error checking for opening file
    if (din.fail())
    {
       cout << "Could not open machines.txt\n";
    }

    // Initializing Variables
    string title;
    string manufacturer;
    string year;
    string type;
    int count = 100;

    // Loop reading MACHINES text file into MACHINES vector
    for (int i = 0; i < count && !din.eof(); i++)
    {
       Machine input;
       BinaryTree Tree;
      
       getline(din, title, ',');
       input.setTitle(title);
      
       getline(din, manufacturer, ',');
       input.setManufacturer(manufacturer);
      
       getline(din, year, ',');
       input.setYear(stoi(year));
      
       getline(din, type);
       input.setType(type);
       
       Tree.Insert(title, input);
    }

    // Close input file
    din.close();
}

int main()
{
// Menu for user: START --------------------------------------------------------
   // Creating Binary Tree
   Machine input;
   BinaryTree Tree;
   
   // Loop for user interface command menu
   cout << "Welcome to Ethan's pinball and arcade database!\n";
   string command = "";
   string choice = "";
   string key = "";
   while (command != "0")
   {
      // Read user command
      cout << "\nCommand Menu:\n";
      cout << "0) Quit\n";
      cout << "1) Read file to initialize database\n";
      cout << "2) Print contents of database\n";
      cout << "3) Search database by machine title\n";
      cout << "4) Insert machine into database\n";
      cout << "5) Remove machine from database\n";
      cout << "Enter command: ";
      cin >> command;

      // Read file to initialize BST database 
      if (command == "1")
      {
         read_file_BST();
      }
      
      // Print contents of BST database 
      else if (command == "2")
      {
         Tree.Print();
      }
      
      // Search database for MACHINE TITLE
      else if (command == "3")
      {
         // making sure the getline works
         getline(cin, choice);
         
         cout << "\nWhat title would you like to search for?: ";
         getline(cin, choice);
         cout << "You selected " << choice << endl;
         
         Tree.Search(choice, input);
      }
      
      // INSERT machine into database
      else if (command == "4")
      {
         string title;
         string manufacturer;
         int year;
         string type;
         
         // making sure the getline works
         getline(cin, choice);
         
         cout << "\nEnter title name: ";
         getline(cin, title);
         input.setTitle(title);
         
         cout << "Enter manufacturer: ";
         getline(cin, manufacturer);
         input.setManufacturer(manufacturer);
         
         cout << "Enter year: ";
         cin >> year;
         input.setYear(year);
         
         cout << "Enter type (Arcade or Pinball): ";
         cin >> type;
         input.setType(type);
         
         Tree.Insert(title, input);
      }
      
      // REMOVE machine from database
      else if (command == "5")
      {
         // making sure the getline works
         getline(cin, choice);
         
         cout << "\nEnter title name: ";
         getline(cin, choice);
         
         Tree.Delete(choice);
      }
   }
// Menu for user: END ----------------------------------------------------------
   cout << "\nI hope you enjoyed the program!";

    return 0;
}
