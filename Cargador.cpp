
#include "Cargador.h"
#include <iostream>
#include "Memoria_liberada.h"

Cargador::Cargador() {

    l_peliculas_vistas;
    l_peliculas_no_vistas;
}


Cargador::~Cargador() {


}


void Cargador::cargar_datos(string nombre_archivo) {

    ifstream archivo(nombre_archivo);
    string nombre, genero, director;
    Lista<string> *elenco;
    unsigned puntos;

    if (!archivo && nombre_archivo == "peliculas_no_vistas.txt") {
        verificar_memoria_liberada();
    }
    else if (archivo.fail())
        cout << "Error no se pudo abrir el archivo" << endl;
    else {
        while (archivo >> nombre) {
            archivo >> genero;
            archivo >> puntos;
            archivo >> director;
            elenco = cargar_l_actores(archivo);
            cargar_lista(nombre_archivo, nombre, genero, director, puntos, elenco);

        }
        archivo.close();
    }


}

void Cargador::cargar_lista(string archivo, string nombre, string genero, string director, unsigned pts,
        Lista<string> *elenco){

    if(archivo == "peliculas_no_vistas.txt")
        cargar_lista_no_vistas(nombre, genero, director, pts, elenco);
    else
        cargar_lista_vistas(nombre, genero, director, pts, elenco);

}

void Cargador::cargar_lista_no_vistas(string nombre, string genero, string director, unsigned pts,
        Lista<string>* elenco) {

    Pelicula *pelicula = new Pelicula(nombre, genero, director, pts, elenco);
    l_peliculas_no_vistas.alta(pelicula);

}


void Cargador::cargar_lista_vistas(string nombre, string genero, string director, unsigned pts,
        Lista<string>* elenco) {

    Pelicula *pelicula = new Pelicula(nombre, genero, director, pts, elenco);
    l_peliculas_vistas.alta(pelicula);


}


Lista<string>* Cargador::cargar_l_actores(ifstream &archivo) {

    string actores;
    Lista<string> *l_actores = new Lista<string>;

    while(archivo >> actores && archivo.get() != '\n'){
        l_actores->alta(actores);
 
    }
    l_actores->alta(actores);
   

    return l_actores;
}


Lista<Pelicula *> Cargador::obtener_peliculas_vistas() {

    return l_peliculas_vistas;
}

Lista<Pelicula *> Cargador::obtener_peliculas_no_vistas() {

    return l_peliculas_no_vistas;
}


void Cargador::verificar_memoria_liberada() {

    try {
        throw memoria_liberada;
    }
    catch (exception &e) {

        cout << e.what() << '\n';

    }

}
