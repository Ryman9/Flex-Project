/*
* Author:  Ryan Barrington
* Purpose: This .h class is for the subclass Hero, this file contains the constructors for Hero objects, as well as the functions and data members
*		   My hero class is one of the larger classes since this class is larger due to the user controlling this object
*          making it have more features like inventory files and past upgrade tracking files.
*
*/
#include <vector>
#include <string>
#include "Enemies.h"
#ifndef HERO_H
#define HERO_H

std::pair<std::string, std::string> parseString(const std::string strToParse, char delim);

class Hero: public Character {
private: 
    // inventory vector 
	static vector<string> inventory;
    // this is used to "regenerate my Hero's health between fights so he has a chance against multiple enemies
    int max_hp;

public:
    // Hero constructor with and without param
    Hero(void);
    Hero(std::string aName, int aHealth, int aDamage);
    // Deconstructor 
    ~Hero(void);
    
    // Hero attack function with
	int attack(Character *);
    //maybe uneccesarry
    std::string defeat_protocol(Character * aCharacter);
    // setter for max hp if the user upgrades it 
    void set_max_hp(int health) {
        max_hp = health; 
    }
    // getter for max hp 
    int get_max_hp() {
        return max_hp;
    }
    // boosting attributes for the upgrades
	void user_boost_h(int health);
	void user_boost_d(int damage);

    // inventory to pick from and upgrade history
	static std::vector<string> & inv_access();
    static std::vector<string> hist_inv_access();

    // Update Inventory
    friend void update_inv(Hero & aHero);

    // used to read and write from the file
    friend istream& operator>>(istream& ifs, const Hero & aHero);
    friend ostream& operator<<(ostream& os, const Hero & aHero);

};

#endif 