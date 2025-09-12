#include "ClasseDerivada.h"
#include <iostream>
using namespace std;
ClasseDerivada::ClasseDerivada() : ClasseBase(){
    this->atr_protected = 0;
    this->atr_publico = 0;
    this->metodo_protected();
    this->metodo_publico();
    this->mostrar_atributos();

}

ClasseDerivada::~ClasseDerivada(){

}

void ClasseDerivada::QuemSou(){
    cout << "Sou a classe Derivada" << endl; 
}

void ClasseDerivada::mostrar_atributos(){
    cout << "Classe Derivada Mostrar Atributos" << endl;
    ClasseBase::mostrar_atributos();
}

void ClasseDerivada::metodo_protected(){
    cout << "Classe Derivada Metodo Protected " << endl;
    ClasseBase::metodo_protected();
}