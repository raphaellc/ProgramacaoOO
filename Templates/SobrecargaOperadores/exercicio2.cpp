#include "Itens.cpp"
#include "Inventory.cpp"

int main() {
    std::cout << "========================================\n";
    std::cout << "       TESTE DO INVENTÁRIO DE ITENS\n";
    std::cout << "========================================\n";

    // 1. Inventário para objetos do tipo Item
    Inventory<Item> itemInventory("Inventário de Equipamento");

    // Adição de itens (usando addItem e o operador +=)
    itemInventory.addItem(Item("Espada Longa", 150));
    itemInventory += Item("Escudo de Madeira", 50); // Uso do operador +=
    itemInventory.addItem(Item("Poção de Vida Menor", 30));
    itemInventory += Item("Anel de Ouro", 150);
    itemInventory.addItem(Item("Adaga Enferrujada", 10));

    itemInventory.listItems();

    // Ordenação (Ordena por Valor > Nome)
    itemInventory.sortItems();
    itemInventory.listItems();
    /* Resultado esperado da ordenação (Valor decrescente, Nome crescente para empate):
    - Espada Longa (150)
    - Anel de Ouro (150)
    - Escudo de Madeira (50)
    - Poção de Vida Menor (30)
    - Adaga Enferrujada (10)
    */

    // Remoção de um item
    itemInventory.removeItem(Item("Escudo de Madeira", 50));
    itemInventory.listItems();

    std::cout << "\n----------------------------------------\n";
    std::cout << "       TESTE DO INVENTÁRIO DE POÇÕES\n";
    std::cout << "----------------------------------------\n";

    // 2. Inventário para objetos do tipo Potion (Tipo distinto)
    Inventory<Potion> potionInventory("Inventário de Poções");

    // Adição de poções
    potionInventory += Potion("Força", 15); // Uso do operador +=
    potionInventory.addItem(Potion("Cura", 50));
    potionInventory += Potion("Força", 10);
    potionInventory.addItem(Potion("Defesa", 50));
    potionInventory.addItem(Potion("Cura", 25));

    potionInventory.listItems();

    // Ordenação (Ordena por Força > Efeito)
    potionInventory.sortItems();
    potionInventory.listItems();
    /*
    Resultado esperado da ordenação (Força decrescente, Efeito crescente para empate):
    - Cura (50)
    - Defesa (50)
    - Força (15)
    - Cura (25)
    - Força (10)
    */

    // Remoção de um item
    potionInventory.removeItem(Potion("Cura", 50));
    potionInventory.listItems();
    
    std::cout << "========================================\n";

    return 0;
}
