#include "Jogador.h"
#include <iostream>
    
void criaJogadores(Jogador* j){
    Jogador Jog(10, 40);
    j = new Jogador(100,100);
}
int main() {
    // a. Defina os valores para os atributos da classe por meio do construtor
    std::cout << "Criando o jogador1..." << std::endl;
    Jogador jogador1(100, 80); // Cria um objeto 'jogador1' e inicializa vida=100, energia=80
    Jogador* jogador2 = nullptr; 
    std::cout << "\n----------------------------------------\n";
    
    // b. Mostre os valores dos atributos definidos
    std::cout << "Mostrando valores iniciais de jogador1:\n";
    std::cout << "Vida atual: " << jogador1.getVida() << std::endl;
    std::cout << "Energia atual: " << jogador1.getEnergia() << std::endl;

    std::cout << "\n----------------------------------------\n";

    // c. Atualize os valores dos atributos por meio dos métodos
    std::cout << "Atualizando os atributos de jogador1...\n";
    jogador1.setVida(90);      // Altera a vida para 90
    jogador1.setEnergia(120);    // Altera a energia para 120
    std::cout << "Valores atualizados com sucesso.\n";

    std::cout << "\n----------------------------------------\n";

    // d. Mostre os valores dos atributos definidos (após a atualização)
    std::cout << "Mostrando valores de jogador1 apos a atualizacao:\n";
    std::cout << "Nova Vida: " << jogador1.getVida() << std::endl;
    std::cout << "Nova Energia: " << jogador1.getEnergia() << std::endl;
    
    jogador2 = new Jogador(100, 100);
    jogador2 = nullptr;
    criaJogadores(jogador2);
    std::cout << jogador2->getVida() << std::endl;
    return 0;
}