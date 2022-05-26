//---------------------------------------------------
// Purpose: Implement menu-based spreadsheet program.
// Author:  Ethan May
//---------------------------------------------------

#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

// Global constants
const int ROWS = 9;
const int COLS = 9;
float myArray[ROWS+ 1][COLS+ 1];

//---------------------------------------------------
// Read and convert location string to row col value
//---------------------------------------------------
void get_location(int &row, int &col)
{
   // Initialize variables
   row = -1;
   col = -1;

   // Loop until a valid location is entered
   while (row < 0 || row > ROWS-1 || col < 0 || col > COLS-1)
   {
      // Get user input
      cout << "Enter location between A1 and I9 to put your value: " << endl;
      string location = "";
      cin >> location;
   
      // Calculate col between 0 and COLS-1
      if (location.length() > 0)
         col = location[0] - 'A';
 
      // Print error message
      if (col < 0 || col > COLS-1)
         cout << "Error: column should be between A and I" << endl;

      // Calculate row between 0 and ROWS-1
      if (location.length() > 1)
         row = location[1] - '1';
 
      // Print error message
      if (row < 0 || row > ROWS-1)
         cout << "Error: row should be between 1 and 9" << endl;
   }
}

//---------------------------------------------------
// Print command menu to user and get input
//---------------------------------------------------
int get_menu_choice()
{
   // Print command menu
   cout << "Welcome to MiniCalc the PF1 Killer App\n"
        << "   0) Quit the program\n"
        << "   1) Store specified data value\n"
        << "   2) Store random data values\n"
        << "   3) Calculate minimum of data values\n"
        << "   4) Calculate maximum of data values\n"
        << "   5) Calculate sum of data values\n"
        << "   6) Calculate product of data values\n"
        << "   7) Calculate average of data values\n"
        << "   8) Calculate standard deviation of data values\n";

   // Initialize variables
   string input = "";
   int command = -1;

   // Loop until a valid location is entered
   while (command < 0 || command > 8)
   {
      // Get user input
      cout << "Enter command: ";
      cin >> input;
      if (input.length() == 1)
         command = input[0] - '0';

      // Print error message
      if (command < 0 || command > 8)
         cout << "Error: command should be between 0 and 8" << endl;
   }
   return command;
}

// function to print array line
void printArrayBorder()
{
    string arrayBorder = "   +---+---+---+---+---+---+---+---+---+";
    cout << arrayBorder << endl;
}

// function to print full array
void printArray()
{
    string xAxis = "     A   B   C   D   E   F   G   H   I";
    cout << xAxis << endl;
    
    string allign = " | ";
    string allignLeft = "| ";
    
    //------------------------------- start printing array HERE -------------------------------//
    printArrayBorder();
    cout << " 1 " << allignLeft << myArray[0][0] << allign << myArray[0][1] << allign << myArray[0][2] << allign << myArray[0][3] << allign
         << myArray[0][4] << allign << myArray[0][5] << allign << myArray[0][6] << allign << myArray[0][7] << allign << myArray[0][8] << allign << endl;
         
    printArrayBorder();
    cout << " 2 " << allignLeft << myArray[1][0] << allign << myArray[1][1] << allign << myArray[1][2] << allign << myArray[1][3] << allign
         << myArray[1][4] << allign << myArray[1][5] << allign << myArray[1][6] << allign << myArray[1][7] << allign << myArray[1][8] << allign << endl;
    
    printArrayBorder();
    cout << " 3 " << allignLeft << myArray[2][0] << allign << myArray[2][1] << allign << myArray[2][2] << allign << myArray[2][3] << allign
         << myArray[2][4] << allign << myArray[2][5] << allign << myArray[2][6] << allign << myArray[2][7] << allign << myArray[2][8] << allign << endl;
         
    printArrayBorder();
    cout << " 4 " << allignLeft << myArray[3][0] << allign << myArray[3][1] << allign << myArray[3][2] << allign << myArray[3][3] << allign
         << myArray[3][4] << allign << myArray[3][5] << allign << myArray[3][6] << allign << myArray[3][7] << allign << myArray[3][8] << allign << endl;
         
    printArrayBorder();
    cout << " 5 " << allignLeft << myArray[4][0] << allign << myArray[4][1] << allign << myArray[4][2] << allign << myArray[4][3] << allign
         << myArray[4][4] << allign << myArray[4][5] << allign << myArray[4][6] << allign << myArray[4][7] << allign << myArray[4][8] << allign << endl;
         
    printArrayBorder();
    cout << " 6 " << allignLeft << myArray[5][0] << allign << myArray[5][1] << allign << myArray[5][2] << allign << myArray[5][3] << allign
         << myArray[5][4] << allign << myArray[5][5] << allign << myArray[5][6] << allign << myArray[5][7] << allign << myArray[5][8] << allign << endl;
         
    printArrayBorder();
    cout << " 7 " << allignLeft << myArray[6][0] << allign << myArray[6][1] << allign << myArray[6][2] << allign << myArray[6][3] << allign
         << myArray[6][4] << allign << myArray[6][5] << allign << myArray[6][6] << allign << myArray[6][7] << allign << myArray[6][8] << allign << endl;
         
    printArrayBorder();
    cout << " 8 " << allignLeft << myArray[7][0] << allign << myArray[7][1] << allign << myArray[7][2] << allign << myArray[7][3] << allign
         << myArray[7][4] << allign << myArray[7][5] << allign << myArray[7][6] << allign << myArray[7][7] << allign << myArray[7][8] << allign << endl;
         
    printArrayBorder();
    cout << " 9 " << allignLeft << myArray[8][0] << allign << myArray[8][1] << allign << myArray[8][2] << allign << myArray[8][3] << allign
         << myArray[8][4] << allign << myArray[8][5] << allign << myArray[8][6] << allign << myArray[8][7] << allign << myArray[8][8] << allign << endl;
         
    printArrayBorder();
}

// function to find range for store value
void userRange(int &row1, int &col1, int &row2, int &col2)
{
    row1 = 0;
    row2 = 0;
    col1 = 0;
    col2 = 0;
    
    string startRange;
    string endRange;
    
    cout << "Here you are going to input the range of the values you want to find! (Use format 'A1, B1...')" << endl;
    
    //------ determining the STARTING range ------//
    cout << "First, input the point you want to start at: ";
    cin >> startRange;
    cout << startRange.at(0) << startRange.at(1) << endl;
    
    col1 = startRange.at(0) - 'A';
    row1 = startRange.at(1) - 49;
    
    while (!((isalpha (startRange.at(0))) && (isdigit (startRange.at(1))) && ((col1 >= 0) && (col1 <= 8)) && ((row1 >= 0) && (row1 <= 8))))
    {
        cout << "Whoops! I don't think I know what that means. Try again using the format 'A1', 'B6', 'C4',..." << endl;
        cin >> startRange;
        
        col1 = startRange.at(0) - 'A';
        row1 = startRange.at(1) - 49;
    }
    
    //------- determining the ENDING range -------//
    cout << "Now, input the point you want to end with: ";
    cin >> endRange;
    cout << endRange.at(0) << endRange.at(1) << endl;
    
    col2 = endRange.at(0) - 'A';
    row2 = endRange.at(1) - 49;
    
    while (!((isalpha (endRange.at(0))) && (isdigit (endRange.at(1))) && ((col2 >= 0) && (col2 <= 8)) && ((row2 >= 0) && (row2 <= 8))))
    {
        cout << "Whoops! I don't think I know what that means. Try again using the format 'A1', 'B6', 'C4',..." << endl;
        cin >> endRange;
        
        col2 = endRange.at(0) - 'A';
        row2 = endRange.at(1) - 49;
    }
    
    // makes sure it is in the correct range
    if (!((col1 <= col2) && (row1 <= row2)))
    {
        cout << "Sorry, it seems that range is not valid." << endl;
        col1 = 10;
        col2 = 10;
        row1 = 10;
        row2 = 10;
    }
}

// function to store specified value
void store_specific_value(int &row, int &col)
{
    printArray();
    
    cout << "What value do you want to put here?: ";
    
    int inputVal = 0;
    cin >> inputVal;
    
    myArray[row][col] = inputVal;
}

// function to randomize values for the function that randomly stores value 
int randomize_value()
{
    int randomize = rand()%10;
    
    return randomize;
}

//function to store randomized value
void store_random_value()
{
    int row1;
    int row2;
    int col1;
    int col2;
    
    // calling to function userRange to find the range of value to find
    userRange(row1, col1, row2, col2);
    
    for (int a = row1; a <= row2; a++)
    {
        for (int i = col1; i <= col2; i++)
        {
            myArray[a][i] = randomize_value();
        }
    }
}

// function to calculate minimum
int calc_min()
{
    int row1;
    int row2;
    int col1;
    int col2;
    
    // calling to function userRange to find the range of value to find
    userRange(row1, col1, row2, col2);
   
    int min;
    min = myArray[0][0];
    for (int a = row1; a <= row2; a++)
    {
        for (int i = col1; i <= col2; i++)
        {
            if (myArray[a][i] < min)
            {
                min = myArray[a][i];
            }
        }
    }
    
    return min;
}

// function to calculate maximum
int calc_max()
{
    int row1;
    int row2;
    int col1;
    int col2;
    
    // calling to function userRange to find the range of value to find
    userRange(row1, col1, row2, col2);
   
    int max;
    max = myArray[0][0];
    for (int a = row1; a <= row2; a++)
    {
        for (int i = col1; i <= col2; i++)
        {
            if (myArray[a][i] > max)
            {
                max = myArray[a][i];
            }
        }
    }
    
    return max;
}

// function to calculate sum
int calc_sum()
{
    int row1;
    int row2;
    int col1;
    int col2;
    
    // calling to function userRange to find the range of value to find
    userRange(row1, col1, row2, col2);
   
    int sum = 0;
    for (int a = row1; a <= row2; a++)
    {
        for (int i = col1; i <= col2; i++)
        {
            sum = sum + myArray[a][i];
        }
    }
    
    return sum;
}

// function to calculate product
int calc_product()
{
    int row1;
    int row2;
    int col1;
    int col2;
    
    // calling to function userRange to find the range of value to find
    userRange(row1, col1, row2, col2);
   
    int product = 1;
    for (int a = row1; a <= row2; a++)
    {
        for (int i = col1; i <= col2; i++)
        {
            product = product * myArray[a][i];
        }
    }
    
    return product;
}

// function to calculate average
float calc_average()
{
    int row1;
    int row2;
    int col1;
    int col2;
    
    // calling to function userRange to find the range of value to find
    userRange(row1, col1, row2, col2);
   
    float average;
    float sum = 0;
    float count = 0;
    for (int a = row1; a <= row2; a++)
    {
        for (int i = col1; i <= col2; i++)
        {
            sum = sum + myArray[a][i];
            count = count + 1;
        }
    }
    
    average = sum / count;
    
    return average;
}

// function to calculate standard deviation
float calc_sd()
{
    int row1;
    int row2;
    int col1;
    int col2;
    
    // calling to function userRange to find the range of value to find
    userRange(row1, col1, row2, col2);
   
    float sd = 0;
    float average = 0;
    float sum = 0;
    float count = 0;
    float var = 0;
    
    for (int a = row1; a <= row2; a++)
    {
        for (int i = col1; i <= col2; i++)
        {
            sum = sum + myArray[a][i];
            count = count + 1;
        }
    }
    
    average = sum / count;
    
    for (int a = row1; a <= row2; a++)
    {
        for (int i = col1; i <= col2; i++)
        {
            var = var + pow(myArray[a][i] - average, 2);
        }
    }
    
    sd = sqrt(var / count);
    
    return sd;
}

// place answer where user inputs
void answer_placement(int &row, int &col, int &command)
{
    float answer;
    float min;
    float max;
    float sum;
    float average;
    float product;
    float sd;
    
    switch (command)
    {
         case 3:
         {
             min = calc_min();
             cout << "The minimum of these values are: " << min << endl;
             get_location(row, col);
             myArray[row][col] = min;
             printArray();
             break;
         }
         case 4:
         {
             max = calc_max();
             cout << "The maximum of these values are: " << max << endl;
             get_location(row, col);
             myArray[row][col] = max;
             printArray();
             break;
         }
         case 5:
         {
             sum = calc_sum();
             cout << "The sum of these values are: " << sum << endl;
             get_location(row, col);
             myArray[row][col] = sum;
             printArray();
             break;
         }
         case 6:
         {
             product = calc_product();
             cout << "The product of these values are: " << product << endl;             
             get_location(row, col);
             myArray[row][col] = product;
             printArray();
             break;
         }
         case 7:
         {
             average = calc_average();
             cout << "The average of these values are: " << average << endl;
             get_location(row, col);
             myArray[row][col] = average;
             printArray();
             break;
         }
         case 8:
         {
             sd = calc_sd();
             cout << "The Standard Deviation is: " << sd << endl;
             get_location(row, col);
             myArray[row][col] = sd;
             printArray();
             break;
         }
    }
}

//---------------------------------------------------
// Main program
//---------------------------------------------------
int main()
{
   //Variables
   int row;
   int col;
   int row1;
   int row2;
   int col1;
   int col2;
   float min;
   float max;
   float sum;
   float average;
   float product;
   float sd;
   
   // Initialize spreadsheet array
   float data[ROWS][COLS];
   for (int row = 0; row < ROWS; row++)
   for (int col = 0; col < COLS; col++)
      data[row][col] = 0;
   
   // testing the print array
   printArray();

   // Loop processing menu commands
   int command = get_menu_choice();
   while (command != 0)
   {
      switch (command)
      {
         case 1:
         {
            get_location(row, col);
            store_specific_value(row, col);
            printArray();
            break;
         }
         case 2:
         {
            store_random_value();
            printArray(); 
            break;
         }
         case 3:
         {
             answer_placement(row, col, command);
             break;
         }
         case 4:
         {
             answer_placement(row, col, command);
             break;
         }
         case 5:
         {
             answer_placement(row, col, command);
             break;
         }
         case 6:
         {
             answer_placement(row, col, command);
             break;
         }
         case 7:
         {
             answer_placement(row, col, command);
             break;
         }
         case 8:
         {
             answer_placement(row, col, command);
             break;
         }
      }

      // Get next command
      command = get_menu_choice();
   }
   return 0;
}
