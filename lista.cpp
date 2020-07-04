#include "lista.h"

Lista::Lista() {
    primero = nullptr;
    tamanio = 0;
}

void Lista::alta(Dato f) {
    Nodo *pnodo = new Nodo(f);
    Nodo *paux = primero;
    while (paux->obtener_siguiente() != nullptr) {
        paux = paux->obtener_siguiente();
    }
    paux->establecer_siguiente(pnodo);
    tamanio++;
}

Dato Lista::obtener_dato(unsigned pos) {
    return obtener_nodo(pos)->obtener_dato();
}

void Lista::baja(unsigned pos) {
    Nodo *paux = primero;
    if (pos == 1) {
        primero = paux->obtener_siguiente();
    } else {
        Nodo *pant = obtener_nodo(pos - 1);
        paux = pant->obtener_siguiente();
        pant->establecer_siguiente(paux->obtener_siguiente());
    }
    //delete paux->obtener_dato(); todo: después ver si hace falta
    delete paux;
    tamanio--;
}

unsigned Lista::obtener_tamanio() {
    return tamanio;
}

Nodo *Lista::obtener_nodo(unsigned pos) {
    Nodo *aux = primero;
    unsigned i = 1;
    while (i < pos) {
        aux = aux->obtener_siguiente();
        i++;
    }
    return aux;
}

bool Lista::lista_vacia() {
    return (primero == nullptr);
}

Lista::~Lista() {
    while (!(lista_vacia())) {
        baja(1);
    }
}

