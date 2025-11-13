#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>


struct NivelSeveridade {
    static const std::string INFO;
    static const std::string AVISO;
    static const std::string CRITICO;
};

// Inicialização das constantes estáticas fora da struct
const std::string NivelSeveridade::INFO = "INFO";
const std::string NivelSeveridade::AVISO = "AVISO";
const std::string NivelSeveridade::CRITICO = "CRITICO";


// Classe Principal: EntradaDeLog
class EntradaDeLog {
private:
    std::string nivel_; 
    std::string mensagem_;
    std::string tempoSimples_; 

public:
    // Acessa as constantes da struct NivelSeveridade para determinar a prioridade
    int obterPrioridade() const {
        if (nivel_ == NivelSeveridade::CRITICO) return 3;
        if (nivel_ == NivelSeveridade::AVISO) return 2;
        return 1; // INFO
    }
    EntradaDeLog(const std::string& mensagem, const std::string& nivel, const std::string& tempo)
        : mensagem_(mensagem), nivel_(nivel), tempoSimples_(tempo) {}

    const std::string& obterNivel() const { return nivel_; }

    // Sobrecarga do Operador > (Comparação de Prioridade)
    bool operator>(const EntradaDeLog& outra) const {
        return obterPrioridade() > outra.obterPrioridade();
    }

    // Sobrecarga do Operador << (Exibição Formatada)
    friend std::ostream& operator<<(std::ostream& os, const EntradaDeLog& entrada) {
        os << "[" << entrada.tempoSimples_ << "] "
           << "[" << entrada.nivel_ << "] "
           << entrada.mensagem_;
        return os;
    }

    std::string obterLogFormatado() const {
        std::stringstream ss;
        ss << *this;
        return ss.str();
    }
};

// --------------------------------------------------


// Classe Template: GerenciadorDeLogs<T>
template <typename T>
class GerenciadorDeLogs {
private:
    std::vector<T> entradas_;
    std::string nomeGerenciador_;

public:
    GerenciadorDeLogs(const std::string& nome) : nomeGerenciador_(nome) {}

    void adicionarEntrada(const T& entrada) {
        entradas_.push_back(entrada);
    }

    void listarTodosOsLogs() const {
        std::cout << "\n--- Registros: " << nomeGerenciador_ << " ---\n";
        for (const auto& entrada : entradas_) {
            std::cout << entrada << "\n"; 
        }
        std::cout << "--------------------------------------\n";
    }

    void filtrarLogs(const std::string& nivelMinimo) const {
        std::cout << "\n--- Registros Filtrados (Mínimo: " << nivelMinimo << ") ---\n";
        bool encontrado = false;
        
        // Determina a prioridade numérica mínima para filtragem
        int prioridadeMinima;
        if (nivelMinimo == NivelSeveridade::CRITICO) prioridadeMinima = 3;
        else if (nivelMinimo == NivelSeveridade::AVISO) prioridadeMinima = 2;
        else prioridadeMinima = 1;

        for (const auto& entrada : entradas_) {
            if (entrada.obterPrioridade() >= prioridadeMinima) {
                std::cout << entrada << "\n";
                encontrado = true;
            }
        }
        if (!encontrado) {
             std::cout << "Nenhum registro encontrado com este nível mínimo.\n";
        }
        std::cout << "--------------------------------------\n";
    }
    
    void exportarLogs(const std::string& nomeArquivo) const {
        std::ofstream arquivo(nomeArquivo);
        if (!arquivo.is_open()) {
            std::cerr << "ERRO: Não foi possível abrir o arquivo: " << nomeArquivo << "\n";
            return;
        }
        
        arquivo << "REGISTRO EXPORTADO\n";
        for (const auto& entrada : entradas_) {
            arquivo << entrada.obterLogFormatado() << "\n";
        }

        arquivo.close();
        std::cout << "\n✅ Registros exportados para: " << nomeArquivo << "\n";
    }
};

int main() {
    // 1. Configuração e Adição de Logs - Usando NivelSeveridade::
    GerenciadorDeLogs<EntradaDeLog> logSeguranca("Monitoramento Simples");

    logSeguranca.adicionarEntrada(EntradaDeLog("Login de usuario 'admin'.", NivelSeveridade::INFO, "10:00:00"));
    logSeguranca.adicionarEntrada(EntradaDeLog("Tentativa de Forca Bruta.", NivelSeveridade::AVISO, "10:05:30"));
    logSeguranca.adicionarEntrada(EntradaDeLog("Servidor Fora do Ar.", NivelSeveridade::CRITICO, "10:15:00"));
    
    logSeguranca.listarTodosOsLogs();
    
    // 2. Teste da Sobrecarga de Operador >
    EntradaDeLog erro("Erro de I/O", NivelSeveridade::CRITICO, "10:16:00");
    EntradaDeLog aviso("Filtro Ativado", NivelSeveridade::AVISO, "10:10:00");

    std::cout << "--- Teste de Prioridade ---\n";
    if (erro > aviso) {
        std::cout << "Erro CRITICO tem prioridade sobre AVISO.\n";
    }
    std::cout << "---------------------------\n";

    // 3. Teste do Filtro
    logSeguranca.filtrarLogs(NivelSeveridade::AVISO);
    
    // 4. Teste da Exportação
    logSeguranca.exportarLogs("log_simples_struct.txt");

    return 0;
}