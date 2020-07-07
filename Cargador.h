

#ifndef CARGADOR_H
#define CARGADOR_H

#include "Lista.h"
#include "Pelicula.h"
#include <string>
#include <fstream>

class Cargador{

    Lista<Pelicula> l_peliculas;
    Lista<string> l_actores;

public:

    Cargador();
    ~Cargador();
    void cargar_datos(ifstream archivo);
    void cargar_l_peliculas(string nombre, string genero, string director, int puntaje, int posicion);
    void cargar_l_actores(ifstream);
    Lista<Pelicula> obtener_l_peliculas();
    Lista<string> obtener_l_actores();
    void verificar_existencia(ifstream archivo);

};


#endif //CARGADOR_H
