#include "Interfaz.h"

// Constructor
 Interfaz::Interfaz(){
 	
 }

 Interfaz::~Interfaz(){

 }

void Menu::selec_opcion(carg_vistas, carg_no_vistas, recomendeichons){
 	// Presentacion del menu de opciones
	cout<<endl<<"Selecciona una opcion correspondiente a una de las siguientes alternativas: "<<endl;
	cout<<"1.- Mostrar las peliculas vistas"<<endl;
	cout<<"2.- Mostrar las peliculas no vistas"<<endl;
	cout<<"3.- Mostrar las peliculas recomendadas"<<endl;
	int opcion; cin>>opcion; cout<<endl;
	
	// Ramificacion del programa de acuerdo a la opcion escogida
	switch(opcion){
		case 1:{
			mostrar(carg_vistas);			
			break;
		}
		case 2:{
			mostrar(carg_no_vistas);
			break;
		}
		case 3:{
			mostrar(recomendeichons);
			break;
		}
	}
 }


 void Menu::mostrar(cargadore){
 	Lista <Pelicula *> lista_pelis = cargador.obtener_l_peliculas();
 	for(int i=1;i<=(lista_pelis.get_tam());i++){
		// le paso al mismo puntero que estaba usando la direccion del objeto en memoria
		puntPeli=lista_pelis.get_dato(i);
		puntPeli->mostrar_pelicula();
	}
 }
