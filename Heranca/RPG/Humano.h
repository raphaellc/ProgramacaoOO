#ifndef HUMANO_H
#define HUMANO_H

#include "Personagem.h"

class Humano : public Personagem {
public:
    Humano(std::string nome, int vida, int forca, int inteligencia, int agilidade);
    std::string getNomeRaca() const override;
};

#endif // HUMANO_H