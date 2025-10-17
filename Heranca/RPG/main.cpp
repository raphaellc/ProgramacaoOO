#include <iostream>
#include <ctime>    // Para srand
#include <cstdlib>  // Para rand e srand

// O main agora só precisa conhecer a Fábrica e o Combate!
#include "FabricaPersonagens.h"
#include "Combate.h"

int main() {
    // Inicializa a semente do gerador de números aleatórios
    srand(time(0));

    std::cout << ">>> BEM-VINDO AO SIMULADOR DE COMBATE RPG DIDATICO <<<\n\n";

    // --- 1. CRIAÇÃO (via Fábrica) ---
    // O main não sabe mais o que é um "Guerreiro" ou "Mago",
    // apenas pede à fábrica por um tipo de personagem.
    Personagem* jogador1 = nullptr;
    Personagem* jogador2 = nullptr;

    try {
        jogador1 = FabricaPersonagens::criarPersonagem(TipoPersonagem::GUERREIRO, "Grommash");
        jogador2 = FabricaPersonagens::criarPersonagem(TipoPersonagem::LADINO, "Valira");
        // Tente mudar para:
        // jogador2 = FabricaPersonagens::criarPersonagem(TipoPersonagem::MAGO, "Alandra");

    } catch (const std::exception& e) {
        std::cerr << "Erro ao criar personagens: " << e.what() << std::endl;
        return 1;
    }


    // --- 2. EXECUÇÃO (via Injeção de Dependência) ---
    // Criamos o objeto de combate e injetamos os personagens
    // que a fábrica nos deu.
    Combate duelo(jogador1, jogador2);

    // O main simplesmente manda o combate começar.
    // Ele não sabe como a luta funciona.
    duelo.iniciarLuta();


    // --- 3. LIMPEZA ---
    // O main ainda é responsável por limpar a memória
    // que a fábrica alocou.
    delete jogador1;
    delete jogador2;

    return 0;
}

