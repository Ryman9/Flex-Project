/*
* Author:  Ryan Barrington
* Purpose: This .h class is for the subclass Enemies, this file contains the constructors for enemy objects
*		   and is also a superclass of the Boss class, so its function will be inherited, some are altered.
*
*/
#ifndef ENEMIES_H
#define ENEMIES_H

#include "Character.h"

class Enemies: public Character {

public: 
    // Constructor with param and without 
    Enemies(void) {}
    Enemies(std::string aName, int aHealth, int aDamage);
    // Deconstructor 
    ~Enemies(void) {}


    // overriden attack
	int attack(Character *);
    //defeat protocal to give hero reward for beating enemy 
	std::string defeat_protocol(Character * aCharacter);
    // function to handle if hero dies
	void user_lost();
};

#endif
