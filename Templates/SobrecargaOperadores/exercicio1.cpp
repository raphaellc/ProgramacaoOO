#include <iostream> // Para std::cout, std::endl
#include <iomanip>  // Para std::boolalpha (para imprimir 'true'/'false')


class Character {
private:

    int vida;
    int ataqueFisico;
    int ataqueMagico;
    int defesa;

    int getPoderTotal() const {
        // O poder total é a soma de todos os atributos
        return vida + ataqueFisico + ataqueMagico + defesa;
    }

public:
    Character(int v, int af, int am, int d)
        : vida(v), ataqueFisico(af), ataqueMagico(am), defesa(d) {}

    int getVida() const {
        return vida;
    }
    
    int getAtaqueTotal() const {
        return ataqueFisico + ataqueMagico;
    }
    
    int getDefesa() const {
        return defesa;
    }

    Character operator+(const Character& other) const {
        int novaVida = this->vida + other.vida;
        int novoAF = this->ataqueFisico + other.ataqueFisico;
        int novoAM = this->ataqueMagico + other.ataqueMagico;
        int novaDef = this->defesa + other.defesa;

        return Character(novaVida, novoAF, novoAM, novaDef);
    }

    Character& operator-(const Character& enemy) {

        int danoSofrido = enemy.getAtaqueTotal() - this->defesa;

        if (danoSofrido < 0) {
            danoSofrido = 0;
        }

        this->vida -= danoSofrido;

        if (this->vida < 0) {
            this->vida = 0;
        }
        

        return *this;
    }


    bool operator==(const Character& other) const {
        return this->getPoderTotal() == other.getPoderTotal();
    }

    friend std::ostream& operator<<(std::ostream& os, const Character& c) {
        os << "Personagem [Vida: " << c.vida
           << ", Atq.F: " << c.ataqueFisico
           << ", Atq.M: " << c.ataqueMagico
           << ", Def: " << c.defesa << "]";
        return os;
    }
}; // Fim da classe Character

// --- Função de Batalha ---


void battle(Character a, Character b) {
    std::cout << "\n--- INICIO DA BATALHA ---" << std::endl;
    std::cout << "Lutador A: " << a << std::endl;
    std::cout << "Lutador B: " << b << std::endl;
    std::cout << "-------------------------" << std::endl;

    int turno = 1;
    while (a.getVida() > 0 && b.getVida() > 0) {
        std::cout << "Turno " << turno << ":" << std::endl;
        
        // Turno de A: B sofre dano de A
        b = b - a; // Usando o operator- sobrecarregado
        std::cout << "  A ataca B. Vida restante de B: " << b.getVida() << std::endl;
        
        if (b.getVida() <= 0) {
            std::cout << "\nO Lutador B foi derrotado! Lutador A vence!" << std::endl;
            break;
        }

        // Turno de B: A sofre dano de B
        a = a - b; // Usando o operator- sobrecarregado
        std::cout << "  B ataca A. Vida restante de A: " << a.getVida() << std::endl;

        if (a.getVida() <= 0) {
            std::cout << "\nO Lutador A foi derrotado! Lutador B vence!" << std::endl;
            break;
        }
        
        turno++;
        std::cout << "-------------------------" << std::endl;
    }
    std::cout << "--- FIM DA BATALHA ---" << std::endl;
}



int main() {
    // Configura o std::cout para imprimir "true" e "false"
    std::cout << std::boolalpha;

    // 1. Criando os personagens
    Character guerreiro(100, 25, 5, 20);
    Character mago(70, 5, 30, 10);
    Character tank(150, 10, 0, 40); // Defesa alta

    std::cout << "--- Personagens Criados ---" << std::endl;
    std::cout << "Guerreiro: " << guerreiro << std::endl; // Testando operator<<
    std::cout << "Mago.....: " << mago << std::endl;
    std::cout << "Tank.....: " << tank << std::endl;

    // 2. Testando operator+ (Modo Cooperativo)
    std::cout << "\n--- Teste do Operador + (Fusão) ---" << std::endl;
    Character fusao = guerreiro + mago;
    std::cout << "Fusão (Guerreiro + Mago): " << fusao << std::endl;

    // 3. Testando operator== (Comparação de Poder)
    std::cout << "\n--- Teste do Operador == (Poder Total) ---" << std::endl;
    std::cout << "Poder (Guerreiro == Mago)? " << (guerreiro == mago) << std::endl;
    
    // Criando um personagem com o mesmo poder total do guerreiro
    // Poder do Guerreiro: 100 + 25 + 5 + 20 = 150
    Character clone(100, 20, 5, 25); // 100+20+5+25 = 150
    std::cout << "Clone....: " << clone << std::endl;
    std::cout << "Poder (Guerreiro == Clone)? " << (guerreiro == clone) << std::endl;

    // 4. Testando a Batalha (que usa operator-)
    // A batalha usa cópias, então os originais 'guerreiro' e 'mago' não serão alterados.
    battle(guerreiro, mago);

    // Batalha 2: O guerreiro deve ter dificuldade contra o tank
    battle(guerreiro, tank);

    // Verificando se os personagens originais estão intactos
    std::cout << "\n--- Status Final (Originais) ---" << std::endl;
    std::cout << "Guerreiro: " << guerreiro << std::endl;
    std::cout << "Mago.....: " << mago << std::endl;
    std::cout << "Tank.....: " << tank << std::endl;

    return 0;
}