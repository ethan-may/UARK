#ifndef PERSON_NODE_H
#define PERSON_NODE_H
//----------------------------------------------
// Author:  Ethan May
//----------------------------------------------
#include <iostream>
using namespace std;

class PersonNode
{
public:
   // Constructors -------------------------------
   PersonNode();
   PersonNode(string first, string last, int birth, int death, string contribution);
   PersonNode(const PersonNode & person);
   ~PersonNode();

   // Get Methods -------------------------------
   string getFirst() const;
   string getLast() const;
   int getBirth() const;
   int getDeath() const;
   string getContribution() const;
   PersonNode *getNext() const;
   
   // Set Methods -------------------------------
   void setFirst(const string first);
   void setLast(const string last);
   void setBirth(const int birth);
   void setDeath(const int death);
   void setContribution(const string contribution);
   void setNext(PersonNode * next);
   
   // Print Methods -----------------------------
   void printAll() const;
   void printPerson() const;

private:
   // Object Attributes -------------------------
   string First;
   string Last;
   int Birth;
   int Death;
   string Contribution;
   
   // Node Declaration --------------------------
   PersonNode *Next;
};

#endif