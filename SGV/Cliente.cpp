#include "Cliente.h"

Cliente::Cliente(){
    this->nome = "";
    this->end = "";
    this->email = "";
}   

Cliente::Cliente(std::string _nome, std::string _end, std::string _email){
    this->nome = _nome;
    this->end = _end;
    this->email = _email;
}
