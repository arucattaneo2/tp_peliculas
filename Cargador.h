

#ifndef CARGADOR_H_
#define CARGADOR_H_

#include "Lista.h"
#include "Pelicula.h"
#include <string>
#include <fstream>

class Cargador {

    Lista<Pelicula *> l_peliculas;


public:
    //Constructor
    Cargador();

    //Destructor
    ~Cargador();

    //PRE:-
    //POS: Lee el archivo y carga la lista o lanza una excepcion dependiendo del estado del archivo
    void cargar_datos(string);

    //PRE:-
    //POS: Carga la lista l_peliculas
    void cargar_l_peliculas(string, string, string, unsigned, Lista<string>*);

    //PRE:-
    //POS: Carga la lista l_actores
    Lista<string>* cargar_l_actores(ifstream &);

    //PRE:-
    //POS: Devuelve l_peliculas
    Lista<Pelicula *> obtener_l_peliculas();

    //PRE:-
    //POS: Lanza un expcecion por pantalla que la memoria fue liberada correctamente
    void verificar_memoria_liberada();

};


#endif //CARGADOR_H
