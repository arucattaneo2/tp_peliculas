#include "Recomendaciones.h"
#include "Interfaz.h"

const string PELICULAS_VISTAS = "peliculas_vistas.txt";
const string PELICULAS_NO_VISTAS = "peliculas_no_vistas.txt";

using namespace std;

int main(){

    Recomendaciones recomendaciones;
    recomendaciones.cargar_datos(PELICULAS_VISTAS, PELICULAS_NO_VISTAS);
    recomendaciones.crear_lista_recomendadas();
    Interfaz i(recomendaciones);
    if(!recomendaciones.obtener_lista_no_vistas()->lista_vacia())
        i.ejecutar_interfaz();

    return 0;
}
