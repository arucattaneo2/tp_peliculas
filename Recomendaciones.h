#ifndef RECOMENDACIONES_H
#define RECOMENDACIONES_H

using namespace std;

#include <string>
#include <fstream>
#include "Lista.h"
#include "Cargador.h"
#include "Pelicula.h"

const int PUNTAJE_MINIMO = 7;

class Recomendaciones {

private:
    //Atributos
    Lista<Pelicula *> *lista_recomendadas;
    Lista<Pelicula *> *lista_vistas;
    Lista<Pelicula *> *lista_no_vistas;

    //Metodos
    //PRE: ---
    //POS: devuelve true si las peliculas comparadas cumplen con [hay coincidencia en el género y (en el director o uno de los actores)] o [puntaje >= 7]
    bool comparar_peliculas(Pelicula *pelicula_no_vista, Pelicula *pelicula_vista);

    //PRE: ---
    //POS: devuelve true si las peliculas comparadas pertenecen al mismo genero, caso contrario devuelve false
    bool coincidencia_genero(Pelicula *pelicula_no_vista, Pelicula *pelicula_vista);

    //PRE: ---
    //POS: devuelve true si las peliculas comparadas tienen el mismo director, caso contrario devuelve false
    bool coincidencia_director(Pelicula *pelicula_no_vista, Pelicula *pelicula_vista);

    //PRE:-
    //POS: Devuelve true si el puntaje de la peli_no_vista es >= 7
    bool puntaje_suficiente(Pelicula *pelicula_no_vista);

    //PRE: ---
    //POST: devuelve true si las peliculas comparadas tienen 1 actor en comun, caso contrario devuelve false
    bool coincidencia_actores(Pelicula *pelicula_no_vista, Pelicula *pelicula_vista);


    //PRE:-
    //POS: Lee el archivo y carga la lista o lanza una excepcion dependiendo del estado del archivo
    void cargar_datos(string nombre_archivo, Lista<Pelicula *> *lista_peliculas);


    //PRE:-
    //POS: Carga la lista lista_actores
    Lista<string> *cargar_lista_actores(ifstream &archivo);

    //PRE:-
    //POS: Lanza un expcecion por pantalla que la memoria fue liberada correctamente
    void verificar_memoria_liberada();

    void cargar_recomendadas_segun_puntaje();

    bool pelicula_es_recomendada(Pelicula *pelicula_no_vista);

public:
    //Metodos
    //PRE:
    //POST:
    Recomendaciones();


    //PRE: las listas fueron creadas
    //POS:
    void crear_lista_recomendadas();

    //PRE: -
    //POST: Carga los atributos lista_no_vistas y lista_vistas con los archivos que se le pasen por parametro.
    void cargar_datos(string nombre_archivo_vistas, string nombre_archivo_no_vistas);


    //PRE: las listas fueron creadas
    //POS: devuelve un puntero al atributo lista_recomendadas
    Lista<Pelicula *> *obtener_lista_recomendadas();

    //PRE: las listas fueron creadas
    //POS: devuelve un puntero al atributo lista_vistas
    Lista<Pelicula *> *obtener_lista_vistas();

    //PRE: las listas fueron creadas
    //POS: devuelve un puntero al atributo lista_no_vistas
    Lista<Pelicula *> *obtener_lista_no_vistas();

    void borrar_lista(Lista<Pelicula *> *lista_aux);

    //PRE:
    //POST:
    ~Recomendaciones();



};

#endif //RECOMENDACIONES_H