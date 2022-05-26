#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    //Volume of the dumbell//
    float sphereVolume;
    float dumbellVolume;
    float cylinderVolume;
    float sphereRadius;
    float cylinderRadius;
    float cylinderLength;
    
    cout << "What is the radius of the sphere in centimeters? ";
    cin >> sphereRadius;
    cout << "What is the radius of the cylinder in centimeters? ";
    cin >> cylinderRadius;
    cout << "What is the length of the cylinder in centimeters? ";
    cin >> cylinderLength;
    
    sphereVolume = (4 * M_PI * pow(sphereRadius, 3)) / 3;
    cylinderVolume = (M_PI * cylinderLength * pow(cylinderRadius, 2));
    dumbellVolume = (sphereVolume * 2) + cylinderVolume;
    
    //mass of dumbell in four metals//
    float massAlluminum;
    float massIron;
    float massLead;
    float massCopper;
    
    massAlluminum = 2.7;        //grams per centimeter cubed//
    massIron = 7.874;           //grams per centimeter cubed//
    massLead = 10.678;          //grams per centimeter cubed//
    massCopper = 8.96;          //grams per centimeter cubed//
    
    cout << "The volume of the sphere is: " << sphereVolume << " centimeters cubed" << endl;
    cout << "The volume of the cylinder is : " << cylinderVolume << " centimeters cubed" << endl;
    cout << "The volume of the dumbell is: " << dumbellVolume << " centimeters cubed" <<endl;
    cout << "These 4 metals are the mass values in the dumbell: Alluminum, Iron, Lead, and Copper." << endl;        
    cout << "The density of Alluminum is: " << massAlluminum << " grams per centimeter cubed" << endl;
    cout << "The density of Iron is: " << massIron << " grams per centimeter cubed" << endl;
    cout << "The density of Lead is: " << massLead << " grams per centimeter cubed" << endl;
    cout << "The density of Copper is: " << massCopper << " grams per centimeter cubed" << endl;
    
    return 0;
}
