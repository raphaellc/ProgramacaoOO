#include <iostream>
#include <string>
#include <stdexcept>

// Classe abstrata "Ave"
class Ave {
public:
    virtual ~Ave() {} 
    virtual void voar() = 0; 
    virtual void trocarPenas() = 0; 
};

class Aguia : public Ave {
public:
    std::string localizacaoAtual;
    int numeroDePenas;

    Aguia(int contagemInicialPenas) {
        this->numeroDePenas = contagemInicialPenas;
    }

    void voar() override {
        this->localizacaoAtual = "no ar";
        std::cout << "Águia está voando. Localização: " << this->localizacaoAtual << std::endl;
    }

    void trocarPenas() override {
        this->numeroDePenas -= 1;
        std::cout << "Águia trocando penas. Penas: " << this->numeroDePenas << std::endl;
    }
};

class Pinguim : public Ave {
public:
    std::string localizacaoAtual;
    int numeroDePenas;

    Pinguim(int contagemInicialPenas) {
        this->numeroDePenas = contagemInicialPenas;
    }

    void trocarPenas() override {
        this->numeroDePenas -= 1;
        std::cout << "Pinguim trocando penas. Penas: " << this->numeroDePenas << std::endl;
    }

    void voar() override {
        throw std::runtime_error("Pinguins não podem voar!");
    }

    void nadar() {
        this->localizacaoAtual = "na água";
        std::cout << "Pinguim está nadando. Localização: " << this->localizacaoAtual << std::endl;
    }
};

int main() {
    Aguia aguia(100);
    aguia.voar();
    aguia.trocarPenas();

    std::cout << "---" << std::endl;

    Pinguim pinguim(50);
    pinguim.nadar();
    pinguim.trocarPenas();

    try {
        pinguim.voar();
    } catch (const std::exception& e) {
        std::cout << "Exceção capturada: " << e.what() << std::endl;
    }

    return 0;
}