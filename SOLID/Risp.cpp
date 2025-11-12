#include <iostream>

// --- 1. Interfaces Segregadas (Pequenas e Específicas) ---
// Em vez de uma interface "gorda", criamos duas interfaces coesas.

// Responsabilidade 1: A capacidade de trabalhar
class ITrabalhavel {
public:
    virtual ~ITrabalhavel() {}
    virtual void trabalhar() = 0;
};

// Responsabilidade 2: A capacidade de se alimentar
class IAlimentavel {
public:
    virtual ~IAlimentavel() {}
    virtual void almocar() = 0;
};

// --- 2. Classes implementam APENAS as interfaces que precisam ---

// Humano implementa ambas as interfaces
class Humano : public ITrabalhavel, public IAlimentavel {
public:
    void trabalhar() override { 
        std::cout << "Humano trabalhando..." << std::endl; 
    }
    void almocar() override { 
        std::cout << "Humano almoçando..." << std::endl; 
    }
};

// Robô implementa apenas a interface relevante para ele
class Robo : public ITrabalhavel {
public:
    void trabalhar() override { 
        std::cout << "Robô trabalhando..." << std::endl; 
    }
    // O método almocar() não existe mais aqui.
    // A classe não é mais forçada a implementar um método que não usa. 
};

// --- 3. Funções (Clientes) agora dependem de abstrações menores ---

// Esta função só se preocupa com quem pode TRABALHAR
void gerenciarTrabalho(ITrabalhavel& trabalhador) {
    trabalhador.trabalhar();
}

// Esta função só se preocupa com quem pode ALMOÇAR
void horaDoAlmoco(IAlimentavel& comedor) {
    comedor.almocar();
}

int main() {
    Humano h;
    Robo r;

    std::cout << "--- Gerenciando Trabalho ---" << std::endl;
    gerenciarTrabalho(h); // OK
    gerenciarTrabalho(r); // OK

    std::cout << "\n--- Hora do Almoço ---" << std::endl;
    horaDoAlmoco(h); // OK

    // A linha abaixo causaria um ERRO DE COMPILAÇÃO, que é o
    // comportamento correto. O robô não pode ser passado para
    // uma função que espera alguém que almoce.
    // horaDoAlmoco(r); 
    
    return 0;
}