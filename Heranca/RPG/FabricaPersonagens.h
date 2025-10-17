#ifndef FABRICA_PERSONAGENS_H
#define FABRICA_PERSONAGENS_H

#include "Personagem.h"
#include <string>
#include <stdexcept> // Para exceções

// Enum class para segurança de tipo na escolha do personagem
enum class TipoPersonagem {
    GUERREIRO,
    MAGO,
    LADINO
};

class FabricaPersonagens {
public:
    // O método de fábrica estático
    // Recebe o tipo desejado e o nome para o personagem
    static Personagem* criarPersonagem(TipoPersonagem tipo, const std::string& nome);
};

#endif // FABRICA_PERSONAGENS_H