#include <iostream>
#include <string>
#include <cctype>
#include "character.h"
#include "dungeon.h"


int main() {
    player p;
    p.InsertName();
    p.randomHP();
    p.randomAttack();
    p.randomDefence();
    p.randomSpeed();
    p.randomLuck();
    p.PrintStats();

    dungeon dungeon(4, 5);

    bool isPlaying = true;
    char input{};

    while(isPlaying)
    {
        std::cout << "\n";
        dungeon.print(p);

        std::cout << "Muoviti ( W = Su, S = Giu, A = Sinistra, D = Destra, Q = Esci): ";
        std::cin >> input;
        input = std::toupper(input);

        if (input == 'Q') {
            std::cout << "Partita terminata.\n";
            break;
        }

        int nextX = p.getX();
        int nextY = p.getY();

        switch (input) {
            case 'W': nextX--; break;
            case 'S': nextX++; break;
            case 'A': nextY--; break;
            case 'D': nextY++; break;
            default:
                std::cout << "Tasto non valido! Usa W, A, S o D.\n";
                continue;
        }

        // Edge control
        if (!dungeon.isValidMove(nextX, nextY)) {
            std::cout << "Muro! Non puoi andare in quella direzione.\n";
            continue;
        }

        // Move 'p' to the new cell
        p.setPosition(nextX, nextY);

        // Check what's in the room
        roomType room = dungeon.getRoomType(nextX, nextY);

        switch (room) {
            case roomType::Empty:
                std::cout << "Stanza vuota.\n";
                break;
            case roomType::Enemy:
                std::cout << "Hai incontrato un nemico!\n";
                dungeon.clearrooms(nextX, nextY);
                break;
            case roomType::Trap:
                std::cout << "Trappola!\n";
                dungeon.clearrooms(nextX, nextY);
                break;
            case roomType::Loot:
                std::cout << "Tesoro trovato!\n";
                dungeon.clearrooms(nextX, nextY);
                break;
            case roomType::Boss:
                std::cout << "Il Drago Boss e' qui!\n";
                dungeon.clearrooms(nextX, nextY);
                break;
            case roomType::Exit:
                dungeon.print(p);
                std::cout << "Hai trovato l'uscita! Vittoria!\n";
                isPlaying = false;
                break;
        }
    }

    return 0;
}
