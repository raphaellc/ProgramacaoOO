#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <fstream>

// ==========================================
// 1. SISTEMA DE ITENS E PERSISTÊNCIA (DAO & SINGLETON)
// ==========================================

struct Item {
    int id;
    std::string nome;
    int poder;
};

// Interface DAO
class ItemDAO {
public:
    virtual void saveItems(const std::vector<Item>& items) = 0;
    virtual std::vector<Item> loadItems() = 0;
    virtual ~ItemDAO() = default;
};

// Implementação Concreta do DAO (Simulada)
class FileItemDAO : public ItemDAO {
public:
    void saveItems(const std::vector<Item>& items) override {
        std::cout << "[DAO] Salvando " << items.size() << " itens no 'banco de dados'...\n";
        // Lógica de arquivo iria aqui
    }
    std::vector<Item> loadItems() override {
        std::cout << "[DAO] Carregando itens...\n";
        return { {1, "Espada Longa", 10}, {2, "Pocao de Vida", 50} };
    }
};

// Singleton Inventory
class Inventory {
private:
    std::vector<Item> items;
    std::unique_ptr<ItemDAO> dao;
    static Inventory* instance;

    // Construtor privado
    Inventory() : dao(std::make_unique<FileItemDAO>()) {
        items = dao->loadItems();
    }

public:
    static Inventory* getInstance() {
        if (instance == nullptr) {
            instance = new Inventory();
        }
        return instance;
    }

    void addItem(const Item& item) {
        items.push_back(item);
        dao->saveItems(items); // Auto-save simplificado
    }

    void listItems() const {
        std::cout << "\n--- Inventario ---\n";
        for (const auto& i : items) {
            std::cout << "- " << i.nome << " (Poder: " << i.poder << ")\n";
        }
        std::cout << "------------------\n";
    }
};
Inventory* Inventory::instance = nullptr;

// ==========================================
// 2. PADRÃO OBSERVER (HUD)
// ==========================================

class IObserver {
public:
    virtual void update(const std::string& name, int hp, int maxHp) = 0;
    virtual ~IObserver() = default;
};

class ISubject {
protected:
    std::vector<IObserver*> observers;
public:
    void attach(IObserver* observer) {
        observers.push_back(observer);
    }
    void notify(const std::string& name, int hp, int maxHp) {
        for (auto* obs : observers) {
            obs->update(name, hp, maxHp);
        }
    }
    virtual ~ISubject() = default;
};

// O HUD concreto
class HUD : public IObserver {
public:
    void update(const std::string& name, int hp, int maxHp) override {
        std::cout << "   [HUD UPDATE] Personagem: " << name 
                  << " | HP: " << hp << "/" << maxHp << "\n";
    }
};

// ==========================================
// 3. PERSONAGENS (BRIDGE/HERANÇA & INTERFACE)
// ==========================================

// Interface de Combatente
class ICombatant {
public:
    virtual void attack(ICombatant* target) = 0;
    virtual void takeDamage(int damage) = 0;
    virtual bool isAlive() const = 0;
    virtual std::string getName() const = 0;
    virtual int getDamage() const = 0;
    virtual ~ICombatant() = default;
};

// Classe Base Abstrata (Herança Virtual para evitar Diamante)
class Character : public ICombatant, public ISubject {
protected:
    std::string name;
    int hp;
    int maxHp;
    int baseDamage;

public:
    Character(std::string n, int h, int dmg) : name(n), hp(h), maxHp(h), baseDamage(dmg) {}

    void takeDamage(int damage) override {
        hp -= damage;
        if (hp < 0) hp = 0;
        // Notifica o HUD sempre que toma dano
        notify(name, hp, maxHp);
    }

    bool isAlive() const override { return hp > 0; }
    std::string getName() const override { return name; }
    
    // Método auxiliar para classes filhas modificarem status
    void addBonus(int hpBonus, int dmgBonus) {
        maxHp += hpBonus;
        hp = maxHp;
        baseDamage += dmgBonus;
    }
};

// --- Raças (Herança) ---
class Orc : virtual public Character {
public:
    Orc(std::string n) : Character(n, 100, 15) { // Orcs tem base forte
        std::cout << n << " nasceu como Orc.\n";
    }
    std::string getRaceAbility() { return "Furia"; }
};

class Human : virtual public Character {
public:
    Human(std::string n) : Character(n, 80, 10) { // Humanos balanceados
        std::cout << n << " nasceu como Humano.\n";
    }
    std::string getRaceAbility() { return "Diplomacia"; }
};

// --- Classes/Jobs (Herança) ---
// Note que Guerreiro herda de Character virtualmente também
class Warrior : virtual public Character {
public:
    Warrior(std::string n) : Character(n, 0, 0) { // Stats base vem da Raça
        addBonus(50, 5); // Guerreiro ganha +50 HP e +5 Dano
    }
    
    void attack(ICombatant* target) override {
        std::cout << name << " (Guerreiro) desfere um golpe pesado!\n";
        target->takeDamage(getDamage());
    }
    
    int getDamage() const override { return baseDamage + 5; }
};

class Mage : virtual public Character {
public:
    Mage(std::string n) : Character(n, 0, 0) {
        addBonus(10, 20); // Mago ganha pouco HP mas muito Dano
    }

    void attack(ICombatant* target) override {
        std::cout << name << " (Mago) lanca uma bola de fogo!\n";
        target->takeDamage(getDamage());
    }

    int getDamage() const override { return baseDamage + 15; }
};

// --- Classes Concretas Finais (Junção de Raça e Classe) ---

class OrcWarrior : public Orc, public Warrior {
public:
    OrcWarrior(std::string n) : Character(n, 100, 15), Orc(n), Warrior(n) {}
};

class HumanMage : public Human, public Mage {
public:
    HumanMage(std::string n) : Character(n, 80, 10), Human(n), Mage(n) {}
};

// ==========================================
// 4. ABSTRACT FACTORY
// ==========================================

class CharacterFactory {
public:
    virtual Character* createWarrior(std::string name) = 0;
    virtual Character* createMage(std::string name) = 0;
    virtual ~CharacterFactory() = default;
};

class OrcFactory : public CharacterFactory {
public:
    Character* createWarrior(std::string name) override {
        return new OrcWarrior(name);
    }
    Character* createMage(std::string name) override {
        // Orcs magos são raros, mas possíveis no sistema
        // Para simplificar, criaríamos uma classe OrcMage se necessário
        // Aqui retornaremos um OrcWarrior disfarçado para não estender demais o código
        return new OrcWarrior(name + " (Xaman)"); 
    }
};

class HumanFactory : public CharacterFactory {
public:
    Character* createWarrior(std::string name) override {
        // Implementar HumanWarrior se necessário, aqui usaremos o Mago como exemplo principal
        return new HumanMage(name + " (Paladino)"); 
    }
    Character* createMage(std::string name) override {
        return new HumanMage(name);
    }
};

// ==========================================
// 5. SISTEMA DE COMBATE (Lógica Separada)
// ==========================================

class CombatSystem {
public:
    static void startCombat(ICombatant* c1, ICombatant* c2) {
        std::cout << "\n=== INICIO DO COMBATE ===\n";
        std::cout << c1->getName() << " VS " << c2->getName() << "\n\n";

        int turn = 1;
        while (c1->isAlive() && c2->isAlive()) {
            std::cout << "--- Turno " << turn << " ---\n";
            
            // Turno do C1
            c1->attack(c2);
            if (!c2->isAlive()) break;

            // Turno do C2
            c2->attack(c1);
            
            turn++;
            std::cout << "\n";
        }

        std::cout << "\n=== FIM DO COMBATE ===\n";
        if (c1->isAlive()) 
            std::cout << "Vencedor: " << c1->getName() << "\n";
        else 
            std::cout << "Vencedor: " << c2->getName() << "\n";
    }
};

// ==========================================
// 6. MAIN
// ==========================================

int main() {
    // 1. Configurar Inventário (Singleton)
    Inventory* inv = Inventory::getInstance();
    inv->listItems();

    // 2. Configurar HUD (Observer)
    HUD* gameHud = new HUD();

    // 3. Criar Fábricas
    std::unique_ptr<CharacterFactory> orcFactory = std::make_unique<OrcFactory>();
    std::unique_ptr<CharacterFactory> humanFactory = std::make_unique<HumanFactory>();

    // 4. Criar Personagens via Fábrica
    // Nota: Cast para Character* para acessar attach(), pois ICombatant não tem attach()
    // No mundo real, Character herdaria de ISubject e implementaria ICombatant
    Character* p1 = orcFactory->createWarrior("Thrall");
    Character* p2 = humanFactory->createMage("Jaina");

    // 5. Registrar HUD nos personagens
    p1->attach(gameHud);
    p2->attach(gameHud);

    // 6. Iniciar Combate
    // O sistema aceita apenas a interface ICombatant, desacoplando da implementação concreta
    CombatSystem::startCombat(p1, p2);

    // Limpeza de memória (Simplificada)
    delete p1;
    delete p2;
    delete gameHud;

    return 0;
}