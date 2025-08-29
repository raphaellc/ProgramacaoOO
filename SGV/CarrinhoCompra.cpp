#ifndef CARRINHOCOMPRA_H
#define CARRINHOCOMPRA_H
#include "CarrinhoCompras.h"

CarrinhoCompras::CarrinhoCompras(){
    this->itens = new vector<Item *>();
    this->valorTotal = 0.0;
}

void CarrinhoCompras::adicionarItemCarrinho(Item *_item){
    this->itens->push_back(_item);
}
#endif // CARRINHOCOMPRA_H