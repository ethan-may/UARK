//----------------------------------------------
// Author:  Ethan May
//----------------------------------------------
#include "person_node.h"

// Constructors ----------------------------------------------------------------
PersonNode::PersonNode()
{
   First = "";
   Last = "";
   Birth = 0;
   Death = 0;
   Contribution = "";
   Next = NULL;
}

//----------------------------------------------
PersonNode::PersonNode(string first, string last, int birth, int death, string contribution)
{
   First = first;
   Last = last;
   Birth = birth;
   Death = death;
   Contribution = contribution;
   Next = NULL;
}

//----------------------------------------------
PersonNode::PersonNode(const PersonNode & person)
{
   First = person.First;
   Last = person.Last;
   Birth = person.Birth;
   Death = person.Death;
   Contribution = person.Contribution;
   Next = person.Next;
}

//----------------------------------------------
PersonNode::~PersonNode()
{
}

// Get Functions ---------------------------------------------------------------
string PersonNode::getFirst() const
{
    return First;
}

//----------------------------------------------
string PersonNode::getLast() const
{
    return Last;
}

//----------------------------------------------
int PersonNode::getBirth() const
{
    return Birth;
}

//----------------------------------------------
int PersonNode::getDeath() const
{
    return Death;
}

//----------------------------------------------
string PersonNode::getContribution() const
{
    return Contribution;
}

//----------------------------------------------
PersonNode *PersonNode::getNext() const
{
    return Next;
}

// Set Functions ---------------------------------------------------------------
void PersonNode::setFirst(const string first)
{
    First = first;
}

//----------------------------------------------
void PersonNode::setLast(const string last)
{
    Last = last;
}

//----------------------------------------------
void PersonNode::setBirth(const int birth)
{
    Birth = birth;
}

//----------------------------------------------
void PersonNode::setDeath(const int death)
{
    Death = death;
}

//----------------------------------------------
void PersonNode::setContribution(const string contribution)
{
    Contribution = contribution;
}

//----------------------------------------------
void PersonNode::setNext(PersonNode * next)
{
    Next = next;
}

// Print Functions -------------------------------------------------------------
void PersonNode::printAll() const
{
    cout << "\nName: " << First << " " << Last << endl;
    if (Death == -1)
    {
        cout << "Life: " << "Born in " << Birth << " and is still alive." << endl;
    }
    else
    {
        cout << "Life: " << "Born in " << Birth << " and died in " << Death << endl;
    }
    cout << "Info: " << Contribution << endl;
   
   if (Next != NULL)
      Next->printAll();
}

//----------------------------------------------
void PersonNode::printPerson() const
{
    cout << "\nName: " << First << " " << Last << endl;
    if (Death == -1)
    {
        cout << "Life: " << "Born in " << Birth << " and is still alive." << endl;
    }
    else
    {
        cout << "Life: " << "Born in " << Birth << " and died in " << Death << endl;
    }
    cout << "Info: " << Contribution << endl;
}