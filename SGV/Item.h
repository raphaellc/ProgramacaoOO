#ifndef ITEM_H
#define ITEM_H
#include "Produto.h"
class Item{
    private:
        Produto * produto = nullptr;
        int quantidade = 0;
    public:
        Item();
        Item(Produto * _produto, int _quantidade);
        Produto * getProduto();
};

#endif