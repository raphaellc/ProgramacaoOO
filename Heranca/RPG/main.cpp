#include <iostream>
#include <vector>
#include <ctime>    // Para srand
#include <cstdlib>  // Para rand e srand
#include <thread>   // Para std::this_thread::sleep_for
#include <chrono>   // Para std::chrono::seconds

// Incluindo as classes finais que vamos instanciar
#include "Guerreiro.h"
#include "Mago.h"
#include "Ladino.h"

int main() {
    // Inicializa a semente do gerador de números aleatórios
    srand(time(0));

    std::cout << ">>> BEM-VINDO AO SIMULADOR DE COMBATE RPG DIDATICO <<<\n\n";

    // Criação dos personagens usando polimorfismo.
    // Ponteiros da classe base apontam para objetos da classe derivada.
    Personagem* jogador1 = new Guerreiro("Grommash");
    Personagem* jogador2 = new Mago("Alandra");
    // Personagem* jogador2 = new Ladino("Valira"); // Você pode trocar os oponentes

    std::cout << "Lutadores prontos!\n";
    jogador1->exibirInfo();
    jogador2->exibirInfo();
    
    std::cout << "\n>>> O COMBATE VAI COMECAR! <<<\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    
    int turno = 1;
    // O combate continua enquanto ambos os jogadores estiverem vivos
    while (jogador1->estaVivo() && jogador2->estaVivo()) {
        std::cout << "\n----- TURNO " << turno << " -----\n";

        // Jogador 1 ataca o Jogador 2
        jogador1->atacar(*jogador2);
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Verifica se o jogador 2 sobreviveu antes de contra-atacar
        if (!jogador2->estaVivo()) {
            break;
        }

        // Jogador 2 ataca o Jogador 1
        jogador2->atacar(*jogador1);
        std::this_thread::sleep_for(std::chrono::seconds(2));
        
        turno++;
    }

    std::cout << "\n>>> FIM DE COMBATE! <<<\n";

    // Declara o vencedor
    if (jogador1->estaVivo()) {
        std::cout << "O vencedor e: " << std::endl;
        jogador1->exibirInfo();
    } else {
        std::cout << "O vencedor e: " << std::endl;
        jogador2->exibirInfo();
    }

    // Libera a memória alocada dinamicamente
    delete jogador1;
    delete jogador2;

    return 0;
}