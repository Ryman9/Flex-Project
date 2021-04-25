/*
* Author:  Ryan Barrington
* Purpose: This Project will be a game that is considered to be a Role-Play Fantasy Game set in a medieval fantasy world where there are enemies,
*          health and health upgrades, and bosses that the user must defeat through turn-based combat using a “dice” roll to determine how effect each
*          attack is on them, as well as against them. Additionally I incorporated a "quick-time event" into my boss fight. To win the game,
*          the user will have to beat several enemies of different difficulties and a boss fight to finish the quest.
*          Along the way the user will be able to upgrade their health or damage as well as collect items from a reward
*          for defeating enemies. Additionally there will be a difficulty selection and an out file that keeps track out these upgrades for the user
*          so they know what upgrades they made an what they can do next time or play with which options they like most
*
*/

#include "Character.h"
#include <iostream>
#include <fstream>
#include "Hero.h"
#include "Enemies.h"
#include "Bosses.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds



void SetBattleHistory(std::string addedPerk);
void ClearBattleHistory(void);
void fight(Character* aHero, Character* aEnemy);


int main() 
{   // this int will be used to start the game and be used to alter the health values based on difficulty 
    int userDif;
    std::cout << "Before we begin the journey, please select your difficulty." << std::endl;
    std::cout << "Easy (1) \nNormal (2) \nHard (3) \n"; 
    std::cout << "Difficulty: ";
    // For our user lost function and the Boss defeated, I wrote to a file to keep track of user upgrades, 
    // To display to the user to let them know what upgrades they made, this clears it so if it is ran a second time 
    // it clears the old file 
    ClearBattleHistory();

    // input validation for the userDif var
    while (!(cin >> userDif) || (userDif > 3 || userDif < 1)) {
        cout << "Incorrect data type or value, please enter an int between 1-3." << std::endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    // Initializing the base values for the enemies in hero, will be changed based on user's
    // difficulty selection, initialized to easy, but the if's will update
    Character* aCharBosPtr = new Bosses("Magnus", 25, 7);
    Character* aCharHero = new Hero("Ratburn", 40, 5);
    Character* aCharEnemy1 = new Enemies("Chipton", 10, 5);
    Character* aCharEnemy2 = new Enemies("Toby", 10, 5);
    Character* aCharEnemy3 = new Enemies("Knightro", 10, 5);


     
        if (userDif == 2) {
            // base values for medium difficulty
        aCharBosPtr->set_health(20);
        aCharEnemy1->set_health(15);
        aCharEnemy2->set_health(15);
        aCharEnemy3->set_health(15);
       
        
    }
    else if (userDif == 3) {
            // base values for hard difficulty
        aCharBosPtr->set_health(25);
        aCharHero->set_health(15);
        aCharEnemy1->set_health(15);
        aCharEnemy2->set_health(15);
        aCharEnemy3->set_health(15);
       
     
    }
        //essentially a temp variable in hero class to hold the value we must regenerate to after winning fights
        // we will adjust this value along with upgrades like damage upgrades, however we need this for health since 
        // the hero must regenerate to his max hp before his next fight. 
       ((Hero*) aCharHero)->set_max_hp(aCharHero->check_health());
    
    // Beginning Dialogue to create story for user to get a feel for the game 
    std::cout << "\n\t\"Our journey begins now at the bottom of a trecherous mountain that holds the most powerful weapon," << endl;
    std::cout << "\tthe legendary sword that's power holds no limits and can protect it's user with many powerful abilities.\n" << endl;
    
   
    ::sleep_for(std::chrono::milliseconds(5000));

    std::cout << "\t\"However, the mountain is guarded by the Maniacal Magnus and his servants, so this won't be an easy feat.\"\n" << endl;
    
    
    ::sleep_for(std::chrono::milliseconds(5000));

    // first encounter 
    std::cout << "\t\"" << aCharHero->get_name() << ",  after walking he comes across his first servant of Magnus, " << aCharEnemy1->get_name() << endl;
    std::cout << "\n\t\"A battle must ensue to continue " << aCharHero->get_name() << "'s journey\"\n" << endl;
    ::sleep_for(std::chrono::milliseconds(5000));
   
    
        
        // FIGHT ONE
        fight(aCharHero, aCharEnemy1);
        if (aCharHero->check_health() < 1) {
            // since user_lost will be called in the fight function if necessary,
            // we can return 0, or exiting the program
            std::cout << "Program will be exited!" << endl;
            return 0; 
        }
       // to create seperation in time between the end of the fight and next dialouge
        ::sleep_for(std::chrono::milliseconds(5000));

        // Fight 2 story telling
        std::cout << "\nAfter defeating " << aCharEnemy1->get_name() << ", " << aCharHero->get_name() << " continues his journey up the mountain to collect the sword." << endl;
        std::cout << aCharHero->get_name() << " comes across a bridge with a cavern at the end, across he sees a figure," << endl;
        std::cout << "not knowing it is his next enemy, " << aCharEnemy2->get_name() << "." << endl;
        std::cout << "A fight between " << aCharHero->get_name() << " and " << aCharEnemy2->get_name() << " must begin to continue the climb!" << endl << endl;
       
        // FIGHT TWO
        ::sleep_for(std::chrono::milliseconds(5000));
        
        fight(aCharHero, aCharEnemy2);
        if (aCharHero->check_health() < 1) {
            // since user_lost will be called in the fight function if necessary,
            // we can return 0, or exiting the program
            std::cout << "Program will be exited!" << endl;
            return 0;
        }

        
        ::sleep_for(std::chrono::milliseconds(5000));

        // Story telling for fight 3 
        std::cout << "\nAfter defeating " << aCharEnemy2->get_name() << ", " << aCharHero->get_name() << " continues his journey up the mountain to collect the sword." << endl;
        std::cout << aCharHero->get_name() << " sees the peak of the mountain, with the large cynical throne of Magnus, " << endl;
        std::cout << "before he can challenge him, he must get through  " << aCharEnemy3->get_name() << "." << endl;
        std::cout << "A battle between " << aCharHero->get_name() << " and " << aCharEnemy3->get_name() << " begins to unfold." << endl << endl;

        ::sleep_for(std::chrono::milliseconds(5000));

        // FIGHT THREE
        fight(aCharHero, aCharEnemy3);
        if (aCharHero->check_health() < 1) {
            // since user_lost will be called in the fight function if necessary,
            // we can return 0, or exiting the program
            std::cout << "Program will be exited!" << endl;
            return 0;
        }
       
       // Seperation from fight to next
        ::sleep_for(std::chrono::milliseconds(5000));
    
    // BOSS FIGHT 
    std::cout << "\nWith no one left to protect " << aCharBosPtr->get_name() << ", " << aCharHero->get_name() << " realizes it is time for end his rule once and for all." << endl;
    std::cout << aCharBosPtr->get_name() << " rises from his throne towering over " << aCharHero->get_name() << endl; 
    std::cout << "The final battle begins between " << aCharHero->get_name() << " and " << aCharBosPtr->get_name() << " begins." << endl << endl;
 
    //chest story line
    std::cout << "Behold, a glowing golden chest appears, stopping the fight and calls " << aCharHero->get_name() << " to open it." << endl; 
   
    
    // Displays chest contents for user to select
    cin >> *((Hero*)aCharHero);
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    
  

    // user can pick one of the chest items
    int  invItem = 0;
    cout << "Selection: ";
    cin >> invItem;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // Input Validation 
    if (invItem > 3 || invItem < 1) {
        std::cout << "Incorrect input, please select an int between 1-3" << endl;
        cin.clear();
        cin >> invItem;
    }
    //cout << *((Hero*)aCharHero);
    std::vector<string> & chestOItems = ((Hero*)aCharHero)->inv_access();
  

    ::sleep_for(std::chrono::milliseconds(4000));
    // Since the boss fight is unique in several ways to the enemy fights, It is not going to work with the fight function
    // Since there is only one boss fight, there is no need to make it a function because you would be writing the code once regardless
    // this is used to alternate attacks
    int count = 0;

    while (aCharHero->check_health() > 0 && aCharBosPtr->check_health() > 0) {

        ::sleep_for(std::chrono::milliseconds(500));
        // If user selected Double Hit from chest
        if (invItem == 1) {
            std::cout << "\nDouble hit item used!" << endl;
            aCharHero->attack(aCharBosPtr);
            std::cout << aCharBosPtr->get_name() << "'s " << "after attack: " << aCharBosPtr->check_health() << endl;
            
            aCharBosPtr->attack(aCharHero);
            std::cout << aCharHero->get_name() << "'s " << "after attack: " << aCharHero->check_health() << endl;
            
            aCharHero->attack(aCharBosPtr);
            std::cout << aCharBosPtr->get_name() << "'s " << "after attack: " << aCharBosPtr->check_health() << endl;
            invItem = 0;
        }
        // If user selected Knife Stab from chest
        if (invItem == 2) {
            std::cout << "\nKnife Stab called, " << aCharBosPtr->get_name() << " loses 5 health points!" << endl;
            aCharBosPtr->set_health(aCharBosPtr->check_health() - 5);
	    invItem = 0;
            ::sleep_for(std::chrono::milliseconds(500));

        }
        // If user selected Turn Skip from chest
        if (invItem == 3) {
            std::cout << "\nTurn Skip called, " << aCharBosPtr->get_name() << " does not get to attack this round!" << endl;
            invItem = 0;
            ::sleep_for(std::chrono::milliseconds(500));

        }
        // After special item is used we convert to normal attack and special attack
        if (invItem == 0) {
            aCharHero->attack(aCharBosPtr);
            std::cout << aCharBosPtr->get_name() << "'s " << "after attack: " << aCharBosPtr->check_health() << endl;
            ::sleep_for(std::chrono::milliseconds(500));
            // This makes the normal and special attack alternate
            if (count % 2 == 0) {
                aCharBosPtr->attack(aCharHero);
                std::cout << aCharHero->get_name() << "'s " << "after attack: " << aCharHero->check_health() << endl;
                ::sleep_for(std::chrono::milliseconds(500));

            }
            else if (count % 2 == 1) {

                ::sleep_for(std::chrono::milliseconds(3000));
                ((Bosses*)aCharBosPtr)->special_attack(aCharHero);
                std::cout << aCharHero->get_name() << "'s " << " health after attack: " << aCharHero->check_health() << endl;
                ::sleep_for(std::chrono::milliseconds(500));

            }

            count++;
            // If user wins 
            if (aCharBosPtr->check_health() < 1) {
                aCharHero->set_health(((Hero*)aCharHero)->get_max_hp());
                ((Bosses*)aCharBosPtr)->Boss_defeated();
                ((Hero*)aCharHero)->set_max_hp(aCharHero->check_health());

                break;
            }
            // if Boss wins
            else if (aCharHero->check_health() < 1) {
                ((Bosses*)aCharBosPtr)->user_lost();
                break;
            }
        }
    }
    /*
    
    
    
    */
   
    cout << "END OF PROGRAM" << endl; 
    
}
// To make my programming more effecient and not re type fights, I added a fight function to handle Hero vs Enemy's fight, 
// not including the boss fight since there are a few unique attributes to that one. 
void fight(Character* aHero, Character* aEnemy) {
    while (aHero->check_health() > 0 && aEnemy->check_health() > 0) {
        //Hero attack
        aHero->attack(aEnemy);
        std::cout << aEnemy->get_name() << "'s health after attack is " << aEnemy->check_health() << endl;
        ::sleep_for(std::chrono::milliseconds(500));

        // Enemy attack 
        aEnemy->attack(aHero);
        std::cout << aHero->get_name() << "'s health after attack is " << aHero->check_health() << endl;
        // After every round they hit each other 
        // Hero won 
        if (aEnemy->check_health() < 1)
        {
            // we set hero's hp back to its base since he won like a health regen in FPS games
            aHero->set_health(((Hero*)aHero)->get_max_hp());
            // calls defeat protocal to give user upgrade option then returns string to add upgrade to file 
            std::string aWard = ((Enemies*)aEnemy)->defeat_protocol(aHero);
            //History called
            SetBattleHistory(aWard);

           
            // Incase the user upgrades the Hero's health in defeat protocal, this will 
            // update max_hp in Hero so that the health regen will be set to the new max health
            ((Hero*)aHero)->set_max_hp(aHero->check_health());
            break;

        }
        // Enemy won
        else if (aHero->check_health() < 1)
        {   // call user lost, also in main fights will be in loop so it will skip any fights after this one 
            ((Enemies*)aEnemy)->user_lost();
            //break is necessary so that it doesn't run the next fight or scenario that could yield regeneration for the hero
            // when the hero doesnt need regen 
            break;
        }
    }
}

// Function tracks the upgrades the user has made and we will display in the user lost function. 
void SetBattleHistory(std::string addedPerk)
{

    ofstream outFile;
    outFile.open("GiftHistory.txt", std::ios_base::app | std::ios_base::out);

    if (outFile)
    {
            outFile << addedPerk << "\n";

    }

    outFile.close();
}

// Function tracks the upgrades the user has made and we will display in the user lost function. 
void ClearBattleHistory(void)
{

    ofstream outFile;
    outFile.open("GiftHistory.txt");

    outFile.close();
}
