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

void character::takeDamage(int dmg)
{
    if (dmg < 1) dmg = 1;
    HP -= dmg;
    if(HP < 0 ) HP = 0;
}

void character::heal(int amount)
{
    HP += amount;
    if(HP > maxHP) HP = maxHP; 
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/


void player::InsertName() // method to insert the name of the player
{
    std::cout << "insert your name: ";
    std::getline(std::cin >> std::ws, name);
}

void player::randomHP() // method to generate a random HP
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    HP = dis(gen);
}

void player::randomAttack() // method to generate a random attack value for the player
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 30);
    attack = dis(gen);
}

void player::randomDefence() // method to generate a random defence value for the player
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    defence = dis(gen);
}

void player::randomSpeed() // method to generate a random speed
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10);
    speed = dis(gen);
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

// inventory

void player::addItem(const Item& newitem)
{
    inventory.push_back(newitem);
    std::cout << "you have collected";
    newitem.print();
}

void player::openInventory()
{

    std::cout << "\n=== CURRENT EQUIPMENT ===\n";
    std::cout << "Arma: " <<  equippedWaepon.name << " (+" <<  equippedWaepon.value << " ATK)\n";
    std::cout << "Armatura: " << equippedArmor.name << " (+" << equippedArmor.value << " DEF)\n";


    std::cout << "\n=== ZAINO ===\n";
    if (inventory.empty())
    {
        std::cout << "Lo zaino e' vuoto.\n";
        return;
    }

    for (size_t i = 0; i < inventory.size(); ++i)
    {
        std::cout << i + 1 << ". ";
        inventory[i].print();
    }

    std::cout << "Scegli il numero dell'oggetto da usare/equipaggiare (0 per chiudere): ";
    int choice{};
    std::cin >> choice;

    if(choice <= 0 || choice > static_cast<int>(inventory.size()))
    {
        std::cout << "Zaino chiuso.\n";
        return;
    }

    int index = choice - 1; 
    Item selected = inventory[index];

    switch (selected.category)
    {
    }

}


/*-----------------------------------------------------------------------------------------------------------------------------------------*/


enemy::enemy(std::string inName, int inHP, int inAttack, int inDefence, double inSpeed)
    : character(inName, inHP, inAttack, inDefence, inSpeed)
{
}

goblin::goblin()
    : enemy("Goblin", 50, 10, 5, 6)
{
}

goblin::goblin(int inHP, int inAttack, int inDefence, double inSpeed)
    : enemy("Goblin", inHP, inAttack, inDefence, inSpeed)
{
}

orc::orc()
    : enemy("Orc", 100, 20, 10, 2)
{
}

orc::orc(int inHP, int inAttack, int inDefence, double inSpeed)
    : enemy("Orc", inHP, inAttack, inDefence, inSpeed)
{
}

skeleton::skeleton()
    : enemy("Skeleton", 30, 7, 4, 4)
{
}

skeleton::skeleton(int inHP, int inAttack, int inDefence, double inSpeed)
    : enemy("Skeleton", inHP, inAttack, inDefence, inSpeed)
{
}

dragon::dragon()
    : enemy("Dragon", 175, 35, 25, 15)
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
    speed = 5;
}

void orc::insertStats() // method to insert the stats of the orc
{
    name = "Orc";
    HP = 100;
    attack = 20;
    defence = 10;
    speed = 2;
}

void skeleton::insertStats() // method to insert the stats of the skeleton
{
    name = "Skeleton";
    HP = 30;
    attack = 7;
    defence = 4;
    speed = 4;
}

void dragon::insertStats() // method to insert the stats of the dragon
{
    name = "Dragon";
    HP = 175;
    attack = 35;
    defence = 25;
    speed = 15;
}
