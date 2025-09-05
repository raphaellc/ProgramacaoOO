#include "CarrinhoCompras.h"
#include <iostream>
using namespace std;

CarrinhoCompras::CarrinhoCompras(){
    this->itens = new vector<Item *>();
    this->valorTotal = 0.0;
}

void CarrinhoCompras::adicionarItemCarrinho(Item *_item){
    this->itens->push_back(_item);
}

void CarrinhoCompras::listarItens(){
    for(int i = 0; i < this->itens->size(); i++){
        cout << this->itens->at(i)->getProduto()->getNome() << endl;  
    }

}