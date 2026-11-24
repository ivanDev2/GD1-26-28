#include "character.h"
#include <iostream>
#include <random>

using namespace std;

character::character(std::string inName, int inHP, int inAttack, int inDefence, double inSpeed)
{
    name = inName;
    HP = inHP;
    maxHP = inHP;
    attack = inAttack;
    defence = inDefence;
    speed = inSpeed;
    //std::cout << "created new character with name: " << name << " HP: " << HP << " attack: " << attack << " defence: " << defence << " speed: " << speed << std::endl;
}

void character::takeDamage(int dmg)
{
    if (dmg < 1) dmg = 1;
    HP -= dmg;
    if (HP < 0) HP = 0;
}

void character::heal(int amount)
{
    HP += amount;
    if (HP > maxHP) HP = maxHP; 
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

void player::InsertName()
{
    std::cout << "insert your name: ";
    std::getline(std::cin >> std::ws, name);
}

void player::randomHP()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(80, 150); // Range bilanciato per affrontare il Drago
    HP = dis(gen);
    maxHP = HP;
}

void player::randomAttack()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(15, 35);
    attack = dis(gen);
}

void player::randomDefence()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(10, 60);
    defence = dis(gen);
}

void player::randomSpeed()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10);
    speed = dis(gen);
}

void player::randomLuck()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    luck = dis(gen);
}

void player::PrintStats()
{
    std::cout << "============================" << std::endl;
    std::cout << "         Welcome to:        " << std::endl;
    std::cout << "    THE SCORCHING DUNGEON   " << std::endl;
    std::cout << "============================" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "Player Stats:\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "HP: " << HP << "/" << maxHP << "\n";
    std::cout << "Attack: " << getTotalAttack() << " (Base: " << attack << " + " << equippedWeapon.value << ")\n";
    std::cout << "Defence: " << getTotalDefence() << " (Base: " << defence << " + " << equippedArmor.value << ")\n";
    std::cout << "Speed: " << speed << "\n";
    std::cout << "Luck: " << luck << "\n";
    std::cout << "--------------------------" << std::endl;
}

// Inventory

void player::addItem(const Item& newitem)
{
    inventory.push_back(newitem);
    std::cout << "You have collected: ";
    newitem.print();
}

void player::openInventory()
{
    std::cout << "\n=== CURRENT EQUIPMENT ===\n";
    std::cout << "Wepon: " << equippedWeapon.name << " (+" << equippedWeapon.value << " ATK)\n";
    std::cout << "Armor: " << equippedArmor.name << " (+" << equippedArmor.value << " DEF)\n";

    std::cout << "\n=== BACKPACK ===\n";
    if (inventory.empty())
    {
        std::cout << "The backpack is empty.\n";
        return;
    }

    for (size_t i = 0; i < inventory.size(); ++i)
    {
        std::cout << i + 1 << ". ";
        inventory[i].print();
    }

    std::cout << "Choose the number of the item to use/equip (0 to close): ";
    int choice{};
    std::cin >> choice;

    if (choice <= 0 || choice > static_cast<int>(inventory.size()))
    {
        std::cout << "Closed backpack.\n";
        return;
    }

    int index = choice - 1; 
    Item selected = inventory[index];

    switch (selected.category)
    {
        case ItemCategory::potion:
            heal(selected.value);
            std::cout << "You drink " << selected.name << " ! Current HP: " << HP << " /" << maxHP << "\n";
            inventory.erase(inventory.begin() + index);
            break;

        case ItemCategory::weapon:
            if (equippedWeapon.value > 0)
            {
                inventory.push_back(equippedWeapon);
            }
            equippedWeapon = selected;
            inventory.erase(inventory.begin() + index);
            std::cout << "You have equipped: " << equippedWeapon.name << " !\n";
            break;

        case ItemCategory::armor:
            if (equippedArmor.value > 0)
            {
                inventory.push_back(equippedArmor);
            }
            equippedArmor = selected;
            inventory.erase(inventory.begin() + index);
            std::cout << "You wore: " << equippedArmor.name << "!\n";
            break;

        case ItemCategory::special:
            if (selected.name.find("Clover") != std::string::npos)
            {
                luck += selected.value;
                std::cout << "Your Luck increases by " << selected.value << " ! (Luck: " << luck << ")\n";
            }
            else
            {
                speed += selected.value;
                std::cout << "Your Speed ​​increases by" << selected.value << " ! (Speed: " << speed << ")\n";
            }
            inventory.erase(inventory.begin() + index);
            break;
    }
}

void player::updateStatusEffects()
{
    if (poisonTurns > 0)
    {
        takeDamage(poisonDamage);
        poisonTurns--;
        std::cout << "[POISON] Take " << poisonDamage << " poison damage! (Turns remaining: " 
                  << poisonTurns << " | HP: " << HP << ")\n";
    }
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

enemy::enemy(std::string inName, int inHP, int inAttack, int inDefence, double inSpeed)
    : character(inName, inHP, inAttack, inDefence, inSpeed)
{
}

goblin::goblin() : enemy("Goblin", 50, 10, 5, 3.0) {}
goblin::goblin(int inHP, int inAttack, int inDefence, double inSpeed) : enemy("Goblin", inHP, inAttack, inDefence, inSpeed) {}

orc::orc() : enemy("Orc", 100, 20, 10, 2.0) {}
orc::orc(int inHP, int inAttack, int inDefence, double inSpeed) : enemy("Orc", inHP, inAttack, inDefence, inSpeed) {}

skeleton::skeleton() : enemy("Skeleton", 60, 12, 6, 4.0) {}
skeleton::skeleton(int inHP, int inAttack, int inDefence, double inSpeed) : enemy("Skeleton", inHP, inAttack, inDefence, inSpeed) {}

dragon::dragon() : enemy("Dragon", 200, 35, 25, 5.0) {}
dragon::dragon(int inHP, int inAttack, int inDefence, double inSpeed) : enemy("Dragon", inHP, inAttack, inDefence, inSpeed) {}

void goblin::insertStats()
{
    name = "Goblin";
    HP = 50;
    attack = 10;
    defence = 5;
    speed = 3.5;
}

void orc::insertStats()
{
    name = "Orc";
    HP = 100;
    attack = 20;
    defence = 10;
    speed = 2.0;
}

void skeleton::insertStats()
{
    name = "Skeleton";
    HP = 60;
    attack = 12;
    defence = 6;
    speed = 3.0;
}

void dragon::insertStats()
{
    name = "Dragon";
    HP = 200;
    attack = 35;
    defence = 25;
    speed = 5.0;
}

int goblin::calculateAttackDamage() const
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    // The Goblin has a 25% chance to perform a quick double strike.
    if (dis(gen) <= 25)
    {
        std::cout << "[GOBLIN ABILITY] Quick double strike! ";
        return attack + 5;
    }
    return attack;
}

int orc::calculateAttackDamage() const
{
    // When the Orc drops below 40 HP, it enters a Frenzy (+50% attack)
    if (HP < 40)
    {
        std::cout << "[ORC'S FURY] The orc is wounded and strikes out in rage! ";
        return static_cast<int>(attack * 1.5);
    }
    return attack;
}

int dragon::calculateAttackDamage() const
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    // The Dragon has a 30% chance of using Fiery Breath.
    if (dis(gen) <= 30)
    {
        std::cout << "[FIERY BREATH] The dragon spews devastating flames! ";
        return attack + 15;
    }
    return attack;
}
