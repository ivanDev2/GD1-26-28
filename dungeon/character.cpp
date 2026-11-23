#include "character.h"
#include <iostream>
#include <random>

using namespace std;

character::character(std::string inName, int inHP, int inAttack, int inDefence, double inSpeed) // constructor
{
    name = inName;
    HP = inHP;
    attack = inAttack;
    defence = inDefence;
    speed = inSpeed;
    std::cout << "created new character with name: " << name << " HP: " << HP << " attack: " << attack << " defence: " << defence << " speed: " << speed << std::endl;
}

void player::InsertName() // method to insert the name of the player
{
    std::cout << "insert your name: ";
    std::getline(std::cin >> std::ws, name);
}

void player::randomAttack() // method to generate a random attack value for the player
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 40);
    attack = dis(gen);
}

void player::randomDefence() // method to generate a random defence value for the player
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 150);
    defence = dis(gen);
}

void player::randomLuck() // method to generate a random luck value for the player
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    luck = dis(gen);
}

void player::PrintStats() // method to print the stats of the player
{
    std::cout << "--------------------------" << std::endl;
    std::cout << "Player Stats:\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "HP: " << HP << "\n";
    std::cout << "Attack: " << attack << "\n";
    std::cout << "Defence: " << defence << "\n";
    std::cout << "Speed: " << speed << "\n";
    std::cout << "Luck: " << luck << "\n";
    std::cout << "--------------------------" << std::endl;
}

enemy::enemy(std::string inName, int inHP, int inAttack, int inDefence, double inSpeed)
    : character(inName, inHP, inAttack, inDefence, inSpeed)
{
}

goblin::goblin()
    : enemy("Goblin", 50, 10, 5, 3.0)
{
}

goblin::goblin(int inHP, int inAttack, int inDefence, double inSpeed)
    : enemy("Goblin", inHP, inAttack, inDefence, inSpeed)
{
}

orc::orc()
    : enemy("Orc", 100, 20, 10, 2.0)
{
}

orc::orc(int inHP, int inAttack, int inDefence, double inSpeed)
    : enemy("Orc", inHP, inAttack, inDefence, inSpeed)
{
}

skeleton::skeleton()
    : enemy("Skeleton", 60, 12, 6, 4.0)
{
}

skeleton::skeleton(int inHP, int inAttack, int inDefence, double inSpeed)
    : enemy("Skeleton", inHP, inAttack, inDefence, inSpeed)
{
}

dragon::dragon()
    : enemy("Dragon", 200, 35, 25, 5.0)
{
}

dragon::dragon(int inHP, int inAttack, int inDefence, double inSpeed)
    : enemy("Dragon", inHP, inAttack, inDefence, inSpeed)
{
}

void goblin::insertStats() // method to insert the stats of the goblin
{
    name = "Goblin";
    HP = 50;
    attack = 10;
    defence = 5;
    speed = 3.5;
}

void orc::insertStats() // method to insert the stats of the orc
{
    name = "Orc";
    HP = 100;
    attack = 20;
    defence = 10;
    speed = 2.0;
}

void skeleton::insertStats() // method to insert the stats of the skeleton
{
    name = "Skeleton";
    HP = 60;
    attack = 12;
    defence = 6;
    speed = 3.0;
}

void dragon::insertStats() // method to insert the stats of the dragon
{
    name = "Dragon";
    HP = 200;
    attack = 35;
    defence = 25;
    speed = 5.0;
}
