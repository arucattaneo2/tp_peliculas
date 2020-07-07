#ifndef INTERFAZ_H
#define ITERFAZ_H

#include "lista.h"
#include "pelicula.h"

class Interfaz{
  private:
   	// almacena la operacion que seleccionará el usuario
	int opcion;
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
	void selec_opcion();
    
  	//muestra una lista completa
 	//PRE: existencia de una lista
 	//POST: a través de un bucle for muestra todos los elementos de una lista, a traves de sus metodos obtener_tamaño y obtener_dato
	void mostrar();
}
