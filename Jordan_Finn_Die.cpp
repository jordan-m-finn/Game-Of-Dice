// Remember that the class member functions/constructor should be implemented
// in the Die.cpp file(class implementation file)

#include <cstdlib> // For random function
#include <ctime> // For time function
#include "Jordan_Finn_Die.h"

// Comment 1:
// Constructor:
// This accepts an argument for the number of sides for the die and performs an initial roll of the die.
Die::Die(int numSides)
{
     sides = numSides; // This initializes the member variable with the number of sides provided by the user.
     roll(); // This performs the initial roll (The computer's side).
}

// Comment 2:
// Function:
// This accepts an argument for the number of sides for the die and performs a roll of the die.
void Die::setSides(int numSides)
{
     sides = numSides; // Set number of sides on die equal to value provided by the user.
     roll(); // This performs a roll (The user's side).
}

// Comment 3:
// Function:
// This simulates the rolling of the die. If the number of sides for the die is 6, then the die's value will be randomly chosen between 1-6.
void Die::roll()
{
     // This is the random number generator.
     srand(time(nullptr));

     // This generates a random value for the die based on the number of sides.
     value = rand() % sides + 1;
}

// Comment 4:
// Function:
// This returns the number of sides for the die.
int Die::getSides() const
{
     return sides;
}

// Comment 5:
// Function:
// This returns the die's current value.
int Die::getValue() const
{
     return value;
}