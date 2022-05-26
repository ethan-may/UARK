//-------------------------
// Author: Ethan May 
//-------------------------
#include "person.h"

Person::Person()
{
    string First = "none";
    string Last = "none";
    int Birth = 0;
    int Death = 0;
    string Contribution = "none";
}

Person::~Person()
{
}

void Person::SetFirst_name(const string first)
{
    First = first;
}

void Person::SetLast_name(const string last)
{
    Last = last;
}

void Person::SetBirth_year(const int birth)
{
    Birth = birth;
}

void Person::SetDeath_year(const int death)
{
    Death = death;
}

void Person::SetContribution(const string contribution)
{
    Contribution = contribution;
}

string Person::GetFirst_name() const
{
    return First;
}

string Person::GetLast_name() const
{
    return Last;
}

int Person::GetBirth_year() const
{
    return Birth;
}

int Person::GetDeath_year() const
{
    return Death;
}

string Person::GetContribution() const
{
    return Contribution;
}

void Person::Print_P() const
{
    cout << "Name: " << First << " " << Last << endl;
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
