#include <iostream>
class Vector2D {
private:
    float x, y;

public:
    Vector2D(float x = 0, float y = 0) : x(x), y(y) {}
    
    // Sobrecarga do operador +
    //v3 = v1 + v2
    // v.operator+(v2)
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }
    
    // Sobrecarga do operador -
    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }
    
    // Sobrecarga do operador * (multiplicação escalar)
    Vector2D operator*(float scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }
    
    // Sobrecarga do operador == para comparação
    bool operator==(const Vector2D& other) const {
        return (x == other.x && y == other.y);
    }
    
    // Sobrecarga do operador == para comparação
    bool operator!=(const Vector2D& other) const {
        return (x != other.x && y != other.y);
    }
    
    // Sobrecarga do operador << para saída
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }
    
    float getX() const { return x; }
    float getY() const { return y; }
};

// Exemplo de uso em um jogo
int main() {
    Vector2D playerPos(100, 200);
    Vector2D velocity(5, -3);
    
    // Atualiza posição do jogador
    playerPos = playerPos + velocity;
    std::cout << "Nova posição: " << playerPos << std::endl;
}