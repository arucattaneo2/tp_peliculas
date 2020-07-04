#include "nodo.h"

Nodo::Nodo(Dato d){
    dato = d;
    psig = nullptr;
}

void Nodo::establecer_dato(Dato d){
    dato = d;
}

Dato Nodo::obtener_dato(){
    return dato;
}

void Nodo::establecer_siguiente(Nodo* ps){
    psig = ps;
}

Nodo* Nodo::obtener_siguiente(){
    return psig;
}
