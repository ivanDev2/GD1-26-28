#ifndef TRAP_H
#define TRAP_H

#include "character.h"

enum class TrapType
{
    Spike,
    Poison,
    Explosive
};

class Trap
{
private:
    TrapType type;

public:
    Trap(); // Costruttore che sceglie casualmente uno dei 3 tipi
    void trigger(player& p) const; // Attiva l'effetto sul giocatore
};

#endif
