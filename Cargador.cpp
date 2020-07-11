#include <iostream>
#include <string>
#include "Cargador.h"
#include "Memoria_liberada.h"
/*
Cargador::Cargador(){
    Lista<Pelicula *> lista_vistas;
    Lista<Pelicula *> lista_no_vistas;
}
*/

Cargador::~Cargador() {
}

void Cargador::cargar_datos(string nombre_archivo){

    ifstream archivo(nombre_archivo);
    string nombre, genero, director;
    unsigned puntos;
    Lista<string> *elenco;

    if (!archivo && nombre_archivo == "peliculas_no_vistas.txt"){
        verificar_memoria_liberada();
    }
    else if (archivo.fail())
        cout << "Error, no se pudo abrir el archivo" << endl;
    else{
        while (archivo >> nombre){
            archivo >> genero;
            archivo >> puntos;
            archivo >> director;
            elenco = cargar_lista_actores(archivo);
            cargar_lista(nombre_archivo, nombre, genero, director, puntos, elenco);
        }
        archivo.close();
    }

}

void Cargador::cargar_lista(string nombre_archivo, string nombre, string genero, string director, unsigned puntos, Lista<string>* elenco){

    if(nombre_archivo == "peliculas_no_vistas.txt")
        cargar_lista_no_vistas(nombre, genero, director, puntos, elenco);
    else
        cargar_lista_vistas(nombre, genero, director, puntos, elenco);

}

void Cargador::cargar_lista_no_vistas(string nombre, string genero, string director, unsigned puntos, Lista<string>* elenco){

    Pelicula *pelicula = new Pelicula(nombre, genero, director, puntos, elenco);
    lista_no_vistas.alta(pelicula);

}


void Cargador::cargar_lista_vistas(string nombre, string genero, string director, unsigned puntos, Lista<string>* elenco){

    Pelicula *pelicula = new Pelicula(nombre, genero, director, puntos, elenco);
    lista_vistas.alta(pelicula);


}


Lista<string>* Cargador::cargar_lista_actores(ifstream &archivo){

    string actores;
    Lista<string> *lista_actores = new Lista<string>;

    while(archivo >> actores && archivo.get() != '\n'){
        lista_actores->alta(actores);
 
    }
    lista_actores->alta(actores);
   

    return lista_actores;
}


Lista<Pelicula *> Cargador::obtener_peliculas_vistas(){

    return lista_vistas;
}

Lista<Pelicula *> Cargador::obtener_peliculas_no_vistas(){

    return lista_no_vistas;
}


void Cargador::verificar_memoria_liberada(){

    try{
        throw memoria_liberada;
    }
    catch (exception &e){

        cout << e.what() << '\n';

    }

}