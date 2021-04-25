/*
* Author:  Ryan Barrington
* Purpose: This .cpp class is for the subclass Enemies, in my program currently I will be creating 3 of these objects since I think creating more 
*          could be a time issue for the demonstration, This enemy will function as the Heros adversary and they will fight.
*/
#include "Enemies.h"
#include <iostream>
#include "Character.h"
#include "Hero.h"
#include <ctime>
#include <fstream>

Enemies::Enemies(std::string aName, int aHealth, int aDamage) : Character(aName,aHealth, aDamage)
{

}

// This attack function is going to be used in battles between the Hero and Enemy, the enemy will have the worst attack odds
// since the enemies in games are traditionally easy to defeat, unlike the boss.
int Enemies::attack(Character * aCharacter)
{
	int attacknum;

    // Random Attack Gen 
    std::srand(std::time(nullptr));
    attacknum = std::rand() % 100 + 1;

    int health = aCharacter->check_health();

	if (health > 0) {

		if (attacknum <= 20) {
			//reduce Hero health by enemy damage
            std::cout << "\t\t =>" << aCharacter ->get_name() << " gets hurt by Normal attack!" << std::endl;

            aCharacter->set_health(health - get_damage());

		}
		else if (attacknum <= 30) {
			std::cout << "\t\t =>" << aCharacter->get_name() << " gets critically hit!" << std::endl;
			//reduce Hero health by enemy damage * 2
            aCharacter->set_health(health - (get_damage() * 2));
        }
		else {
			std::cout << "\t\t =>" << aCharacter ->get_name() << " Dodges Attack!" << std::endl;
			// no damage done 
		}
	}
	else 
    {
		std::cout << "\t\t => " << aCharacter->get_name() << " has been defeated!" << endl;
		
        user_lost(); 

	}
    
    return 0;
}


// user lost will handle when the hero dies in any battle versus the enemies, it will display some text detailing the situation
// then it will display the upgrade history file the User has made to give them a chance to review the upgrade path they went on. 
void Enemies::user_lost() 
{

	std::cout << "You have been defeated on your path to ultimate victory. However, you may restart and try again." << std::endl;
    std::cout << "Since you were unsuccessful on your path to the ultimate sword, next time try a easier difficulty if possible." << endl;
    std::cout << "Here was your upgrades you made during your, fights, since you lost, it is recommeneded to try different upgrades" << endl; 
    
     // Displaying The upgrades the user has made the gift History 
     ifstream inFile;
     inFile.open("GiftHistory.txt");
     string histsItems;
     std::vector<string> history;

     cout << "Upgrades used in the battle :" << endl;
     if (inFile)
     {
         int index = 1;
         while (getline(inFile, histsItems))
         {
             cout << index << "\t" << histsItems << endl;
             index++;
         }
     }

     inFile.close();

    std::cout << "\n Thank you for playing" << endl << endl; 
	
}

// This function is called whenever the Hero and an enemy fight and the Hero wins
// It will allow the user to select an upgrade from a text file, then the user can pick a health or damage upgrade
// then based on the choice it will call user boost function to increase the hero's attribute, then return the 
// string based on what function got upgraded, the returned string is used in a Hero function that creates the 
// upgrade history text file.
std::string Enemies::defeat_protocol(Character * aCharacter)
{   // to track what upgrade the user wants
    int userChoice = 0;
    std::string retVal;

  // strings that will be returned 
    std::string option1 = "You Selected a Health Upgrade";
    std::string option2 = "You Selected a Damage Upgrade";

    std::cout << "\nCongratulations on your victory, select an upgrade!" << endl;
    string line;
    // This file holds the upgrade options 
    ifstream myfile("Upgradelist.txt");
    // Displaying the file of upgrade options
    if (myfile.is_open())
    {

        while (getline(myfile, line)) {
            cout << line << endl;
        }
        myfile.close();
    }

    else cout << "Unable to open file";

    cin >> userChoice;
    // input validation
    if (userChoice > 2 || userChoice < 1) {
        cout << "Incorrect data type or value, please enter 1 or 2." << std::endl;
        cin.clear();
        cin.clear();
        cin >> userChoice;
    }
    // They selected health upgrade
    if (userChoice == 1) {
        // calls health boost function for Hero 
        ((Hero*)aCharacter)->user_boost_h(aCharacter->check_health());
        // Let's the user know the upgrade happened
        std::cout << aCharacter->get_name() << "'s health is now: " << aCharacter->check_health() << endl << endl;
        //call function to write to outfile so user can keep track of upgrades
        retVal = option1;
    }
    // They selected damage upgrade
    if (userChoice == 2) {
        // calls damage boost function for Hero
        ((Hero*)aCharacter)->user_boost_d(aCharacter->get_damage());
        // Lets the user know the upgrade happened
        std::cout << aCharacter->get_name() << "'s damage is now: " << aCharacter->get_damage() << endl << endl;
        // Then we call out file and write what upgrade we want
        retVal = option2;
    }
   // string to store upgrade in text file 
    return retVal;
}