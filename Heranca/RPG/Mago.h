#ifndef MAGO_H
#define MAGO_H

#include "Elfo.h" // Mago será um Elfo neste exemplo

class Mago : public Elfo {
public:
    Mago(std::string nome);
    std::string getNomeClasse() const override;
    void atacar(Personagem& alvo) override;
};

#endif // MAGO_H