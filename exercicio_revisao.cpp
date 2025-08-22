#include <iostream>

int main() {
    // a. Declare uma variável do tipo ponteiro para inteiro
    int *ponteiro;

    // b. Declare uma variável do tipo inteiro
    int numero;

    // c. Inicialize a variável do tipo inteiro com o valor 0
    numero = 0;

    std::cout << "Valor inicial da variavel 'numero': " << numero << std::endl;
    
    // Antes de usar o ponteiro, precisamos fazê-lo apontar para o endereço de 'numero'
    ponteiro = &numero;

    // d. Atribua o valor 10 à variável do tipo inteiro, por meio da variável do tipo ponteiro
    *ponteiro = 10;
    
    std::cout << "O valor foi alterado para 10 atraves do ponteiro." << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;

    // e. Mostre na tela o valor da variável inteira utilizando ela própria e a variável ponteiro
    std::cout << "Mostrando o valor da variavel 'numero' (acesso direto): " << numero << std::endl;
    std::cout << "Mostrando o valor apontado pelo 'ponteiro' (acesso indireto): " << *ponteiro << std::endl;

    return 0;
}