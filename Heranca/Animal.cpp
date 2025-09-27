#include <iostream>
using namespace std;

class Animal {

public:
    Animal(){};
    virtual void mover() { cout << "Não sei qual animal sou!" << endl; }
};

class Peixe : public Animal {
public:
    Peixe(){};
    void mover() { cout << "Nadando!" << endl; }
};

int main() {
    Animal* a = new Peixe();
    a->mover();
    return 0;
}