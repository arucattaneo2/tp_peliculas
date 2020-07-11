
#include "Interfaz.h"
#include "Pelicula.h"
#include "Lista.h"


 Interfaz::Interfaz(Recomendaciones recomendaciones) {
    lista_vistas = recomendaciones.obtener_lista_vistas();
    lista_no_vistas = recomendaciones.obtener_lista_no_vistas();
    lista_recomendadas = recomendaciones.obtener_lista_recomendadas();
    unsigned opcion;
 }

 Interfaz::~Interfaz() {

 }


 void Interfaz::ejecutar_interfaz() {

    do{
        mostrar_opciones();
        solicitar_opcion();
        redireccionar_opcion();

    }while (opcion != 0);
}


void Interfaz::mostrar_opciones() {

    cout << "-------------------Menu-------------------" << endl;
    cout << "1.- Mostrar las peliculas vistas" << endl;
    cout << "2.- Mostrar las peliculas no vistas" << endl;
    cout << "3.- Mostrar las peliculas recomendadas" << endl;
    cout << "4.- Salir" << endl;

}

void Interfaz::solicitar_opcion() {

    cout << "Elija la accion que desea realizar" << endl;
    cin >> opcion;
}


void Interfaz::redireccionar_opcion() {

	switch(opcion){
		case 1:{
			mostrar_peliculas_vistas();
			break;
		}
		case 2:{
			mostrar_peliculas_no_vistas();
			break;
		}
		case 3:{
			mostrar_recomendaciones();
			break;
		}

	}

 }


 void Interfaz::mostrar_peliculas_vistas() {
     Pelicula *pelicula;
    for(unsigned i = 1; i <= (lista_vistas->obtener_tamanio()); i++) {
         pelicula = lista_vistas->consultar_dato(i);
         pelicula->mostrar_pelicula();
    }

 }

 void Interfaz::mostrar_peliculas_no_vistas() {
    Pelicula *pelicula;
    for(unsigned i = 1; i <= (lista_no_vistas->obtener_tamanio()); i++) {
         pelicula = lista_no_vistas->consultar_dato(i);
         pelicula->mostrar_pelicula();
    }

 }

 void Interfaz::mostrar_peliculas_recomendadas() {
    Pelicula *pelicula;
    for(unsigned i = 1; i <= (lista_recomendadas->obtener_tamanio()); i++) {
         pelicula = lista_romendadas -> consultar_dato(i);
         pelicula -> mostrar();
    }

}