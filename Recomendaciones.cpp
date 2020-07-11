#include <iostream>
#include "Recomendaciones.h"

Recomendaciones::Recomendaciones() {
    lista_vistas = new Lista<Pelicula *>();
    lista_no_vistas = new Lista<Pelicula *>();
    lista_recomendaciones = new Lista<Pelicula *>();
}

Recomendaciones::~Recomendaciones() {

}

void Recomendaciones::comparar_listas() {
    for (int i = 1; i <= (lista_vistas->obtener_tamanio()); i++) {
        Pelicula *pelicula_vista = lista_vistas->obtener_dato(i);

        for (int j = 1; i <= (lista_no_vistas->obtener_tamanio()); j++) {
            Pelicula *pelicula_no_vista = lista_no_vistas->obtener_dato(j);

            if (comparar_peliculas(pelicula_no_vista, pelicula_vista)) {
                lista_recomendaciones->alta(pelicula_no_vista);
            }
        }
    }
}


Lista<Pelicula *> *Recomendaciones::obtener_lista_recomendaciones() {
    return lista_recomendaciones;
}

bool Recomendaciones::comparar_peliculas(Pelicula *pelicula_no_vista, Pelicula *pelicula_vista) {
    return coincidencia_genero(pelicula_no_vista, pelicula_vista) && (coincidencia_director(pelicula_no_vista, pelicula_vista) || coincidencia_actores(pelicula_no_vista, pelicula_vista)) || puntaje_suficiente(pelicula_no_vista);

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

        for (int j = 1; i <= pelicula_no_vista->cantidad_actores(); j++) {
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

