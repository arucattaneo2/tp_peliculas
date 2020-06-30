#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "nodo.h"

typedef Figura* Dato;

// se declara la clase Lista
class Lista{
     private:

        Nodo* primero;
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
         metodo insertar
         PRE: la lista fue creada
         POST: agrega un dato a la lista e incrementa en unoa unidad el tamanio
         */
         void insertar(Dato f);
         /*
         metodo borrar_dato
         PRE: la lista fue creada
         POST: libera el nodo que esta en la posición pos
         */
         void borrar_dato(unsigned pos);
         /*
         metodo obtener_dato
         PRE: la lista fue creada
         POST: devuelve el dato de la posicion pos
         */
         Dato obtener_dato(unsigned pos);
         /*
         destructor
         PRE: la lista fue creada
         POST: elimina la lista
         */
         ~Lista();
};
#endif //LISTA_H