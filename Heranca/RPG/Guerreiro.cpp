#include "Guerreiro.h"

// O construtor define os atributos base para um Guerreiro Orc.
Guerreiro::Guerreiro(std::string nome)
    : Orc(nome, 100, 15, 5, 10) {} // nome, vida, forca, int, agi

std::string Guerreiro::getNomeClasse() const {
    return "Guerreiro";
}

// O ataque do guerreiro é baseado na FORÇA.
void Guerreiro::atacar(Personagem& alvo) {
    int dano = this->forca + (rand() % 6); // Dano = forca + um valor aleatório de um dado de 6 lados
    std::cout << this->nome << " usa seu machado em um Ataque Poderoso!" << std::endl;
    alvo.receberDano(dano);
}