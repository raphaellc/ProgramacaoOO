#include <iostream>

class Personagem { public: virtual ~Personagem() {} void info() { std::cout << "Personagem"; } };
class Mago : public Personagem { public: void info() { std::cout << "Mago"; } };

int main() {
Mago m;
Personagem& p_ref = m;
p_ref.info();
return 0;
}