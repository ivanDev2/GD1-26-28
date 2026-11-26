#include "dungeon.h"
#include <iostream>
#include <random>

dungeon::dungeon(int r, int c) : rows(r), cols(c) {
    generate();
}

void dungeon::generate(int floor, int maxFloor){

    // Generate the dungeon layout
    rooms.assign(rows, std::vector<roomType>(cols, roomType::Empty));

    // place the exit room at the bottom right corner
    rooms[rows - 1][cols - 1] = roomType::Exit;

    if(floor < maxFloor){
        placeRooms(static_cast<int>(roomType::Enemy), 12); // place 10 enemy rooms
        placeRooms(static_cast<int>(roomType::Trap), 10); // place 5 trap rooms
        placeRooms(static_cast<int>(roomType::Loot), 15); // place 5 loot rooms
        placeRooms(static_cast<int>(roomType::Stairs),1); //pace 1 stairs room
    } else{
        placeRooms(static_cast<int>(roomType::Boss), 1); // place 1 boss room
    }
    
    

}

// Private method for generating N rooms of a specific type in the dungeon
void dungeon::placeRooms(int type, int count)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> disRow(0, rows - 1);
    std::uniform_int_distribution<> disCol(0, cols - 1);

    int placedRooms = 0;
    while (placedRooms < count)
    {
        int r = disRow(gen);
        int c = disCol(gen);

        if((r != 0 || c!= 0) && rooms[r][c] == roomType::Empty) // Ensure not placing in the starting room (0,0)
        {
            rooms[r][c] = static_cast<roomType>(type);
            placedRooms++;
        }

    }

}

void dungeon::print(const player& p) const
{
    for (int r = 0; r < rows; ++r)
    {
        //print the top border of the row
        for (int c = 0; c < cols; ++c)
        {
            std::cout <<"+---";
        }
        std::cout <<"+\n";

        //print the cells of the row
        for (int c = 0; c < cols; ++c)
        {
            char simbol = ' ';

            if (r == p.getX() && c == p.getY())
            {
                simbol = 'P'; // Player's position
            }
            else
            {
                switch (rooms[r][c])
                {
                    case roomType::Empty: simbol = ' '; break;
                    case roomType::Enemy: simbol = ' '; break;
                    case roomType::Trap:  simbol = ' '; break;
                    case roomType::Loot:  simbol = ' '; break;
                    case roomType::Stairs:simbol = 'S'; break;
                    case roomType::Boss:  simbol = ' '; break;
                    case roomType::Exit:  simbol = 'X'; break;
                   
                        
                }
            }
            std::cout << "| " << simbol << " ";
        }
        std::cout <<"|\n";
    }

    for (int c = 0; c < cols; ++c)
    {
        std::cout << "+---";
    }
    std::cout << "+\n";
}


bool dungeon::isValidMove(int x, int y) const
{
    return( x >= 0 && x < rows && y >= 0 && y < cols);

}


roomType dungeon::getRoomType(int x, int y) const
{
    if (isValidMove(x, y))
    {
        return rooms[x][y];
    }
    return roomType::Empty;
}


void dungeon::clearrooms(int x, int y)
{
    if (isValidMove(x, y))
    {
        rooms[x][y] = roomType::Empty;
    }
}