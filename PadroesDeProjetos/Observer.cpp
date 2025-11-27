#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

// Interface do Assinante
class EventListener {
public:
    virtual void update(const std::string& filename) = 0;
};

// Classe Publicadora
class EventManager {
private:
    std::unordered_map<std::string, std::vector<EventListener*>> listeners;

public:
    void subscribe(const std::string& eventType, EventListener* listener) {
        listeners[eventType].push_back(listener);
    }

    void unsubscribe(const std::string& eventType, EventListener* listener) {
        auto& vec = listeners[eventType];
        vec.erase(std::remove(vec.begin(), vec.end(), listener), vec.end());
    }

    void notify(const std::string& eventType, const std::string& data) {
        for (auto listener : listeners[eventType]) {
            listener->update(data);
        }
    }
};

// Classe do Editor (Publicador Concreto)
class Editor {
private:
    EventManager events;
    std::string file;

public:
    void openFile(const std::string& path) {
        file = path;
        events.notify("open", file);
    }

    void saveFile() {
        events.notify("save", file);
    }

    EventManager& getEventManager() {
        return events;
    }
};

// Implementação do Assinante: LoggingListener
class LoggingListener : public EventListener {
private:
    std::string logFilename;
    std::string message;

public:
    LoggingListener(const std::string& logFile, const std::string& msg)
        : logFilename(logFile), message(msg) {}

    void update(const std::string& filename) override {
        std::cout << "Log: " << message.replace(message.find("%s"), 2, filename) << std::endl;
    }
};

// Implementação do Assinante: EmailAlertsListener
class EmailAlertsListener : public EventListener {
private:
    std::string email;
    std::string message;

public:
    EmailAlertsListener(const std::string& emailAddr, const std::string& msg)
        : email(emailAddr), message(msg) {}

    void update(const std::string& filename) override {
        std::cout << "Email to " << email << ": " << message.replace(message.find("%s"), 2, filename) << std::endl;
    }
};

// Classe de Aplicação para configurar os assinantes
class Application {
public:
    void config() {
        Editor editor;

        LoggingListener logger("/path/to/log.txt", "Someone has opened the file: %s");
        editor.getEventManager().subscribe("open", &logger);

        EmailAlertsListener emailAlerts("admin@example.com", "Someone has changed the file: %s");
        editor.getEventManager().subscribe("save", &emailAlerts);

        editor.openFile("example.txt");
        editor.saveFile();
    }
};

int main() {
    Application app;
    app.config();
    return 0;
}
