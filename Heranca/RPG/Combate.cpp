#include "Combate.h"

// O construtor armazena os ponteiros para os personagens
Combate::Combate(Personagem* jogador1, Personagem* jogador2)
    : p1(jogador1), p2(jogador2), turno(1) {
    std::cout << "Lutadores prontos!\n";
    p1->exibirInfo();
    p2->exibirInfo();
}

void Combate::iniciarLuta() {
    std::cout << "\n>>> O COMBATE VAI COMECAR! <<<\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));

    // O loop de combate agora vive dentro desta classe
    while (!lutaTerminou()) {
        executarTurno();
        turno++;
    }

    anunciarVencedor();
}

bool Combate::lutaTerminou() const {
    return !p1->estaVivo() || !p2->estaVivo();
}

void Combate::executarTurno() {
    std::cout << "\n----- TURNO " << turno << " -----\n";

    // A lógica de quem ataca primeiro (baseada na agilidade)
    Personagem* atacante = (p1->obterAgilidade() > p2->obterAgilidade()) ? p1 : p2;
    Personagem* defensor = (atacante == p1) ? p2 : p1;

    // Primeiro ataque
    std::cout << "(Primeiro a agir: " << atacante->getNomeRaca() << ")" << std::endl;
    atacante->atacar(*defensor);
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Verifica se o defensor sobreviveu para contra-atacar
    if (defensor->estaVivo()) {
        // Contra-ataque
        defensor->atacar(*atacante);
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

void Combate::anunciarVencedor() const {
    std::cout << "\n>>> FIM DE COMBATE! <<<\n";
    if (p1->estaVivo()) {
        std::cout << "O vencedor e: " << std::endl;
        p1->exibirInfo();
    } else {
        std::cout << "O vencedor e: " << std::endl;
        p2->exibirInfo();
    }
}