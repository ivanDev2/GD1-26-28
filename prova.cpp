#include <iostream>

int somma(int a, int b);
int potenza(int a, int b);
int moltiplicazione(int a, int b);




int main(){

    int a,b,c;
    int num1 = 4;
    int num2 = 3;
    int base = 4; 
    int esponente = 5;


    a = somma(num1, num2);
    b = moltiplicazione(num1, num2);
    c =potenza(base, esponente);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;


    return 0;


}


int somma(int num1, int num2){

    int risultato = 0;

    risultato = num1 + num2;

    return risultato;
}

int moltiplicazione(int num1, int num2){

    int risultato = 0;

    risultato = num1 * num2;

    return risultato;
}

int potenza(int base, int esponente ){

    int risultato = 1;

    for(int i = 0; i < esponente, i++;){

        risultato *=base;
    }

    risultato = base;

    return risultato;
}