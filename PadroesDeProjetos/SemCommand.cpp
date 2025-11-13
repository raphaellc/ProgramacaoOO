#include <iostream>

enum Button {
    BUTTON_X,
    BUTTON_Y,
    BUTTON_A,
    BUTTON_B
};

class Game {
public:
    void jump() {
        std::cout << "Jump!" << std::endl;
    }

    void fireGun() {
        std::cout << "Fire Gun!" << std::endl;
    }

    void swapWeapon() {
        std::cout << "Swap Weapon!" << std::endl;
    }

    void lurchIneffectively() {
        std::cout << "Lurch Ineffectively!" << std::endl;
    }
};

class InputHandler {
public:
    void handleInput() {
        if (isPressed(BUTTON_X)) game.jump();
        else if (isPressed(BUTTON_Y)) game.fireGun();
        else if (isPressed(BUTTON_A)) game.swapWeapon();
        else if (isPressed(BUTTON_B)) game.lurchIneffectively();
    }

private:
    Game game;

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
