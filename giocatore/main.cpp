//creare un programma che permette di chiedere in input il nickname, la difesa, l'attacco e la velocità (noi andremo a sceglier il valore massimo per difesa attacco e velocità).

#include <iostream>
#include <string>

class player{

    private:
        std::string nickname;
        int difesa;
        int attacco;
        int velocità;

    public:
        player(std::string inNickname, int inDifesa, int inAttacco, int inVelocità){

            nickname = inNickname;
            difesa = inDifesa;
            attacco = inAttacco;
            velocità = inVelocità;

            std::cout << "created new caracter with nickname: " << nickname << " difesa: " << difesa << " attacco: " << attacco << " velocità: " << velocità << std::endl;

        }

        void Insertnickname()
        {
            std::cout << "insert your nickname: ";
            std::getline(std::cin, nickname);
            std::cout << "Your nickname is: " << nickname << std::endl;
        }

        void Printdifesa()
        {
            std::cout << "insert your difesa: ";
            if(difesa < 0 || difesa > 150){
                std::cout << "invalid value " << std::endl;
            } else {
                std::getline(std::cin, difesa);
                std::cout << "Your difesa is: " << difesa << std::endl;
            }
            
        }
        
        void Printattacco()
        {
            std::cout << "insert your attacco: ";
            if(attacco < 0 || attacco > 70){
                std::cout << "invalid value " << std::endl;
            } else {
                std::getline(std::cin, attacco);
                std::cout << "Your attacco is: " << attacco << std::endl;
            }
        }

        void Printvelocità()
        {
            std::cout << "insert your velocità: ";
            if(velocità < 0 || velocità > 100){
                std::cout << "invalid value " << std::endl;
            } else {
                std::getline(std::cin, velocità);
                std::cout << "Your velocità is: " << velocità << std::endl;
            }
        }
};

int main(){

    player p;

    p.Insertnickname();
    p.Printdifesa();
    p.Printattacco();
    p.Printvelocità();

    return 0;
}