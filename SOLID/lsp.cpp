#include <iostream>
#include <stdexcept>

class Ave {
public:
    virtual void voar() {
        std::cout << "Estou voando!" << std::endl;
    }
};

class PicaPau : public Ave {
    
};


class Pinguim : public Ave {
public:
    void voar() override {
        throw std::runtime_error("Pinguins não voam!");
    }
};


void fazerAveVoar(Ave& ave) {
    ave.voar();
}

int main() {
    PicaPau pp;
    Pinguim p;

    fazerAveVoar(pp); // Funciona
    // fazerAveVoar(p);  // Quebra a aplicação (lança exceção)
    return 0;
}