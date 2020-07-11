#ifndef RECOMENDACIONES_H
#define RECOMENDACIONES_H

using namespace std;

#include <string.h>
#include "Lista.h"
#include "Cargador.h"
#include "Pelicula.h"

class Recomendaciones {

private:
    Lista<Pelicula *> lista_recomendaciones;
    Lista<Pelicula *> lista_vistas;
    Lista<Pelicula *> lista_no_vistas;
    Pelicula peli_vista;
    Pelicula peli_no_vista;

public:
    //metodo constructor
    //PRE:
    //POST:
    Recomendaciones(Cargador cargador);

    //metodo destructor
    //PRE:
    //POST:
    ~Recomendaciones();

    //metodo comparar_listas
    //PRE: las listas fueron creadas
    //POS:
    void comparar_listas();

    //metodo generar_lista_recomendadas
    //PRE: las listas fueron creadas
    //POS: crea la lista de peliculas recomendadas
    Lista<Pelicula *> generar_lista_recomendadas();

    //metodo obtener_lista_recomendaciones
    //PRE: las listas fueron creadas
    //POS: devuelve el atributo lista_recomendaciones
    Lista<Pelicula *> obtener_lista_recomendaciones();

    //metodo coincidencias
    //PRE: ---
    //POS: devuelve el valor de verdad resultante del criterio de recomendacion
    bool coincidencias();

    //metodo coincidencia_genero
    //PRE: ---
    //POS: devuelve el valor de verdad de la coincidencia entre los géneros de peli_vista y peli_no_vista
    bool coincidencia_genero();

    //metodo coincidencia_director
    //PRE: ---
    //POS: devuelve el valor de verdad de la coincidencia entre los directores de peli_vista y peli_no_vista
    bool coincidencias_director();

};

#endif //RECOMENDACIONES_H