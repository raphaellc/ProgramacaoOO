#ifndef ELFO_H
#define ELFO_H

#include "Personagem.h"

class Elfo : public Personagem {
public:
    Elfo(std::string nome, int vida, int forca, int inteligencia, int agilidade);
    std::string getNomeRaca() const override;
};

#endif // ELFO_H