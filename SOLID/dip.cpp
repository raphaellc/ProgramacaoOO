#include <iostream>

class Lampada {
public:
    void ligar() {
        std::cout << "Lâmpada acesa." << std::endl;
    }
    void desligar() {
        std::cout << "Lâmpada apagada." << std::endl;
    }
};


class Interruptor {
public:
    Lampada lamp; 
    bool ligado = false;

    void pressionar() {
        if (ligado) {
            lamp.desligar();
            ligado = false;
        } else {
            lamp.ligar();
            ligado = true;
        }
    }
};

int main() {
    Interruptor i;
    i.pressionar();
    i.pressionar();
    return 0;
}