#include "table.h"

int main()
{
    // Initialize Variable
    string parameter;
    int variable;
    
    // Initialize table 
    Table table;
    
    //Initialize person
    Person person;
    
    string filename = "people.txt";
    
    table.Read_file();
    
    int choice = 0;
    cout << "In this program, you can search for computer scientists by 3 different ways..." << endl;
    cout << "1) First name \n2) Last name \n3) Birth year" << endl;
    cout << "Now how would you like to search? (1, 2, 3): ";
    cin >> choice;
    if (choice == 1)
    {
        table.search_first_name(parameter);
    }
    else if (choice == 2)
    {
        table.search_last_name(parameter);
    }
    else if (choice == 3)
    {
        table.search_year(variable);
    }
    
    return 0;
}
