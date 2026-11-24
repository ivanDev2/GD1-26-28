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
    std::cout << "COMBATTIMENTO CONTRO: " << e.getName() << "!\n";
    std::cout << "========================================\n";

    // Chi ha la Speed più alta inizia per primo
    bool playerTurn = (p.getSpeed() >= e.getSpeed());
    if (playerTurn)
        std::cout << "Sei piu' veloce! Attacchi per primo.\n";
    else
        std::cout << e.getName() << " e' piu' veloce e attacca per primo!\n";

    while (p.isAlive() && e.isAlive())
    {
        std::cout << "\n[TU] HP: " << p.getHP() << " | ATK: " << p.getTotalAttack() << " | DEF: " << p.getTotalDefence() << "\n";
        std::cout << "[" << e.getName() << "] HP: " << e.getHP() << " | ATK: " << e.getAttack() << " | DEF: " << e.getDefence() << "\n";

        if (playerTurn)
        {
            // Applica eventuali danni da veleno ad ogni turno
            p.updateStatusEffects();
            if (!p.isAlive()) break;

            std::cout << "Scegli azione (1 = Attacca, 2 = Inventario/Usa Pozione): ";
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
                    std::cout << "COLPO CRITICO! ";
                }

                e.takeDamage(damage);
                std::cout << "Infliggi " << damage << " danni a " << e.getName() << "!\n";
            }
        }
        else
        {
            // Turno del nemico
            int damage = (e.getAttack() * 100) / (100 + p.getTotalDefence());
            if (damage < 1) damage = 1;

            p.takeDamage(damage);
            std::cout << e.getName() << " ti infligge " << damage << " danni!\n";
        }

        playerTurn = !playerTurn;
    }

    if (p.isAlive())
    {
        std::cout << "\nHai sconfitto " << e.getName() << "!\n";
        return true;
    }
    else
    {
        std::cout << "\nSei stato sconfitto da " << e.getName() << "...\n";
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

        std::cout << "Comandi (W/A/S/D = Muovi, I = Inventario, P = Stats, Q = Esci): ";
        std::cin >> input;
        input = std::toupper(input);

        if (input == 'Q') {
            std::cout << "Partita terminata.\n";
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
                std::cout << "Tasto non valido! Usa W, A, S, D, I o P.\n";
                continue;
        }

        // Edge control
        if (!dungeon.isValidMove(nextX, nextY)) {
            std::cout << "Muro! Non puoi andare in quella direzione.\n";
            continue;
        }

        // Move 'p' to the new cell & update poison damage
        p.setPosition(nextX, nextY);
        p.updateStatusEffects();

        if (!p.isAlive()) {
            std::cout << "\nIl veleno ti ha ucciso! GAME OVER.\n";
            break;
        }

        // Check what's in the room
        roomType room = dungeon.getRoomType(nextX, nextY);

        switch (room) {
            case roomType::Empty:
                std::cout << "Stanza vuota.\n";
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
                    std::cout << "Sei morto nella trappola! GAME OVER.\n";
                    isPlaying = false;
                } else {
                    dungeon.clearrooms(nextX, nextY);
                }
                break;
            }

            case roomType::Loot:
                std::cout << "Tesoro trovato!\n";
                p.addItem(generateRandomLoot());
                dungeon.clearrooms(nextX, nextY);
                break;

            case roomType::Boss:
            {
                std::cout << "Il Drago Boss e' qui!\n";
                dragon boss;
                if (startCombat(p, boss)) {
                    std::cout << "\nINCREDIBILE! Hai sconfitto il Drago e completato il dungeon! VITTORIA!\n";
                } else {
                    std::cout << "\nIl Drago ti ha sconfitto... GAME OVER.\n";
                }
                isPlaying = false;
                break;
            }

            case roomType::Exit:
                dungeon.print(p);
                std::cout << "Hai trovato l'uscita! Vittoria!\n";
                isPlaying = false;
                break;
        }
    }

    return 0;
}
