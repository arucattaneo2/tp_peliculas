#ifndef INTERFAZ_H
#define INTERFAZ_H

using namespace std;

#include "Lista.h"
#include "Pelicula.h"
#include "Cargador.h"
#include "Recomendaciones.h"

class Interfaz {

	private:
	    // almacena la operacion que seleccionará el usuario
	    int opcion;
	    Pelicula* puntPeli;

	public:
	    //constructor
	    //PRE: ninguna
	    //POST: crea un objeto que administra y canaliza los requerimientos del usuario
	    Interfaz();

	    //Destructor
	    //PRE: Menu creado
	    //POST: destruye un ojeto de tipo Menu
	    ~Interfaz();

	    //permite seleccionar una opcion
	    //PRE: Menu creado
	    //POST: propone al usuario una serie de opciones de menu, e inicia las operaciones necesarias para la concrecion de cada una
	    void selecionar_opcion(Cargador carg_vistas, Cargador carg_no_vistas, Recomendaciones recomendaciones);

	    //muestra una lista completa
	    //PRE: existencia de una lista
	    //POST: a través de un bucle for muestra todos los elementos de una lista, a traves de sus metodos obtener_tamaño y obtener_dato
	    void mostrar_1(Cargador cargador);
	    
	    //muestra una lista completa
	    //PRE: existencia de una lista
	    //POST: a través de un bucle for muestra todos los elementos de una lista, a traves de sus metodos obtener_tamaño y obtener_dato
	    void mostrar_2(Recomendaciones recomendador);
	    
};

#endif //INTERFAZ_H