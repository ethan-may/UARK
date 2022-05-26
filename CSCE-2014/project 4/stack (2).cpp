//-----------------------------------------------------------
//  Author:     Ethan May
//-----------------------------------------------------------
#include "stack.h"

//-----------------------------------------------------------
// Constructor function.
//-----------------------------------------------------------
Stack::Stack()
{
   Head = NULL;
   Length = 0;
}

// Constructor Function ------------------------------
Stack::Stack(const Stack & stack)
{
   // Create first node
   StackNode *copy = new StackNode();
   Head = copy;

   // Walk list to copy nodes
   StackNode *ptr = stack.Head;
   while (ptr != NULL)
   {
      copy->Next = new StackNode();
      copy = copy->Next;
      copy->str = ptr->str;
      copy->Next = NULL;
      ptr = ptr->Next;
   }

   // Tidy first node
   copy = Head;
   Head = copy->Next;
   delete copy;
}

// Destructor function -------------------------------
Stack::~Stack()
{
   // Walk stack deleting data
   while (Head != NULL)
   {
      StackNode *Temp = Head;
      Head = Head->Next;
      delete Temp;
   }

   // Reset head
   Head = NULL;
   Length = 0;
}

// Check to see if stack is full ---------------------
bool Stack::IsFull()
{
   return (false);
}

// Check to see if stack is empty --------------------
bool Stack::IsEmpty()
{
   return (Length == 0);
}

// Push data into the stack --------------------------
void Stack::Push(string str)
{
   // Check for full stack
   if (IsFull())
      return;

   // Allocate space for data
   StackNode *Temp = new StackNode;
   if (Temp == NULL)
      return;

   // Insert data at head of list
   Temp->str = str;
   Temp->Next = Head;
   Head = Temp;
   Length++;
}

// Pop data from the stack ----------------------------
void Stack::Pop(string &str)
{
   // Check for empty stack
   if (IsEmpty())
      return;

   // Extract information from node
   str = Head->str;

   // Pop item from linked list
   StackNode *Temp = Head;
   Head = Head->Next;
   delete Temp;
   Length--;
}

// Return data from top of stack ----------------------
void Stack::Top(string &str)
{
   // Check for empty stack
   if (IsEmpty())
      return;

   // Return information from node
   str = Head->str;
}

// Return the number of elements in stack -------------
int Stack::GetLength()
{
   return Length;
}

// Print Function -------------------------------------
void Stack::Print()
{
   // Walk the stack printing data
   cout << "stack: ";
   StackNode *Temp = Head;
   while (Temp != NULL)
   {
      cout << Temp->str << " ";
      Temp = Temp->Next;
   }
   cout << endl;
}

// JSON file syntax checker ---------------------------
void Stack::SyntaxChecker(const string file_name)
{
    ifstream din;
    din.open(file_name.c_str());
    
    char ch;
    string topper = "";
    int count = 0;
    
    // Testing Variables
    int numQ = 0;
    int numLB1 = 0;
    int numLB2 = 0;
    int numRB1 = 0;
    int numRB2 = 0;
    int testCount = 0;
    
    while (!din.eof())
    {
        din >> ch;
        
        // Checking left brackets-----------------------------------------------
        if (ch == '{' || ch == '[')
        {
            if (ch == '{')
            {
                Push("{");
                // Checking to make sure it's reading right amount
                numLB1 = numLB1 + 1;
            }
            else if (ch == '[')
            {
                Push("[");
                // Checking to make sure it's reading right amount
                numLB2 = numLB2 + 1;
            }
        }
        
        // Checking right brackets-----------------------
        if (ch == '}' || ch == ']') //potentially && numLB1 > numRB1
        {
            if (ch == '}' && numRB1 != 5)
            {
                // ADD TOP CHECK HERE
                Top(topper);
                if (topper == "{" && numLB1 == 6)
                {
                    cout << "\nError: Unmatched { found in input." << endl;
                    return;
                }
                else if (topper == "{")
                {
                    //cout << "\nTop RB1: " << topper << endl;
                    Pop(topper);
                }
                else
                {
                    cout << "\nError: Unmatched { found in input." << endl;
                    return;
                }
            
                // Checking to make sure it's reading right amount
                numRB1 = numRB1 + 1;
            }
            else if (ch == ']')
            {
                // ADD TOP CHECK HERE
                Top(topper);
                if (topper == "[")
                {
                    //cout << "\nTop RB2: " << topper << endl;
                    Pop(topper);
                }
                else
                {
                    cout << "\nError: Unmatched ] found in input." << endl;
                    return;
                }
            
                // Checking to make sure it's reading right amount
                numRB2 = numRB2 + 1;
            }
        }
        
        // Checking for double quotes ------------------------------------------
        if (ch == '"')
        {
            if (count == 0)
            {
                // NOTE TO SELF: fix dq to something else
                Push("dq");
                count = count + 1;
            }
            else if (count == 1)
            {
                Top(topper);
                if (topper == "dq")
                {
                    Pop(topper);
                    count = count - 1;
                }
                else if (topper != "dq")
                {
                    cout << "Error: Unmatched double quote found in input." << endl;
                    return;
                }
            }
            
            // Checking to make sure it's reading right amount
            numQ = numQ + 1;
        }
    }
    
    // Testing for correct amount of calls
    // cout << "\nCounts - " << "DQ: " << numQ
    //                     << ", {: " << numLB1 
    //                     << ", [: " << numLB2
    //                     << ", }: " << numRB1
    //                     << ", ]: " << numRB2
    //                     << endl;
    
    din.close();
}

// Read in JSON files and reformat it -----------------
void Stack::Read(const string file_name)
{
    ifstream din;
    din.open(file_name.c_str());
    
    char ch;
    int numC = 0;
    int numLB1 = 0; 
    int numLB2 = 0;
    int numRB1 = 0;
    int numRB2 = 0;
    int trigger = 0;
    string space = " ";
    string space1 = "  ";
    string space2 = "    ";
    string space3 = "      ";
    
    while (!din.eof())
    {
        din >> ch;
        
        if (!(ch == '{' || ch == '[' || ch == ',' || ch == '}' || ch == ']' || ch == ':'))
        {
            cout << ch;
        }
        
        // indent with brackets -------------------------------
        if (ch == '{')
        {
            numLB1 = numLB1 + 1;
            if (numLB1 == 2)
            {
                cout << endl;
                cout << space1;
            }
            else if (numLB1 == 3 && numRB1 < 1)
            {
                numLB1 = numLB1 - 1;
                numRB1 = numRB1 + 1;
                trigger = trigger + 1;
            }
            else if (numLB1 >= 3 && numLB1 <= 5)
            {
                cout << space2;
            }
            cout << ch;
            cout << endl;
            if (numLB1 == 1)
            {
                cout << space1;
            }
            else if (numLB1 == 2)
            {
                cout << space2;
            }
            else if (numLB1 >= 3 && numLB1 <= 5)
            {
                cout << space3;
            }
        }
        else if (ch == ',')
        {
            numC = numC + 1;
            cout << ch;
            cout << endl;
            if (numC <= 4)
            {
                cout << space1;
            }
            else if (numC >=5 && numC <=7)
            {
                cout << space2;
            }
            else if (numC == 8)
            {
                cout << space1;
            }
            else if (numC == 9 || numC == 11 || numC == 13)
            {
                cout << space3;
            }
            else if (numC >= 14 && numC <= 15)
            {
                cout << space1;
            }
        }
        else if (ch == '[')
        {
            numLB2 = numLB2 + 1;
            cout << endl;
            if (numLB2 == 1)
            {
                cout << space1;
            }
            cout << ch;
            cout << endl;
        }
        else if (ch == '}')
        {
            numRB1 = numRB1 + 1;
            cout << endl;
            if (numRB1 == 2 && numLB1 == 2)
            {
                cout << space2;
                numRB1 = numRB1 - 1;
            }
            else if (numRB1 == 1)
            {
                cout << space1;
            }
            else if (numRB1 >= 2 && numRB1 <= 4)
            {
                cout << space2;
            }
            else if (numRB1 == 5 && trigger == 1)
            {
                cout << space1;
            }
            else if (numRB1 > 5)
            {
                return;
            }
            cout << ch;
        }
        else if (ch == ']')
        {
            numRB2 = numRB2 + 1;
            cout << endl;
            if (numRB2 == 1)
            {
                cout << space1;
            }
            
            if (numRB1 < 4 && numRB2 == 1)
            {
                cout << space1;
                cout << ch;
                return;
            }
            else if (numRB2 > numLB2)
            {
                cout << space1;
                cout << ch;
                return;
            }
            cout << ch;
        }
        else if (ch == ':')
        {
            cout << ch;
            cout << space;
        }
        
        // NOTE TO SELF: add something to find whitespace //--------------------
    }
    
    din.close();
}
