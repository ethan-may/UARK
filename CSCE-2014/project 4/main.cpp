//-----------------------------------------------------------
//  Author:     Ethan May
//-----------------------------------------------------------
#include "stack.h"

int main()
{
    Stack s;
    string input;
    int var;
    
    cout << "Welcome to Ethan's JSON file syntax checker!" << endl;
    
    // User Menu
    string command = "";
    while (command != "0")
    {
        // Read user command
        cout << "\nCommand Menu:\n";
        cout << "0) Quit\n";
        cout << "1) Check JSON file 1\n";
        cout << "2) Check JSON file 2\n";
        cout << "3) Check JSON file 3\n";
        cout << "4) Check JSON file 4\n";
        cout << "Enter command: ";
        cin >> command;
        
        // JSON file 1 ---------------------------------------------------------
        if (command == "1")
        {
            cout << "\nJSON file 1:\n";
            s.Read("input1.json");
            s.SyntaxChecker("input1.json");
            if (!s.IsEmpty())
            {
                cout << "JSON file has syntax errors." << endl;
                //s.Print();
            }
            else if (s.IsEmpty())
            {
                cout << "\nJSON file has correct syntax!" << endl;
            }
        }
        
        // JSON file 2 ---------------------------------------------------------
        else if (command == "2")
        {
            cout << "\nJSON file 2:\n";
            s.Read("input2.json");
            s.SyntaxChecker("input2.json");
            if (!s.IsEmpty())
            {
                cout << "JSON file has syntax errors." << endl;
                //s.Print();
            }
            else if (s.IsEmpty())
            {
                cout << "\nJSON file has correct syntax!" << endl;
            }
        }
        
        // JSON file 3 ---------------------------------------------------------
        else if (command == "3")
        {
            cout << "\nJSON file 3:\n";
            s.Read("input3.json");
            cout << endl;
            s.SyntaxChecker("input3.json");
            if (!s.IsEmpty())
            {
                cout << "JSON file has syntax errors." << endl;
                //s.Print();
                while (!s.IsEmpty())
                {
                    s.Pop(input);
                }
            }
            else if (s.IsEmpty())
            {
                cout << "JSON file has correct syntax!" << endl;
            }
        }
        
        // JSON file 4 ---------------------------------------------------------
        else if (command == "4")
        {
            cout << "\nJSON file 4:\n";
            s.Read("input4.json");
            s.SyntaxChecker("input4.json");
            if (!s.IsEmpty())
            {
                cout << "JSON file has syntax errors." << endl;
                //s.Print();
                while (!s.IsEmpty())
                {
                    s.Pop(input);
                }
            }
            else if (s.IsEmpty())
            {
                cout << "JSON file has correct syntax!" << endl;
            }
        }
    }

    return 0;
}
