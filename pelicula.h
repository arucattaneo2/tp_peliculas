#ifndef PELICULA_H	
#define PELICULA_H
#include "lista.h"

// Se define la clase Pelicula
class Pelicula{

	private:

	// atributos

		string nombre;
		string genero;
		string director;
		int puntaje;
		Lista<string>* elenco;

	public:
		
		/*
		metodo constructor (sobrecarga)
		PRE: ---
		POST: crea un objeto de tipo Pelicula
		*/
		Pelicula(string nombre, string genero, string director, int puntaje);
		/*
		metodo agregar_actor_o_actriz
		PRE: el objeto de tipo Pelicula fue creado
		POST: agrega un actor o actriz al listado del elenco
		*/
		void agregar_actor_o_actriz(string nombre_actor_o_actriz);
		/*
		metodo obtener_nombre
		PRE: ---
		POST: devuelve el nombre de la pelicula
		*/
		string obtener_nombre();
		/*
		metodo obtener_genero
		PRE: ---
		POST: devuelve el genero de la pelicula
		*/
		string obtener_genero();
		/*
		metodo obtener_director
		PRE: ---
		POST: devuelve el nombre del director de la pelicula
		*/
		string obtener_director();
		/*
		metodo obtener_puntaje
		PRE: ---
		POST: devuelve el puntaje de la pelicula
		*/
		string obtener_puntaje();
		/*
		metodo obtener_elenco
		PRE: ---
		POST: muestra por pantalla el listado del elenco
		*/
		Lista<string>* obtener_elenco();
		/*
		metodo cantidad_actores
		PRE: ---
		POST: devuelve la cantidad de actores de la pelicula
		*/
		int cantidad_actores();
		/*
		metodo mostrar_pelicula
		PRE: el objeto de tipo Pelicula fue creado
		POST: muestra por pantalla los distintos atributos correspondientes a la pelicula
		*/
		void mostrar_pelicula();
		/*
		metodo destructor
		PRE: el objeto de tipo Pelicula fue creado
		POST: elimina el objeto de tipo Pelicula. Libera la memoria que se usa 
		para elenco, los demás atributos están en el stack
		*/
		~Pelicula();
};

#endif PELICULA_H