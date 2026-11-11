

#include <iostream>

int somma();
int potenza();
int moltiplicazione();




int main(){

    int a,b,c;

    a = somma();
    b = moltiplicazione();

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    return 0;


}


int somma(){

    int num1 = 2, num2 = 6, risultato = 0;

    risultato = num1 + num2;

    return risultato;
}

int moltiplicazione(){

    int num1 = 2, num2 = 4, risultato = 0;

    risultato = num1 * num2;

    return risultato;
}
