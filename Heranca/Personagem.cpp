#include "Personagem.h"

Personagem::Personagem(int vida, int mana, string raca, string classe, int forca, int agilidade, int inteligencia){ 
    this->vida = vida;
    this->mana = mana;          
    this->agilidade = agilidade;
    this->forca = forca;
    this->inteligencia = inteligencia;
    this->raca = raca;
    this->classe = classe;
}