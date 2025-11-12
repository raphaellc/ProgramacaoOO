#include <iostream>
#include <string>

class ProcessadorPagamento {
public:
    void processar(const std::string& tipo, double valor) {
        if (tipo == "Credito") {
            std::cout << "Processando R$" << valor << " com Cartão de Crédito." << std::endl;
        } else if (tipo == "Debito") {
            std::cout << "Processando R$" << valor << " com Cartão de Débito." << std::endl;
        }
        
    }
};
int main() {
    ProcessadorPagamento pp;
    pp.processar("Credito", 100.0);
    return 0;
}