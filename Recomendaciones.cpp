#include <iostream>
#include "Recomendaciones.h"

Recomendaciones::Recomendaciones(Cargador cargador) {

    lista_vistas = cargador.obtener_peliculas_vistas(); // obtengo lista_vistas
    lista_no_vistas = cargador.obtener_peliculas_no_vistas(); // obtengo lista_no_vistas
    Pelicula peli_vista;
    Pelicula peli_no_vista;
}

Recomendaciones::~Recomendaciones() {

}

void Recomendaciones::comparar_listas() {

}

Lista<Pelicula *> generar_lista_recomendadas() {
    for (int i = 1; i < (lista_vistas.obtener_tamanio()); i++) {
        for (int j = 1; i < (lista_no_vistas.obtener_tamanio()); j++) {
            peli_vista = lista_vistas.obtener_dato(i);
            peli_no_vista = lista_no_vistas.obtener_dato(j);
            if (coincidencias()) {
                lista_recomendaciones.alta(peli_no_vista);
            }
        }
    }
}

Lista<Pelicula *> Recomendaciones::obtener_lista_recomendaciones() {
    return lista_recomendaciones;
}

bool coincidencias() {
    if (((coincidencia_genero()) && ((coincidencia_director()) || (coincidencia_actores()))) ||
        (puntaje_suficiente())) {
        return true;
    }
}

bool coincidencia_genero() {
    if ((peli_vista->obtener_genero()) == (peli_no_vista->obtener_genero())) {
        return true;
    }
}

bool coincidencia_director() {
    if ((peli_vista->obtener_director()) == (peli_no_vista->obtener_director())) {
        return true;
    }
}