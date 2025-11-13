#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>


class Projetil {
public:
    int id;
    float x;
    float y;
    float velocidade;
    
    Projetil(int id_inicial = 0) : id(id_inicial), x(0.0f), y(0.0f), velocidade(0.0f) {}

    // Método para "ativar" o projétil
    void atirar(float inicio_x, float inicio_y, float velocidade_tiro) {
        x = inicio_x;
        y = inicio_y;
        velocidade = velocidade_tiro;
        std::cout << "  [ATIRADO] Projétil ID " << id << " em (" << x << ", " << y << ") com velocidade " << velocidade << ".\n";
    }

    // Método para "reiniciar" o projétil
    void reiniciar() {
        x = 0.0f;
        y = 0.0f;
        velocidade = 0.0f;
    }
};

// ===============================================
// 2. CLASSE TEMPLATE: RESERVA DE OBJETOS (ObjectPool<T>)
// ===============================================

template <typename T>
class ReservaDeObjetos {
private:
    std::vector<std::unique_ptr<T>> todosOsObjetos_; 
    std::vector<T*> disponiveis_; 
    
    int totalAlocado_ = 0;
    int emUso_ = 0;

public:
    // Construtor: Pré-aloca os objetos
    ReservaDeObjetos(size_t tamanhoReserva) {
        std::cout << "--- Inicializando Reserva de Objetos (" << tamanhoReserva << " slots) ---\n";
        for (size_t i = 0; i < tamanhoReserva; ++i) {
            auto novoObjeto = std::make_unique<T>(i + 1); 
            T* ptr = novoObjeto.get();

            todosOsObjetos_.push_back(std::move(novoObjeto));
            disponiveis_.push_back(ptr);
            totalAlocado_++;
        }
        std::cout << "Reserva pronta. " << totalAlocado_ << " objetos pré-alocados.\n";
    }


    T* adquirir() {
        if (disponiveis_.empty()) {
            std::cerr << "⚠️ ERRO: Reserva vazia! Não é possível adquirir mais objetos.\n";
            return nullptr;
        }

        T* objeto = disponiveis_.back();
        disponiveis_.pop_back();
        
        emUso_++;
        return objeto;
    }

    // Método para devolver o objeto à reserva 
    void liberar(T* obj) {
        if (!obj) return;
        
        obj->reiniciar(); // Limpa o estado
        disponiveis_.push_back(obj);
        emUso_--;
        
        std::cout << "  [DEVOLVIDO] Projétil ID " << obj->id << " liberado e reiniciado.\n";
    }

    // Exibir Estatísticas
    void exibirEstatisticas() const {
        std::cout << "\n--- Estatísticas da Reserva ---\n";
        std::cout << "Total de Objetos Pré-alocados: " << totalAlocado_ << "\n";
        std::cout << "Objetos Disponíveis (Livres): " << disponiveis_.size() << "\n";
        std::cout << "Objetos em Uso: " << emUso_ << "\n";
        std::cout << "------------------------------\n";
    }
};

// ===============================================
// 3. CLASSE ARMA 
// ===============================================

class Arma {
private:
    ReservaDeObjetos<Projetil>& reserva_; // 
    std::vector<Projetil*> projeteisAtivos_;

public:
    Arma(ReservaDeObjetos<Projetil>& reserva) : reserva_(reserva) {}

    
    void atirar(float x, float y, float velocidade) {
        Projetil* p = reserva_.adquirir();
        if (p) {
            p->atirar(x, y, velocidade);
            projeteisAtivos_.push_back(p);
        }
    }

    
    void limparProjeteis(int id_projetil) {
        auto it = std::find_if(projeteisAtivos_.begin(), projeteisAtivos_.end(), 
            [id_projetil](Projetil* p) { return p->id == id_projetil; });

        if (it != projeteisAtivos_.end()) {
            Projetil* p = *it;
            reserva_.liberar(p); // Devolve à reserva
            projeteisAtivos_.erase(it); 
        }
    }
};

int main() {
    // 1. Criação da Reserva para 3 Projéteis
    ReservaDeObjetos<Projetil> reservaDeProjeteis(3); // 
    Arma jogador1(reservaDeProjeteis); // 

    reservaDeProjeteis.exibirEstatisticas();

    std::cout << "\n--- TIRO 1: Adquirindo objetos ---\n";
    
    // 2. Adquirir 3 Projéteis (Preenchendo a reserva)
    jogador1.atirar(10.0f, 5.0f, 100.0f); 
    jogador1.atirar(11.0f, 5.0f, 100.0f); 
    jogador1.atirar(12.0f, 5.0f, 120.0f); 
    
    reservaDeProjeteis.exibirEstatisticas();

    std::cout << "\n--- TIRO 2: Reserva está cheia (tentativa de falha) ---\n";
    
    // 3. Tentativa de adquirir um 4º objeto
    jogador1.atirar(20.0f, 10.0f, 80.0f);

    reservaDeProjeteis.exibirEstatisticas();

    std::cout << "\n--- TIRO 3: Liberando e Reutilizando ---\n";
    
    // 4. Libera o primeiro projétil (ID 1)
    jogador1.limparProjeteis(1); 
    
    reservaDeProjeteis.exibirEstatisticas();

    // 5. Atira novamente (reutiliza o ID 1)
    jogador1.atirar(30.0f, 15.0f, 150.0f); 

    reservaDeProjeteis.exibirEstatisticas();
    
    return 0;
}
