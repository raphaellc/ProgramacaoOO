#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <string>
#include <iostream>

class Personagem {
protected:
    std::string nome;
    int vidaAtual;
    int vidaMaxima;
    int forca;
    int inteligencia;
    int agilidade;

public:
    // Construtor
    Personagem(std::string nome, int vida, int forca, int inteligencia, int agilidade);
    
    // Destrutor virtual para garantir a limpeza correta em classes derivadas
    virtual ~Personagem() = default;

    // Métodos virtuais puros (abstratos) - devem ser implementados pelas classes filhas
    virtual void atacar(Personagem& alvo) = 0;
    virtual std::string getNomeRaca() const = 0;
    virtual std::string getNomeClasse() const = 0;

    // Métodos concretos (com implementação)
    void receberDano(int dano);
    bool estaVivo() const;
    void exibirInfo() const;
};

#endif // PERSONAGEM_H