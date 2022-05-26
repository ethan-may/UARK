//-------------------------
// Author: Ethan May 
//-------------------------
#include "table.h"

Table::Table()
{
    
}

Table::~Table()
{
}

void Print_T()
{
    
}

void Table::Read_file()
{
    ifstream din;
    din.open("people.txt");
    if (din.fail())
    {
        cout << "Error: file could not be opened." << endl;
        return;
    }
    
    // Read and Print the data from people.txt
    for (int count = 0; count < 21 && count < SIZE && !din.eof(); count++)
    {
        string first, last, contribution;
        int birth, death;
        
        din >> first;
        person[count].SetFirst_name(first);
        din >> last;
        person[count].SetLast_name(last);
        din >> birth;
        person[count].SetBirth_year(birth);
        din >> death;
        person[count].SetDeath_year(death);
        getline(din, contribution);
        while (contribution[0] == ' ')
        {
            contribution.erase(0, 1);
        }
        person[count].SetContribution(contribution);
        // person[count].Print_P();
    }
}

void Table::search_first_name(string first)
{
    string search = "no";
    
    while (search == "no")
    {
        cout << "What first name would you like to search for?: ";
        cin >> first;
        cout << "Is, " << first << ", the correct name? (yes or no): ";
        cin >> search;
    }
    
    Table table;
    table.Read_file();
    
    for (int count = 0; count < 21; count++)
    {
        if (person[count].GetFirst_name() == first)
        {
            cout << "\nHere is your computer scientists information" << endl;
            person[count].Print_P();
        }
    }
}
   
void Table::search_last_name(string last)
{
    string search = "no";
    
    while (search == "no")
    {
        cout << "What last name would you like to search for?: ";
        cin >> last;
        cout << "Is, " << last << ", the correct name? (yes or no): ";
        cin >> search;
    }
    
    Table table;
    table.Read_file();
    
    for (int count = 0; count < 21; count++)
    {
        if (person[count].GetLast_name() == last)
        {
            cout << "\nHere is your computer scientists information" << endl;
            person[count].Print_P();
        }
    }
}
   
void Table::search_year(int birth)
{
    string search = "no";
    
    while (search == "no")
    {
        cout << "What birth year would you like to search for?: ";
        cin >> birth;
        cout << "Is, " << birth << ", the correct year? (yes or no): ";
        cin >> search;
    }
    
    Table table;
    table.Read_file();
    
    for (int count = 0; count < 21; count++)
    {
        if (person[count].GetBirth_year() == birth)
        {
            cout << "\nHere is your computer scientists information" << endl;
            person[count].Print_P();
        }
    }
}
