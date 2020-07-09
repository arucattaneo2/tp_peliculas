
#include "Cargador.h"
#include <iostream>
#include "Memoria_liberada.h"

Cargador::Cargador() {

    l_peliculas;
}


Cargador::~Cargador() {


}


void Cargador::cargar_datos(string nombre_archivo) {

    ifstream archivo(nombre_archivo);
    string nombre, genero, director;
    Lista<string> *elenco;
    unsigned puntaje;


    if (!archivo && nombre_archivo == "peliculas_no_vistas.txt") {
        verificar_memoria_liberada();
    }
    else if (archivo.fail())
        cout << "Error no se pudo abrir el archivo" << endl;
    else {
        while (archivo >> nombre) {
            archivo >> genero;
            archivo >> puntaje;
            archivo >> director;
            elenco = cargar_l_actores(archivo);
            cargar_l_peliculas(nombre, genero, director, puntaje, elenco);

        }
        archivo.close();
    }


}

void Cargador::cargar_l_peliculas(string nombre, string genero, string director, unsigned pnt, Lista<string>* elen) {

    Pelicula *pelicula = new Pelicula(nombre, genero, director, pnt, elen);
    l_peliculas.alta(pelicula);

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


Lista<Pelicula *> Cargador::obtener_l_peliculas() {

    return l_peliculas;
}


void Cargador::verificar_memoria_liberada() {

    try {
        throw memoria_liberada;
    }
    catch (exception &e) {

        cout << e.what() << '\n';


    }

}
