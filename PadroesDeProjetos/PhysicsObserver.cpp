#include <iostream>
#include <vector>
#include <algorithm>

// Definição da interface Observer
class Observer {
public:
    virtual ~Observer() {}
    virtual void onNotify(const std::string& event) = 0;
};

// Definição da classe Subject
class Subject {
private:
    std::vector<Observer*> observers; // Lista de observadores

public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify(const std::string& event) {
        for (Observer* observer : observers) {
            observer->onNotify(event);
        }
    }
};

// Classe que representa um objeto no jogo
class GameObject {
public:
    std::string name;
    bool isOnSurface;

    GameObject(const std::string& name) : name(name), isOnSurface(true) {}

    void fall() {
        if (isOnSurface) {
            isOnSurface = false;
            std::cout << name << " Chegou ao fim!" << std::endl;
        }
    }
};

// Implementação do sistema de física
class PhysicsEngine : public Subject {
public:
    void updateEntity(GameObject& entity) {
        // Simula a atualização do estado do objeto
        entity.fall();
        if (!entity.isOnSurface) {
            notify(entity.name + " fim da Fase!"); // Notifica os observadores
        }
    }
};

// Implementação concreta de um Observer para conquistas
class AchievementSystem : public Observer {
public:
    void onNotify(const std::string& event) override {
        if (event == "Heroi fim da Fase!") {
            std::cout << "Conquista desbloqueada: Mais uma fase!" << std::endl;
        }
    }
};

// Exemplo de uso
int main() {
    PhysicsEngine physicsEngine; // Cria o motor de física
    AchievementSystem achievementSystem; // Cria o sistema de conquistas

    physicsEngine.addObserver(&achievementSystem); // Adiciona o observador

    GameObject hero("Heroi"); // Cria um objeto do tipo GameObject

    // Atualiza o estado do objeto e notifica os observadores
    physicsEngine.updateEntity(hero);

    // Remove o sistema de conquistas
    physicsEngine.removeObserver(&achievementSystem);

    // Tenta notificar novamente (não deve haver saída)
    physicsEngine.updateEntity(hero);

    return 0;
}
