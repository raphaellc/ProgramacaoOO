/*
 * Exemplo de Algoritmo em C++: Templates e Sobrecarga de Operadores
 *
 * Este programa demonstra:
 * 1.  **Templates de Classe:** Criação de classes genéricas (CaixaGenerica, ParGenerico)
 * que podem operar com diferentes tipos de dados (int, double, string, etc.).
 * 2.  **Sobrecarga de Operador (+):** Define como o operador de adição deve
 * se comportar para objetos dessas classes, somando seus atributos correspondentes.
 * 3.  **Sobrecarga de Operador (==):** Define como o operador de igualdade
 * deve se comportar, comparando os objetos com base *apenas* em seus IDs.
 * 4.  **Sobrecarga de Operador (<<):** (Bônus) Facilita a impressão dos
 * objetos no console.
 */

#include <iostream> // Para std::cout, std::endl
#include <string>   // Para std::string
#include <iomanip>  // Para std::boolalpha

// --- CLASSE GENÉRICA 1: CaixaGenerica ---

template <typename T>
class CaixaGenerica {
private:
    T val1; // Primeiro atributo genérico
    T val2; // Segundo atributo genérico
    int id;   // Atributo de identificação

public:
    // Construtor
    CaixaGenerica(T v1, T v2, int id) : val1(v1), val2(v2), id(id) {}

    // Getter para o ID (usado na demonstração de comparação)
    int getId() const { return id; }

    /**
     * SOBRECARGA DO OPERADOR DE ADIÇÃO (+)
     * Soma os atributos correspondentes de dois objetos CaixaGenerica.
     * O ID do novo objeto será o ID do objeto à esquerda da operação.
     */
    CaixaGenerica<T> operator+(const CaixaGenerica<T>& outra) const {
        T novoVal1 = this->val1 + outra.val1;
        T novoVal2 = this->val2 + outra.val2;
        // O novo objeto herda o ID do primeiro operando (this)
        return CaixaGenerica<T>(novoVal1, novoVal2, this->id);
    }

    /**
     * SOBRECARGA DO OPERADOR DE IGUALDADE (==)
     * Compara dois objetos CaixaGenerica com base *apenas* em seus IDs.
     */
    bool operator==(const CaixaGenerica<T>& outra) const {
        return this->id == outra.id;
    }

    // Função amiga para sobrecarregar o operador << (impressão)
    // Usamos 'U' para evitar conflito com o 'T' da classe
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const CaixaGenerica<U>& caixa);
};

// Implementação da função amiga (operador <<) para CaixaGenerica
template <typename T>
std::ostream& operator<<(std::ostream& os, const CaixaGenerica<T>& caixa) {
    os << "Caixa[ID: " << caixa.id << "] (val1: " << caixa.val1 << ", val2: " << caixa.val2 << ")";
    return os;
}

// --- CLASSE GENÉRICA 2: ParGenerico ---
// (Estruturalmente similar à CaixaGenerica para cumprir o requisito de "duas classes")

template <typename T>
class ParGenerico {
private:
    T item1; // Primeiro atributo genérico
    T item2; // Segundo atributo genérico
    int id;    // Atributo de identificação

public:
    // Construtor
    ParGenerico(T i1, T i2, int id) : item1(i1), item2(i2), id(id) {}

    // Getter para o ID
    int getId() const { return id; }

    /**
     * SOBRECARGA DO OPERADOR DE ADIÇÃO (+)
     * Soma os atributos correspondentes de dois objetos ParGenerico.
     */
    ParGenerico<T> operator+(const ParGenerico<T>& outro) const {
        T novoItem1 = this->item1 + outro.item1;
        T novoItem2 = this->item2 + outro.item2;
        return ParGenerico<T>(novoItem1, novoItem2, this->id);
    }

    /**
     * SOBRECARGA DO OPERADOR DE IGUALDADE (==)
     * Compara dois objetos ParGenerico com base *apenas* em seus IDs.
     */
    bool operator==(const ParGenerico<T>& outro) const {
        return this->id == outro.id;
    }

    // Função amiga para sobrecarregar o operador << (impressão)
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const ParGenerico<U>& par);
};

// Implementação da função amiga (operador <<) para ParGenerico
template <typename T>
std::ostream& operator<<(std::ostream& os, const ParGenerico<T>& par) {
    os << "Par  [ID: " << par.id << "] (item1: " << par.item1 << ", item2: " << par.item2 << ")";
    return os;
}


// --- FUNÇÃO PRINCIPAL (MAIN) ---
// Onde o algoritmo é executado e os exemplos são demonstrados.

int main() {
    // Configura std::cout para imprimir 'true'/'false' em vez de '1'/'0'
    std::cout << std::boolalpha; 

    std::cout << "--- 1. Demonstração: CaixaGenerica<int> ---" << std::endl;
    CaixaGenerica<int> caixaA(10, 20, 101);
    CaixaGenerica<int> caixaB(5, 7, 102);
    
    // Demonstração da sobrecarga de adição (+)
    CaixaGenerica<int> caixaSoma = caixaA + caixaB;
    
    std::cout << "Caixa A: " << caixaA << std::endl;
    std::cout << "Caixa B: " << caixaB << std::endl;
    std::cout << "Soma (A+B): " << caixaSoma << " (Note: 10+5=15, 20+7=27. ID=101 de A)" << std::endl;
    
    std::cout << "\n--- 2. Demonstração: ParGenerico<double> ---" << std::endl;
    ParGenerico<double> parA(1.5, 2.2, 201);
    ParGenerico<double> parB(0.5, 3.3, 202);

    // Demonstração da sobrecarga de adição (+)
    ParGenerico<double> parSoma = parA + parB;

    std::cout << "Par A:   " << parA << std::endl;
    std::cout << "Par B:   " << parB << std::endl;
    std::cout << "Soma (A+B): " << parSoma << " (Note: 1.5+0.5=2.0, 2.2+3.3=5.5. ID=201 de A)" << std::endl;

    std::cout << "\n--- 3. Demonstração: ParGenerico<std::string> ---" << std::endl;
    // O operador + para std::string é a concatenação
    ParGenerico<std::string> parStrA("Ola", "Mundo", 301);
    ParGenerico<std::string> parStrB("!", "!", 302);
    
    ParGenerico<std::string> parStrSoma = parStrA + parStrB;
    std::cout << "Par Str A: " << parStrA << std::endl;
    std::cout << "Par Str B: " << parStrB << std::endl;
    std::cout << "Soma (A+B):  " << parStrSoma << " (Concatenação)" << std::endl;


    std::cout << "\n--- 4. Demonstração: Comparação (==) por ID ---" << std::endl;
    CaixaGenerica<int> c1(10, 10, 555);
    CaixaGenerica<int> c2(10, 10, 666); // IDs diferentes
    CaixaGenerica<int> c3(99, 99, 555); // Mesmo ID de c1, mas valores diferentes

    std::cout << "Caixa c1: " << c1 << std::endl;
    std::cout << "Caixa c2: " << c2 << std::endl;
    std::cout << "Caixa c3: " << c3 << std::endl;
    
    std::cout << "\nComparando c1 == c2 (IDs 555 vs 666): " << (c1 == c2) << std::endl;
    std::cout << "Comparando c1 == c3 (IDs 555 vs 555): " << (c1 == c3) << std::endl;
    std::cout << "(Note que c1 == c3 é 'true' mesmo com valores diferentes, pois a regra é comparar IDs)" << std::endl;


    return 0;
}