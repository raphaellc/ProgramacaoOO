#include <iostream>
#include "SisGestaoVendas.h"
using namespace std;

int main(){
    
    Cliente * cliente = new Cliente;
    CarrinhoCompras * carrinho = new CarrinhoCompras;
    SisGestaoVendas * sis = new SisGestaoVendas(cliente, carrinho);
    Produto * prod = new Produto("Mouse",25.00);
    sis->adicionarProdutoCarrinho(prod);
    
    Produto prod2;
    prod2.setNome("Carro");
    prod2.setPreco(55000.50);

    sis->adicionarProdutoCarrinho(&prod2);
    sis->listarProdutosCarrinho();

    return 0;


}