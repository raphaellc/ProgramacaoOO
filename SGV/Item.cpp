#ifndef ITEM_H
#define ITEM_H
#include "Item.h"
Item::Item(){
    Produto *produto = nullptr;
    int quantidade = 0;
}
Item::Item(Produto *_produto, int _quantidade){
    this->produto = _produto;
    this->quantidade = _quantidade;
}
#endif