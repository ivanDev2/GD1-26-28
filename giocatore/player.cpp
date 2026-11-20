#include "player.h"
#include <iostream>

using namespace std;

player::player(std::string inNickname, int inDifesa, int inAttacco, double inVelocità) // metodo costruttore
{
    nickname = inNickname;
    difesa = inDifesa;
    attacco = inAttacco;
    velocità = inVelocità;
    std::cout << "created new caracter with nickname: " << nickname << " difesa: " << difesa << " attacco: " << attacco << " velocità: " << velocità << std::endl;
}

void player::Insertnickname() // metodo per l'inserimento del nickname
{
    std::cout << "insert your nickname: ";
    std::getline(std::cin >> std::ws, nickname);
}


void player::Printdifesa() //metodo per l'iserimento della difesa 
{
    std::cout << "insert your defense between 0 and 150: ";
    std::cin >> difesa;
    while (difesa < 0 || difesa > 150)
    {
        std::cout << "invalid value, please insert your defense between 0 and 150: ";
        std::cin >> difesa;
    }
}

void player::Printattacco() //metodo per l'inserimento dell'attacco
{
    std::cout << "insert your attack between 0 and 70: ";
    std::cin >> attacco;
    while (attacco < 0 || attacco > 70)
    {
        std::cout << "invalid value, please insert your attack between 0 and 70: ";
        std::cin >> attacco;
    }
}

void player::printstats() //metodo per la stampa a schermo delle statistiche del player
{
    std::cout << "--------------------------" << std::endl;
    std::cout << "Player Stats:\n";
    std::cout << "Nickname: " << nickname << "\n";
    std::cout << "Defense: " << difesa << "\n";
    std::cout << "Attack: " << attacco << "\n";
    std::cout << "--------------------------" << std::endl;
}

void player::AggiornaMovimento(char tasto, double dt) // metodo per definire i tasti e la distanza del movimento
{
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

    const double limite = 5.0; // Limite di movimento in metri
    bool toccaMuro = false;

    if (x >= limite) {
        x = limite;
        toccaMuro = true;
    }
    else if (x <= -limite) {
        x = -limite;
        toccaMuro = true;
    }
    if (y >= limite) {
        y = limite;
        toccaMuro = true;   
    }
    if (y <= -limite) {
        y = -limite;
        toccaMuro = true;
    }

    if (toccaMuro && !controIlmuro){
        std::cout << "\nYou hit a wall!" << std::endl;
        controIlmuro = true; // Imposta il flag per indicare che il giocatore ha colpito un muro
    }
    else if (!toccaMuro) {
        controIlmuro = false; // Resetta il flag se il giocatore non sta toccando un muro
    }


}


double player::GetX() const 
{
    return x;
}

double player::GetY() const
{
    return y;
}

std::string player::GetNickname() const 
{
    return nickname;
}
