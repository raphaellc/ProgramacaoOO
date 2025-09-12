#ifndef CLASSEDERIVADA_H
#define CLASSEDERIVADA_H
#include "ClasseBase.h"

class ClasseDerivada : public ClasseBase{
    public:
        ClasseDerivada();
        ~ClasseDerivada();
        void mostrar_atributos() override;
        void metodo_protected() override;
        void QuemSou();

};
#endif //CLASSEDERIVADA_H