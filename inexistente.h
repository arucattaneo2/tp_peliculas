#ifndef INEXISTENTE_H
#define INEXISTENTE_H

#include <exception>

using namespace std;

class Archivo_inexistente : public exception{

public:
    Archivo_inexistente();
    ~Archivo_inexistente();
    virtual const char* what() const throw();

} archivo_inexistente;


#endif //INEXISTENTE_H
