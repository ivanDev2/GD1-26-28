#include <iostream>
#include <string>
#include <cctype>
#include <random>
#include "character.h"
#include "dungeon.h"
#include "trap.h"
#include "item.h"

// Funzione per gestire il combattimento a turni
bool startCombat(player& p, enemy& e)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> critRoll(1, 100);

    std::cout << "\n========================================\n";
    std::cout << "COMBAT AGAINST: " << e.getName() << "!\n";
    std::cout << "========================================\n";

    // Chi ha la Speed più alta inizia per primo
    bool playerTurn = (p.getSpeed() >= e.getSpeed());
    if (playerTurn)
        std::cout << "You're faster! You attack first..\n";
    else
        std::cout << e.getName() << " It is faster and attacks first.!\n";

    while (p.isAlive() && e.isAlive())
    {
        std::cout << "\n[TU] HP: " << p.getHP() << " | ATK: " << p.getTotalAttack() << " | DEF: " << p.getTotalDefence() << "\n";
        std::cout << "[" << e.getName() << "] HP: " << e.getHP() << " | ATK: " << e.getAttack() << " | DEF: " << e.getDefence() << "\n";

        if (playerTurn)
        {
            // Applica eventuali danni da veleno ad ogni turno
            p.updateStatusEffects();
            if (!p.isAlive()) break;

            std::cout << "Choose action (1 = Attack, 2 = Inventory/Use Potion): ";
            int choice{};
            std::cin >> choice;

            if (choice == 2)
            {
                p.openInventory();
            }
            else
            {
                int damage = (p.getTotalAttack() * 100) / (100 + e.getDefence());
                if (damage < 1) damage = 1;

                // Colpo critico basato su Luck
                if (critRoll(gen) <= p.getLuck())
                {
                    damage *= 2;
                    std::cout << "CRITICAL HIT!";
                }

                e.takeDamage(damage);
                std::cout << "Inflict " << damage << " damage to " << e.getName() << "!\n";
            }
        }
        else
        {
            // Turno del nemico
            int damage = (e.getAttack() * 100) / (100 + p.getTotalDefence());
            if (damage < 1) damage = 1;

            p.takeDamage(damage);
            std::cout << e.getName() << "inflicts upon you" << damage << " damages!\n";
        }

        playerTurn = !playerTurn;
    }

    if (p.isAlive())
    {
        std::cout << "\nYou have defeated " << e.getName() << "!\n";
        return true;
    }
    else
    {
        std::cout << "\nYou have been defeated by " << e.getName() << "...\n";
        return false;
    }
}

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

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> enemyPicker(1, 3);

    bool isPlaying = true;
    char input{};

    while(isPlaying)
    {
        std::cout << "\n";
        dungeon.print(p);

        std::cout << "Controls (W/A/S/D = Move, I = Inventory, P = Stats, Q = Exit): ";
        std::cin >> input;
        input = std::toupper(input);

        if (input == 'Q') {
            std::cout << "Match finished.\n";
            break;
        }
        if (input == 'I') {
            p.openInventory();
            continue;
        }
        if (input == 'P') {
            p.PrintStats();
            continue;
        }

        int nextX = p.getX();
        int nextY = p.getY();

        switch (input) {
            case 'W': nextX--; break;
            case 'S': nextX++; break;
            case 'A': nextY--; break;
            case 'D': nextY++; break;
            default:
                std::cout << "Invalid key! Use W, A, S, D, I, or P.\n";
                continue;
        }

        // Edge control
        if (!dungeon.isValidMove(nextX, nextY)) {
            std::cout << "Wall! You can't go in that direction.\n";
            continue;
        }

        // Move 'p' to the new cell & update poison damage
        p.setPosition(nextX, nextY);
        p.updateStatusEffects();

        if (!p.isAlive()) {
            std::cout << "\nThe poison killed you! GAME OVER.\n";
            break;
        }

        // Check what's in the room
        roomType room = dungeon.getRoomType(nextX, nextY);

        switch (room) {
            case roomType::Empty:
                std::cout << "Empty room.\n";
                break;

            case roomType::Enemy:
            {
                int tipo = enemyPicker(gen);
                bool won = false;

                if (tipo == 1) { goblin g; won = startCombat(p, g); }
                else if (tipo == 2) { skeleton s; won = startCombat(p, s); }
                else { orc o; won = startCombat(p, o); }

                if (!won) {
                    std::cout << "GAME OVER!\n";
                    isPlaying = false;
                } else {
                    dungeon.clearrooms(nextX, nextY);
                }
                break;
            }

            case roomType::Trap:
            {
                Trap t;
                t.trigger(p);

                if (!p.isAlive()) {
                    std::cout << "You died in the trap! GAME OVER.\n";
                    isPlaying = false;
                } else {
                    dungeon.clearrooms(nextX, nextY);
                }
                break;
            }

            case roomType::Loot:
                std::cout << "Treasure found!\n";
                p.addItem(generateRandomLoot());
                dungeon.clearrooms(nextX, nextY);
                break;

            case roomType::Boss:
            {
                std::cout << "The Boss Dragon is here!\n";
                dragon boss;
                if (startCombat(p, boss)) {
                    std::cout << "\nINCREDIBLE! You’ve defeated the Dragon and completed the dungeon! VICTORY!\n";
                } else {
                    std::cout << "\nThe dragon has defeated you... GAME OVER.\n";
                }
                isPlaying = false;
                break;
            }

            case roomType::Exit:
                dungeon.print(p);
                std::cout << "You found the exit! Victory!\n";
                isPlaying = false;
                break;
        }
    }

    return 0;
}
