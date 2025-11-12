#include <iostream>
#include <string>
class IProcessador{
    public:
        virtual void processar(double valor) = 0;

};
class ProcessadorCredito : public IProcessador {
    public:
        ProcessadorCredito() {}
        void processar(double valor)  {
            std::cout << "Processando R$" << valor << " com Cartão de Crédito." << std::endl;
        } 
    
};
class ProcessadorDebito : public IProcessador {
    public: 
        ProcessadorDebito() {}
        void processar(double valor)  {
            std::cout << "Processando R$" << valor << " com Cartão de Débito." << std::endl;
        }
};
class ProcessadorPagamento {

    public:
    ProcessadorPagamento(IProcessador* iprocessador){
        this->iprocessador = iprocessador;
    }
    void processar(double valor) {
        this->iprocessador->processar(valor);
        
    }
    private:
        IProcessador* iprocessador;
};
int main() {
    IProcessador* pagamento_credito = new ProcessadorCredito();
    ProcessadorPagamento pp(pagamento_credito);
    pp.processar(100.0);
    return 0;
}