#ifndef CARRINHOCOMPRA_H
#define CARRINHOCOMPRA_H
#include <vector>
#include "Item.h"
using namespace std;
class CarrinhoCompras{
    private:
        vector<Item *> * itens;
        double valorTotal;
    public:
        CarrinhoCompras();
        void adicionarItemCarrinho(Item * _item);
        void listarItens();
};
#endif // CARRINHOCOMPRA_H