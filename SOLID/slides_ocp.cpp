#include <iostream>
#include <string>
//código sem o princípio aplicado
class Pagamento {
public:
    void processarPagamento(const std::string& tipoPagamento) {
        if (tipoPagamento == "cartao") {
            std::cout << "Processando pagamento com cartão de crédito...\n";
        } 
        else if (tipoPagamento == "paypal") {
            std::cout << "Processando pagamento com PayPal...\n";
        } 
        else if (tipoPagamento == "pix") {
            std::cout << "Processando pagamento com Pix...\n";
        } 
        else {
            std::cout << "Tipo de pagamento inválido!\n";
        }
    }
};

int main() {
    Pagamento p;
    p.processarPagamento("cartao");
    p.processarPagamento("paypal");
}
