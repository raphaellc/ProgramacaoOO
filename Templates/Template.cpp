#include <vector>
#include <iostream>
template <class T>
class Inventario {
    public:
        T * item = nullptr;
        int size = 0;
        Inventario(T *item) : item(item) {}
        ~Inventario();
        T* getItem(){
            return item;
        }
        void setItem (T * item){
            this->item = item;
        }
};

template <class U>
void swap(U *a, U *b){
    U temp = *a;
    *a = *b;
    *b = temp;
   
}

int main(){
    int* i = new int[10];
    float * f = new float[10];
    char * c = new char[10];
    Inventario<int> * inv = new Inventario<int>(i);
    Inventario<float> * inv1 = new Inventario<float>(f);
    Inventario<char> * inv2 = new Inventario<char>(c);
    int a, b;
    a = 10;
    b = 20;
    swap(&a, &b);
    std::cout << a << " " << b << std::endl;
    return 0;

}