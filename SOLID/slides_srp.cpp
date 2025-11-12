#include <iostream>
#include <string>

class Cliente {
public:
    int id;
    std::string nome;
    std::string email;
};

class ClienteController {
public:
    bool salvar(const Cliente& cliente) {
        if (validar(cliente)) {
            salvarNoBanco(cliente);
            enviarEmail(cliente.email);
            return true;
        }
        return false;
    }

private:
    bool validar(const Cliente& cliente) {
        if (cliente.nome.empty() || cliente.email.empty()) {
            std::cout << "Erro: nome ou e-mail vazio!\n";
            return false;
        }
        return true;
    }

    void salvarNoBanco(const Cliente& cliente) {
        std::cout << "Salvando cliente no banco: " << cliente.nome << "\n";
    }

    void enviarEmail(const std::string& email) {
        std::cout << "Enviando e-mail para " << email << "\n";
    }
};

int main() {
    Cliente c{1, "João", "joao@email.com"};
    ClienteController ctrl;
    ctrl.salvar(c);
}
