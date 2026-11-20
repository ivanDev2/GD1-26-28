#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class player {
private:
    std::string nickname;
    int difesa{};
    int attacco{};
    double velocità{2.5};
    double x{0.0};
    double y{0.0};

public:
    player() = default;
    player(std::string inNickname, int inDifesa, int inAttacco, double inVelocità);
    void Insertnickname();
    void Printdifesa();
    void Printattacco();
    void printstats();
    void AggiornaMovimento(char tasto, double dt);
    double GetX() const;
    double GetY() const;
    std::string GetNickname() const;
};

#endif
