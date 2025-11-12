#include <iostream>

// --- 1. Classe Base ---
// Removemos voar() daqui. Esta classe agora contém
// apenas comportamentos comuns a TODAS as aves.
class Ave {
public:
    virtual ~Ave() {} // Boa prática ter um destrutor virtual

    // Adicionamos um comportamento que todos compartilham
    void bicar() {
        std::cout << "Ave bicando..." << std::endl;
    }
};

// --- 2. Nova Abstração para Aves que Voam ---
// Esta classe "é uma" Ave e "adiciona o contrato" de voar.
class AveVoadora : public Ave {
public:
    virtual void voar() = 0; // Contrato de voo (método virtual puro)
};

// --- 3. PicaPau "é uma" AveVoadora ---
// Herda da abstração correta.
class PicaPau : public AveVoadora {
public:
    void voar() override {
        std::cout << "Pica-pau voando!" << std::endl;
    }
};

// --- 4. Pinguim "é uma" Ave (mas NÃO uma AveVoadora) ---
// Herda apenas da classe base. Não é forçado a ter um método voar().
class Pinguim : public Ave {
public:
    // Pode ter seus próprios métodos
    void nadar() {
        std::cout << "Pinguim nadando." << std::endl;
    }
};

// --- 5. A função cliente agora "pede" a abstração correta ---
// Esta função só deve aceitar aves que podem, de fato, voar.
void fazerAveVoar(AveVoadora& ave) {
    ave.voar();
}

// Esta função ainda funciona para todas as aves
void fazerAveBicar(Ave& ave) {
    ave.bicar();
}

int main() {
    PicaPau pp;
    Pinguim p;

    std::cout << "--- Testando voo ---" << std::endl;
    fazerAveVoar(pp); // Funciona

    // A linha abaixo agora causa um ERRO DE COMPILAÇÃO
    // em vez de um erro em tempo de execução.
    // O sistema de tipos agora protege o contrato de Liskov.
    //
    // fazerAveVoar(p); 

    std::cout << "\n--- Testando bicar ---" << std::endl;
    // Ambas ainda podem ser tratadas como "Ave" para
    // comportamentos comuns.
    fazerAveBicar(pp); // Funciona
    fazerAveBicar(p);  // Funciona
    
    return 0;
}