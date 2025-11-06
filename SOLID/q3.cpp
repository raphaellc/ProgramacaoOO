#include <iostream>
#include <string>

class Saudador {
private:
    std::string formalidade;

public:
    std::string saudar() {
        if (this->formalidade == "formal") {
            return "Boa noite, senhor.";
        } else if (this->formalidade == "casual") {
            return "E aí, cara?";
        } else if (this->formalidade == "intimo") {
            return "Olá, querido(a)!";
        } else {
            return "Olá.";
        }
    }

    void definirFormalidade(std::string formalidade) {
        this->formalidade = formalidade;
    }
};

int main() {
    Saudador saudador;

    saudador.definirFormalidade("formal");
    std::cout << saudador.saudar() << std::endl;

    saudador.definirFormalidade("casual");
    std::cout << saudador.saudar() << std::endl;

    saudador.definirFormalidade("intimo");
    std::cout << saudador.saudar() << std::endl;

    saudador.definirFormalidade("outro");
    std::cout << saudador.saudar() << std::endl;

    return 0;
}