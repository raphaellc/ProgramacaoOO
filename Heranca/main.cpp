#include "ClasseBase.h"
#include "ClasseDerivada.h"
#include <iostream>
int main(){

    ClasseBase * cb = new ClasseBase();
    
    cb->atr_publico = 1;
    cb->metodo_publico();
    cb->mostrar_atributos();
    

    delete cb;

    ClasseDerivada * cd = new ClasseDerivada();
    cd->mostrar_atributos();
    
    cd->atr_publico = 20;
    
    cd->mostrar_atributos();
    cd->QuemSou();
    delete cd;

    ClasseBase * cbd = new ClasseDerivada();
    std::cout << "classe Base Derivada" << std::endl;
    cbd->mostrar_atributos();
    cbd->atr_publico = 100;
    cbd->mostrar_atributos();





    return 0;

}