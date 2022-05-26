//----------------------------------------------
// Purpose: Demonstrate recursive flood fill
// Author:  John Gauch
//----------------------------------------------
#include <iostream>
using namespace std;

// Global variables
const int ROWS = 20;
const int COLS = 20;
char pixel[ROWS][COLS];

//----------------------------------------------
void fill(int r, int c, char value)
{
   // Check first terminating condition
   if ((r < 0) || (r >= ROWS) || (c < 0) || (c >= COLS))
      return;

   // Check second terminating condition
   else if (pixel[r][c] == value)
      return;

   // Handle recursive case
   else
   {
      cout << r << " " << c << endl;
      pixel[r][c] = value;

      // ADD HERE
      fill(r, c + 1, value);
      fill(r, c - 1, value);
      fill(r + 1, c, value);
      fill(r - 1, c, value);
   }
}

//----------------------------------------------
void print()
{
   for (int r = 0; r < ROWS; r++)
   {
      for (int c = 0; c < COLS; c++)
	 if (pixel[r][c] != 0)
	    cout << pixel[r][c];
	 else
	    cout << '.';
      cout << endl;
   }
}

//----------------------------------------------
int main()
{
   fill(0, 0, '#');
   print();
   return 0;
}
