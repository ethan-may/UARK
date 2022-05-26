//-----------------------------------------------------------
// Author:  Ethan May
//-----------------------------------------------------------
#include "p_list.h"

// Constructor methods ---------------------------------------------------------
List::List()
{
   if (DEBUG) cout << "Table::constructor\n";
   count = 0;
}

//-----------------------------------------------------------
List::List(const List & list)
{
   if (DEBUG) cout << "Table::copy\n";
   count = list.count;
   for (int index=0; index<count; index++)
      data[index] = list.data[index];
}

//-----------------------------------------------------------
List::~List()
{
   if (DEBUG) cout << "Table::destructor\n";
}

// Print Functions -------------------------------------------------------------
void List::printAll() const
{
   if (DEBUG) cout << "Table::print\n";
   PersonNode *next = new PersonNode();
   next = Head->getNext();
   next->printAll();
}

//-----------------------------------------------------------
void List::printPerson() const
{
    PersonNode *next = new PersonNode();
    next = Head->getNext();
    next->printPerson();
}

// Read File Function ----------------------------------------------------------
void List::readFile(string file_name)
{
   if (DEBUG) cout << "Table::read\n";
   
   ifstream din;
   din.open(file_name.c_str());
   
   string first;
   string last;
   int birth;
   int death;
   string contribution;
   count = 0;
   
   while (!din.eof() && count < 21)
   {
       din >> first;
       din >> last;
       din >> birth;
       din >> death;
       getline(din, contribution);
       
       PersonNode *temp = new PersonNode(first, last, birth, death, contribution);
       PersonNode *tail = new PersonNode();
       
       tail = Head->getNext();
       temp->setNext(tail);
       Head->setNext(temp);
   }
   din.close();
}

// Insert Functions ------------------------------------------------------------
void List::insertAtHead(string first, string last, int birth, int death, string contribution)
{
    // Insert new node from insertPerson at head
    PersonNode *ptr = new PersonNode(first, last, birth, death, contribution);
    ptr->setNext(Head);
    Head = ptr;
}

//-----------------------------------------------------------
void List::insertPerson()
{
    string first = "";
    string last = "";
    int birth = 0;
    int death = 0;
    string contribution = "";
    
    string choice = "yes";
    while (choice != "no")
    {
        cout << "\nCreate your person and add them to the list!" << endl;
        
        cout << "Enter FIRST name: ";
        cin >> first;
        
        cout << "Enter LAST name: ";
        cin >> last;
        
        cout << "Enter year of BIRTH: ";
        cin >> birth;
        
        cout << "Enter year of DEATH: ";
        cin >> death;
        
        cout << "Enter the person's CONTRIBUTION to the world: ";
        cin >> contribution;
        
        // insertAtHead(first, last, birth, death, contribution);
        
        PersonNode *temp = new PersonNode(first, last, birth, death, contribution);
        PersonNode *tail = new PersonNode();
       
        tail = Head->getNext();
        temp->setNext(tail);
        Head->setNext(temp);
        
        printAll();
        
        cout << "\nWould you like to create another person? ('yes' or 'no'): ";
        cin >> choice;
    }
}

//-----------------------------------------------------------
void List::sortedInsert()
{
   string first;
   string last;
   int birth = 1791;
   int death;
   string contribution;
   
   PersonNode *curr = Head;
   PersonNode *prev = Head;
   curr = curr->getNext();
   while (curr != NULL)
   {
      if (curr->getBirth() < birth)
      {
          PersonNode *ptr = new PersonNode(first, last, birth, death, contribution);
          if (curr == Head)
          {
              Head->setNext(ptr);
              ptr->setNext(curr);
          }
          else
          {
              prev->setNext(ptr);
              ptr->setNext(curr);
          }
      }
      
      prev = curr;
      curr = curr->getNext();
   }

   if (curr == NULL)
   {
       PersonNode *ptr = new PersonNode(first, last, birth, death, contribution);
       prev->setNext(ptr);
   }
}

// Delete Function -------------------------------------------------------------
bool List::deletePerson()
{
    string first;
    string last;
    int choice;
    
    cout << "\nWould you like to delete a person from your current list or "
         << "out of everyone?" << endl;
    cout << "1. Current List\n";
    cout << "2. Everyone\n";
    cout << "(1 or 2): ";
    cin >> choice;
    if (choice == 1)
    {
        cout << "Enter FIRST name: ";
        cin >> first;
        cout << "Enter LAST name: ";
        cin >> last;
    }
    else if (choice == 2)
    {
        cout << "Enter FIRST name: ";
        cin >> first;
        cout << "Enter LAST name: ";
        cin >> last;
    }
    
    PersonNode *curr = Head;
    PersonNode *prev = Head;
    curr = curr->getNext();
    
    while ((curr != NULL) && (curr->getFirst() != first) && (curr->getLast() != last))
    {
        prev = curr;
        curr = curr->getNext();
    }
    
    if (curr == NULL)
    {
        return false;
    }
    
    if (curr == Head)
    {
        Head = curr->getNext();
    }
    else
    {
        prev->setNext(curr->getNext());
    }
    
    delete curr;
    return true;
}

// Search Functions ------------------------------------------------------------
void List::searchFirst() const
{
   if (DEBUG) cout << "Table::search_first_name\n";
   string first;
   cout << "\nWho would you like to search for? (first name): ";
   cin >> first;
   
   PersonNode *search = Head;
   search = search->getNext();
   while ((search != NULL) && (search->getFirst() != first))
   {
       search = search->getNext();
       if (search == NULL)
       {
           cout << "That person is not in the list.. Please try again.\n";
           cout << "Search for first name: ";
           cin >> first;
       }
   }
   
   search->printPerson();
}

//-----------------------------------------------------------
void List::searchBirth() const
{
   if (DEBUG) cout << "Table::search_year\n";
   int birth;
   cout << "\nWhat birth year would you like to search for? (1791 - 1984): ";
   cin >> birth;
   
   PersonNode *search = Head;
   search = search->getNext();
   
   if (search == NULL)
    {
        cout << "There is no one with that birth year.. Please try again.\n";
        cout << "Search for birth year: ";
        cin >> birth;
    }
       
   while (search != NULL)
   {
      if (((search->getBirth()) < (birth + 10)) && ((search->getBirth()) > (birth - 10)))
      {
          search->printPerson();
      }
      
      search = search->getNext();
   }
}

// Write File Function ---------------------------------------------------------
void List::writeFile(const string file_name)
{
    ofstream dout;
    dout.open(file_name.c_str());
    
    string first;
    string last;
    int birth;
    int death;
    string contribution;
    
    PersonNode *curr = Head;
    PersonNode *prev = Head;
    curr = curr->getNext();
    
    while (curr != NULL)
    {
        dout << curr->getFirst() << " ";
        dout << curr->getLast() << " | ";
        dout << curr->getBirth() << " ";
        dout << curr->getDeath() << " | ";
        dout << curr->getContribution() << endl;
        curr = curr->getNext();
    }
    
    dout.close(); 
}