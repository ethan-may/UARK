#ifndef PERSON_H
#define PERSON_H
//-----------------------------------------------------------
// Purpose: Header file for the Person class.
//          This class is designed to store five pieces of 
//          information describing a famous person.  
// Author:  Ethan May
//-----------------------------------------------------------
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
   // Constructor methods
   Person();
   Person(const Person & person);
   ~Person();

   // Set Methods
   void SetFirst_name(const string first);
   void SetLast_name(const string last);
   void SetBirth_year(const int birth);
   void SetDeath_year(const int death);
   void SetContribution(const string contribution);
   
   // Get Methods
   string GetFirst_name() const;
   string GetLast_name() const;
   int GetBirth_year() const;
   int GetDeath_year() const;
   string GetContribution() const;

   // Other methods
   void Print_P() const;

private:
   // Object attributes
   string First;
   string Last;
   int Birth;
   int Death;
   string Contribution;

};
#endif
