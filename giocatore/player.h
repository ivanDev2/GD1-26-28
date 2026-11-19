#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class player {
private:
    std::string nickname;
    int difesa{};
    int attacco{};
    int velocità{};

public:
    player() = default;
    player(std::string inNickname, int inDifesa, int inAttacco, int inVelocità);
    void Insertnickname();
    void Printdifesa();
    void Printattacco();
    void Printvelocità();
};

#endif
