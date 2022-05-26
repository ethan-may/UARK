//---------------------------------------------------
// Purpose:     Implementation for the Cave class
// Author:      Ethan May
//---------------------------------------------------
#include "cave.h"

// Variables
   string name;
   int treasure;
   string creature;
   string food;
   string items;
   string description;
   
   int gold;
   int health;
   string item;
   int damage;
   int HPfood;

// Remove all white space from start and end of string
// Corrected code to handle empty string input - John
string trim(const string str)
{
   int start = 0;
   int end = str.length()-1;
   while ((start < str.length()) && (isspace(str[start]))) start++;
   while ((end > start) && (isspace(str[end]))) end--;
   return str.substr(start, (end-start+1));
}

Cave::Cave()
{
   count = 0;
}

Cave::~Cave()
{
}

int Cave::GetCount()
{
   return count;
}

bool Cave::ReadRooms(const string filename)
{
   // Variables
   string word;
   string word2;
   string word3;
   string word4;
   
   // TO BE ADDED
   fstream roomsIn;
   roomsIn.open("rooms.txt", ios::in);
   
   // For loop to read all the rooms
   
   roomsIn >> name;
   roomsIn >> treasure;
   roomsIn >> creature;
   roomsIn >> food;
   roomsIn >> items;
   roomsIn >> description;
   
   word = description;
   word3 = " ";
   word4 = "\n";
   int count = 0;
   // While loop for description
   while (word2 != "#")
   {
       roomsIn >> word2;
       word = word + word3 + word2;
       count = count + 1;
       word3 = " ";
       if (count == 11)
       {
           word = word + word4;
           count = 0;
           word3 = "";
       }
   }
   
   description = word;
   
   roomsIn.close();
   
   return true;
}

bool Cave::WriteRooms(const string filename)
{
   // TO BE ADDED
   fstream roomsOut;
   roomsOut.open("rooms.copy", ios::out);
   
   // For loop to repeat output text
   
   roomsOut << name << endl;
   roomsOut << treasure << endl;
   roomsOut << creature << endl;
   roomsOut << food << endl;
   roomsOut << items << endl;
   roomsOut << description;
   
   roomsOut.close();
   
   return true;
}

bool Cave::ReadMap(const string filename)
{
   // Open input file
   ifstream din;
   din.open(filename.c_str());
   if (din.fail()) 
      return false;

   // Read map information
   for (int room = 0; room < count; room++)
      for (int dir = 0; dir < MAX_DIRS; dir++)
         din >> map[room][dir];

   // Close input file
   din.close();
   return true;
}

bool Cave::WriteMap(const string filename)
{
   // Open output file
   ofstream dout;
   dout.open(filename.c_str());
   if (dout.fail()) 
      return false;

   // Write map information
   for (int room = 0; room < count; room++)
   {
      for (int dir = 0; dir < MAX_DIRS; dir++)
         dout << map[room][dir] << " ";
      dout << endl;
   }

   // Close output file
   dout.close();
   return true;
}

int Cave::VisitRoom(const int room, Player & player)
{
   ReadRooms("rooms.txt");
   WriteRooms("rooms.txt");
   
   // Player Initialize
   Player Player;
   
   // Room Initialize
   Room Room;
   
   Room.Set(name, description, treasure, creature, food, items);
   Room.Get(name, description, treasure, creature, food, items);
   Room.Print();
   
   // gold from treasure
   gold = Player.getGold();
   gold = gold + Room.FindTreasure();
   Player.setGold(gold);
   
   // health after fighting
   damage = Room.FightCreature();
   health = Player.getHealth();
   health = health - damage;
   Player.setHealth(health);
   
   // health after finding food
   HPfood = Room.EatFood();
   health = Player.getHealth();
   health = health + HPfood;
   Player.setHealth(health);
   
   // giving them the item
   item = Player.getItems();
   item = Room.PickupItem();
   if (item == "")
   {
       item = "none";
       Player.setItems(item);
   }
   else
   {
       Player.setItems(item);
   }
   
   Player.Print();
   
   return 0;
}

int Cave::NextRoom(const int room)
{
   // Error checking
   if (room < 0 || room >= count)
      return 0;

   // Prompt the user for direction
   cout << "\nWhat direction would you like to go (N,S,E,W): ";
   char direction;
   cin >> direction;
   direction = toupper(direction);
   while ((direction != 'N') && (direction != 'S') &&
          (direction != 'E') && (direction != 'W'))
   {
      cout << "Sorry, You can not go that way...\n";
      cout << "What direction would you like to go (N,S,E,W): ";
      cin >> direction;
      direction = toupper(direction);
   }

   // Return next room number
   int next = room;
   switch (direction)
   {
      case 'N': next = map[room][0]; break;
      case 'S': next = map[room][1]; break;
      case 'E': next = map[room][2]; break;
      case 'W': next = map[room][3]; break;
   }
   return next;
}
