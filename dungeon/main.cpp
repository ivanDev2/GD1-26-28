#include <iostream>
#include <string>
#include "character.h"


int main() {
    player p;
    p.InsertName();
    p.randomAttack();
    p.randomDefence();
    p.randomLuck();
    p.PrintStats();

    return 0;
}
