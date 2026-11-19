//creare un programma che permette di chiedere in input il nickname, la difesa, l'attacco e la velocità (noi andremo a sceglier il valore massimo per difesa attacco e velocità).

#include <iostream>
#include <string>
#include "player.h"

using namespace std;

int main() {
    player p;
    p.Insertnickname();
    p.Printdifesa();
    p.Printattacco();
    p.Printvelocità();
    return 0;
}
