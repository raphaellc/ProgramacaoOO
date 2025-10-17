#include "FabricaPersonagens.h"

// Note que SÓ o .cpp da fábrica precisa conhecer as classes concretas.
// Isso desacopla o resto do programa (como o main) de Guerreiro.h, Mago.h, etc.
#include "Guerreiro.h"
#include "Mago.h"
#include "Ladino.h"

Personagem* FabricaPersonagens::criarPersonagem(TipoPersonagem tipo, const std::string& nome) {
    switch (tipo) {
        case TipoPersonagem::GUERREIRO:
            // new Guerreiro(nome) irá chamar o construtor de Guerreiro,
            // que por sua vez chama o construtor de Orc (ou outra raça),
            // que chama o construtor de Personagem com os atributos base.
            return new Guerreiro(nome);

        case TipoPersonagem::MAGO:
            return new Mago(nome);

        case TipoPersonagem::LADINO:
            return new Ladino(nome);

        default:
            // Lança uma exceção se o tipo for desconhecido
            throw std::invalid_argument("Tipo de personagem invalido ou nao implementado.");
    }
}