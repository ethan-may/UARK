#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

float Power(float Num, int exponent)
{
   cout << "Entering power " << Num << " " << exponent << endl;
   float Return = 0;
   float temp;

   // Check terminating conditions
   if (exponent == 0)
      Return = 1;

   else if (exponent == 1)
      Return = Num;

   // Handle recursive cases
   else if (exponent < 0)
   {
      Return = 1 / pow(Num, -exponent);
   }
   else if (exponent % 2 == 0)
   {
      temp = pow(Num, exponent / 2);
      Return = temp * temp;
   }
   else if (exponent % 2 == 1)
   {
      float temp = pow(Num, exponent / 2);
      Return = Num * temp * temp;
   }

   cout << "Leaving power " << Num << " " << exponent << endl;
   return Return;
}

int main()
{
    // Prompt input for Num
    float Num;
    int exponent;
    int var;

    // Testing Power Function -------------------
    cout << "Enter value: ";
    cin >> Num;
    cout << "Enter exponent: ";
    cin >> exponent;
    var = Power(Num, exponent);
    cout << "\nPower: " << var << endl;

    return 0;
}
