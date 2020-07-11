#include <iostream>
#include "Lista.h"
#include "Interfaz.h"

using namespace std;

// Constructor
 Interfaz::Interfaz(){
 	
 }

 Interfaz::~Interfaz(){

 }

void Interfaz::selecionar_opcion(Cargador carg_vistas,Cargador carg_no_vistas,Recomendaciones recomendaciones){
 	// Presentacion del menu de opciones
	cout<<"\n############## Opciones: ################\n"<<endl;
	cout<<"1.- Mostrar las peliculas vistas"<<endl;
	cout<<"2.- Mostrar las peliculas no vistas"<<endl;
	cout<<"3.- Mostrar las peliculas recomendadas"<<endl;
	cout<<"4.- Salir"<<endl;
	cout<<"\n#########################################\n";
	int opcion; cin>>opcion; cout<<endl;
	
	// Ramificacion del programa de acuerdo a la opcion escogida
	switch(opcion){
		case 1:{
			mostrar_1(carg_vistas);			
			break;
		}
		case 2:{
			mostrar_1(carg_no_vistas);
			break;
		}
		case 3:{
			mostrar_2(recomendaciones);
			break;
		}
		case 4:{
			exit(0);
			break;
		}
	}
 }


 void Interfaz::mostrar_1(Cargador cargador){
 	Lista <Pelicula *> pelis_vistas = cargador.obtener_peliculas_vistas();
 	for(unsigned i=1;i<=(pelis_vistas.obtener_tamanio());i++){
		// le paso al mismo puntero que estaba usando la direccion del objeto en memoria
		puntPeli=pelis_vistas.obtener_dato(i);
		puntPeli->mostrar_pelicula();
	}
 }

 void Interfaz::mostrar_2(Recomendaciones recomendador){
 	Lista <Pelicula *> pelis_recomendadas = recomendador.obtener_lista_recomendaciones();
 	for(unsigned i=1;i<=(pelis_recomendadas.obtener_tamanio());i++){
		// le paso al mismo puntero que estaba usando la direccion del objeto en memoria
		puntPeli=pelis_recomendadas.obtener_dato(i);
		puntPeli->mostrar_pelicula();
	}
 }
