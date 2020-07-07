

#include "inexistente.h"


Archivo_inexistente::Archivo_inexistente() {

}

Archivo_inexistente::~Archivo_inexistente() {

}

const char* Archivo_inexistente::what() const throw() {

    return "El archivo no existe";
}
