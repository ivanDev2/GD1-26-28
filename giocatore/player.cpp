#include "player.h"
#include <iostream>

using namespace std;

player::player(std::string inNickname, int inDifesa, int inAttacco, double inVelocità)
{
    nickname = inNickname;
    difesa = inDifesa;
    attacco = inAttacco;
    velocità = inVelocità;
    std::cout << "created new caracter with nickname: " << nickname << " difesa: " << difesa << " attacco: " << attacco << " velocità: " << velocità << std::endl;
}

void player::Insertnickname()
{
    std::cout << "insert your nickname: ";
    std::cin >> nickname;
    std::cout << "Your nickname is: " << nickname << std::endl;
}

void player::Printdifesa()
{
    std::cout << "insert your defense between 0 and 150: ";
    std::cin >> difesa;
    if (difesa < 0 || difesa > 150)
    {
        std::cout << "invalid value " << std::endl;
    }
    else
    {
        std::cout << "Your defense is: " << difesa << std::endl;
    }
}

void player::Printattacco()
{
    std::cout << "insert your attack between 0 and 70: ";
    std::cin >> attacco;
    if (attacco < 0 || attacco > 70)
    {
        std::cout << "invalid value " << std::endl;
    }
    else
    {
        std::cout << "Your attack is: " << attacco << std::endl;
    }
}

void player::AggiornaMovimento(char tasto, double dt) {
    if (tasto == 'd' || tasto == 'D') {
        x += velocità * dt;
    }
    else if (tasto == 'a' || tasto == 'A') {
        x -= velocità * dt;
    }
}

double player::GetX() const {
    return x;
}

std::string player::GetNickname() const {
    return nickname;
}
