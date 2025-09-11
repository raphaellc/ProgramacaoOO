#include "Humano.h"

// O Humano é equilibrado, então não adicionamos modificadores extras,
// apenas repassamos os valores para o construtor de Personagem.
Humano::Humano(std::string nome, int vida, int forca, int inteligencia, int agilidade)
    : Personagem(nome, vida, forca, inteligencia, agilidade) {}

std::string Humano::getNomeRaca() const {
    return "Humano";
}