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
};