

#ifndef RECOMENDACIONES_H
#define RECOMENDACIONES_H

#include "Lista.h"
#include "Pelicula.h"

class Recomendaciones {

    Lista<Pelicula*> l_recomendaciones;
    Lista<Pelicula*> l_vistas;
    Lista<Pelicula*> l_no_vistas;
    Pelicula* vista;
    Pelicula* no_vista;

public:
    //Constructor
    Recomendaciones(Cargador);
    //Destructor
    ~Recomendaciones();

    //PRE:
    //POS:
    void comparar_listas();

    //PRE:
    //POS: Devuelve el atributo l_recomendaciones;
    Lista<Pelicula *> obtener_l_recomendaciones();

};

#endif //RECOMENDACIONES_H
