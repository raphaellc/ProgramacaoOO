#include <iostream>
#include <string>

// Simulação das classes VO e DAO
struct ClienteVO { std::string nome; };
class ClienteDAO {
public:
    static ClienteDAO* getInstance() {
        static ClienteDAO instance;
        return &instance;
    }
    void save(ClienteVO c) {
        std::cout << "Salvando cliente " << c.nome << " no banco de dados." << std::endl;
    }
};

// VIOLAÇÃO DO SRP: Classe com múltiplas responsabilidades [cite: 20]
class ClienteController {
public:
    // Responsabilidade 1: Orquestrar salvamento [cite: 26-33]
    void save(ClienteVO c) {
        if (this->validate(c)) { // Responsabilidade 2 [cite: 28]
            ClienteDAO::getInstance()->save(c); // Responsabilidade 1 [cite: 30]
            this->sendEmail(); // Responsabilidade 3 [cite: 31]
        }
    }

private:
    // Responsabilidade 2: Validação [cite: 22, 34-37]
    bool validate(ClienteVO c) {
        if (c.nome.empty()) return false;
        std::cout << "Cliente " << c.nome << " validado." << std::endl;
        return true;
    }

    // Responsabilidade 3: Envio de e-mail [cite: 23, 38-44]
    void sendEmail() {
        std::cout << "Enviando e-mail de confirmação..." << std::endl;
        // Lógica de MimeMessage, Transport.send, etc. [cite: 40, 43]
    }
};

int main() {
    ClienteController controller;
    controller.save({"Raphael"});
    return 0;
}