#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"

class Lista {

private:
    Nodo *primero;
    unsigned tamanio;

public:
    /*
    constructor
    PRE: ---
    POST: construye una lista vacia
    */
    Lista();

    /*
    metodo lista_vacia
    PRE: la lista fue creada
    POST: indica si la lista tiene elementos dentro o no
    */
    bool lista_vacia();

    /*
    metodo obtener_tamanio
    PRE: la lista fue creada
    POST: devuelve el tamanio de la lista
    */
    unsigned obtener_tamanio();

    /*
    metodo alta
    PRE: la lista fue creada
    POST: agrega un dato a la lista e incrementa en una unidad el tamanio
    */
    void alta(Dato f);

    /*
    metodo baja
    PRE: la lista fue creada
    POST: libera el nodo que esta en la posición pos
    */
    void baja(unsigned pos);

    /*
    metodo obtener_dato
    PRE: la lista fue creada
    POST: devuelve un puntero al dato de la posicion pos
    */
    Dato obtener_dato(unsigned pos);

    /*
    destructor
    PRE: la lista fue creada
    POST: elimina la lista
    */
    ~Lista();

private:
    // PRE: 0 < pos <= tam
    // POST: devuelve un puntero al nodo
    Nodo *obtener_nodo(unsigned pos);

};

#endif //LISTA_H