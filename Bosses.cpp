/*
* Author:  Ryan Barrington
* Purpose: This .cpp class is for the sub class Bosses, this class has all the basic attributes all
*		   my other objects will need such as their names, health, and damage.
*
*/
#include "Bosses.h"
#include "Character.h"
#include <iostream>
#include <thread>
#include <ctime>
#include <fstream>


Bosses::Bosses(std::string aName, int aHealth, int aDamage) : Enemies(aName,aHealth, aDamage)
{
}


// If user beats the game after the boss fight the hero gets the reward sword displayed to them as well as some text congratulating them
void Bosses::Boss_defeated() {
	std::cout << "\nCongratulations brave warrior, for your success in battle," << endl;
    std::cout << "you will receive the ultimate honor, the legendary sword:" << endl << endl;
	// idea for making an ASCII art sword as the reward for beating final boss
    string line;
    ifstream myfile("RewardSword.txt");
    if (myfile.is_open())
    {

        while (getline(myfile, line)) {
            cout << line << endl;
        }
        myfile.close();
    }

    else cout << "Unable to open file";
    
    std::cout << endl << endl; 
    // This is displaying the upgrades the hero has selected throughout his journey
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

// This function was overriden however we use boss defeated rather than defeat protocal to give reward, unlike the enemy version that
// offers items from the reward file 
std::string Bosses::defeat_protocol(Character * aCharacter)
{
	

    return "";
}

// Added this after the proposal to make the boss unique, this is a function that performs a quick time event
// similar to many fighting games, the function will give the user a randomly generated char
// and it will start a 5 second timer to press it and enter it in, if they do it in time, the attack gets dodged, 
// if they dont press the char in time or the wrong char, the Hero takes a large damage attack. 
int Bosses::special_attack(Character* aCharacter)
{
    cout << "\n The special attack has begun, stay alert!" << endl << endl;

    int health = aCharacter->check_health();

    // generating random number 1-26
    srand(time(NULL));
    char userinput;
    int r = rand() % 26;
    int i = 'a' + r;
    // converting to char for event 
    char randchar = i;
    std::cout << "Enter '" << randchar << "' + ENTER to dodge special attack!" << std::endl;
   //  this is the timer for the event 
    std::thread t1([&]() {
        std::cin >> userinput;
        });
    std::this_thread::sleep_for(std::chrono::seconds(5));
    t1.detach();
    // checks if the user selected right or not. 
    if (userinput != randchar) {
        std::cout << "\nHero has taken " << (get_spec_attack() * 2) << " damage points." << std::endl;
        aCharacter->set_health(health - (get_spec_attack() * 2));
    }
    //selected right
    else {
    std::cout << "You dodged the attack, well done!" << endl;
    }   
    return 0;
}

// Bosses normal attack function, odds are boosted compared to enemies since the boss should be a more formidable adversary
int Bosses::attack(Character * aCharacter) 
{
	int attacknum;

    // Random Attack Gen 
    std::srand(std::time(nullptr));
    attacknum = std::rand() % 100 + 1;

    int health = aCharacter->check_health();

    if (health > 0)
    {

		if (attacknum <= 40) 
        {
			//reduce Hero health by boss damage
            std::cout << "\t\t =>" << aCharacter->get_name() << " gets hurt by Normal attack!" << std::endl;
            aCharacter->set_health(health - get_damage());
		}
		if (attacknum <= 45) 
        {
            std::cout << "\t\t =>" << aCharacter->get_name() << " gets critically hit!" << std::endl;
            //reduce Hero health by boss damage * 2 
            aCharacter->set_health(health - (get_damage() * 2));

        }
		else 
        {
            std::cout << "\t\t =>" << aCharacter->get_name() << " narrowly avoided the attack!" << std::endl;
            // no damage done 
		}
	}
	else 
    {
		std::cout << aCharacter->get_name() << " has been defeated" << endl;
    	user_lost();
	}
    
    return 0;

}
