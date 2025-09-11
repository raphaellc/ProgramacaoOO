#ifndef ORC_H
#define ORC_H

#include "Personagem.h"

class Orc : public Personagem {
public:
    Orc(std::string nome, int vida, int forca, int inteligencia, int agilidade);
    std::string getNomeRaca() const override;
};

#endif // ORC_H