//---------------------------------------------------
// Purpose:     Implementation for the Room class
// Author:      Ethan May
//---------------------------------------------------
#include "room.h"

//------------------------------------------------------------
// Purpose: Constructor function 
// Input:   None
// Output:  None
//------------------------------------------------------------
Room::Room()
{
   Name = "none";
   Description = "none";
   Treasure = 0;
   Creature = "none";
   Food = "none";
   Item = "none";
}

//------------------------------------------------------------
// Purpose: Destructor function
// Input:   None
// Output:  None
//------------------------------------------------------------
Room::~Room()
{
   Name = "none";
   Description = "none";
   Treasure = 0;
   Creature = "none";
   Food = "none";
   Item = "none";
}

//------------------------------------------------------------
// Purpose: To set one private attribute
// Input:   Value for one private attribute
// Output:  None
//------------------------------------------------------------
void Room::SetName(const string name) { Name = name; }
void Room::SetDescription(const string description) { Description = description; }
void Room::SetTreasure(const int treasure) { Treasure = treasure; }
void Room::SetCreature(const string creature) { Creature = creature; }
void Room::SetFood(const string food) { Food = food; }
void Room::SetItem(const string item) { Item = item; }

//------------------------------------------------------------
// Purpose: To set all private attributes
// Input:   Values for all private attributes
// Output:  None
//------------------------------------------------------------
void Room::Set(const string name, const string description, const int treasure, 
      const string creature, const string food, const string item)
{
   Name = name;
   Description = description;
   Treasure = treasure;
   Creature = creature;
   Food = food;
   Item = item;
}

//------------------------------------------------------------
// Purpose: To get one private attribute
// Input:   None
// Output:  Value for one private attribute
//------------------------------------------------------------
string Room::GetName() const { return Name; }
string Room::GetDescription() const { return Description; }
int    Room::GetTreasure() const { return Treasure; }
string Room::GetCreature() const { return Creature; }
string Room::GetFood() const { return Food; }
string Room::GetItem() { return Item; }

//------------------------------------------------------------
// Purpose: To get all private attributes
// Input:   None
// Output:  Values for all private attributes
//------------------------------------------------------------
void Room::Get(string & name, string & description, int & treasure, 
      string & creature, string & food, string & item) const
{
   name = Name;
   description = Description;
   treasure = Treasure;
   creature = Creature;
   food = Food;
   item = Item;
}

//------------------------------------------------------------
// Purpose: To simulate the finding of treasure
// Input:   None
// Output:  The amount of gold found by player
//------------------------------------------------------------
int Room::FindTreasure() const
{
   int treasure = 0;
   if (Treasure > 0)
      treasure += random() % Treasure;
   if (treasure == 0)
      cout << "It does not look like there is any treasure here.\n";
   else if (treasure == 1)
      cout << "You find one small gold coin on the floor.\n";
   else if (treasure < Treasure/2)
      cout << "You find " << treasure << " gold pieces on the floor.\n";
   else
      cout << "You find a huge mound of " << treasure << " gold pieces!\n";
   return treasure;
}

//------------------------------------------------------------
// Purpose: To simulate fighting a battle with a creature
// Input:   None
// Output:  The amount health is damaged
//------------------------------------------------------------
int Room::FightCreature() const
{
   // Creature constants
   const int BUNNY_DAMAGE = 5;
   const int DWARF_DAMAGE = 10;
   const int TROLL_DAMAGE = 20;
   int damage = 0;

   if (Creature == "BUNNY")
   {
      damage = 1 + random() % BUNNY_DAMAGE;
      cout << "You trip over a cute bunny and do " 
           << damage << " damage to your health.\n";
   }
   else if (Creature == "DWARF")
   {
      damage = 1 + random() % DWARF_DAMAGE;
      cout << "A drunken dwarf hits you with a beer mug and does " 
           << damage << " damage to your health.\n";
   }
   else if (Creature == "TROLL")
   {
      damage = 1 + random() % TROLL_DAMAGE;
      cout << "An angry troll kicks you in the rear and does " 
           << damage << " damage to your health.\n";
   }
   else 
      cout << "It is ghostly quiet here, you must be alone\n";
   return damage;
}

//------------------------------------------------------------
// Purpose: To simulate eating food to restore health
// Input:   None
// Output:  The amount health is restored
//------------------------------------------------------------
int Room::EatFood() const
{
   // Food constants
   const int CANDY_RESTORE = 10;
   const int STEAK_RESTORE = 20;
   const int POTION_RESTORE = 40;
   int restore = 0;

   if (Food == "CANDY")
   {
      restore = 1 + random() % CANDY_RESTORE;
      cout << "You find a half eaten energy bar on the floor " 
           << "which restores your health by " << restore << endl;
   }         
   else if (Food == "STEAK")
   {
      restore = 1 + random() % STEAK_RESTORE;
      cout << "You eat a warm and juicy steak on the table " 
           << "which restores your health by " << restore << endl;
   }
   else if (Food == "POTION")
   {
      restore = 1 + random() % POTION_RESTORE;
      cout << "You drink a green glowing potion on a shelf " 
           << "which restores your health by " << restore << endl;
   }
   else
      cout << "Your stomach is rumbling, but there is nothing to eat\n";
   return restore;
}

//------------------------------------------------------------
// Purpose: To simulate picking up an item
// Input:   None
// Output:  The name of the item picked up
//------------------------------------------------------------
string Room::PickupItem() const
{
   string item = "";
   if (Item == "none")
      return item;

   if (random() % 2 == 0)
      cout << "On the floor you see a " << Item << " under a pile of papers\n";
   else
      cout << "In the corner you spot a " << Item << " covered in dust\n";
 
   cout << "Would you like to pick up this item (yes/no): ";
   string reply = "";
   cin >> reply;

   if ((reply == "yes") || (reply == "y"))
   {
      cout << "Great, you can put it in your backback\n";
      item = Item;
   }
   else
      cout << "Too bad, it might have been handy someday\n";
   return item;
}

//------------------------------------------------------------
// Purpose: To print all room information
// Input:   None
// Output:  None
//------------------------------------------------------------
void Room::Print() const
{
   cout << "\nRoom Information" << endl;
   cout << "Name:        " << Name << endl;
   cout << "Description: " << Description << endl;
   cout << "Treasure:    " << Treasure << endl;
   cout << "Creature:    " << Creature << endl;
   cout << "Food:        " << Food << endl;
   cout << "Item:        " << Item << endl;
}
