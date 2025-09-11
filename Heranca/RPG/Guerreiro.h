#ifndef GUERREIRO_H
#define GUERREIRO_H

#include "Orc.h" // Guerreiro será um Orc neste exemplo

class Guerreiro : public Orc {
public:
    Guerreiro(std::string nome);
    std::string getNomeClasse() const override;
    void atacar(Personagem& alvo) override;
};

#endif // GUERREIRO_H