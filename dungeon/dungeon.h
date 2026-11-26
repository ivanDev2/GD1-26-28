#ifndef DUNGEON_H
#define DUNGEON_H

#include <vector>
#include "character.h"

enum class roomType
{
    Empty,
    Enemy,
    Trap,
    Loot,
    Boss,
    Exit
};



class dungeon
{
private:
    dungeon() = default; // default constructor
    int rows{};
    int cols{};
    std::vector<std::vector<roomType>> rooms; // 2D vector to represent the dungeon layout

    void placeRooms(int type, int count); // method to generate the dungeon layout

public:
    dungeon(int r=15, int c=15);
    ~dungeon() = default;

    void generate(); // method to generate the dungeon layout

    void print(const player& p) const; // method to print the player's position in the dungeon
    
    bool isValidMove(int x, int y) const; // method to check if the player's move is valid

    roomType getRoomType(int x, int y) const; // method to get the type of room at the given coordinates

    void clearrooms(int x, int y); // method to clear the dungeon layout
};


#endif // DUNGEON_H