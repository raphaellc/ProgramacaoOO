class Jogador {
private://modificador de acesso
    // a. Declare dois atributos privados inteiros
    int vida;
    int energia;

public://modificador de acesso
    // b. Inicialize por meio do construtor ambos os atributos
    Jogador(int vidaInicial, int energiaInicial);
    ~Jogador();//destrutor do objeto
    // c. Declare métodos para definir e obter o valor de cada atributo

    // Métodos para "obter" (getters)
    int getVida() const;
    int getEnergia() const;

    // Métodos para "definir" (setters)
    void setVida(int novaVida);
    void setEnergia(int novaEnergia);
};
