#ifndef COMBATE_H
#define COMBATE_H

#include "Personagem.h"
#include <iostream>
#include <thread>   // Para std::this_thread::sleep_for
#include <chrono>   // Para std::chrono::seconds

class Combate {
private:
    Personagem* p1;
    Personagem* p2;
    int turno;

    // Métodos privados de ajuda
    void executarTurno();
    void anunciarVencedor() const;
    bool lutaTerminou() const;

public:
    // O construtor recebe os combatentes por Injeção de Dependência
    Combate(Personagem* jogador1, Personagem* jogador2);

    // Método principal que inicia e gerencia o combate
    void iniciarLuta();
};

#endif // COMBATE_H