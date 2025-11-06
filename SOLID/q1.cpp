#include <iostream>
#include <string>
#include <vector>

class Tabuleiro {
public:
    std::vector<std::string> posicoes;

    // Construtor
    Tabuleiro() {
        for (int i = 0; i < 9; ++i) {
            this->posicoes.push_back(std::to_string(i));
        }
    }

    std::vector<std::string> primeiraLinha() {
        std::vector<std::string> linha;
        linha.push_back(this->posicoes.at(0));
        linha.push_back(this->posicoes.at(1));
        linha.push_back(this->posicoes.at(2));
        return linha;
    }

    std::vector<std::string> segundaLinha() {
        std::vector<std::string> linha;
        linha.push_back(this->posicoes.at(3));
        linha.push_back(this->posicoes.at(4));
        linha.push_back(this->posicoes.at(5));
        return linha;
    }

    std::vector<std::string> terceiraLinha() {
        std::vector<std::string> linha;
        linha.push_back(this->posicoes.at(6));
        linha.push_back(this->posicoes.at(7));
        linha.push_back(this->posicoes.at(8));
        return linha;
    }

    void exibir() {
        std::string linhaFormatada = 
            this->posicoes.at(0) + " | " + this->posicoes.at(1) + " | " + this->posicoes.at(2) + "\n" +
            this->posicoes.at(3) + " | " + this->posicoes.at(4) + " | " + this->posicoes.at(5) + "\n" +
            this->posicoes.at(6) + " | " + this->posicoes.at(7) + " | " + this->posicoes.at(8);
        
        std::cout << linhaFormatada << std::endl;
    }
};

int main() {
    Tabuleiro tabuleiro;
    tabuleiro.exibir();
    return 0;
}