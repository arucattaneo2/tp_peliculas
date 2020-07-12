#include "Recomendaciones.h"

using namespace std;

int main(){

    Recomendaciones recomendaciones;
    recomendaciones.cargar_datos("peliculas_vistas.txt", "peliculas_no_vistas.txt");
    recomendaciones.comparar_listas();
    for (int i = 1; i <= recomendaciones.obtener_lista_recomendadas()->obtener_tamanio(); i++) {
        recomendaciones.obtener_lista_recomendadas()->obtener_dato(i)->mostrar_pelicula();
    }


    return 0;
}