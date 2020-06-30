#include <iostream>
#include "nodo.h"

Nodo::Nodo(Dato d){
    dato = d;
    psig = 0;
}

void Nodo::establecer_dato(Dato f){
    dato = f;
    cout<<dato<<endl;
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

Nodo::~Nodo(){
    delete dato;
}