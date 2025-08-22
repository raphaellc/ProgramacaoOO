#include "Jogador.h"
#include <iostream>

Jogador::Jogador(int vidaInicial, int energiaInicial) : vida(vidaInicial), energia(energiaInicial) {
    std::cout << "Objeto Jogador criado com Vida=" << vida << " e Energia=" << energia << std::endl;
}

Jogador::~Jogador() {
    std::cout << "Objeto Jogador destruido" << std::endl;
}

// Implementação dos Getters
//tipo_retorno Classe::nomeMetodo(argumentos/parametros) modidifacador da função Const {}
int Jogador::getVida() const {
    return this->vida;
}

int Jogador::getEnergia() const {
    return this->energia;
}

// Implementação dos Setters
void Jogador::setVida(int novaVida) {
    
    this->vida = novaVida;
}

void Jogador::setEnergia(int novaEnergia) {
    this->energia = novaEnergia;
}
