/*
* Author:  Ryan Barrington
* Purpose: This .h class is for the subclass Bosses, this file contains the constructors for boss objects
*		   and is also a subclass of the Enemies class, so it enherits functions from Enemies, that is used and some are altered.
*
*/
#ifndef BOSSES_H
#define BOSSES_H

#include "Enemies.h"
#include "Hero.h"



class Bosses: public Enemies {
protected:
	// special attack function is used for the bosses quick time event damage value 
	int specialAttack = 7;
	
public:
	// Constructor with and without param
    Bosses(void) {}
    Bosses(std::string aName, int aHealth, int aDamage);
	// Deconstructor 
    ~Bosses(void) {}
	// Function is when the user defeats the boss, giving them the reward from file
	void Boss_defeated();
	// defeat protocal similar to one in Enemies, however it is different since and upgrade to an
	// attribute would be irrelavant since the user already won 
	std::string defeat_protocol(Character * aCharacter);
	// Created a quick time event in my program and this special attack function holds that
	int special_attack(Character* aCharacter);
	// ovverriden attack function 
	int attack(Character *);
	// this attack getter is used for the unique damage value for the special attack function
	int get_spec_attack() {
		return specialAttack;
	}
	// setter is used for the special attack function for the Bosses class
	void set_spec_attack(int damage) {
		specialAttack = damage; 
	}
};

#endif 