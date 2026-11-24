#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include "item.h"


/*-----------------------------------------------------------------------------------------------------------------------------------------*/


// class character
class character
{

protected:
    std::string name;
    int HP{};
    int maxHP{100}; // for not cure above the max
    int attack{};
    int defence{};
    double speed{}; 
    int luck{};

public:
    character() = default; // default constructor
    character(std::string inName, int inHP, int inAttack, int inDefence, double inSpeed); // constructor
    virtual ~character() = default; // default destructor

    //function for combact and UI
    int getHP() const { return HP; }
    int getDefence() const { return defence; }
    double getSpeed() const { return speed; }
    int getLuck() const { return luck; }
    bool isAlive() const { return HP > 0; }

    //health management
    void takeDamage(int dmg);
    void heal(int amount);

};


/*-----------------------------------------------------------------------------------------------------------------------------------------*/

// class player
class player : public character
{
private:
    int posX{0};
    int posY{0};

    std::vector<Item> inventory;
    Item equippedWaepon{"Pugni", ItemCategory::weapon, 0, "No weapon equipped"};
    Item equippedArmor{"clothes", ItemCategory::armor, 0, "No armor equipped"};

public:

    player() = default; // default constructor
    player(std::string inName, int inHP, int inAttack, int inDefence, double inSpeed, int inLuck); // constructor


    void InsertName();// method to insert the name of the character
    void randomHP(); // method to generate a random HP
    void randomAttack(); // method to generate a random attack value based on the character's attack stat
    void randomDefence(); // method to generate a random defence value based on the character's
    void randomSpeed(); // method to generate random speed
    void randomLuck(); // method to generate a random luck value based on the character's
    void PrintStats(); // print player stats


    int getX() const { return posX; }
    int getY() const { return posY; }
    void setPosition(int newX, int newY) { posX = newX; posY = newY; }

    //method for the total attack and defence after find a weapon or a armor
    int getTotalAttack() const {return attack + equippedWaepon.value; };
    int getTotalDefence() const {return defence + equippedArmor.value;};

    //method inventory
    void addItem(const Item& newItem);
    void openInventory();

};


/*-----------------------------------------------------------------------------------------------------------------------------------------*/

// class enemy
class enemy : public character
{
public:
    enemy() = default; // default constructor
    enemy(std::string inName, int inHP, int inAttack, int inDefence, double inSpeed); // constructor
    
};



// class goblin
class goblin : public enemy
{
public:
    goblin(); // default constructor
    goblin(int inHP, int inAttack, int inDefence, double inSpeed); // constructor
    void insertStats(); // insert stats of the goblin
};



// class skeleton
class skeleton : public enemy
{
public:
    skeleton(); // default constructor
    skeleton(int inHP, int inAttack, int inDefence, double inSpeed); // constructor
    void insertStats(); // insert stats of the skeleton
};



// class ORC
class orc : public enemy
{
public:
    orc(); // default constructor
    orc(int inHP, int inAttack, int inDefence, double inSpeed); // constructor   
    void insertStats(); // insert stats of the orc     
};



// class dragon
class dragon : public enemy
{
public:
    dragon(); // default constructor
    dragon(int inHP, int inAttack, int inDefence, double inSpeed); // constructor
    void insertStats(); // insert stats of the dragon

};



#endif