#include <iostream>
using namespace std;

int main()
{
    // FIVE food items
    float foodItems = 0;
    float cheeseBurger;
    float chickenSandwich;
    float chickenNuggets;
    float bfastTacos;
    float bfastBurritos;
    // Food prices
    cheeseBurger = 8.25;
    chickenSandwich = 7.75;
    chickenNuggets = 7.00;
    bfastTacos = 6.25;
    bfastBurritos = 5.50;

    // FOUR drink options
    float drinkItems = 0;
    float drPepper;
    float cocaCola;
    float Sprite;
    float mtnDew;
    // Drink prices
    drPepper = 1.25;
    cocaCola = 1.25;
    Sprite = 1.00;
    mtnDew = 1.00;
    
    // THREE size choices
    float mealSizes = 0;
    float sizeSmall;
    float sizeMedium;
    float sizeLarge;
    // Size prices
    sizeSmall = 1.00;
    sizeMedium = 1.75;
    sizeLarge = 2.50;
    
    cout << "Welcome to our express lane menu! Have a look at the first menu and order with the corresponding number when ready!" << endl;
    cout << "Food Menu: \n" << "1: Double Cheese Burger Combo ($8.25)\n" << "2: Original Chicken Sandwich Combo ($7.75)\n";  
    cout << "3: 10 Piece Spicy Chicken Nuggets Combo ($7.00)\n" << "4: 3 Breakfast Tacos Meal ($6.25)\n" << "5: 2 Breakfast Burritos Meal ($5.50)\n";
    cin >> foodItems;
    
    if (foodItems == 1) {
        cout << "You have ordered a Double Cheese Burger Combo, good choice. Now what will you have to drink?" << endl;
        foodItems = cheeseBurger; }
    else if (foodItems == 2) {
        cout << "You have ordered an Original Chicken Sandwich Combo, good choice. Now what will you have to drink?" << endl;
        foodItems = chickenSandwich; }
    else if (foodItems == 3) {
        cout << "You have ordered the 10 Piece Spicy Chicken Nuggets Combo, good choice. Now what will you have to drink?" << endl;
        foodItems = chickenNuggets; }
    else if (foodItems == 4) {
        cout << "You have ordered the 3 Breakfast Tacos Meal, good choice. Now what will you have to drink?" << endl;
        foodItems = bfastTacos; }
    else if (foodItems == 5) {
        cout << "You have ordered the 2 Breakfast Burritos Meal, good choice. Now what will you have to drink?" << endl;
        foodItems = bfastBurritos; }
        
    cout << "Drink Menu: \n" << "1: Dr Pepper ($1.25)\n" << "2: Coca Cola ($1.25)\n" << "3: Sprite ($1.00)\n" << "4: Mountain Dew ($1.00)\n";
    cin >> drinkItems;
    
    if (drinkItems == 1) {
        cout << "Dr Pepper it is, now lastly, what size will your meal be?" << endl;
        drinkItems = drPepper; }
    else if (drinkItems == 2) {
        cout << "Coca Cola it is, now lastly, what size will your meal be?" << endl;
        drinkItems = cocaCola; }
    else if (drinkItems == 3) {
        cout << "Sprite it is, now lastly, what size will your meal be?" << endl;
        drinkItems = Sprite; }
    else if (drinkItems == 4) {
        cout << "Mountain Dew it is, now lastly, what size will your meal be?" << endl;
        drinkItems = mtnDew; }
    
    cout << "Sizes: \n" << "1: Small ($1.00)\n" << "2: Medium ($1.75)\n" << "3: Large ($2.50)\n";
    cin >> mealSizes;
    
    if (mealSizes == 1) {
        cout << "Small, got it!" << endl;
        mealSizes = sizeSmall; }
    else if (mealSizes == 2) {
        cout << "Medium, got it!" << endl;
        mealSizes = sizeMedium; }
    else if (mealSizes == 3) {
        cout << "Large, got it!" << endl;
        mealSizes = sizeLarge; }
    
    // Total cost calculations
    float totalCost;
    float taxCost;
    
    taxCost = .05;
    totalCost = (foodItems + drinkItems + mealSizes) + (taxCost * (foodItems + drinkItems + mealSizes));
    cout << "The total cost of your meal with 5% tax is: $" << totalCost << endl;
    
    return 0;
}
