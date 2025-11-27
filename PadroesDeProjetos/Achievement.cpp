#include <iostream>
#include <vector>

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

// Implementação concreta de um Observer
class GameEvent : public Observer {
public:
    void onNotify(const std::string& event) override {
        std::cout << "Evento recebido: " << event << std::endl;
    }
};

// Exemplo de uso
int main() {
    Subject subject; // Cria um subject
    GameEvent eventObserver; // Cria um observador

    subject.addObserver(&eventObserver); // Adiciona o observador ao subject

    // Notifica os observadores sobre um evento
    subject.notify("O jogador ganhou uma conquista!");

    // Remove o observador
    subject.removeObserver(&eventObserver);

    // Notifica novamente (nenhum observador deve receber)
    subject.notify("Esse evento não será recebido.");

    return 0;
}
