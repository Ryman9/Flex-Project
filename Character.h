/*
* Author:  Ryan Barrington
* Purpose: This .h class is for the super/parent class Character, this class has all the basic attributes all
*		   my other objects will need such as their names, health, and damage.
*
*/
#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>

using namespace std;

class Character 
{
protected: 
	// elements of the Character objects 
	string name; 
	int health;
	int damage;

public: 
	// Constructors with and without param 
    Character(void) {}
    Character(std::string aName, int aHealth, int aDamage);
	// Deconstructor
    virtual ~Character(void) {}

	//getter functions for our protected members
	string get_name();
	int check_health();
	int get_damage();
	// setters for our protected members
	void set_name(string aname);
	void set_damage(int adamage);
	void set_health(int ahealth);
	// 2 member functions that will be overriden in the subclasses
	virtual int attack(Character *);
    virtual std::string defeat_protocol(Character * aCharacter);

};

#endif 

