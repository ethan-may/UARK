//------------------------------------------------------------
// Purpose: Program to simulate the classic 1970s adventure game.
//          Rooms in the maze are described by separate functions.
//          The user finds gold/food as they travel, fights a
//          variety of creatures, and eventually finds the exit.
//
// Author: Ethan May
//------------------------------------------------------------

#include "player.h"
#include "room.h"
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
   // Initialize game
   srandom(time(NULL));

   // Create room1
   Room room;
   
   // Create player
   Player player;
   player.setName("Red Shirt Guy");
   player.setGold(0);
   player.setHealth(MAX_HEALTH);
   player.setItems("");
 
   // Call Player methods
   player.addItem("compass");
   player.Print();

   // Call Room methods
   room.PrintFoD();
   room.fightCentaur(50,50);
   player.setHealth(MAX_HEALTH - 30);
   room.findFood(100);
   
   //player.setHealth();
   player.setGold(20);
   string itemChoice1;
   room.selectItem1("Captain America's shield");
   cout << "Do you want to take the item? (Y or N)\n";
   cin >> itemChoice1;
   if (itemChoice1 == "y" || itemChoice1 == "Y")
   {
      cout << "you have acquired Captain America's shield!\n";
      player.addItem("Captain America's shield");
   }
   else if (itemChoice1 == "n" || itemChoice1 == "N")
   {
      cout << "you did not take Captain America's shield... you're never gonna live this down.\n";
   }
   else
   {
      cout << "you did not enter a valid answer, no shield for you.\n";
   }
   
   cout << "Do you want to eat the food? F.Y.I. - Food replinishes your health! (Y or N)\n";
   string foodChoice1;
   cin >> foodChoice1;
   if (foodChoice1 == "y" || foodChoice1 == "Y")
   {
      
      room.getFood1(75 + 20);
      player.setHealth(MAX_HEALTH - 5);
   }
   else if (foodChoice1 == "n" || foodChoice1 == "N")
   {
      cout << "So you don't want food, not a wise choice.\n";
   }
   else 
   {
      cout << "Next time you should choose a correct answer, no food for you.\n";
   }
   player.Print();
   
   // Call Room methods
   room.PrintDragonLair();
   room.fightDragon(50,25);
   
   // Call Player methods
   player.setHealth(MAX_HEALTH - 65);
   room.findFood(100);
   player.setGold(55);
  
   string itemChoice2;
   room.selectItem2("cloak of invisibility");
   cout << "Do you want to take the item? (Y or N)\n";
   cin >> itemChoice2;
   if (itemChoice2 == "y" || itemChoice2 == "Y")
   {
      cout << "you have acquired the cloak of invisibility!\n";
      player.addItem("cloak of invisibility");
   }
   else if (itemChoice2 == "n" || itemChoice2 == "N")
   {
      cout << "Well, you passed up the opportunity to be invisible.\n";
   }
   else
   {
      cout << "you did not enter a valid answer, no invisibility cloak for you.\n";
   }
   
   cout << "Do you want to eat the food? F.Y.I. - Food replinishes your health! (Y or N)\n";
   string foodChoice2;
   cin >> foodChoice2;
   if (foodChoice2 == "y" || foodChoice2 == "Y")
   {
      
      room.getFood2(75 + 20);
      player.setHealth(MAX_HEALTH);
   }
   else if (foodChoice2 == "n" || foodChoice2 == "N")
   {
      cout << "So you don't want food, not a wise choice.\n";
   }
   else 
   {
      cout << "Next time you should choose a correct answer, no food for you.\n";
   }
   player.Print();

   return 0;
}
