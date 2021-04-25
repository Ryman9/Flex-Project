Ryan Barrington's Flex Project Read Me File

Table of Contents:
1. Basic Information Regarding Program
2. Installation and Compilation 
3. Files in More Detail 
4. Additional Info and Recommendations

1. Basic Information Regarding Project:

This project is a game that is a turn based
fighting game that utilizes many unique features 
and additions to make the game interesting, replayable,
and unique. 


2. Installation and Compilation
 a) First download files from submitted zip folder
 b) Extract files to your device
 c) Compile Information:
    before attempting to compile,
    module purge
    module add compilers/gcc/7.3.0 
    on the Terminal
 d) Compile files by doing command: 
   g++ Hero.cpp Enemies.cpp -pthread Bosses.cpp Enemies.cpp main.cpp
 e) After compilation run the program with command ./a.out

3. Files in More Detail

Character.h - Header file for superclass Character.

Character.cpp - This file holds the content for the abstract class
Character, it is inherited by all the other classes so it holds basic
info that is needed by every object. Things like their names, health, 
damage, and how they attack are all parts of this class since all the 
subclasses utilize these attributes and functions. 

Hero.h - Header file for subclass Hero.

Hero.cpp - This file holds the content for the Hero in the game, also 
the character that the user will control during the game. Hero.cpp 
has many unique functions outside of the inherited ones in Character.cpp.
This file handles almost all of the file reading and writing as well as 
storing and altering upgrades given to the Hero along their Journey. Hero
also has vectors for these said reading files to store content from text
files into these vectors. Additionally, Hero.cpp has a unique protected 
member called max_hp, this unique attribute is used by the Hero to 
regenerate the Hero's health after a fight, so they go into the next one 
with full health. 

Enemies.h - Header file for subclass Enemies.

Enemies.cpp - This file is for the subclass Enemies, this file holds many
crucial functions to the command of the game, since the Hero begins the 
game with fighting Enemies before they reach the final boss. Enemies 
attack function, unlike Hero's has much worse odds to give the Hero a 
better chance to win the battles. Additionally Enemies is a parent class
to the subclass of both Character and Enemies, Bosses. Enemies unique 
functions of defeat_protocol and user_lost are inherited by Bosses. 
Function defeat_protocal is to recreate an Enemy in game dropping an 
item or upgrade when they get eliminated, defeat_protocal starts with
offering the user a upgrade to their Hero's health or damage, it takes
the input and then writes to a GiftHistory.txt file that holds the 
previous upgrades and will be displayed to the user later on. Function
user_lost handles when an enemy or boss defeats the hero, it will display
some more story and information, then display the user upgrade choices
they made and thank them for playing.

Bosses.h - Header file for subclass Bosses

Bosses.cpp - Bosses.cpp is file that is a subclass of both Character and
Enemies inheriting both of their members. Bosses has some unique features,
such as the function special_attack, in many games I have played over the 
years I have always enjoyed quick time events, or things that have a time 
limit, things like pushing a button in a certain time peroid or you miss 
or get hit. Function special_attack accomplishes this by generating a 
random number and giving the user a time window to select that input, and
if the user misses the input or puts something wrong, the Hero takes a 
large chunk of damage. Additionally, the boss uses the Enemies unique 
functions like defeat_protocal and user_lost, however it has one more 
unique function, Boss_defeated, this is called when the user's Hero 
defeats the final boss, therefore winning the game. This function gives 
the user praise, displays the upgrade path the user gave the Hero, and 
then gives them the ultimate reward spoken about in the main story, a 
sword, the sword is in a text file and is made out of ASCII art. Bosses
attack function is not quite as strong as the Hero's however the odds are
better than the Enemies, also the Bosses have much more health and do 
more damage than Enemies. 

main.cpp - This is the main file for the program, it runs the program and 
calls all the functions from the other files and is where the files are 
actually used. Additionally, main has a function called fight that takes 
care of all the fights between the Hero's and Enemies. Also, main.cpp
holds storyline information and any actions regarding the fights or 
inventory management and upgrades. 


4. Additional Info and Recommendations

I recommend when testing my program to play on the easy difficulty
This will allow the best chance for the user to get the entire experience 
and beat the game. I strived for replayability and the random chance 
aspect of numbergenerators and the different upgrades the user can 
acquire, as well as the chest items really makes that goal a reality 
for me. 

If you want to run the program multiple times I factored that in
so that at the beginning of every run, the UpgradeHistory file will clear 
itself.
 
