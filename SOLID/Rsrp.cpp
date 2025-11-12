#include <iostream>
#include <string>

class Usuario {
public:
    std::string nome;
    std::string email;

    Usuario(const std::string& n, const std::string& e) : nome(n), email(e) {}

};
//Como ficaria a aplicação de Templates nesta DAO?
class DAO{
    
public:
    void salvarUsuarioNoBanco(Usuario& usuario) {
        std::cout << "Salvando " << usuario.nome << " no banco de dados a partir do DAO..." << std::endl;
    }
};

int main() {
    Usuario user("Ana", "ana@email.com");
    DAO dao;
    dao.salvarUsuarioNoBanco(user);
    return 0;
}