#include "lista.h"

Lista::Lista(){
    primero = 0 ;
    tamanio = 0;
}

void Lista::insertar(Dato f){
    Nodo* pnodo = new Nodo(f);
    Nodo* paux = primero;
    if (this->lista_vacia()){
        primero = pnodo;
    }
    else{
        while (paux->obtener_siguiente() != 0){
            paux = paux->obtener_siguiente();
        }
        paux->establecer_siguiente(pnodo);
    }
    tamanio++;
}

Dato Lista::obtener_dato(unsigned pos){
    Nodo* paux = primero;
    unsigned i = 1;
    while (i < pos && paux->obtener_siguiente()){
        paux = paux->obtener_siguiente();
        i++;
    }
    return paux->obtener_dato();
}

void Lista::borrar_dato(unsigned pos){
    Nodo* paux = primero;
    if (pos == 1 || !(primero->obtener_siguiente())){
        primero = paux->obtener_siguiente();
    }
    else{
        unsigned i = 1;
        Nodo* pant; 
        while (i < pos && paux->obtener_siguiente()){
            pant = paux;
            paux = paux->obtener_siguiente();
            i++;
        }
        pant->establecer_siguiente(paux->obtener_siguiente());
    }
    delete paux;
    tamanio--;
}

unsigned Lista::obtener_tamanio(){
    return tamanio;
}

bool Lista::lista_vacia(){
    return(primero == 0);
}

Lista::~Lista(){
    while (!(this->lista_vacia())){
        this->borrar_dato(1);
    }
}