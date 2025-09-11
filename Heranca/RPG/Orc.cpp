#include "Orc.h"

// Orcs são fortes e resistentes.
Orc::Orc(std::string nome, int vida, int forca, int inteligencia, int agilidade)
    : Personagem(nome, vida + 20, forca + 10, inteligencia, agilidade) {}

std::string Orc::getNomeRaca() const {
    return "Orc";
}