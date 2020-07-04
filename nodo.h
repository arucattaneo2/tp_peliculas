#ifndef NODO_H
#define NODO_H

#include "pelicula.h"

typedef Pelicula Dato;

class Nodo {

private:
    Dato dato;
    Nodo *psig;

public:
    /*
    constructor
    PRE: ---
    POST: Crea un nodo con el dato d y el puntero a NULL
    */
    Nodo(Dato d);

    /*
    metodo establecer_dato
    PRE: el nodo fue creado
    POST: El nodo queda con el dato d
    */
    void establecer_dato(Dato d);

    /*
    metodo obtener_dato
    PRE: el nodo fue creado
    POST: devuelve el dato que contiene el nodo
    */
    Dato obtener_dato();

    /*
    metodo establecer_siguiente
    PRE: el nodo fue creado
    POST: el puntero al siguiente nodo apuntará a psig
    */
    void establecer_siguiente(Nodo *ps);

    /*
    metodo obtener_siguiente
    PRE: el nodo fue creado
    POST: Devuelve el puntero al siguiente nodo
    */
    Nodo *obtener_siguiente();
};

#endif //NODO_H
