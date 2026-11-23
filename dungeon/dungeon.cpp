#include "dungeon.h"
#include <iostream>
#include <random>

dungeon::dungeon(int r, int c) : rows(r), cols(c) {
    generate();
}

void dungeon::generate(){

    // Generate the dungeon layout
    rooms.assign(rows, std::vector<roomType>(cols, roomType::Empty));

    // place the exit room at the bottom right corner
    rooms[rows - 1][cols - 1] = roomType::Exit;

    generateDungeon(static_cast<int>(roomType::Enemy), 10); // place 10 enemy rooms
    generateDungeon(static_cast<int>(roomType::Trap), 5); // place 5 trap rooms
    generateDungeon(static_cast<int>(roomType::Loot), 5); // place 5 loot rooms
    generateDungeon(static_cast<int>(roomType::Boss), 1); // place 1 boss room

}
