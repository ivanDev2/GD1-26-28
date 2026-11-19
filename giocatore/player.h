#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class player {
private:
    std::string nickname;
    int difesa{}; // difesa del player
    int attacco{}; // attacco del player
    int velocità{1.5}; // velocità del player in m/s 
    double x{0.0}; // posizione del player sull'asse x 

public:
    player() = default;
    player(std::string inNickname, int inDifesa, int inAttacco, int inVelocità);
    void Insertnickname(); // funzione per inserire il nickname del player
    void Printdifesa(); // funzione per stampare la difesa del player
    void Printattacco(); // funzione per stampare l'attacco del player
    //void Printvelocità(); // funzione per stampare la velocità del player
    void muovi(char direzione); // funzione per muovere il player in base alla direzione e al tempo trascorso
};

#endif
