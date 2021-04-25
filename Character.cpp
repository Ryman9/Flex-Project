/*
* Author:  Ryan Barrington
* Purpose: This .cpp class is for the super/parent class Character, this class has all the basic attributes all 
*		   my other objects will need such as their names, health, and damage.
*
*/

#include "Character.h"
	// Character constructor
    Character::Character(std::string aName, int aHealth, int aDamage)
    {
        name = aName;
        health = aHealth;
        damage = aDamage;
    }
	// to get names of characters
	string Character::get_name()
	{
		return name;
	}
	// to check the health of characters
	int Character::check_health()
	{
		return health;
	}
	// to get the damage of character
	int Character::get_damage()
	{
		return damage;
	}
	//setters for the 3 getters
	void Character::set_name(string aname)
	{
		name = aname;
	}

	void Character::set_damage(int adamage)
	{
		damage = adamage;
	}
	
    void Character::set_health(int ahealth) {
		health = ahealth;
	}
	// attack function will be overriden  by every character
	int Character::attack(Character * aCharacter)
	{
		return 0;

	}
	// defeat protocal will be overriden in my subclasses as well 
    std::string Character::defeat_protocol(Character * aCharacter)
    {
        std::cout << "No Action" << std::endl;

        return "";
    }