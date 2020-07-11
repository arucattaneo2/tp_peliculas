#include "Cargador.h"

using namespace std;

int main(){

    Cargador carga;
    carga.cargar_datos("peliculas_no_vistas.txt");
    /*Pelicula *p = new Pelicula("The Room", "Drama", "Tommy Wiseau", 10);
    //Pelicula q("The Lobster", "Drama", "kcyo", 8);
    Lista<Pelicula*> peliculas;
    peliculas.alta(p);
    */
    
    /*
    peliculas.alta(q);
    peliculas.obtener_dato(1).mostrar_pelicula();
    peliculas.obtener_dato(2).mostrar_pelicula();
    peliculas.baja(1);
    peliculas.obtener_dato(1).mostrar_pelicula();
    */
    //delete p;
    return 0;
}