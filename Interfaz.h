
#ifndef INTERFAZ_H
#define INTERFAZ_H

#include "Recomendaciones.h"
#include "Lista.h"
#include "Pelicula.h"

class Interfaz {

private:
    Lista<Pelicula *> *lista_vistas;
    Lista<Pelicula *> *lista_no_vistas;
    Lista<Pelicula *> *lista_recomendadas;
    unsigned opcion;

public:
    //Constructor
    Interfaz(Recomendaciones recomendaciones);

    //PRE: Interfaz debe estar credo
    //POS: Muestra las acciones posible por pantalla y redirige la accion segun la opcion ingresada
    void ejecutar_interfaz();

    //PRE:--
    //POS: Muestra por pantalla las acciones posibles
    void mostrar_opciones();

    //PRE: Debe recibir un unsigned
    //POS: Solicita por pantalla el ingresa de una opcion
    void solicitar_opcion();

    //PRE:--
    //POS: Muestra por pantalla la lista de peliculas vistas
    //PRE:  0 < opcion >= 3
    //POS: Segun el valor del atributo opcion realiza la accion correspondiente
    void redireccionar_opcion();

    void mostrar_peliculas_vistas();

    //PRE:--
    //POS: Muestra por pantalla la lista de peliculas no vistas
    void mostrar_peliculas_no_vistas();

    //PRE:--
    //POS: Muestra por pantalla la lista de peliculas recomendadas
    void mostrar_peliculas_recomendadas();

};

#endif //INTERFAZ_H

