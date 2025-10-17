#include <iostream>

class Personagem { public: virtual ~Personagem() {} void info() { std::cout << "Personagem"; } };
class Mago : public Personagem { public: void info() { std::cout << "Mago"; } };

int main() {
Mago m;
Personagem& p_ref = m;
Personagem* p_ptr = new Mago();
Mago * m_ptr = new Mago();
p_ptr->info();
m_ptr->info();
//p_ref.info();
//m.info();
return 0;
}