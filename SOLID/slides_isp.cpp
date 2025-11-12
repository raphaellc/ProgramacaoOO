#include <iostream>
#include <string>

class IProduto {
public:
    virtual std::string exibirInformacoes() = 0;
    virtual double calcularPreco() = 0;
    virtual void adicionarAoCarrinho() = 0;
    virtual void removerDoCarrinho() = 0;
};

// Eletrônicos não precisam ser adicionados a carrinho (exemplo didático)
class Eletronico : public IProduto {
public:
    std::string exibirInformacoes() override {
        return "Eletrônico: Notebook Gamer";
    }

    double calcularPreco() override {
        return 5999.90;
    }

    void adicionarAoCarrinho() override {
        std::cout << "Este produto não pode ser adicionado ao carrinho!\n";
    }

    void removerDoCarrinho() override {
        std::cout << "Este produto não pode ser removido do carrinho!\n";
    }
};

int main() {
    Eletronico e;
    std::cout << e.exibirInformacoes() << "\n";
    e.adicionarAoCarrinho();
}
