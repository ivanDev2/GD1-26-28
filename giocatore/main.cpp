#include <iostream>
#include <chrono>
#include <thread>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <iomanip>
#include <string>
#include "player.h"

using namespace std;

char leggiTastoNonBloccante() {
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    int oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    char ch = 0;
    read(STDIN_FILENO, &ch, 1);

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    return ch;
}

int main() {
    player p;
    p.Insertnickname();
    p.Printdifesa();
    p.Printattacco();
    p.printstats();

    std::cout << "\nHold [W] forward, [S] back, [A] left, [D] right, [Q] to quit.\n" << std::endl;

    auto tempoPrecedente = std::chrono::steady_clock::now();
    double xPrecedente = p.GetX();
    double yPrecedente = p.GetY();
    std::string direzioneTesto = "";

    while (true) {
        char tasto = leggiTastoNonBloccante();

        if (tasto == 'q' || tasto == 'Q') {
            break;
        }

        // Aggiorna il testo della direzione solo quando premi un tasto valido
        if (tasto == 'w' || tasto == 'W') {
            direzioneTesto = "moving forward";
        } else if (tasto == 's' || tasto == 'S') {
            direzioneTesto = "moving back";
        } else if (tasto == 'a' || tasto == 'A') {
            direzioneTesto = "moving left";
        } else if (tasto == 'd' || tasto == 'D') {
            direzioneTesto = "moving right";
        }

        auto tempoAttuale = std::chrono::steady_clock::now();
        std::chrono::duration<double> intervallo = tempoAttuale - tempoPrecedente;
        double dt = intervallo.count();
        tempoPrecedente = tempoAttuale;

        p.AggiornaMovimento(tasto, dt);

        // Stampa sulla stessa riga (\r) solo quando la posizione cambia
        if (p.GetX() != xPrecedente || p.GetY() != yPrecedente) {
            std::cout << "\r" << p.GetNickname() << " is " << direzioneTesto 
                      << " | Position: (" << std::fixed << std::setprecision(2) 
                      << p.GetX() << " m, " << p.GetY() << " m) from start          " 
                      << std::flush;

            xPrecedente = p.GetX();
            yPrecedente = p.GetY();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    std::cout << "\nGame over." << std::endl;
    return 0;
}
