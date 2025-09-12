#ifndef CLASSEBASE_H
#define CLASSEBASE_H
#include <vector>
using namespace std;


class ClasseBase {
    public:
        int atr_publico;
        //metodo construtor
        ClasseBase();
        ~ClasseBase();

        void metodo_publico();
        virtual void mostrar_atributos();

    private:
        vector<int> * vetor_privado;
        int atr_privado;
        void metodo_privado();

    protected:
        virtual void metodo_protected();
        int atr_protected;
};

#endif //CLASSEBASE_H