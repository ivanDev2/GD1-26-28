#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class player {
private:
    std::string nickname;
    int difesa{};
    int attacco{};
    double velocità{5.0}; //velocità in km/h
    double x{0.0}; //posizione sull'asse x
    double y{0.0}; //posizione sull'asse y
    bool controIlmuro{false}; // flag per indicare se il giocatore ha colpito un muro

public:
    player() = default; // costruttore di default
    player(std::string inNickname, int inDifesa, int inAttacco, double inVelocità); //costruttore
    void Insertnickname(); // nickname del player
    void Printdifesa(); // difesa del player
    void Printattacco(); // attacco del player
    void printstats(); // statistiche del player
    void AggiornaMovimento(char tasto, double dt); // posizione del player
    double GetX() const;
    double GetY() const;
    std::string GetNickname() const;
};

#endif
