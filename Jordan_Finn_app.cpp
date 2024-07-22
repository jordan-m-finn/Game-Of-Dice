// All of the application logic should be in the app.cpp file

// The first thing you need to do in the application program is create two
// different Die objects, because two six - sided dice are needed to play the game
// (the user and the computer SHARE the same two dice, which is why there are two
// die objects rather than four die objects).

#include "Jordan_Finn_Die.h"
#include <iostream>
#include <string>
#include <stdexcept>

// Function prototypes:
// Comment 6: The rollDice function is in charge of tracking 2 die objects for both the user and computer while also tracking their totals.
void rollDice(Die& die1, Die& die2, int& total);
// Comment 7: The blackJack function contains most of the application's logic and is specific for utilizing the Die class for the purposes of the style of game BlackJack.
// Hence, if the function were named a different popular game that uses dice, then it should be expected that the logic within that function would utilize the Die class for that specific sense.
void blackJack();

int main()
{
     // Comment 8: The main function first prompts the user of the game that will be played and then procedes to call the function for the game mentioned to perform its logic.
     std::cout << "Let's play a game of 21!" << std::endl;
     std::cout << "--------------------------------------" << std::endl;
     blackJack();

     return 0;
}

// Comment 9:
// Function:
// This rolls the two six-sided dice and updates the total.

void rollDice(Die& die1, Die& die2, int& total)
{
     die1.roll(); // Rolls the first.
     die2.roll(); // Rolls the second die.
     total += die1.getValue() + die2.getValue(); // Updates the total.
}


// Function:
// This is the logic for BlackJack
void blackJack()
{
     // This is a random number generator.
     srand(time(nullptr));

     Die die1(6); // First die object.
     Die die2(6); // Second die object.

     int computerTotal = 0;
     int userTotal = 0;

     char decision; // The user's Y or N response.

     std::cout << "Would you like to roll the dice?" << std::endl;
     std::cout << "Enter Y for yes or N for no: ";
     std::cin >> decision;
     
     // Comment 10: This is the entire logic of the game BlackJack where it iterates through several loops depending on user input.
     // Comment 11: The game begins if the user enters 'Y' which is stored in the 'decision' variable in which the rest of the loop uses to determine the following operations.
     if (decision == 'Y' || decision == 'y') 
     {
          do 
          {
               rollDice(die1, die2, userTotal);
               std::cout << "You have " << userTotal << " points." << std::endl;
               if (userTotal >= 21) 
               {
                    break; // Stop rolling if user reaches 21 or more
               }
               // Comment 12: This prompts the user asking if they'd like to roll again after their previous roll.
               std::cout << "Would you like to roll the dice?" << std::endl;
               std::cout << "Enter Y for yes or N for no: ";
               std::cin >> decision;
          } while (userTotal < 21 && (decision == 'Y' || decision == 'y'));
     }
     // Comment 13: If the user decides to answer no when first asked to roll, the game immediately ends.
     else if (decision == 'N' || decision == 'n') 
     {
          std::cout << "Game Over" << std::endl;
          return;
     }
     // Comment 14: If the user enters an invalid response the following message will be displayed.
     else 
     {
          std::cout << "Invalid input. Please enter Y or N." << std::endl;
          return;
     }

     // Comment 15: This loop ensures that the computer doesn't stop rolling "too early"
     while (computerTotal < 17) 
     {
          rollDice(die1, die2, computerTotal);
     }

     
     std::cout << "The computer has " << computerTotal << " points." << std::endl;

     // Comment 16: This if else statement takes the user and computer's totals and compares them to see who won.
     if (userTotal > 21) 
     {
          std::cout << "Better luck next time." << std::endl;
     }
     else if (computerTotal > 21 || userTotal > computerTotal) 
     {
          std::cout << "Congratulations! You won!" << std::endl;
     }
     else if (userTotal == computerTotal) 
     {
          std::cout << "It's a tie." << std::endl;
     }
     else 
     {
          std::cout << "Better luck next time." << std::endl;
     }
     std::cout << "--------------------------------------" << std::endl;
     std::cout << std::endl;
     std::cout << "Game Over" << std::endl;
}