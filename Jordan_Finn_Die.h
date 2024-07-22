// the Die.h file (class specification file)
// should only contain the member variables and the prototypes of the
// functions / constructor.

// Make sure to use an include guard in your Die.h file.

// NOTE: It’s important to keep in mind that this Die class could be used for other
// applications besides this Blackjack game that you are implementing.For
// example, it could be used to implement a game that requires three dice, each
// with ten sides.

#ifndef DIE_H
#define DIE_H

class Die
{
private:
     int sides; // Number of sides on the die
     int value; // The die's value

public:
     // Function prototypes:
     Die(int numSides);
     void setSides(int numSides); 
     void roll();
     int getSides() const; 
     int getValue() const;
};

#endif
