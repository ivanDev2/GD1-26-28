#include "player.h"
#include <iostream>

using namespace std;

player::player(std::string inNickname, int inDifesa, int inAttacco, int inVelocità)
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
    std::cout << "insert your difesa: ";
    std::cin >> difesa;
    if (difesa < 0 || difesa > 150)
    {
        std::cout << "invalid value " << std::endl;
    }
    else
    {
        std::cout << "Your difesa is: " << difesa << std::endl;
    }
}

void player::Printattacco()
{
    std::cout << "insert your attacco: ";
    std::cin >> attacco;
    if (attacco < 0 || attacco > 70)
    {
        std::cout << "invalid value " << std::endl;
    }
    else
    {
        std::cout << "Your attacco is: " << attacco << std::endl;
    }
}

void player::Printvelocità()
{
    std::cout << "insert your velocità: ";
    std::cin >> velocità;
    if (velocità < 0 || velocità > 100)
    {
        std::cout << "invalid value " << std::endl;
    }
    else
    {
        std::cout << "Your velocità is: " << velocità << std::endl;
    }
}
void player::muovi(char direzione)
{
    if(direzione == 'w' || direzione == 'W'){
        x+=velocità;
    }else if(direzione == 's' || direzione == 'S'){
        x-=velocità;
    }else{
        std::cout << "invalid direction" << std::endl;
        return;
    }

    std::cout << nickname << "moved to position:" << x << std::endl;
}
}
