/*
* Author:  Ryan Barrington
* Purpose: This .cpp class is for the Hero class, this class has all the attributes the user can alter or is incorporated with the user
*          since the user controls the Hero in the game. This cpp file has the attack functions and basic things the hero needs 
*          as well as all the file management and opening and reading to manage and override the Hero's inventory.
*		   
*
*/
#include "Hero.h"
#include <ctime>
#include "Character.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream> 
#include <sstream>

// Helper Functions
std::vector<string> LoadInventory(void);
void SaveInventory(std::vector<string> aInventory);


// Static Member Defintion
vector<string> Hero::inventory;

// user can come across chest items in game for upgrades in the game that can boost attributes or do special actions
std::vector<std::string> ChestItems = { "DOUBLE HIT: Allows the user to attack twice in one turn.", "KNIFE STAB: 100% hit rate for 5 damage.",
                                        "Turn Skip: Skips the enemies attack for one turn." };
// inv update function 
void update_inv(Hero & aHero);


//loading inventory 
Hero::Hero(void)
{
    inventory = LoadInventory();
}


// with param
Hero::Hero(std::string aName, int aHealth, int aDamage) : Character(aName,aHealth, aDamage)
{
    inventory = LoadInventory();
}



// deconstructor for hero save inventory
Hero::~Hero(void)
{
    SaveInventory(inventory);
}

// Hero's attack function has very good odds to allow him to fight multiple people
int Hero::attack(Character * aCharacter) 
{
    // random number holder var
	int attacknum;

    // Random Attack Gen 
    std::srand(std::time(nullptr));
    attacknum = std::rand() % 100 + 1;

    int health = aCharacter->check_health();

    if (health > 0)
    {
		if (attacknum <= 90) 
        {
			//reduce enemy health by hero's damage value 
            aCharacter->set_health(health - get_damage());
            std::cout << "\t\t =>" << aCharacter->get_name() << " gets hit by Normal attack" << std::endl;
        }
		else if (attacknum <= 95) 
        {
            std::cout << "\t\t =>" << aCharacter->get_name() << " gets hit by CRITICAL ATTACK!" << std::endl;
            //reduce enemy health by hero's damage value * 2
            aCharacter->set_health(health - (get_damage() * 2));
        }
		else 
        {
            std::cout << "\t\t =>" << aCharacter->get_name() << " Dodges Attack!" << std::endl;
            // no damage done 
		}
	}
	else 
    {
        std::cout << "\t\t => " << aCharacter->get_name() << " has been defeated!" << endl;
		
	}
    
    return 0;
}
// function used in enemies defeat protocal to increment Hero's health 
void Hero::user_boost_h(int health) 
{
    int temp;
    temp = health;
	temp = temp + 3;
    set_health(temp); 
}
// function used in enemies defeat protocal to increment Hero's damage 
void Hero::user_boost_d(int damage) 
{
    int temp;
    temp = damage;
    temp = temp + 3;
    set_damage(temp);
}
    // Necessary for prototyping however could be expanded if this becomes passion
    std::string Hero::defeat_protocol(Character * aCharacter)
{

    std::cout << "\t\" What do want to give your Hero :\" " << endl;

    for (int index = 0; index < inventory.size(); index++)
    {

        std::pair<string, string> myInvValue = parseString(inventory.front(), ':');

        std::cout << "\t\t\" " << ::to_string(index) << "  Gift : " << myInvValue.first <<  "  :" << myInvValue.second << endl;
    }

    std::cout << "\t\t\" Choose index for Victory Reward : "<< endl;

    // CIN of index
    // Based on index add to Victors Health or something like 

    return "We Lost";
}

    // return inv 
std::vector<string> & Hero::inv_access()
{
    return inventory;
}
// update our inv vector 
void update_inv(Hero & aHero)
{
    std::vector<string> aInventory = aHero.inv_access();
    SaveInventory(aInventory);

}

// for displaying inv
ostream& operator<<(ostream& os, const Hero & aHero)
{

    std::vector<string> aInventory = aHero.inv_access();

    os << "Hero Invetory" << endl;

    for (int index = 0; index < aInventory.size(); index++)
    {
        os  << aInventory[index] << "\n";
    }

    return os;
}


// displays chest items so that user can select a temp boost
istream& operator>>(istream & in , const Hero & aHero)
{
    // Example of 
    std::vector<string> & aInv = aHero.inv_access();

    int item;
 
    cout << "Choose a Chest Item : " << endl;
    // displaying items the user can pick
    for (int idx = 0; idx < aInv.size(); idx++)
    {
        cout << idx + 1 << " " << aInv[idx] << endl;
    }
  
    return in;
}


// loading and adding inv to vector
std::vector<string> LoadInventory(void)
{
    ifstream invFile;
    invFile.open("Inventory.txt");
    string invString;
    std::vector<string> retInventory;

    if (invFile)
    {
        while (getline(invFile, invString))
        {
            retInventory.push_back(invString);
        }
    }

    invFile.close();

    return retInventory;
}


// these files need to be different because we read in to get inv then we write to another file to track 
// the upgrades our user has selected so we can show them at the end
void SaveInventory(std::vector<string> aInventory)
{
    ofstream outFile;
    outFile.open("Inventory.txt");
    
    if (outFile)
    {
        for (int index = 0; index < aInventory.size(); index++)
        {
            outFile << aInventory[index] << "\n";
        }
    }

    outFile.close();
}


//to delim text files and format
std::pair<std::string, std::string> parseString(const std::string strToParse, char delim)
{
    std::string invType;
    std::string invTypeValue;

    int pos  = strToParse.find_first_of(delim);
    invType = strToParse.substr(0, pos);
    invTypeValue = strToParse.substr(pos + 1, strToParse.size());

    std::pair<std::string, std::string> invPair(invType,invTypeValue);

    return invPair;
}


