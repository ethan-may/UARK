//---------------------------------------------------
// Purpose:     Implementationfile for the Player class
// Author:      Ethan May
//---------------------------------------------------
#include "player.h"
#include "room.h"

Room::Room()
{
   Name = "none";
   Gold = 0;
   Health = 0;
   Items = "none.";
}

Room::~Room()
{
}

void Room::selectItem1(const string name)
{
   cout << "You found Captain America's shield!\n";
}

void Room::getFood1(const int health)
{
   cout << "You eat some berries from a bush that you find.";
   Health = health + 20;
}

void Room::selectItem2(const string name)
{
   cout << "You found the cloak of invisibility!\n";
}

void Room::getFood2(const int health)
{
   cout << "You find the dragon has killed and prepared goats to " << endl
        << "eat for his dinner, so you sneakily take one on your way out.\n";
   Health = health + 100;
}

void Room::fightCentaur(const int health, const int gold)
{
   cout << "You stumble upon a wild centaur looking for his family. " << endl
        << "The centaur quickly tries to defend himself and uses his legs to attack you with a powerful kick. " << endl
        << "You lose 30 health, but he drops a bag on his way out containing 20 gold!\n";
   Health = health - 30;
   Gold = gold + 20;
}

void Room::fightDragon(const int health, const int gold)
{
   cout << "You find a dragon sleeping in his lair. When you try to leave, " << endl 
        << "you trip over a rock and wake him up... and he is not happy. " << endl
        << "The dragon shoots fire at you and takes 65 health, as you're leaving " << endl
        << "you realize it wasn't a rock you tripped over, it was a bunch of gold!\n";
   Health = health - 65;
   Gold = gold + 35;
}

void Room::findFood(const int health)
{
   cout << "You found food!\n";
}

void Room::setHealth(const int health)
{
   Health = health;
   if (Health > MAX_HEALTH) Health = MAX_HEALTH;
   if (Health < 0) Health = 0;
}

void Room::PrintFoD()
{
   cout << "\nRoom Information" << endl;
   cout << "Room Name: Forest of Despair" << endl;
   cout << "Description: " << endl;
   cout << "You enter the forest of despair.\n";
}

void Room::PrintDragonLair()
{
   cout << "\nRoom Information" << endl;
   cout << "Room Name: Dragon Lair" << endl;
   cout << "Description: " << endl;
   cout << "You enter the dragon lair.\n";
}

void Room::addItem(const string item)
{
   if (Items == "")
   {
      Items = item;
   }
   else if (item != "")
   {
      Items = Items + "," + item;
   }
}
