#include <iostream>
#include <string>

class Usuario {
public:
    std::string nome;
    std::string email;

    Usuario(const std::string& n, const std::string& e) : nome(n), email(e) {}

    void salvarUsuarioNoBanco() {
        std::cout << "Salvando " << nome << " no banco de dados..." << std::endl;
        
    }
};

int main() {
    Usuario user("Ana", "ana@email.com");
    user.salvarUsuarioNoBanco();
    return 0;
}