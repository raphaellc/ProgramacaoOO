#ifndef PRODUTO_H
#define PRODUTO_H
#include "Produto.h"
Produto::Produto(std::string _nome, double _preco){
    this->nome = _nome;
    this->preco = _preco;
}
Produto::Produto(){
    this->nome = "";
    this->preco = 0.0;
}
std::string Produto::getNome(){
    return this->nome;
}
double Produto::getPreco(){
    return this->preco;
}
void Produto::setNome(std::string _nome){
    this->nome = _nome;
}
void Produto::setPreco(double _preco){
    this->preco = _preco;
}

#endif


