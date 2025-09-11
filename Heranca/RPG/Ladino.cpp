#include "Ladino.h"

// Atributos base para um Ladino Humano.
Ladino::Ladino(std::string nome)
    : Humano(nome, 80, 10, 10, 20) {} // nome, vida, forca, int, agi

std::string Ladino::getNomeClasse() const {
    return "Ladino";
}

// O ataque do ladino é baseado na AGILIDADE e tem chance de dano crítico.
void Ladino::atacar(Personagem& alvo) {
    int dano = this->agilidade;
    std::cout << this->nome << " tenta um Ataque Furtivo com suas adagas!" << std::endl;

    // Chance de 25% de acerto crítico (dano dobrado)
    if ((rand() % 4) == 0) {
        dano *= 2;
        std::cout << " >> ACERTO CRITICO! << " << std::endl;
    }
    alvo.receberDano(dano);
}