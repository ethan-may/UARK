//------------------------------------------------------------
// Purpose: Program to simulate the classic 1970s adventure game.
//          Rooms in the maze are described by separate functions.
//          The user finds gold/food as they travel, fights a
//          variety of creatures, and eventually finds the exit.
//
// Author: Ethan May
//------------------------------------------------------------

#include <cstdlib>
#include <iostream>
using namespace std;

// Food constants
const int CANDY = 0;
const int STEAK = 1;
const int POTION = 2;
const int CANDY_RESTORE = 10;
const int STEAK_RESTORE = 20;
const int POTION_RESTORE = 40;

// Creature constants
const int BUNNY = 0;
const int DWARF = 1;
const int TROLL = 2;
const int BUNNY_DAMAGE = 10;
const int DWARF_DAMAGE = 30;
const int TROLL_DAMAGE = 80;

// Other constants
const int TUITION = 50;
const int BEER = 10;

// Function prototypes
void PrintStatus(int gold, int health);
int FindTreasure(const int max_gold);
void EatFood(const int food, int &health, int &findFood);
int FightBattle(const int creature);
char GetDirection();
void Exit(int &gold, int &health); //add a food thing to each
void Room1(int &gold, int &health, int &findFood);
void Room2(int &gold, int &health, int &findFood);
void Room3(int &gold, int &health, int &findFood);
void Room4(int &gold, int &health, int &findFood);
void Room5(int &gold, int &health, int &findFood);
void Room6(int &gold, int &health, int &findFood);
void Room7(int &gold, int &health, int &findFood);

// ADD FUNCTION PROTOTYPES HERE

//------------------------------------------------------------
// Purpose: To print the player's status
// Input:   Gold amount, health value
// Output:  None
//------------------------------------------------------------
void PrintStatus(int gold, int health)
{
   if (gold > 2 * health)
      cout << endl << "You are rich with " << gold 
           << " gold, but your health is only " << health << endl;
   else if (health > 2 * gold)
      cout << endl << "You are strong with " << health 
           << " health, but you only have " << gold << " gold" << endl;
   else
      cout << endl << "Your health is " << health 
           << " and you have " << gold << " gold" << endl;
}

//------------------------------------------------------------
// Purpose: To calculate how much treasure is found
// Input:   Maximum amount of gold possible
// Output:  Actual amount of gold found
//------------------------------------------------------------
int FindTreasure(const int max_gold)
{
   int gold = 1 + random() % max_gold;
   if (gold < max_gold/2)
      cout << "\nYou find " << gold << " gold pieces on the floor.\n";
   else
      cout << "\nYou find a huge mound of " << gold << " gold pieces!\n";
   return gold;
}

//------------------------------------------------------------
// Purpose: To eating food item to restore health.
// Input:   Food item number between [0..2]
// Output:  Health value after eating food.
//------------------------------------------------------------
void EatFood(int food, int & health, int &findFood)
{
   findFood = random() % 3;
   food = findFood;
   switch (food)
   {
      case CANDY:
         health = health + CANDY_RESTORE;
         cout << "\nYou find a half eaten energy bar on the floor " 
              << "which restores your health by " << CANDY_RESTORE << endl;
         break;
      case STEAK:
         health = health + STEAK_RESTORE;
         cout << "\nYou find a warm and jucy steak on the table " 
              << "which restores your health by " << STEAK_RESTORE << endl;
         break;
      case POTION:
         health = health + POTION_RESTORE;
         cout << "\nYou find a green glowing potion on a shelf " 
              << "which restores your health by " << POTION_RESTORE << endl;
         break;
      default:
         cout << "\nYour stomach is rumbling, but there is nothing to eat\n";
         break;
   }

   // Check maximum value for health
   if (health > 100) 
      health = 100;
}

//------------------------------------------------------------
// Purpose: To simulate battle with a creature
// Input:   Creature number between [0..3]
// Output:  Amount of damage done to your health.
//------------------------------------------------------------
int FightBattle(const int creature)
{
   int damage = 0;
   switch (creature)
   {
      case BUNNY:
         damage = 1 + random() % BUNNY_DAMAGE;
         cout << "\nA ravid bunny mistakes you for grass and does " 
              << damage << " damage to your health.\n";
         break;
      case DWARF:
         damage = 1 + random() % DWARF_DAMAGE;
         cout << "\nA drunken dwarf chucks his beer mug at you for walking in and does " 
              << damage << " damage to your health.\n";
         break;
      case TROLL:
         damage = 1 + random() % TROLL_DAMAGE;
         cout << "\nAn angry troll whacks you with a giant branch and does " 
              << damage << " damage to your health.\n";
         break;
      default:
         cout << "\nIt sure seems quiet, must be an empty room.\n";
         break;
   }
   return damage;
}

//------------------------------------------------------------
// Purpose: To get direction from user
// Input:   None
// Output:  Character code for N,S,E,W direction
//------------------------------------------------------------
char GetDirection()
{
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
   return direction;
}

//------------------------------------------------------------
// Purpose: To find the cave exit
// Input:   The gold and health variables
// Output:  None
//------------------------------------------------------------
void Exit(int &gold, int &health)
{
   cout << "\n------------------------------------------------------------\n";
   cout << "\nYou crawl out of some escape door behind the bar\n";
   cout << "and full sprint back home to safety.\n"; 
   cout << "Congratulations, you made it out of the cave with " << health << " health!\n";

   if (gold >= TUITION)
   {
      cout << "\nYou empty your pockets and discover " << gold << " gold coins.\n";
      cout << "This will pay for tuition next semester!!!\n";
   }
   else if (gold >= BEER)
   {
      cout << "\nYou notice that you have " << gold << " gold coins in your pocket.\n";
      cout << "This will pay for beer and pizza next semester!!!\n";
   }
   else 
   {
      cout << "\nYou check your pocket and find " << gold << " gold coins.\n";
      cout << "Man, I thought there would be way cooler stuff in a MANSION!!!\n";
   }
   
   // Leave program
   exit(0);
}

//------------------------------------------------------------
// Purpose: MAIN HALLWAY AT ENTRANCE
// Input:   The gold and health variables
// Output:  None
// Room 1: Starting Room, decide which direction you want to go to start your journey. Should also give instructions/rules.
//------------------------------------------------------------
void Room1(int &gold, int &health, int &findFood)
{
   cout << "\n------------------------------------------------------------\n";
   cout << "\nYou just waltzed into the front doors of an abandoned castle. When you\n";
   cout << "spark up a match, you realize it's not just SOME mansion. In fact,\n";
   cout << "it's the oldest mansion the land has had in centuries. As you\n";
   cout << "take a look around, you decide it might be fun to explore the rest of the castle.\n";

   // ADD CODE HERE
   
   PrintStatus(gold, health); //Recursion call

   cout << "Choose which direction you want to go to: (N,S,E,W)" << endl;
   char d = GetDirection();
   
   switch (d)
   {
       case 'N': 
            cout << "You can't go that way, try again." << endl;
            Room1(gold, health, findFood);
            
            break;
   
       case 'S':
            cout << "You went South." << endl;
            Room4(gold, health, findFood);
            
            break;
            
       case 'E':
            cout << "You went East." << endl;
            Room2(gold, health, findFood);
            
            break;
       case 'W': 
            cout << "You went West." << endl;
            Room3(gold, health, findFood);
            
            break;
   }
}

//------------------------------------------------------------
// Purpose: KING AND QUEEN BEDROOM
// Input:   The gold and health variables
// Output:  None
// Room 2: Fight Bunny, lose 1-10 HP, steal coins that bunny had.
//------------------------------------------------------------
void Room2(int &gold, int &health, int &findFood)
{
   cout << "\n------------------------------------------------------------\n";
   cout << "\nYou wandered into the King and Queens master bedroom.\n";
   cout << "This room is way bigger than most of the other rooms, so\n";
   cout << "big that there are actually roots and grass growing all throughout the room.\n";
   cout << "As you procede to look around in awe, you start to let your guard down.\n";
   cout << "Something rustles in the grass, you remember you might not be alone here.\n";

   // Health/Damage and Gold Interections
   health = health - FightBattle(0);
   gold = FindTreasure(10);
   
   PrintStatus(gold, health);
   
   cout << "Choose which direction you want to go to: (N,S,E,W)" << endl;
   char d = GetDirection();
   
   switch (d)
   {
       case 'N': 
            cout << "You can't go that way, try again." << endl;
            Room2(gold, health, findFood);
            
            break;
   
       case 'S':
            cout << "You went South." << endl;
            Room4(gold, health, findFood);
            
            break;
            
       case 'E':
            cout << "You went East." << endl;
            Room5(gold, health, findFood);
            
            break;
       case 'W': 
            cout << "You can't go that way, try again." << endl;
            Room2(gold, health, findFood);
            
            break;
   }
}

//------------------------------------------------------------
// Purpose: WINE CELLAR
// Input:   The gold and health variables
// Output:  None
// Room 3: Fight Dwarf, lose 1-30 HP, gain HP and steal coins.
//------------------------------------------------------------
void Room3(int &gold, int &health, int &findFood)
{
   cout << "\n------------------------------------------------------------\n";
   cout << "\nYou have entered the prized wine cellar. As you wander around, you come to\n";
   cout << "find all the bottles are still perfectly in place, but some are empty,\n";
   cout << "and some are still full. You hear someone coming and duck behind a table to hide.\n";

   // Health/Damage and Gold Interections
   health = health - FightBattle(1);
   gold = FindTreasure(25);

   PrintStatus(gold, health);
   
   cout << "Choose which direction you want to go to: (N,S,E,W)" << endl;
   char d = GetDirection();
   
   switch (d)
   {
       case 'N': 
            cout << "You can't go that way, try again." << endl;
            Room3(gold, health, findFood);
            
            break;
   
       case 'S':
            cout << "You went South." << endl;
            Room7(gold, health, findFood);
            
            break;
            
       case 'E':
            cout << "You went East." << endl;
            Room4(gold, health, findFood);
            
            break;
       case 'W': 
            cout << "You went West." << endl;
            Room6(gold, health, findFood);
            
            break;
   }
}

//------------------------------------------------------------
// Purpose: THRONE ROOM WITH TROLL
// Input:   The gold and health variables
// Output:  None
// Room 4: Fight Troll, lose 1-100 HP (Can potentially 1 shot), gain 15 HP and steal coins (coins = damage taken / 2).
//------------------------------------------------------------
void Room4(int &gold, int &health, int &findFood)
{
   cout << "\n------------------------------------------------------------\n";
   cout << "\nYou have entered the throne room. In the middle\n";
   cout << "of the room there is a giant wooden throne with\n";
   cout << "intricate carvings. As you take a closer look at the\n";
   cout << "carvings, you see that they show humans using trolls as slaves.\n";
   cout << "You get a shiver and feel a chill run down your spine.\n";
   cout << "This probably isn't the best place to stay. You need to get out, NOW!\n";

   // Health/Damage and Gold Interections
   health = health - FightBattle(2);
   gold = gold + FindTreasure(40);
   
   // Food for health up
   if (findFood > 0)
   {
       int answer;
       cout << "\nYou found food! Would you like to eat it to gain more health?: (1 = yes, 0 = no) ";
       cin >> answer;
       if (answer = 1 && findFood < 1)
       {
           EatFood(gold, health, findFood);
       }
       else if (answer = 1 && findFood < 2)
       {
           EatFood(gold, health, findFood);
       }
       else if (answer = 1 && findFood >= 2)
       {
           EatFood(gold, health, findFood);
       }
       else if (answer == 0)
       {
           cout << "Not hungry I see, your loss!\n";
       }
   }

   PrintStatus(gold, health);
   
   cout << "Choose which direction you want to go to: (N,S,E,W)" << endl;
   char d = GetDirection();
   
   switch (d)
   {
       case 'N': 
            cout << "You can't go that way, try again." << endl;
            Room4(gold, health, findFood);
            
            break;
   
       case 'S':
            cout << "You went South." << endl;
            Room7(gold, health, findFood);
            
            break;
            
       case 'E':
            cout << "You went East." << endl;
            Room5(gold, health, findFood);
            
            break;
       case 'W': 
            cout << "You went West." << endl;
            Room6(gold, health, findFood);
            
            break;
   }
}

//------------------------------------------------------------
// Purpose: WALK IN STORAGE CLOSET
// Input:   The gold and health variables
// Output:  None
// Room 5: Fight bunny, lose 1-10 HP, find Treasure Chest! gain 30 coins and get full health from treasure chest, also steal coins from bunny.
//------------------------------------------------------------
void Room5(int &gold, int &health, int &findFood)
{
   cout << "\n------------------------------------------------------------\n";
   cout << "\nYou have entered a huge storage room filled with empty boxes\n";
   cout << "and clutter. Looking at the side of one box, you see 'Troll Food'.\n";
   cout << "As you take a closer look, you see something shiny hidden behind\n";
   cout << "all the boxes... A Treasure Chest! Quick, take your earnings and\n";
   cout << "leave while you still can!\n";

   // Health/Damage and Gold Interections
   health = health - FightBattle(0);
   gold = gold + FindTreasure(10) + 25;
   
   // Food for health up
   if (findFood > 0)
   {
       int answer;
       cout << "\nYou found food! Would you like to eat it to gain more health?: (1 = yes, 0 = no) ";
       cin >> answer;
       if (answer = 1 && findFood < 1)
       {
           EatFood(gold, health, findFood);
       }
       else if (answer = 1 && findFood < 2)
       {
           EatFood(gold, health, findFood);
       }
       else if (answer = 1 && findFood >= 2)
       {
           EatFood(gold, health, findFood);
       }
       else if (answer = 0)
       {
           cout << "Not hungry I see, your loss!\n";
       }
   }

   PrintStatus(gold, health);
   
   cout << "Choose which direction you want to go to: (N,S,E,W)" << endl;
   char d = GetDirection();
   
   switch (d)
   {
       case 'N': 
            cout << "You can't go that way, try again." << endl;
            Room5(gold, health, findFood);
            
            break;
   
       case 'S':
            cout << "You went South." << endl;
            Room7(gold, health, findFood);
            
            break;
            
       case 'E':
            cout << "You can't go that way, try again." << endl;
            Room5(gold, health, findFood);
            
            break;
       case 'W': 
            cout << "You went West." << endl;
            Room4(gold, health, findFood);
            
            break;
   }
}

//------------------------------------------------------------
// Purpose: BATHROOM
// Input:   The gold and health variables
// Output:  None
// Room 6: Fight Bunny, lose 1-10 HP, steal coins and no HP.
//------------------------------------------------------------
void Room6(int &gold, int &health, int &findFood)
{
   cout << "\n------------------------------------------------------------\n";
   cout << "\nYou have entered a ginormous bathroom with a shower bigger than\n";
   cout << "your entire bathroom back home. As you peak inside the shower,\n";
   cout << "you see it's become a bunny sanctuary now. It's time to go.\n";

   // Health/Damage and Gold Interections
   health = health - FightBattle(0);
   gold = gold + FindTreasure(10);
   
   // Food for health up
   if (findFood > 0)
   {
       int answer;
       cout << "\nYou found food! Would you like to eat it to gain more health?: (1 = yes, 0 = no) ";
       cin >> answer;
       if (answer = 1 && findFood < 1)
       {
           EatFood(gold, health, findFood);
       }
       else if (answer = 1 && findFood < 2)
       {
           EatFood(gold, health, findFood);
       }
       else if (answer = 1 && findFood >= 2)
       {
           EatFood(gold, health, findFood);
       }
       else if (answer = 0)
       {
           cout << "Not hungry I see, your loss!\n";
       }
   }

   PrintStatus(gold, health);
   
   cout << "Choose which direction you want to go to: (N,S,E,W)" << endl;
   char d = GetDirection();
   
   switch (d)
   {
       case 'N': 
            cout << "You went North." << endl;
            Room4(gold, health, findFood);
            
            break;
   
       case 'S':
            cout << "You went South." << endl;
            Exit(gold, health);
            
            break;
            
       case 'E':
            cout << "You went East." << endl;
            Room7(gold, health, findFood);
            
            break;
       case 'W': 
            cout << "You can't go that way, try again." << endl;
            Room6(gold, health, findFood);
            
            break;
   }
}

//------------------------------------------------------------
// Purpose: BAR/HANGOUT ROOM
// Input:   The gold and health variables
// Output:  None
// Room 7: Fight Dawrf, lose 1-30 HP, steal coins and HP.
//------------------------------------------------------------
void Room7(int &gold, int &health, int &findFood)
{
   cout << "\n------------------------------------------------------------\n";
   cout << "\nYou have stumbled apon the secret bar. There are countless\n";
   cout << "amounts of broken mugs and dirty dishes all over the place.\n";
   cout << "You go to check the bar to see if there is anything left, but\n";
   cout << "you hear someone coming in, you quickly duck behind the bar.\n";

   // Health/Damage and Gold Interections
   health = health - FightBattle(1);
   gold = gold + FindTreasure(25);
   
   // Food for health up
   if (findFood > 0)
   {
       int answer;
       cout << "\nYou found food! Would you like to eat it to gain more health?: (1 = yes, 0 = no) ";
       cin >> answer;
       if (answer = 1 && findFood < 1)
       {
           EatFood(gold, health, findFood);
       }
       else if (answer = 1 && findFood < 2)
       {
           EatFood(gold, health, findFood);
       }
       else if (answer = 1 && findFood >= 2)
       {
           EatFood(gold, health, findFood);
       }
       else if (answer == 0)
       {
           cout << "Not hungry I see, your loss!\n";
       }
   }

   PrintStatus(gold, health);
   
   cout << "Choose which direction you want to go to: (N,S,E,W)" << endl;
   char d = GetDirection();
   
   switch (d)
   {
       case 'N': 
            cout << "You can't go that way, try again." << endl;
            Room7(gold, health, findFood);
            
            break;
   
       case 'S':
            cout << "You went South." << endl;
            Exit(gold, health);
            
            break;
            
       case 'E':
            cout << "You can't go that way, try again." << endl;
            Room7(gold, health, findFood);
            
            break;
       case 'W': 
            cout << "You went West." << endl;
            Room6(gold, health, findFood);
            
            break;
   }
}

// ADD FUNCTIONS HERE

//------------------------------------------------------------
// Purpose: The main program
// Input:   None
// Output:  None
//------------------------------------------------------------
int main()
{
   // Initialize game
   int gold = 0;
   int health = 100;
   int findFood;
   srandom(time(NULL));

   // ADD CODE HERE
   Room1(gold, health, findFood);

   return 0;
}
