#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class player {
private:
    std::string nickname;
    int difesa{};
    int attacco{};
    int velocità{};
    int x{0};

public:
    player() = default;
    player(std::string inNickname, int inDifesa, int inAttacco, int inVelocità);
    void Insertnickname();
    void Printdifesa();
    void Printattacco();
    void Printvelocità();
    void muovi(char direzione);
};

#endif
