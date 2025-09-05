#ifndef SISGESTAOVENDAS_H
#define SISGESTAOVENDAS_H
#include "Cliente.h"
#include "CarrinhoCompras.h"
#include "Produto.h"
#include "Item.h"
class SisGestaoVendas {
    private:
        Cliente * cliente;
        CarrinhoCompras * carrinho;
    public:
        SisGestaoVendas(Cliente * _cliente);
        SisGestaoVendas(Cliente * _cliente, CarrinhoCompras * _carrinho);
        void adicionarProdutoCarrinho(Produto * _prod);
        void listarProdutosCarrinho();

};
#endif