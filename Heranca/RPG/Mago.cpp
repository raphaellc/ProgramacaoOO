#include "Mago.h"

// Atributos base para um Mago Elfo.
Mago::Mago(std::string nome)
    : Elfo(nome, 70, 5, 20, 15) {} // nome, vida, forca, int, agi

std::string Mago::getNomeClasse() const {
    return "Mago";
}

// O ataque do mago é baseado na INTELIGÊNCIA.
void Mago::atacar(Personagem& alvo) {
    int dano = this->inteligencia + (rand() % 4); // Dano = inteligencia + um dado de 4 lados
    std::cout << this->nome << " lanca uma Bola de Fogo!" << std::endl;
    alvo.receberDano(dano);
}