#ifndef ITEM_H
#define ITEM_H

#include <string>

//the 4 categories 
enum class ItemCategory
{
    weapon,
    armor,
    potion,
    special

};


struct Item
{
    std::string name;
    ItemCategory category;
    int value{};
    std::string description;

    void print() const;
};

//function to generate a random loot in the loot room
Item generateRandomLoot();

#endif