#include <iostream>
#include <vector>

template <typename T, typename CipherFunc>
class CryptoEngine {
private:
    CipherFunc cipher;

public:
    CryptoEngine(CipherFunc func) : cipher(func) {}
    
    std::vector<T> encrypt(const std::vector<T>& data) {
        std::vector<T> result;
        for (const auto& item : data) {
            result.push_back(cipher(item, true));
        }
        return result;
    }
    
    std::vector<T> decrypt(const std::vector<T>& data) {
        std::vector<T> result;
        for (const auto& item : data) {
            result.push_back(cipher(item, false));
        }
        return result;
    }
};

// Função de cifra simples (XOR)
class XORCipher {
private:
    unsigned char key;
public:
    XORCipher(unsigned char k) : key(k) {}
    
    unsigned char operator()(unsigned char data, bool encrypt) const {
        return data ^ key; // XOR é simétrico
    }
};

// Uso
int main() {
    XORCipher xorCipher(0xAB);
    CryptoEngine<unsigned char, XORCipher> engine(xorCipher);
    
    std::vector<unsigned char> message = {'H', 'e', 'l', 'l', 'o'};
    auto encrypted = engine.encrypt(message);
    auto decrypted = engine.decrypt(encrypted);
    
    for (auto c : decrypted) {
        std::cout << c;
    }
    std::cout << std::endl;
}