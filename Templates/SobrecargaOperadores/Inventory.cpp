template <typename T>
class Inventory {
private:
    std::vector<T> items_;
    std::string inventoryName_;

public:
    Inventory(const std::string& name = "Inventário Genérico") : inventoryName_(name) {}

    // Método para adicionar elementos
    void addItem(const T& item) {
        items_.push_back(item);
        std::cout << "Adicionado item ao inventário " << inventoryName_ << ".\n";
    }

    // Método para remover elementos
    bool removeItem(const T& itemToRemove) {
        // Usa std::remove para encontrar e mover o item para o final
        auto it = std::remove_if(items_.begin(), items_.end(), 
            [&](const T& currentItem) {
                // Para a remoção funcionar corretamente, T deve ter um operator== ou 
                // aqui usamos uma comparação simplificada (se o item for um objeto complexo, 
                // você pode precisar de um identificador único)
                // Usando o operator< para verificar se os itens não são diferentes (funciona para tipos simples)
                // Para itens complexos, DEVE-SE usar um ID ou operator==
                // Para este teste, vamos remover a primeira ocorrência do item *idêntico*
                return !(currentItem < itemToRemove) && !(itemToRemove < currentItem); // Equivalente a currentItem == itemToRemove
            }
        );

        if (it != items_.end()) {
            items_.erase(it, items_.end()); // Remove o elemento (ou elementos)
            std::cout << "Item removido com sucesso de " << inventoryName_ << ".\n";
            return true;
        }
        std::cout << "Item não encontrado em " << inventoryName_ << ".\n";
        return false;
    }

    // Método para listar elementos
    void listItems() const {
        std::cout << "\n--- Conteúdo do Inventário: " << inventoryName_ << " ---\n";
        if (items_.empty()) {
            std::cout << "O inventário está vazio.\n";
            return;
        }

        // Tenta imprimir o nome/valor, se os métodos existirem (usamos a classe Item para o exemplo)
        for (const auto& item : items_) {
            // Este bloco requer que T tenha get...()
            if constexpr (std::is_same_v<T, Item>) {
                std::cout << "  - Nome: " << item.getName() << ", Valor: " << item.getValue() << "\n";
            } else if constexpr (std::is_same_v<T, Potion>) {
                std::cout << "  - Efeito: " << item.getEffect() << ", Força: " << item.getStrength() << "\n";
            } else {
                std::cout << "  - Item (Tipo desconhecido para listagem detalhada).\n";
            }
        }
        std::cout << "--------------------------------------\n";
    }

    // Método para ordenar elementos (usa o operador < de T)
    void sortItems() {
        std::sort(items_.begin(), items_.end());
        std::cout << "Inventário " << inventoryName_ << " ordenado com sucesso!\n";
    }

    // Desafio Extra: Sobrecarga do operador += para adicionar itens
    Inventory<T>& operator+=(const T& item) {
        addItem(item);
        return *this;
    }
};