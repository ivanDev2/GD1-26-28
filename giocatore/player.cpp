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
    std::getline(std::cin >> std::ws, nickname);
}


void player::Printdifesa()
{
    std::cout << "insert your defense between 0 and 150: ";
    std::cin >> difesa;
    while (difesa < 0 || difesa > 150)
    {
        std::cout << "invalid value, please insert your defense between 0 and 150: ";
        std::cin >> difesa;
    }
}

void player::Printattacco()
{
    std::cout << "insert your attack between 0 and 70: ";
    std::cin >> attacco;
    while (attacco < 0 || attacco > 70)
    {
        std::cout << "invalid value, please insert your attack between 0 and 70: ";
        std::cin >> attacco;
    }
}

void player::printstats() {
    std::cout << "Player Stats:\n";
    std::cout << "Nickname: " << nickname << "\n";
    std::cout << "Defense: " << difesa << "\n";
    std::cout << "Attack: " << attacco << "\n";
}

void player::AggiornaMovimento(char tasto, double dt) {
    if (tasto == 'w' || tasto == 'W') {
        y += velocità * dt; // Avanti (asse Y)
    }
    else if (tasto == 's' || tasto == 'S') {
        y -= velocità * dt; // Indietro (asse Y)
    }
    else if (tasto == 'd' || tasto == 'D') {
        x += velocità * dt; // Destra (asse X)
    }
    else if (tasto == 'a' || tasto == 'A') {
        x -= velocità * dt; // Sinistra (asse X)
    }
}


double player::GetX() const {
    return x;
}

double player::GetY() const{
    return y;
}

std::string player::GetNickname() const {
    return nickname;
}
