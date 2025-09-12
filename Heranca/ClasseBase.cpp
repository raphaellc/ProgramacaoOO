#include "ClasseBase.h"
#include <iostream>
using namespace std;
ClasseBase::ClasseBase(){
    atr_privado = 0;
    atr_protected = 0;
    atr_publico = 0;
    vetor_privado = new vector<int>();
  
}
ClasseBase::~ClasseBase(){
    //não tem nada a fazer
    delete vetor_privado;
}

void ClasseBase::metodo_publico(){
    atr_privado++;
    atr_protected++;
    atr_publico++;
    cout <<"sou o método público"<<endl;
}

void ClasseBase::metodo_privado(){
    atr_privado++;
    atr_protected++;
    atr_publico++;
    cout <<"sou o método privado"<<endl;
}

void ClasseBase::metodo_protected(){
    atr_privado++;
    atr_protected++;
    atr_publico++;
    cout <<"sou o método protected"<<endl;
}

void ClasseBase::mostrar_atributos(){
    cout << "Atributo Público:" << atr_publico << endl;
    cout << "Atributo Privado:" << atr_privado << endl;
    cout << "Atributo Protected:" << atr_protected << endl;

}