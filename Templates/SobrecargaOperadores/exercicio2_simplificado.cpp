#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// ===============================================
// 1. CLASSE ITEM (Apenas o tipo T a ser armazenado)
// ===============================================

class Item {
private:
    std::string nome_;
    int valor_; // Usado como critério principal de ordenação
public:
    Item(const std::string& nome, int valor) : nome_(nome), valor_(valor) {}
    
    // Getters
    const std::string& obterNome() const { return nome_; }
    int obterValor() const { return valor_; }

    // ➡️ Sobrecarga do Operador < (CRITÉRIO DE ORDENAÇÃO)
    // Define a prioridade: Valor Decrescente, Nome Crescente (desempate).
    bool operator<(const Item& outro) const {
        if (valor_ != outro.valor_) {
            // Se os valores são diferentes, queremos o MAIOR valor primeiro
            // (retornar true para valor maior o coloca antes)
            return valor_ > outro.valor_; 
        }
        // Se os valores são iguais, ordena pelo nome (A-Z)
        return nome_ < outro.nome_; 
    }
    
    // Opcional: Sobrecarga do Operador == (Necessário para remoção direta)
    bool operator==(const Item& outro) const {
        return nome_ == outro.nome_ && valor_ == outro.valor_;
    }
};

// ===============================================
// 2. CLASSE TEMPLATE (O GENÉRICO)
// ===============================================

template <typename T>
class Inventario {
private:
    std::vector<T> itens_;
    std::string nomeInventario_;

public:
    Inventario(const std::string& nome = "Inventário Genérico") : nomeInventario_(nome) {}

    void adicionarItem(const T& item) { 
        itens_.push_back(item); 
    }

    // ➡️ Sobrecarga do Operador += (ADICIONAR ITEM SIMPLES)
    Inventario<T>& operator+=(const T& item) { 
        adicionarItem(item); 
        std::cout << "  [+ Adicionado via +=] " << "\n";
        return *this; 
    }
    
    bool removerItem(const T& itemParaRemover) {
        // Usa std::remove_if para encontrar o primeiro item que é == ao itemParaRemover
        auto it = std::remove_if(itens_.begin(), itens_.end(), 
            [&itemParaRemover](const T& itemAtual) {
                return itemAtual == itemParaRemover;
            }
        );

        if (it != itens_.end()) {
            itens_.erase(it, itens_.end()); 
            std::cout << "  [Removido] Item encontrado e removido.\n";
            return true;
        }
        std::cout << "  [Falha] Item não encontrado.\n";
        return false;
    }

    void listarItens() const {
        std::cout << "\n--- Conteúdo do Inventário: " << nomeInventario_ << " ---\n";
        if (itens_.empty()) {
            std::cout << "O inventário está vazio.\n";
            return;
        }
        // Nota: A listagem assume que T tem os métodos obterNome e obterValor
        for (const auto& item : itens_) {
            std::cout << "  - Nome: " << item.obterNome() << ", Valor: " << item.obterValor() << "\n";
        }
        std::cout << "--------------------------------------\n";
    }

    // ** IMPLEMENTAÇÃO DO ALGORITMO INSERTION SORT **
    void ordenarItens() {
        if (itens_.size() < 2) {
            std::cout << "Inventário já está ordenado.\n";
            return;
        }

        for (size_t i = 1; i < itens_.size(); ++i) {
            // T key = std::move(itens_[i]); // Simplificado: usa cópia em vez de move semantics
            T chave = itens_[i];
            long long j = i - 1;

            // Condição: key < items_[j] usa o operator< da classe T (Item)
            while (j >= 0 && chave < itens_[j]) { 
                // itens_[j + 1] = std::move(itens_[j]); // Simplificado: usa cópia
                itens_[j + 1] = itens_[j];
                j--;
            }
            
            // itens_[j + 1] = std::move(key); // Simplificado: usa cópia
            itens_[j + 1] = chave;
        }
        
        std::cout << "✅ Inventário ordenado usando Insertion Sort!\n";
    }
};

// ===============================================
// 3. FUNÇÃO PRINCIPAL (TESTE)
// ===============================================

int main() {
    std::cout << "========================================\n";
    std::cout << " TESTE DO INVENTÁRIO (Didático)\n";
    std::cout << "========================================\n";

    // O inventário é genérico, mas é instanciado com o tipo Item
    Inventario<Item> meuInventario("Mochila do Herói");

    // Adição de Itens (Demonstração de addItem e operator+=)
    meuInventario.adicionarItem(Item("Espada Longa", 150));
    meuInventario += Item("Escudo de Madeira", 50); 
    meuInventario.adicionarItem(Item("Poção de Vida Menor", 30));
    meuInventario += Item("Anel de Ouro", 150);
    meuInventario.adicionarItem(Item("Adaga Enferrujada", 10));

    meuInventario.listarItens();

    // ----------------------------------------
    // Teste de Ordenação (Insertion Sort)
    // ----------------------------------------
    meuInventario.ordenarItens();
    meuInventario.listarItens();
    
    // ----------------------------------------
    // Teste de Remoção
    // ----------------------------------------
    // Tenta remover o item exato (Nome: "Escudo de Madeira", Valor: 50)
    meuInventario.removerItem(Item("Escudo de Madeira", 50));
    
    // Tenta remover um item que não existe (Nome: "Escudo de Madeira", Valor: 40)
    meuInventario.removerItem(Item("Escudo de Madeira", 40));

    meuInventario.listarItens();

    return 0;
}