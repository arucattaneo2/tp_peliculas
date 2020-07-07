#include <iostream>
#include "Pelicula.h"

Pelicula::Pelicula(string nombre, string genero, string director, unsigned puntaje, Lista<string> elenco) {
    this->nombre = nombre;
    this->genero = genero;
    this->director = director;
    this->puntaje = puntaje;
    this->elenco = elenco;
}

/*
void Pelicula::agregar_actor_o_actriz(string nombre_actor_o_actriz){
	elenco.alta(nombre_actor_o_actriz);
}
*/
string Pelicula::obtener_nombre() {
    return nombre;
}

string Pelicula::obtener_genero() {
    return genero;
}

string Pelicula::obtener_director() {
    return director;
}

unsigned Pelicula::obtener_puntaje() {
    return puntaje;
}

Lista<string> Pelicula::obtener_elenco() {
    return elenco;
}

unsigned Pelicula::cantidad_actores() {
    return elenco.obtener_tamanio();
}

void Pelicula::mostrar_pelicula() {
    cout << "#############################################################\n" << endl;
    cout << "Pelicula: " << nombre << endl;
    cout << "Genero: " << genero << endl;
    cout << "Director/a: " << director << endl;
    cout << "Puntaje: " << puntaje << endl;
    cout << "Elenco: " << endl;

    for (int i = 1; i <= elenco.obtener_tamanio(); i++) {
        cout << '\n' << (elenco.obtener_dato(i)) << endl;
    }

    cout << "#############################################################" << endl;
}

Pelicula::~Pelicula() {

}
