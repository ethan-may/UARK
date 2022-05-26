//------------------------------------------------------------
// Purpose: Program to simulate the classic 1970s adventure game.
// Author:  Ethan May
//------------------------------------------------------------

#include "cave.h"

int main()
{
   // Initialize game
   srandom(time(NULL));

   
   // Initialize player
   Player player;
   
   player.Print();
   
   // Initialize room
   Room room;
   
   // Initialize cave
   Cave cave;
   
   cave.VisitRoom(1, player);
   
   int health = player.getHealth();
   int gold = player.getGold();
   
   // Explore cave until player wins or dies
   
   /*
   while (health > 0 && gold < MAX_GOLD)
   {
       
   }
   */

   // Print final message
   if (player.getHealth() == 0)
      cout << "\nSorry, you died exploring the cave." << endl;
   else
      cout << "\nYou leave the cave with " << MAX_GOLD << " gold coins!" << endl;
   return 0;
}
