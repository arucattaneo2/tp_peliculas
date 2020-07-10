
#include "Recomendacion.h"
#include "Cargador.h"

Recomendaciones::Recomendaciones(Cargador carga) {
    l_recomendaciones;
    Lista <Pelicula *> l_vistas = carga.obtener_peliculas_vistas(); // obtengo lista vistas
	Lista <Pelicula *> l_no_vistas = carga.obtener_peliculas_no_vistas(); // obtengo lista no vistas
	Pelicula* vista;
	Pelicula* no_vista;
}

Recomendaciones::~Recomendaciones() {

}


void Recomendaciones::comparar_listas() {

}

Lista<Pelicula *> Recomendaciones::obtener_l_recomendaciones() {

    return l_recomendaciones;
}




Lista <Pelicula*> generar_recomendadas(){
	for(unsigned i=1;i<(l_vistas.get_tam());i++){
		for(unsigned j=1;i<(l_no_vistas.get_tam());j++){
			vista=l_vistas.obtener_dato(i);
			no_vista=l_no_vistas.obtener_dato(j);
			if(juez_booleano()){
				l_recomendaciones.alta(no_vista);
			}
		}
	}
}

bool juez_booleano(){
	if( ((match_genero())&&( (match_director()) || (match_actores()) )) || (puntaje_suficiente()) ){
		return true
	}
}

bool match_genero(){
	if((vista->obtener_genero())==(no_vista->obtener_genero())){
		return true
	}
}

bool match_genero(){
	if((vista->obtener_director())==(no_vista->obtener_director())){
		return true
	}
}
