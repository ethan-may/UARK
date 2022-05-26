//---------------------------------------------------
// Purpose:     Header file for the Player class
// Author:      Ethan May
//---------------------------------------------------
#include <cstdlib>
#include <iostream>
using namespace std;

class Room
{
private:
   string Name;
   int Gold;
   int Health;
   string Items;

public:
   Room();
   ~Room();
   
   void selectItem1(const string item);
   void selectItem2(const string item);
   void getFood1(const int health);
   void getFood2(const int health);
   void fightCentaur(const int health, const int gold);
   void fightDragon(const int health, const int gold);
   void setHealth(const int health);
   void findFood(const int health);
   void roomOne(const int gold);
   string getroomName(const string name);
   
   void PrintFoD();
   void PrintDragonLair();
   void addItem(const string item);
};
