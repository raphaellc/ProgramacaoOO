#include <iostream>
#include <vector>
#include <random> // Para geração de números aleatórios de alta qualidade
#include <ctime>  // Para obter uma semente para o gerador aleatório

// Função para imprimir o tabuleiro na tela
void imprimirTabuleiro(const std::vector<std::vector<char>>& tabuleiro) {
    for (const auto& linha : tabuleiro) {
        for (const char& celula : linha) {
            std::cout << celula << "  "; // Adiciona espaço para melhor visualização
        }
        std::cout << std::endl;
    }
}

int main() {
    int n, m;

    // 1. Solicitar as dimensões do tabuleiro ao usuário
    std::cout << "--- Criacao do Tabuleiro Aleatorio ---" << std::endl;
    std::cout << "Digite o numero de linhas (n): ";
    std::cin >> n;
    std::cout << "Digite o numero de colunas (m): ";
    std::cin >> m;

    // Validação simples da entrada
    if (n <= 0 || m <= 0) {
        std::cerr << "Erro: As dimensoes do tabuleiro devem ser numeros positivos." << std::endl;
        return 1; // Termina o programa com um código de erro
    }

    // 2. Solicitar as cinco letras ao usuário
    std::vector<char> letras_disponiveis(5);
    std::cout << "\nDigite as 5 letras que irao preencher o tabuleiro:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << "Letra " << i + 1 << ": ";
        std::cin >> letras_disponiveis[i];
    }

    // 3. Configurar o gerador de números aleatórios
    // std::random_device fornece uma semente não-determinística (se disponível)
    std::random_device rd;
    // O motor Mersenne Twister é um gerador de alta qualidade
    std::mt19937 gerador(rd());
    // Cria uma distribuição que gera números inteiros uniformemente entre 0 e 4 (índices do nosso vetor de letras)
    std::uniform_int_distribution<> distribuicao(0, 4);

    // 4. Criar o tabuleiro e preenchê-lo
    std::vector<std::vector<char>> tabuleiro(n, std::vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // Gera um índice aleatório (0, 1, 2, 3 ou 4)
            int indice_aleatorio = distribuicao(gerador);
            // Atribui a letra correspondente à célula do tabuleiro
            tabuleiro[i][j] = letras_disponiveis[indice_aleatorio];
        }
    }

    // 5. Mostrar o tabuleiro resultante
    std::cout << "\n--- Tabuleiro Gerado (" << n << "x" << m << ") ---\n" << std::endl;
    imprimirTabuleiro(tabuleiro);

    return 0;
}