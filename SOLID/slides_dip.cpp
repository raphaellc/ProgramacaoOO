#include <iostream>
#include <string>

class ConsoleLogger {
public:
    void log(const std::string& msg) {
        std::cout << "[LOG] " << msg << "\n";
    }
};

class Venda {
private:
    ConsoleLogger logger;  // dependência concreta (erro)

public:
    void processarVenda() {
        // lógica da venda...
        logger.log("Venda processada com sucesso!");
    }
};

int main() {
    Venda v;
    v.processarVenda();
}
