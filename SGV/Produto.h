#include <string>
class Produto{
    private:
        std::string nome;
        double preco;
    public:
        Produto(std::string _nome, double _preco);
        Produto();
        std::string getNome();
        double getPreco();
        void setNome(std::string _nome);
        void setPreco(double _preco);
};