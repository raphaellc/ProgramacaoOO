#include "Elfo.h"

// Elfos são ágeis e inteligentes.
// O construtor recebe os atributos base e aplica os bônus raciais.
Elfo::Elfo(std::string nome, int vida, int forca, int inteligencia, int agilidade)
    : Personagem(nome, vida, forca, inteligencia + 5, agilidade + 5) {}

std::string Elfo::getNomeRaca() const {
    return "Elfo";
}