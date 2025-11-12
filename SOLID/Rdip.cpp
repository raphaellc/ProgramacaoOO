#include <iostream>
#include <memory> // Para std::unique_ptr e std::make_unique

// --- 1. Criamos a Abstração ---
// Módulos de alto e baixo nível dependerão disto.
class IDispositivo {
public:
    virtual ~IDispositivo() {} // Destrutor virtual para classes base
    virtual void ligar() = 0;
    virtual void desligar() = 0;
};

// --- 2. O Módulo de Baixo Nível (detalhe) depende da Abstração ---
class Lampada : public IDispositivo {
public:
    void ligar() override {
        std::cout << "Lâmpada acesa." << std::endl;
    }
    void desligar() override {
        std::cout << "Lâmpada apagada." << std::endl;
    }
};

// --- BENEFÍCIO DO DIP: Podemos adicionar novos dispositivos ---
// Este é um novo módulo de baixo nível. O Interruptor não saberá
// da existência dele, mas poderá controlá-lo.
class Ventilador : public IDispositivo {
public:
    void ligar() override {
        std::cout << "Ventilador ligado." << std::endl;
    }
    void desligar() override {
        std::cout << "Ventilador desligado." << std::endl;
    }
};

// --- 3. O Módulo de Alto Nível depende da Abstração ---
class Interruptor {
private:
    // Agora depende da interface, não da classe concreta
    IDispositivo& dispositivo; 
    bool ligado = false;

public:
    // --- 4. A dependência é "injetada" ---
    // O interruptor RECEBE o dispositivo, ele não o cria.
    Interruptor(IDispositivo& disp) : dispositivo(disp) {}

    void pressionar() {
        if (ligado) {
            dispositivo.desligar();
            ligado = false;
        } else {
            dispositivo.ligar();
            ligado = true;
        }
    }
};

int main() {
    // A camada de "composição" (main) agora é responsável
    // por criar os objetos concretos e injetar as dependências.
    
    Lampada minhaLampada;
    Ventilador meuVentilador;

    // O interruptor pode controlar a Lâmpada
    Interruptor interruptorDeLuz(minhaLampada);
    std::cout << "Controlando a Lâmpada:" << std::endl;
    interruptorDeLuz.pressionar();
    interruptorDeLuz.pressionar();

    std::cout << "\nControlando o Ventilador:" << std::endl;
    // A *mesma* classe Interruptor pode controlar o Ventilador
    // sem nenhuma modificação.
    Interruptor interruptorDeVentilador(meuVentilador);
    interruptorDeVentilador.pressionar();
    interruptorDeVentilador.pressionar();
    
    return 0;
}