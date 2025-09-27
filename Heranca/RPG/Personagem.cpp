#include "Personagem.h"

Personagem::Personagem(std::string nome, int vida, int forca, int inteligencia, int agilidade)
    : nome(nome), vidaMaxima(vida), vidaAtual(vida), forca(forca), inteligencia(inteligencia), agilidade(agilidade) {}

void Personagem::receberDano(int dano) {
    vidaAtual -= dano;
    if (vidaAtual < 0) {
        vidaAtual = 0;
    }
    std::cout << nome << " recebeu " << dano << " de dano e agora tem " << vidaAtual << " de vida." << std::endl;
}

bool Personagem::estaVivo() const {
    return vidaAtual > 0;
}

void Personagem::exibirInfo() const {
    std::cout << "-----------------------------------\n"
              << "Nome: " << this->nome << " (" << this->getNomeRaca() << " " << this->getNomeClasse() << ")\n"
              << "Vida: " << this->vidaAtual << "/" << this->vidaMaxima << "\n"
              << "Forca: " << this->forca << " | Inteligencia: " << this->inteligencia << " | Agilidade: " << this->agilidade << "\n"
              << "-----------------------------------\n";
}

int Personagem::obterAgilidade() const {
    return this->agilidade;
}