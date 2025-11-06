#include <iostream>


class ITrabalhador {
public:
    virtual ~ITrabalhador() {}
    virtual void trabalhar() = 0;
    virtual void almocar() = 0; 
};

class Humano : public ITrabalhador {
public:
    void trabalhar() override { std::cout << "Humano trabalhando..." << std::endl; }
    void almocar() override { std::cout << "Humano almoçando..." << std::endl; }
};

class Robo : public ITrabalhador {
public:
    void trabalhar() override { std::cout << "Robô trabalhando..." << std::endl; }

    void almocar() override { std::cout << "Robô almoçando..." << std::endl; }
};