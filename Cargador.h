

#ifndef CARGADOR_H_
#define CARGADOR_H_

#include "Lista.h"
#include "Pelicula.h"
#include <string.h>
#include <fstream>

class Cargador {

    Lista<Pelicula *> l_peliculas_vistas;
    Lista<Pelicula *> l_peliculas_no_vistas;


public:
    //Constructor
    Cargador();

    //Destructor
    ~Cargador();

    //PRE:-
    //POS: Lee el archivo y carga la lista o lanza una excepcion dependiendo del estado del archivo
    void cargar_datos(string);

    void cargar_lista(string, string, string, string, unsigned, Lista<string> *);

    //PRE:-
    //POS: Carga la lista l_peliculas
    void cargar_lista_no_vistas(string, string, string, unsigned, Lista<string> *);

    void cargar_lista_vistas(string, string, string, unsigned, Lista<string> *);

    //PRE:-
    //POS: Carga la lista l_actores
    Lista<string> * cargar_l_actores(ifstream &);

    //PRE:-
    //POS: Devuelve l_peliculas_vistas
    Lista<Pelicula *> obtener_peliculas_vistas();
    //PRE:-
    //POS: Devuelve l_peliculas_no_vistas
    Lista<Pelicula *> obtener_peliculas_no_vistas();

    //PRE:-
    //POS: Lanza un expcecion por pantalla que la memoria fue liberada correctamente
    void verificar_memoria_liberada();

};


#endif //CARGADOR_H
