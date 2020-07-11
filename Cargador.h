#ifndef CARGADOR_H_
#define CARGADOR_H_

#include <string>
#include <fstream>
#include "Lista.h"
#include "Pelicula.h"

class Cargador {

private:
    Lista<Pelicula *> lista_vistas;
    Lista<Pelicula *> lista_no_vistas;


public:
    //Constructor
    //Cargador();

    //Destructor
    ~Cargador();

    //PRE:-
    //POS: Lee el archivo y carga la lista o lanza una excepcion dependiendo del estado del archivo
    void cargar_datos(string nombre_archivo);

    void cargar_lista(string nombre_archivo, string nombre, string genero, string director, unsigned puntos, Lista<string> *elenco);

    //PRE:-
    //POS: Carga la lista lista_peliculas
    void cargar_lista_no_vistas(string nombre, string genero, string director, unsigned puntos, Lista<string> *elenco);

    void cargar_lista_vistas(string nombre, string genero, string director, unsigned puntos, Lista<string> *elenco);

    //PRE:-
    //POS: Carga la lista lista_actores
    Lista<string> *cargar_lista_actores(ifstream &archivo);

    //PRE:-
    //POS: Devuelve lista_peliculas_vistas
    Lista<Pelicula *> obtener_peliculas_vistas();

    //PRE:-
    //POS: Devuelve lista_peliculas_no_vistas
    Lista<Pelicula *> obtener_peliculas_no_vistas();

    //PRE:-
    //POS: Lanza un expcecion por pantalla que la memoria fue liberada correctamente
    void verificar_memoria_liberada();

};

#endif //CARGADOR_H