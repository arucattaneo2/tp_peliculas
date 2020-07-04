
#include "cargador.h"
#include <iostream>
#include "excepcion.h"

Cargador::Cargador() {

    l_peliculas = 0;
    l_actores = 0;
}

Cargador::~Cargador() {


}


void Cargador::cargar_datos(ifstream archivo) { // carga los datos leidos del archivo en variables declaradas y luego a listas con el empleo del metodo 

    string nombre, genero, director, actores; // variables que almacenaran informacion de cada pelicula
    int puntaje;
    unsigned posicion = 1; //variable que será utilizada en la creación de la lista, identificando en ella las posiciones de cada nodo

    verificar_existencia(archivo);

    if(archivo.fail())
        cout << "Error no se pudo abrir el archivo" << endl;
    while(archivo >> nombre) {
        archivo >> genero;
        archivo >> director;
        archivo >> puntaje;
        cargar_l_actores(archivo);
        cargar_l_peliculas(nombre, genero, director, puntaje, posicion);
        posicion++;
    }
    archivo.close();

}

void Cargador::cargar_l_peliculas(string nombre, string genero, string dire, int puntaje, int pos) {

    Pelicula *ptrpelicula = new Pelicula(nombre, genero, puntaje, dire, l_actores);
    l_peliculas.alta(ptrpelicula, pos);

}


void Cargador::cargar_l_actores(ifstream archivo) {

    int contador = 0;
    string actores;
    while(getline(archivo, actores, ' ')) {
        l_actores.alta(actores, contador);
        contador++;
    }
}


Lista<Pelicula> Cargador::obtener_l_peliculas() {

    return l_peliculas;
}

Lista<string> Cargador::obtener_l_actores() {

    return l_actores;
}


void Cargador::verificar_existencia(ifstream nombre_archivo) {

    try {

        if (!nombre_archivo)
            throw archivo_inexistente;
    }
    catch (const exception& e) {

        cout << e.what() << endl;
    }

}
