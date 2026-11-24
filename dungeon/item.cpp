#include "item.h"
#include <iostream>
#include <vector>
#include <random>

void Item::print() const
{

    std::string catName;
    switch (category)
    {
    case ItemCategory::weapon:
        catName = "Weapon";
        break;
    case ItemCategory::armor:
        catName = "Armor";
        break;
    case ItemCategory::potion:
        catName = "Potion";
        break;
    case ItemCategory::special:
        catName = "special";
        break;
    }

    std::cout << "[ " << catName << " ]" << name << " (value: +" << value << " ) - " << description << "\n";
}

Item generateRandomLoot()
{
    static const std::vector<Item> lootPool = {
        // Potion (Consumable)
        {"Minor Potion", ItemCategory::potion, 30, "Restore 30 HP."},
        {"Major Potion", ItemCategory::potion, 60, "Restore 60 HP."},

        // Weapons (Increase Attack)
        {"Rusted Dagger", ItemCategory::weapon, 5, "Increases attack by 5."},
        {"Steel Sword", ItemCategory::weapon, 12, "Increases attack by 12."},
        {"Berserker's Axe", ItemCategory::weapon, 20, "Increases attack by 20."},

        // Armor (Increases Defence)
        {"Wooden Shield", ItemCategory::armor, 8, "Increases defence by 8."},
        {"Chainmail", ItemCategory::armor, 18, "Increases defence by 18."},
        {"Dragon Armor", ItemCategory::armor, 30, "Increases defence by 30."},

        // Special Items (Unique effects)
        {"Golden Four-Leaf Clover", ItemCategory::special, 15, "Permanently increases Luck by 15."},
        {"Boots of the Wind", ItemCategory::special, 2, "Permanently increases Speed ​​by 2."}
    };

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, lootPool.size() - 1);

    return lootPool[dis(gen)];
}

