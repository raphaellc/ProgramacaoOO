#include <iostream>
class Animal {
public:
    Animal() {
        std::cout << "Construtor de Animal padrão chamado." << std::endl;
    }
    Animal(std::string especie) : especie_(especie) {
        std::cout << "Construtor de Animal chamado com especie: " << especie_ << std::endl;
    }
protected:
    std::string especie_;
};

class Cachorro : public Animal {
public:
    Cachorro() : Animal() { // Chamada EXPLÍCITA do construtor padrão de Animal
        std::cout << "Construtor de Cachorro padrão chamado." << std::endl;
        raca_ = "SRD";
    }

    Cachorro(std::string nome, std::string raca) : Animal("Canis familiaris"), nome_(nome), raca_(raca) {
        // Chamada EXPLÍCITA do construtor de Animal que recebe a espécie
        std::cout << "Construtor de Cachorro chamado com nome: " << nome_ << ", raca: " << raca_ << std::endl;
    }

private:
    std::string nome_;
    std::string raca_;
};

int main() {
    Cachorro c1;
    Cachorro c2("Rex", "Pastor Alemão");
    return 0;
}