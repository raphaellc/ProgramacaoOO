#include <iostream>

class Retangulo {
protected:
    double largura;
    double altura;

public:
    Retangulo(double l, double a) : largura(l), altura(a) {}

    virtual void setLargura(double l) { largura = l; }
    virtual void setAltura(double a) { altura = a; }

    double getArea() const { return largura * altura; }
};

class Quadrado : public Retangulo {
public:
    Quadrado(double lado) : Retangulo(lado, lado) {}

    void setLargura(double l) override {
        largura = altura = l; // altera comportamento do Retangulo
    }

    void setAltura(double a) override {
        largura = altura = a; // idem
    }
};

int main() {
    Retangulo* r = new Quadrado(5);
    r->setAltura(10);
    r->setLargura(20);

    std::cout << "Área (esperado 200): " << r->getArea() << "\n";
    delete r;
}
