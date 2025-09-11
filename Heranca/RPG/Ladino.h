#ifndef LADINO_H
#define LADINO_H

#include "Humano.h" // Ladino será um Humano neste exemplo

class Ladino : public Humano {
public:
    Ladino(std::string nome);
    std::string getNomeClasse() const override;
    void atacar(Personagem& alvo) override;
};

#endif // LADINO_H