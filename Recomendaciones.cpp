#include <iostream>
#include "Recomendaciones.h"
#include "Memoria_liberada.h"

Recomendaciones::Recomendaciones() {
    lista_vistas = new Lista<Pelicula *>();
    lista_no_vistas = new Lista<Pelicula *>();
    lista_recomendadas = new Lista<Pelicula *>();
}

void Recomendaciones::borrar_lista(Lista<Pelicula *> *lista_aux) {
    while (!(lista_aux->lista_vacia())) {
        delete lista_aux->obtener_dato(1);
        lista_aux->baja(1);
    }
}

Recomendaciones::~Recomendaciones() {
    Lista<Pelicula *> *lista_aux = lista_vistas;
    borrar_lista(lista_aux);
    lista_aux = lista_no_vistas;
    borrar_lista(lista_aux);
    borrar_lista(lista_recomendadas);
    delete lista_vistas;
    delete lista_no_vistas;
    delete lista_recomendadas;
}

void Recomendaciones::comparar_listas() {
    if (lista_vistas->lista_vacia()) {
        for (int i = 1; i <= (lista_no_vistas->obtener_tamanio()); i++) {
            Pelicula *pelicula_no_vista = lista_no_vistas->obtener_dato(i);
            if (puntaje_suficiente(pelicula_no_vista))
                lista_recomendadas->alta(pelicula_no_vista);
        }

    } else {

        for (int i = 1; i <= (lista_no_vistas->obtener_tamanio()); i++) {
            Pelicula *pelicula_no_vista = lista_no_vistas->obtener_dato(i);

            for (int j = 1; j <= (lista_vistas->obtener_tamanio()); j++) {
                Pelicula *pelicula_vista = lista_vistas->obtener_dato(j);
                if (comparar_peliculas(pelicula_no_vista, pelicula_vista)) {
                    lista_recomendadas->alta(pelicula_no_vista);
                    //esta agregando más de una vez pelicula no vista
                }
            }
        }
    }
}

bool Recomendaciones::comparar_peliculas(Pelicula *pelicula_no_vista, Pelicula *pelicula_vista) {
    return coincidencia_genero(pelicula_no_vista, pelicula_vista) &&
           (coincidencia_director(pelicula_no_vista, pelicula_vista) ||
            coincidencia_actores(pelicula_no_vista, pelicula_vista)) || puntaje_suficiente(pelicula_no_vista);

}

bool Recomendaciones::coincidencia_genero(Pelicula *pelicula_no_vista, Pelicula *pelicula_vista) {
    return pelicula_vista->obtener_genero() == pelicula_no_vista->obtener_genero();
}

bool Recomendaciones::coincidencia_director(Pelicula *pelicula_no_vista, Pelicula *pelicula_vista) {
    return pelicula_vista->obtener_director() == pelicula_no_vista->obtener_director();
}

bool Recomendaciones::coincidencia_actores(Pelicula *pelicula_no_vista, Pelicula *pelicula_vista) {
    for (int i = 1; i <= (pelicula_vista->cantidad_actores()); i++) {
        string actor_pelicula_vista = pelicula_vista->obtener_elenco()->obtener_dato(i);

        for (int j = 1; j <= pelicula_no_vista->cantidad_actores(); j++) {
            string actor_pelicula_no_vista = pelicula_no_vista->obtener_elenco()->obtener_dato(j);

            if (actor_pelicula_no_vista == actor_pelicula_vista) {
                return true;
            }
        }
    }
    return false;
}

bool Recomendaciones::puntaje_suficiente(Pelicula *pelicula_no_vista) {
    return pelicula_no_vista->obtener_puntaje() >= PUNTAJE_MINIMO;
}

Lista<Pelicula *> *Recomendaciones::obtener_lista_recomendadas() {
    return lista_recomendadas;
}

Lista<Pelicula *> *Recomendaciones::obtener_lista_vistas() {
    return lista_vistas;
}

Lista<Pelicula *> *Recomendaciones::obtener_lista_no_vistas() {
    return lista_no_vistas;
}

void Recomendaciones::cargar_datos(string nombre_archivo_vistas, string nombre_archivo_no_vistas) {
    cargar_datos(nombre_archivo_no_vistas, lista_no_vistas);
    cargar_datos(nombre_archivo_vistas, lista_vistas);
}

void Recomendaciones::cargar_datos(string nombre_archivo, Lista<Pelicula *> *lista_peliculas) {

    ifstream archivo(nombre_archivo);
    string nombre, genero, director;
    unsigned puntos;
    Lista<string> *elenco;

    if (!archivo && nombre_archivo == "peliculas_no_vistas.txt") {
        verificar_memoria_liberada();
    } else if (archivo.fail())
        cout << "Error, no se pudo abrir el archivo: " << nombre_archivo << endl;
    else {
        while (archivo >> nombre) {
            archivo >> genero;
            archivo >> puntos;
            archivo >> director;
            elenco = cargar_lista_actores(archivo);
            Pelicula *pelicula = new Pelicula(nombre, genero, director, puntos, elenco);
            lista_peliculas->alta(pelicula);
        }
        archivo.close();
    }

}

Lista<string> *Recomendaciones::cargar_lista_actores(ifstream &archivo) {

    string actores;
    Lista<string> *lista_actores = new Lista<string>;

    while (archivo >> actores && archivo.get() != '\n')
        lista_actores->alta(actores);

    lista_actores->alta(actores);

    return lista_actores;
}

void Recomendaciones::verificar_memoria_liberada() {

    try {
        throw memoria_liberada;
    }
    catch (exception &e) {

        cout << e.what() << '\n';

    }

}