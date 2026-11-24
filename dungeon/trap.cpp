#include "trap.h"
#include <iostream>
#include <random>

Trap::Trap()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 2);
    type = static_cast<TrapType>(dis(gen));
}

void Trap::trigger(player& p) const
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> luckRoll(1, 100);

   // Dodge check based on the player's luck
    if (luckRoll(gen) <= (p.getLuck() / 2))
    {
        std::cout << "You noticed a trap and avoided it thanks to your luck.!\n";
        return;
    }

    switch (type)
    {
        case TrapType::Spike:
            std::cout << "SPIKE TRAP! Spikes emerge from the floor (-15 HP)!\n";
            p.takeDamage(15);
            break;

        case TrapType::Poison:
            std::cout << "POISON TRAP! A toxic cloud envelops you (5 damage for 3 turns)!\n";
            p.applyPoison(3, 5);
            break;

        case TrapType::Explosive:
            std::cout << "EXPLOSIVE TRAP! A landmine detonates beneath your feet (-35 HP)!\n";
            p.takeDamage(35);
            break;
    }
}
