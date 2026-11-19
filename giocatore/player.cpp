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

/*void player::Printvelocità()
{
    std::cout << "insert your velocità in m/s: ";
    std::cin >> velocità;
    if (velocità < 0 || velocità > 100)
    {
        std::cout << "invalid value " << std::endl;
    }
    else
    {
        std::cout << "Your velocità is: " << velocità << std::endl;
    }
}*/

void player::muovi(char direzione)
{
    const double tempopasso = 1.0; 

    double distanza = 0;

    const double velcamminata = 1.5;
    const double velcorsa = 3.0;

    if(direzione == 'w' || direzione == 'W'){
        velocità = velcamminata;
        x+=velocità * tempopasso;
        std::cout << "Player " << nickname << " moved to position relative to the start forward by: 1.5 m" << std::endl;
    }else if(direzione == 's' || direzione == 'S'){
        velocità = velcamminata;
        x-=velocità * tempopasso;
        std::cout << "Player " << nickname << " moved to position relative to the start backward by: 1.5 m" << std::endl;  
    }else if(direzione == 'r' || direzione == 'R'){
        velocità = velcorsa;
        x+=velocità * tempopasso;
        std::cout << "Player " << nickname << " moved to position relative to the start forward by: 3.0 m" << std::endl;
    }else if(direzione == 'f' || direzione == 'F'){
        velocità = velcorsa;
        x-=velocità * tempopasso;
        std::cout << "Player " << nickname << " moved to position relative to the start backward by: 3.0 m" << std::endl;
    }

    std::cout << "Current position of player " << nickname << " is: " << x << " m" << std::endl;
}

