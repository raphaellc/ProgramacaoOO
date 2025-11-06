#include <iostream>
#include <string>

class EnviadorDeEmail {
public:
    std::string gerarAlertaMeteorologico(std::string condicoesClimaticas) {
        std::string alerta = "O tempo está " + condicoesClimaticas;
        return alerta;
    }
};

class Telefone {
public:
    std::string gerarAlertaMeteorologico(std::string condicoesClimaticas) {
        std::string alerta = "O tempo está " + condicoesClimaticas;
        return alerta;
    }
};

class MonitorDoClima {
public:
    std::string condicoesAtuais;
    Telefone telefone;
    EnviadorDeEmail enviadorDeEmail;

    MonitorDoClima() {
        // Construtor vazio
    }

    void definirCondicoesAtuais(std::string descricaoDoClima) {
        this->condicoesAtuais = descricaoDoClima;
        
        if (descricaoDoClima == "chuvoso") {
            std::string alerta = telefone.gerarAlertaMeteorologico(descricaoDoClima);
            std::cout << alerta;
        }
        
        if (descricaoDoClima == "ensolarado") {
            std::string alerta = enviadorDeEmail.gerarAlertaMeteorologico(descricaoDoClima);
            std::cout << alerta;
        }
    }
};

int main() {
    MonitorDoClima monitor;

    std::cout << "Definindo para chuvoso: ";
    monitor.definirCondicoesAtuais("chuvoso");
    std::cout << std::endl;

    std::cout << "Definindo para ensolarado: ";
    monitor.definirCondicoesAtuais("ensolarado");
    std::cout << std::endl;

    return 0;
}