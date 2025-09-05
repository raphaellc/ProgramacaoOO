#include "SisGestaoVendas.h"
SisGestaoVendas::SisGestaoVendas(Cliente * _cliente){
    this->cliente = _cliente;
    this->carrinho = new CarrinhoCompras();
}
SisGestaoVendas::SisGestaoVendas(Cliente * _cliente, CarrinhoCompras * _carrinho){
    this->cliente = _cliente;
    this->carrinho = _carrinho;
}        
void SisGestaoVendas::adicionarProdutoCarrinho(Produto * _produto){
    Item * item = new Item(_produto, 1);
    this->carrinho->adicionarItemCarrinho(item);
}

void SisGestaoVendas::listarProdutosCarrinho(){
    this->carrinho->listarItens();
}