#ifndef Personagem_H
#define Personagem_H
#include <string>
using namespace std;

class Personagem{
    protected:
        int vida;
        int mana;
        string raca;
        string classe;
        int forca;
        int agilidade;
        int inteligencia;

    public:
        Personagem(int vida, int mana, string raca, string classe, int forca, int agilidade, int inteligencia);
};
#endif