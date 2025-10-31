#include "Inventario.h"
#include <string> // Inclui os tipos que serão instanciados

template <class T>
Inventario<T>::Inventario(T *item) : item(item) {}

template <class T>
Inventario<T>::~Inventario() {}

template <class T>
T* Inventario<T>::getItem() {
    return item;
}

template <class T>
void Inventario<T>::setItem(T * item) {
    this->item = item;
}