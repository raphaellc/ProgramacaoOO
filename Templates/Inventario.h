#pragma once
template <class T>
class Inventario {
public:
    T * item = nullptr;
    int size = 0;

    Inventario(T *item);
    ~Inventario();
    T* getItem();
    void setItem(T * item);
};