//creare un programma che permette di chiedere in input il nickname, la difesa, l'attacco e la velocità (noi andremo a sceglier il valore massimo per difesa attacco e velocità).

#include <iostream>
#include <chrono>
#include <thread>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include "player.h"

using namespace std;

// Funzione per leggere un tasto su Linux/Mac senza premere Invio
char leggiTastoNonBloccante() {
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // Disattiva l'attesa di Invio e la stampa del carattere
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    int oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    char ch = 0;
    read(STDIN_FILENO, &ch, 1);

    // Ripristina le impostazioni normali del terminale
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    return ch;
}

int main() {
    player p;
    p.Insertnickname();
    p.Printdifesa();
    p.Printattacco();

    std::cout << "\nHold [D] to move forward, [A] to move back, [Q] to quit.\n" << std::endl;

    auto tempoPrecedente = std::chrono::steady_clock::now();
    double posizionePrecedente = p.GetX();

    while (true) {
        char tasto = leggiTastoNonBloccante();

        if (tasto == 'q' || tasto == 'Q') {
            break;
        }

        auto tempoAttuale = std::chrono::steady_clock::now();
        std::chrono::duration<double> intervallo = tempoAttuale - tempoPrecedente;
        double dt = intervallo.count();
        tempoPrecedente = tempoAttuale;

        p.AggiornaMovimento(tasto, dt);

        if (p.GetX() != posizionePrecedente) {
            std::cout << "\r" << p.GetNickname() << " is at " << p.GetX() << " m from start    " << std::flush;
            posizionePrecedente = p.GetX();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }

    std::cout << "\nGame over." << std::endl;
    return 0;
}
