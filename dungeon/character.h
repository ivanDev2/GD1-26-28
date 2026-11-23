#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>


// class character
class character
{

protected:
    std::string name;
    int HP{};
    int attack{};
    int defence{};
    double speed{5.0}; // speed in km/h
    int luck{};

public:
    character() = default; // default constructor
    character(std::string inName, int inHP, int inAttack, int inDefence, double inSpeed); // constructor
    ~character() = default; // default destructor

};



// class player
class player : public character
{
private:
    int luck{};

public:
    player() = default; // default constructor
    player(std::string inName, int inHP, int inAttack, int inDefence, double inSpeed, int inLuck); // constructor
    void InsertName(); // method to insert the name of the character
    void randomAttack(); // method to generate a random attack value based on the character's attack stat
    void randomDefence(); // method to generate a random defence value based on the character's
    void randomLuck(); // method to generate a random luck value based on the character's
    void PrintStats(); // print player stats
};



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