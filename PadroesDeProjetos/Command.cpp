#include <iostream>
#include <vector>

enum Button {
    BUTTON_X,
    BUTTON_Y,
    BUTTON_A,
    BUTTON_B
};

// Classe base Command
class Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;
};

// Comandos concretos
class JumpCommand : public Command {
public:
    void execute() override {
        std::cout << "Jump!" << std::endl;
    }
};

class FireCommand : public Command {
public:
    void execute() override {
        std::cout << "Fire Gun!" << std::endl;
    }
};

class SwapWeaponCommand : public Command {
public:
    void execute() override {
        std::cout << "Swap Weapon!" << std::endl;
    }
};

class LurchCommand : public Command {
public:
    void execute() override {
        std::cout << "Lurch Ineffectively!" << std::endl;
    }
};

// Classe InputHandler
class InputHandler {
public:
    InputHandler() {
        // Mapeia botões para comandos
        buttonX_ = new JumpCommand();
        buttonY_ = new FireCommand();
        buttonA_ = new SwapWeaponCommand();
        buttonB_ = new LurchCommand();
    }

    ~InputHandler() {
        delete buttonX_;
        delete buttonY_;
        delete buttonA_;
        delete buttonB_;
    }

    void handleInput() {
        if (isPressed(BUTTON_X)) buttonX_->execute();
        else if (isPressed(BUTTON_Y)) buttonY_->execute();
        else if (isPressed(BUTTON_A)) buttonA_->execute();
        else if (isPressed(BUTTON_B)) buttonB_->execute();
    }

private:
    Command* buttonX_;
    Command* buttonY_;
    Command* buttonA_;
    Command* buttonB_;

    bool isPressed(Button button) {
        // Implementação simulada para verificar se um botão foi pressionado
        return false; // Para fins de exemplo, sempre retorna falso
    }
};

int main() {
    InputHandler inputHandler;
    inputHandler.handleInput();
    return 0;
}
