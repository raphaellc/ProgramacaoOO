#include <iostream>
#include <vector>
#include <memory> // Para usar smart pointers (std::unique_ptr)

// Enum de Botões (mantido)
enum Button {
    BUTTON_X,
    BUTTON_Y,
    BUTTON_A,
    BUTTON_B
};

// 1. Classe Receptor (Actor)
// O objeto que sabe realizar todas as operações
class Actor {
public:
    void jump() {
        std::cout << "Actor: Jump!" << std::endl;
    }
    void fireGun() {
        std::cout << "Actor: Fire Gun!" << std::endl;
    }
    void swapWeapon() {
        std::cout << "Actor: Swap Weapon!" << std::endl;
    }
    void lurchIneffectively() {
        std::cout << "Actor: Lurch Ineffectively!" << std::endl;
    }
};

// Classe base Command (mantida)
class Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;
};

// 2. Comandos Concretos com Referência ao Actor (Receptor)
// Eles encapsulam a ação E o receptor (Actor) que a executará.

class JumpCommand : public Command {
private:
    Actor& actor_; // Referência ao ator

public:
    // Injeção da dependência (o ator) no construtor
    JumpCommand(Actor& actor) : actor_(actor) {}

    void execute() override {
        actor_.jump(); // Chama o método real no ator
    }
};

class FireCommand : public Command {
private:
    Actor& actor_;

public:
    FireCommand(Actor& actor) : actor_(actor) {}

    void execute() override {
        actor_.fireGun();
    }
};

class SwapWeaponCommand : public Command {
private:
    Actor& actor_;

public:
    SwapWeaponCommand(Actor& actor) : actor_(actor) {}

    void execute() override {
        actor_.swapWeapon();
    }
};

class LurchCommand : public Command {
private:
    Actor& actor_;

public:
    LurchCommand(Actor& actor) : actor_(actor) {}

    void execute() override {
        actor_.lurchIneffectively();
    }
};

// 3. Classe InputHandler com Injeção de Dependência
// O InputHandler não sabe (e não se importa) quais comandos concretos ele está usando;
// ele só precisa de objetos que implementem a interface Command.
class InputHandler {
public:
    // Injeção de Dependência no construtor
    // Usamos std::unique_ptr para gerenciar a memória dos comandos
    InputHandler(std::unique_ptr<Command> x,
                 std::unique_ptr<Command> y,
                 std::unique_ptr<Command> a,
                 std::unique_ptr<Command> b)
        : buttonX_(std::move(x)),
          buttonY_(std::move(y)),
          buttonA_(std::move(a)),
          buttonB_(std::move(b))
    {
        // O InputHandler agora é mais desacoplado.
        // A lógica de "o que o botão faz" foi movida para fora desta classe.
    }

    // Não precisamos de um destrutor explícito, o unique_ptr fará o trabalho.

    void handleInput(Button pressedButton) {
        if (pressedButton == BUTTON_X) buttonX_->execute();
        else if (pressedButton == BUTTON_Y) buttonY_->execute();
        else if (pressedButton == BUTTON_A) buttonA_->execute();
        else if (pressedButton == BUTTON_B) buttonB_->execute();
    }

private:
    std::unique_ptr<Command> buttonX_;
    std::unique_ptr<Command> buttonY_;
    std::unique_ptr<Command> buttonA_;
    std::unique_ptr<Command> buttonB_;
};

int main() {
    // 4. Configuração (Composition Root)
    
    // 4a. Criação do Receptor (Ator)
    Actor player;

    // 4b. Criação dos Comandos Concretos, injetando o Receptor (Ator)
    // Usamos std::make_unique para criar e gerenciar a memória.
    auto jump = std::make_unique<JumpCommand>(player);
    auto fire = std::make_unique<FireCommand>(player);
    auto swap = std::make_unique<SwapWeaponCommand>(player);
    auto lurch = std::make_unique<LurchCommand>(player);

    // 4c. Criação do InputHandler, injetando os Comandos
    // Os comandos são transferidos (movidos) para o InputHandler.
    InputHandler inputHandler(std::move(jump),
                              std::move(fire),
                              std::move(swap),
                              std::move(lurch));

    std::cout << "--- Testando Input ---" << std::endl;
    
    // Simulação da pressão dos botões
    std::cout << "Pressionando X:" << std::endl;
    inputHandler.handleInput(BUTTON_X);

    std::cout << "Pressionando Y:" << std::endl;
    inputHandler.handleInput(BUTTON_Y);
    
    std::cout << "Pressionando B:" << std::endl;
    inputHandler.handleInput(BUTTON_B);

    return 0;
}